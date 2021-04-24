#ifndef INC_RECTANGLE_H
#define INC_RECTANGLE_H

#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(
        const Point& upperLeft,
        const Point& lowerRight,
        std::ostream& canvas); // the stream draw writes to

    void draw() const override;
    void stream(std::ostream& os) const override;

    const Point& getUpperLeft() const;
    const Point& getLowerRight() const;

private:
    Point m_upperLeft;
    Point m_lowerRight;
    std::ostream& m_canvas;
};

#endif