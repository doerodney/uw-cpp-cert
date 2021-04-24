#ifndef INC_GEOMETRIC_FEATURE_FITTER_H
#define INC_GEOMETRIC_FEATURE_FITTER_H

#include <vector>
#include "Point.h"

class GeometricFeatureFitter {
public:
  GeometricFeatureFitter();
  virtual ~GeometricFeatureFitter();

  void AddData(const Point& pt);
  void AddData(const std::vector<Point>& pts);
  virtual bool Fit() = 0;
  std::size_t GetDataCount() const;
  std::string GetError() const;

protected:
  std::vector<Point> m_data;
  std::string m_error;

};

#endif
