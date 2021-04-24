#include "GeometricFeatureFitter.h"

GeometricFeatureFitter::GeometricFeatureFitter() :
m_data(), m_error(std::string("None")) {

}

GeometricFeatureFitter::~GeometricFeatureFitter() {

}

void GeometricFeatureFitter::AddData(const Point& pt) {
    m_data.push_back(pt);
}

void GeometricFeatureFitter::AddData(const std::vector<Point>& pts) {
    m_data.insert(m_data.end(), pts.begin(), pts.end());
}

std::size_t GeometricFeatureFitter::GetDataCount() const {
    return m_data.size();
}

std::string GeometricFeatureFitter::GetError() const {
    return m_error;
}

