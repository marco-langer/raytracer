#pragma once

#include "image.hpp"

#include <filesystem>

void write_ppm(const std::filesystem::path& filepath, const Image& image);
