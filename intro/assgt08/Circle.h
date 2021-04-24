#ifndef INC_CIRCLE_H
#define INC_CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
public:
    Circle(
        const Point& origin,
        double radius,
        std::ostream& canvas); // the stream draw writes to

    void draw() const override;
    void stream(std::ostream& os) const override;

    const Point& getOrigin() const;
    double getRadius() const;


private:
    Point m_origin;
    double m_radius;
    std::ostream& m_canvas;
};

#endif