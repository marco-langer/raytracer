#include "geometry/ray.hpp"

namespace geo {

Point3 at(const Ray& ray, double t) { return ray.origin() + t * ray.direction(); }

}   // namespace geo
