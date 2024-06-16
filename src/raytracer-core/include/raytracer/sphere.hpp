#pragma once

#include "geometry/sphere.hpp"
#include "raytracer/color.hpp"

class Sphere
{
public:
    Sphere(const geo::Point3& center, double radius, Color color)
        : m_sphere{ center, radius }
        , m_color{ color }
    {}

    const geo::Sphere& sphere() const { return m_sphere; }
    const Color& color() const { return m_color; }

private:
    geo::Sphere m_sphere;
    Color m_color;
};
