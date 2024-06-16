#include "geometry/collision.hpp"

#include "geometry/ray.hpp"
#include "geometry/sphere.hpp"

#include <cmath>

namespace geo {

std::optional<double> hit(const Ray& ray, const Sphere& sphere)
{
    const Vec3 oc{ sphere.center() - ray.origin() };
    const double a{ dot(ray.direction(), ray.direction()) };
    const double h{ dot(ray.direction(), oc) };
    const double c{ dot(oc, oc) - sphere.radius() * sphere.radius() };
    const double discriminant{ h * h - a * c };

    if (discriminant < 0) {
        return std::nullopt;
    }

    auto sqrtd = sqrt(discriminant);
    auto root = (h - sqrtd) / a;

    if (root > 0.01) {
        return root;
    }
    root = (h + sqrtd) / a;
    if (root > 0.01) {
        return root;
    }

    return std::nullopt;
}

}   // namespace geo
