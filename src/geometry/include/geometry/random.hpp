#pragma once

#include "geometry/vec3.hpp"

#include <random>

class RandomNumberGenerator
{
public:
    RandomNumberGenerator(double min, double max, std::size_t seed = std::random_device{}())
        : m_dist{ min, max }
        , m_gen{ seed }
    {}

    double operator()() { return m_dist(m_gen); }

private:
    std::uniform_real_distribution<double> m_dist;
    std::mt19937 m_gen;
};

namespace geo {

Vec3 randomInUnitSphere(RandomNumberGenerator& generator);

}   // namespace geo
