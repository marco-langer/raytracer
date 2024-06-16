#include "raytracer/image_io.hpp"

#include <cmath>
#include <fstream>

namespace {

double linearToGamma(double value) { return std::sqrt(value); }

void writeColor(std::ostream& out, const Color& color)
{
    const auto rbyte{ static_cast<int>(255.999 * linearToGamma(color.r())) };
    const auto gbyte{ static_cast<int>(255.999 * linearToGamma(color.g())) };
    const auto bbyte{ static_cast<int>(255.999 * linearToGamma(color.b())) };

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

}   // namespace

void write_ppm(const std::filesystem::path& filepath, const Image& image)
{
    std::ofstream outStream{ filepath };
    if (!outStream.is_open()) {
        return;
    }

    outStream << "P3\n" << image.width() << ' ' << image.height() << "\n255\n";

    for (int i = 0; i < image.height(); ++i) {
        for (int j = 0; j < image.width(); ++j) {
            writeColor(outStream, image.pixel(i, j));
        }
    }
}
