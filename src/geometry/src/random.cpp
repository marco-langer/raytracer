#include "geometry/random.hpp"


namespace geo {


Vec3 randomInUnitSphere(RandomNumberGenerator& generator)
{
    Vec3 vec;
    do {
        vec = Vec3{ .x = generator(), .y = generator(), .z = generator() };
    } while (lengthSquared(vec) >= 1.0);

    return normalized(vec);
}

}   // namespace geo
