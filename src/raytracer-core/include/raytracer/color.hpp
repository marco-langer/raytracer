#pragma once

class Color
{
public:
    Color() = default;
    Color(double r, double g, double b)
        : m_r{ r }
        , m_g{ g }
        , m_b{ b }
    {}

    double r() const { return m_r; }
    double g() const { return m_g; }
    double b() const { return m_b; }

private:
    double m_r{ 0.0 };
    double m_g{ 0.0 };
    double m_b{ 0.0 };
};

Color operator*(double scalar, const Color& color);
