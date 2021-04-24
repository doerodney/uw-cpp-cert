// Copyright [2021] March Madness

#include "Triangle.h"

Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3,
  std::ostream& canvas): Shape(),
  m_v1(v1), m_v2(v2), m_v3(v3), m_canvas(canvas) {
}


void Triangle::draw() const {
  this->stream(m_canvas);
}


void Triangle::stream(std::ostream& os) const {
  os << "draw triangle: " << m_v1 << "," << m_v2 << "," << m_v3;
}


const Point& Triangle::getV1() const {
  return m_v1;
}

const Point& Triangle::getV2() const {
  return m_v2;
}

const Point& Triangle::getV3() const {
  return m_v3;
}
