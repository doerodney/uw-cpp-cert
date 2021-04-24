#include <cmath>
#include "CircleFitter.h"
#include "mathutils.h"

CircleFitter::CircleFitter() :
  GeometricFeatureFitter(), m_centerX(nan("")), m_centerY(nan("")), m_radius(nan("")) {
}

// Ref: https://goodcalculators.com/best-fit-circle-least-squares-calculator/
bool CircleFitter::Fit() {
  bool success = false;

  if (0 == m_data.size()) {
    m_error = std::string("No data");
  } else {
    double sigma_x = 0.0;
    double sigma_y = 0.0;
    double sigma_xx = 0.0;
    double sigma_yy = 0.0;
    double sigma_xy = 0;

    double b[3] = {0.0, 0.0, 0.0};

    double x = 0.0;
    double y = 0.0;
    double sum_xx_yy;


    for (std::vector<Point>::const_iterator it = m_data.begin() ; it != m_data.end(); ++it) {
      Point pt = *it;
      x = pt.GetX();
      y = pt.GetY();

      sigma_x += x;
      sigma_y += y;
      sigma_xx += x * x;
      sigma_yy += y * y;
      sigma_xy += x * y;

      sum_xx_yy = x*x + y*y;

      b[0] += x * sum_xx_yy;
      b[1] += y * sum_xx_yy;
      b[2] += sum_xx_yy;
    }

    double a1[3] = {sigma_xx, sigma_xy, sigma_x};
    double a2[3] = {sigma_xy, sigma_yy, sigma_y};
    double a3[3] = {sigma_x, sigma_y, static_cast<double>(m_data.size())};
    std::vector<double> solution;

    solve(a1, a2, a3, solution, b);
    if (3 == solution.size()) {
      success = true;
      
      m_centerX = solution[0]/2.0;
      m_centerY = solution[1]/2.0;
      m_radius = sqrt(  (solution[0] * solution[0]) +
                        (solution[1] * solution[1]) +
                        (4 * solution[2]) 
                     ) / 2.0;
    }    
  }

  return success;
}

double CircleFitter::GetCenterX() const {
  return m_centerX;
}

double CircleFitter::GetCenterY() const {
  return m_centerY;
}

double CircleFitter::GetRadius() const {
  return m_radius;
}
