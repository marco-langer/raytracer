#include "raytracer/render.hpp"

#include "geometry/collision.hpp"
#include "geometry/random.hpp"
#include "geometry/ray.hpp"
#include "raytracer/camera.hpp"
#include "raytracer/color.hpp"
#include "raytracer/image.hpp"
#include "raytracer/world.hpp"

#include <algorithm>
#include <array>
#include <span>
#include <vector>

namespace {

Color backgroundColor(double y)
{
    const double t{ 0.5 * (y + 1.0) };
    const double r{ 1.0 - t * 0.5 };
    const double g{ 1.0 - t * 0.3 };
    const double b{ 1.0 };
    return Color{ r, g, b };
}

Color calcColor(const geo::Ray& ray, const World& world, const Color& color, int maxDepth)
{
    if (maxDepth <= 0) {
        return Color{};
    }

    static RandomNumberGenerator randomGenerator{ -1.0, 1.0, 42 };

    using HitResult = std::pair<std::size_t, double>;
    std::vector<HitResult> hitResults;
    for (std::size_t i = 0; i < world.spheres.size(); ++i) {
        if (auto maybeHit{ hit(ray, world.spheres[i].sphere()) }) {
            hitResults.emplace_back(i, *maybeHit);
        }
    }

    auto nearest =
        std::ranges::min_element(hitResults, {}, &std::pair<std::size_t, double>::second);
    if (nearest == hitResults.end()) {
        return backgroundColor(ray.direction().y);
    }

    const geo::Point3 hitPosition{ geo::at(ray, nearest->second) };
    const geo::Vec3 normal{ geo::normalized(
        hitPosition - world.spheres[nearest->first].sphere().center()) };

    return 0.3
         * calcColor(
               geo::Ray{ hitPosition, normal + geo::randomInUnitSphere(randomGenerator) },
               world,
               color,
               maxDepth - 1);
}

Color calcColor(const geo::Ray& ray, const World& world)
{
    constexpr int maxDepth{ 10 };
    return calcColor(ray, world, Color{}, maxDepth);
}

Color pixelAverage(std::span<const Color> subPixelColors)
{
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    for (const Color& subPixelColor : subPixelColors) {
        r += subPixelColor.r();
        g += subPixelColor.g();
        b += subPixelColor.b();
    }

    const std::size_t elements{ subPixelColors.size() };
    return Color{ r / elements, g / elements, b / elements };
}

}   // namespace

void render(Image& image, const World& world, const Camera& camera)
{
    const Viewport& viewport{ camera.viewport() };

    const geo::Vec3 viewportUpperLeft{ camera.center() - geo::Vec3{ 0.0, 0.0, camera.focalLength() }
                                       - viewport.u() / 2.0 - viewport.v() / 2.0 };
    const geo::Vec3 pixelDelta_u{ viewport.u() / image.width() };
    const geo::Vec3 pixelDelta_v{ viewport.v() / image.height() };
    const geo::Vec3 firstPixelPosition{ viewportUpperLeft + 0.5 * (pixelDelta_u + pixelDelta_v) };
    const geo::Point3 cameraCenter{ camera.center() };

    std::array<Color, 50> subPixelColors;
    const geo::Vec3 subPixelDelta{ 1.0 / subPixelColors.size() * (pixelDelta_u + pixelDelta_v) };

    for (int i = 0; i < image.height(); ++i) {
        for (int j = 0; j < image.width(); ++j) {
            const geo::Vec3 pixelPosition{ firstPixelPosition + j * pixelDelta_u
                                           + i * pixelDelta_v };

            for (std::size_t k = 0; k < subPixelColors.size(); ++k) {
                const geo::Ray ray{ cameraCenter,
                                    normalized(
                                        pixelPosition
                                        + (-0.5 * subPixelColors.size() + k) * subPixelDelta
                                        - cameraCenter) };
                subPixelColors[k] = calcColor(ray, world);
            }
            image.pixel(i, j) = pixelAverage(subPixelColors);
        }
    }
}
