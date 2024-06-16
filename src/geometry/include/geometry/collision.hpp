#pragma once

#include <optional>

namespace geo {

class Ray;
class Sphere;

std::optional<double> hit(const Ray& ray, const Sphere& sphere);

}   // namespace geo
