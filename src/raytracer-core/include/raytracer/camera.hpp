#pragma once

#include "geometry/vec3.hpp"
#include "viewport.hpp"

class Camera
{
public:
    Camera(const geo::Point3& center, const Viewport& viewport)
        : m_center{ center }
        , m_viewport{ viewport }
    {}

    double focalLength() const { return m_focalLength; }

    const geo::Point3& center() const { return m_center; }

    const Viewport& viewport() const { return m_viewport; }

private:
    double m_focalLength{ 1.0 };
    geo::Point3 m_center;
    Viewport m_viewport;
};
