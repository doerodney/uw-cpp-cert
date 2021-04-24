#ifndef INC_TRIANGLE_H
#define INC_TRIANGLE_H

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(
        const Point& v1,
        const Point& v2,
        const Point& v3,
        std::ostream& canvas); // the stream draw writes to

    void draw() const override;
    void stream(std::ostream& os) const override;

    const Point& getV1() const;
    const Point& getV2() const;
    const Point& getV3() const;

private:
    Point m_v1;
    Point m_v2;
    Point m_v3;
    std::ostream& m_canvas;
};

#endif