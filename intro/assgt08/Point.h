#ifndef INC_POINT_H
#define INC_POINT_H

#include <cstddef>
#include <ostream>
#include <string>

class Point {
public:
    Point() = default;
    Point(double x, double y);
    Point& operator=(const Point& rhs) = default;
    virtual ~Point() = default;
    friend std::ostream& operator<<(std::ostream& os, const Point& pt);

    double GetX() const { return m_x; }
    double GetY() const { return m_y; }

private:
    double m_x;
    double m_y;
};

#endif