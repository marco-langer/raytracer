#include "geometry/vec3.hpp"

#include <cmath>

namespace geo {

Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
{
    return Vec3{ .x = lhs.x + rhs.x, .y = lhs.y + rhs.y, .z = lhs.z + rhs.z };
}

Vec3 operator*(double scalar, const Vec3& vec)
{
    return Vec3{ .x = vec.x * scalar, .y = vec.y * scalar, .z = vec.z * scalar };
}

Vec3 operator/(const Vec3& vec, double scalar)
{
    return Vec3{ .x = vec.x / scalar, .y = vec.y / scalar, .z = vec.z / scalar };
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
{
    return Vec3{ .x = lhs.x - rhs.x, .y = lhs.y - rhs.y, .z = lhs.z - rhs.z };
}

Vec3 operator-(const Vec3& vec) { return (-1.0) * vec; }

double length(const Vec3& vec) { return std::sqrt(lengthSquared(vec)); }

double lengthSquared(const Vec3& vec) { return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z; }

Vec3 normalized(const Vec3& vec) { return vec / length(vec); }

double dot(const Vec3& lhs, const Vec3& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

}   // namespace geo
