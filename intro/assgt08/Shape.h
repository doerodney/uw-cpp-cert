#ifndef INC_SHAPE_H
#define INC_SHAPE_H

#include <ostream>

class Shape
{
public:
    Shape() = default;

    Shape(const Shape& src) = delete;
    Shape& operator=(const Shape& rhs) = delete;

    virtual ~Shape() = default;

    virtual void draw() const = 0;

    virtual void stream(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    shape.stream(os);
    return os;
}

#endif