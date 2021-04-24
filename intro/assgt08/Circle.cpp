// Copyright [2021] March Madness

#include "Circle.h"

Circle::Circle(const Point& origin, double radius,
  std::ostream& canvas): Shape(),
  m_origin(origin), m_radius(radius), m_canvas(canvas) {
}


void Circle::draw() const {
  this->stream(m_canvas);
}


void Circle::stream(std::ostream& os) const {
  os << "draw circle: " << m_origin << "," << m_radius;
}


const Point& Circle::getOrigin() const {
  return m_origin;
}


double Circle::getRadius() const {
  return m_radius;
}
