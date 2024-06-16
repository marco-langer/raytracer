#include "raytracer/camera.hpp"
#include "raytracer/image.hpp"
#include "raytracer/image_io.hpp"
#include "raytracer/render.hpp"
#include "raytracer/sphere.hpp"
#include "raytracer/viewport.hpp"
#include "raytracer/world.hpp"

#include <chrono>
#include <iostream>

int main()
{
    World world;
    world.spheres.push_back(Sphere{ geo::Point3{ 0.0, 0.0, -1.0 }, 0.5, Color{ 1.0, 0.0, 0.0 } });
    world.spheres.push_back(
        Sphere{ geo::Point3{ 0.0, -100.5, -1.0 }, 100.0, Color{ 1.0, 0.0, 0.0 } });

    Image image{ 640, 16.0 / 9.0 };

    const Camera camera{ geo::Point3{}, Viewport{ image.width(), image.aspectRatio() } };

    const auto start{ std::chrono::steady_clock::now() };
    render(image, world, camera);
    const auto end{ std::chrono::steady_clock::now() };
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    write_ppm("test.ppm", image);
}
