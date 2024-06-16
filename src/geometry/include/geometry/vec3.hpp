#pragma once

namespace geo {

struct Vec3
{
    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };
};

using Point3 = Vec3;


Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
Vec3 operator*(double scalar, const Vec3& vec);
Vec3 operator/(const Vec3& vec, double scalar);
Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
Vec3 operator-(const Vec3& vec);

double length(const Vec3& vec);
double lengthSquared(const Vec3& vec);
Vec3 normalized(const Vec3& vec);
double dot(const Vec3& lhs, const Vec3& rhs);

}   // namespace geo
