// Copyright [2021] March Madness

#include "Rectangle.h"

Rectangle::Rectangle(const Point& upperLeft, const Point& lowerRight,
  std::ostream& canvas): Shape(),
  m_upperLeft(upperLeft), m_lowerRight(lowerRight), m_canvas(canvas) {
}


void Rectangle::draw() const {
  this->stream(m_canvas);
}


void Rectangle::stream(std::ostream& os) const {
  os << "draw rectangle: " << m_upperLeft << "," << m_lowerRight;
}


const Point& Rectangle::getUpperLeft() const {
  return m_upperLeft;
}

const Point& Rectangle::getLowerRight() const {
  return m_lowerRight;
}

