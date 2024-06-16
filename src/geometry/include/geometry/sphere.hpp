#pragma once

#include "geometry/vec3.hpp"

namespace geo {

class Sphere
{
public:
    Sphere(const Point3& center, double radius)
        : m_center{ center }
        , m_radius{ radius }
    {}

    const Point3& center() const { return m_center; }

    double radius() const { return m_radius; }

private:
    Point3 m_center;
    double m_radius;
};

}   // namespace geo
