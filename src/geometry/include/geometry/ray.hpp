#pragma once

#include "geometry/vec3.hpp"

namespace geo {

class Ray
{
public:
    Ray(const Point3& origin, const Vec3& direction)
        : m_origin{ origin }
        , m_direction{ direction }
    {}

    const Point3& origin() const { return m_origin; }
    const Vec3& direction() const { return m_direction; }

private:
    Point3 m_origin;
    Vec3 m_direction;
};

Point3 at(const Ray& ray, double t);

}   // namespace geo
