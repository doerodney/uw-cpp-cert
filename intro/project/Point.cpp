// Copyright [2021] March Madness
#include "Point.h"

Point::Point(double x, double y) : m_x{x}, m_y{y} {}

std::ostream&  operator<<(std::ostream& os, const Point& pt) {
    os << pt.GetX()
       << std::string(",")
       << pt.GetY();

    return os;
}
