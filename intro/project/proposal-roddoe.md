# C++ Intro - Project Proposal
My background is C++ has mostly been in machine vision used for metrology and inspection.  For my project, I would like to combine my interest in inexpensive hardware (Raspberry Pi) with machine vision.  This project is a well-you-have-to-start-somewhere component of this endeavor - fitting points to geometric features.

## Problem to be Solved
Given a set of 2-D data points, fit these points to a feature.  To limit the scope, the features used in this phase of the project will include:
* Fit a cloud of points to a line with slope `m` and intercept `b`.
* Fit a cloud of points to a circle located at (x,y) = `(a,b)`, of radius `r`.
* Fit a point to the intersection of two lines.

## Implementation
The general approach to these sets of problems is to identify parameters that minimize the error.  For example, if the error in the problem is the square of the difference between a measured `y'` and a calculated `y`, find the values of `m` and `b` that minimize that error.

For the line and circle features, this will require some partial derivatives and linear algebra to solve sets of simultaneous equations.  To keep it simple, I will use Cramer's Rule to solve the 2x2 line problem and the 3x3 circle problem.  Hopefully, I can get the math right.  It's been a while...

For more complicated future features, such as 3-D points measured from a sphere, I would like to use the Gnu Scientific Library's minimization functionality.  That will not be for now.  It may be a superior approach generally.

## Deliverables
This project will deliver:
* Class implementations that: 
  * Identify parameters that minimize total error.
  * Calculate goodness of fit.
* Unit tests to test positive fits.
* Unit tests to identify insufficient data situations.

