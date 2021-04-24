#ifndef INC_MATHUTILS_H
#define INC_MATHUTILS_H

#include <memory>
#include <vector>

double determinant(double a, double b, double c, double d);

double determinant(double r1[2], double r2[2]);

double determinant(double r1[3], double r2[3], double r3[3]);

void solve(double a1[2], double a2[2], std::vector<double>& x, double b[2]);

void solve(double a1[3], double a2[3], double a3[3], std::vector<double>& x, double b[3]);

#endif
