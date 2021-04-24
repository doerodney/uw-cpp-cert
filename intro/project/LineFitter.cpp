// Copyright 2021 cpplint user
#include <cmath>
#include "LineFitter.h"
#include "mathutils.h"

LineFitter::LineFitter() :
  GeometricFeatureFitter(), m_intercept(nan("")), m_slope(nan("")) {
}


bool LineFitter::Fit() {
  bool success = false;

  if (0 == m_data.size()) {
    m_error = std::string("No data");
  } else {
    double sigma_x = 0.0;
    double sigma_y = 0.0;
    double sigma_x_sq = 0.0;
    double sigma_xy = 0;

    double x = 0.0;
    double y = 0.0;

    for (std::vector<Point>::const_iterator it = m_data.begin() ; it != m_data.end(); ++it) {
      Point pt = *it;
      x = pt.GetX();
      y = pt.GetY();

      sigma_x += x;
      sigma_y += y;
      sigma_x_sq += x * x;
      sigma_xy += x * y;
    }

    double a1[2] = {sigma_x, static_cast<double>(m_data.size())};
    double a2[2] = {sigma_x_sq, sigma_x};
    double b[2] = {sigma_y, sigma_xy};
    std::vector<double> solution;

    solve(a1, a2, solution, b);
    if (2 == solution.size()) {
      success = true;
      m_slope = solution[0];
      m_intercept = solution[1];
    }    
  }

  return success;
}

double LineFitter::GetIntercept() const {
  return m_intercept;
}


double LineFitter::GetSlope() const {
  return m_slope;
}
