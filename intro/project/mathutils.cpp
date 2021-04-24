// Copyright [2021] March Madness
#include "mathutils.h"

double determinant(double a, double b, double c, double d) {
    auto result = a * d - b * c;
    return result;
}

double determinant(double r1[2], double r2[2]) {
    auto result = determinant(r1[0], r1[1], r2[0], r2[1]);    
    return result;
}


double determinant(double r1[3], double r2[3], double r3[3]) {
    auto result = r1[0] * determinant(r2[1], r2[2], r3[1], r3[2]) -
                  r1[1] * determinant(r2[0], r2[2], r3[0], r3[2]) +
                  r1[2] * determinant(r2[0], r2[1], r3[0], r3[1]);
    return result;
}

// Solves AX=B for X using Cramer's Rule:
void solve(double a1[2], double a2[2], std::vector<double>& x, double b[2]) {
    x.clear();
    
    // Take determinant of matrix X:
    double denominator = determinant(a1[0], a1[1], a2[0], a2[1]);
    if (denominator != 0.0) {
        // Take determinant of maxtrix comprised of matrix A with left
        // column replaced by B:
        double numerator = determinant(b[0], a1[1], b[1], a2[1]);
        // Divide by determinant of matrix A and store:
        x.push_back(numerator/denominator);

        // Take determinant of matrix comprised of matrix A with right
        // column replaced by B:
        numerator = determinant(a1[0], b[0], a2[0], b[1]);
        // Divide by determinant of matrix A and store:
        x.push_back(numerator/denominator);
    }
}

// Solves AX=B for X using Cramer's Rule
void solve(double a1[3], double a2[3], double a3[3], std::vector<double>& x, double b[3]) {
    x.clear();

    double denominator = determinant(a1, a2, a3);
    if (denominator != 0.0) {
        double m1[3], m2[3], m3[3];  // temp matrix rows
        for (int iter = 0; iter < 3; iter++) {
            // Copy the source data into the temp matrix rows:
            for (int i = 0; i < 3; i++) {
                m1[i] = a1[i];
                m2[i] = a2[i];
                m3[i] = a3[i];
            }
            // Copy the b matrix into the iter'th column of the temp matrix rows:
            m1[iter] = b[0];
            m2[iter] = b[1];
            m3[iter] = b[2];
            double numerator = determinant(m1, m2, m3);

            // Push the result onto the result vector:
            x.push_back(numerator/denominator);
        }
    }
}

