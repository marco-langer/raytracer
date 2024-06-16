#pragma once

#include "color.hpp"

#include <cassert>
#include <iostream>
#include <span>
#include <vector>
class Image
{
public:
    Image(int width, double aspectRatio)
        : m_width{ width }
        , m_height(static_cast<int>(width / aspectRatio))
    {
        m_pixels.resize(width * m_height);
    }

    int width() const { return m_width; }
    int height() const { return m_height; }
    double aspectRatio() const { return static_cast<double>(m_height) / m_width; }

    const Color& pixel(int i, int j) const
    {
        assert(i >= 0 && i < m_height);
        assert(j >= 0 && j < m_width);

        return *(m_pixels.begin() + i * m_width + j);
    }

    Color& pixel(int i, int j)
    {
        assert(i >= 0 && i < m_height);
        assert(j >= 0 && j < m_width);

        return *(m_pixels.begin() + i * m_width + j);
    }

private:
    int m_width;
    int m_height;
    std::vector<Color> m_pixels;
};
