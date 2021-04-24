#ifndef INC_CIRCLE_FITTER_H
#define INC_CIRCLE_FITTER_H

#include "GeometricFeatureFitter.h"

class CircleFitter : public GeometricFeatureFitter {
public:
  CircleFitter();
  virtual bool Fit();

  // Point m_center;
  double GetCenterX() const;
  double GetCenterY() const;
  double GetRadius() const;

protected:
  double m_centerX;
  double m_centerY;
  double m_radius;
};


#endif