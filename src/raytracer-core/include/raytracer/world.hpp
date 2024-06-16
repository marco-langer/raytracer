#pragma once

#include "raytracer/sphere.hpp"

#include <vector>

struct World
{
    std::vector<Sphere> spheres;
};
