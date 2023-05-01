#include "../hdrs/point.h"
#include "../algorithm.h"

point::point(int x, int y)
    : x(x), y(y) {}

bool point::operator==(const point& other) const
{
    return isEqual(other);
}

bool point::operator!=(const point& other) const
{
    return !isEqual(other);
}

bool point::isEqual(const point& other) const
{
    return (x == other.x) && (y == other.y);
}

void point::swap()
{
    std::swap(x, y);
}

void point::swap(point& other)
{
    std::swap(x, other.x);
}

point point::operator+(const point& other) const
{
    point tmp(x + other.x, y + other.y);
    return tmp;
}

point point::operator-(const point& other) const
{
    point tmp(x - other.x, y - other.y);
    return tmp;
}

point point::operator*(int scale) const
{
    point tmp(x * scale, y * scale);
    return tmp;
}

void point::operator+=(const point& other)
{
    (*this) = ((*this) + other);
}

void point::operator-=(const point& other)
{
    (*this) = ((*this) - other);
}

void point::operator*=(int scale)
{
    (*this) = ((*this) * scale);
}