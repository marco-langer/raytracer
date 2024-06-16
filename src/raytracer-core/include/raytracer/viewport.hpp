#pragma once

#include "geometry/vec3.hpp"

#include <utility>

class Viewport
{
public:
    Viewport(int imageWidth, double aspectRatio)
        : m_width{ m_height / aspectRatio }
        , m_u{ m_width, 0.0, 0.0 }
        , m_v{ 0.0, -m_height, 0.0 }
    {}

    const geo::Vec3& u() const { return m_u; }

    const geo::Vec3& v() const { return m_v; }


private:
    double m_height{ 2.0 };
    double m_width;
    geo::Vec3 m_u;
    geo::Vec3 m_v;
};
