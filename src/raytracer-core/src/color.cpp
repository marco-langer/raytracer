#include "raytracer/color.hpp"

Color operator*(double scalar, const Color& color)
{
    return Color{ color.r() * scalar, color.g() * scalar, color.b() * scalar };
}
