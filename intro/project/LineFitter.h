#ifndef INC_LINE_FITTER_H
#define INC_LINE_FITTER_H

#include "GeometricFeatureFitter.h"

class LineFitter : public GeometricFeatureFitter {
public:
  LineFitter();
  virtual bool Fit();

  double GetIntercept() const;
  double GetSlope() const;

protected:
  double m_intercept;
  double m_slope;
};

#endif
