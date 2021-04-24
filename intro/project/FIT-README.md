# Description

This document describes the feature fitting process, using the line feature as an example.

Feature fitting involves selection of a model to which to match a set points.  The task is to select values of parameters that minimize the error produced by the model.

Scaling to arbitrarily complex feature is discussed.

## Line Feature
For a line, the model is `y = mx + b`.  

For a perfect fit, with ideal values of `m` and `b`, the error would be zero.  That means that the summation of each instance of `y - mx + b` would be zero for each x,y.  However, some error is expected.  Some errors could result in a positive number and some could result in a negative number.  To eliminate errors due to the sign of the error, the error is squared.  So the error equation becomes:

E = sigma (y - mx - b)^2

To find the values of `m` and `b` that minimizes error, it is necessary to take partial derivatives of the error equation with respect to m and b.

dE/dm = 2 sigma (y - mx -b) (-x).

Setting the result to zero, applying the sigma to each term, and dividing by -2 yields:

sigma x^2 * m + sigma x * b = sigma xy  

A similar approach applies to the intercept `b`.  Taking the partial derivative:

dE/db = 2 sigma (y - mx -b) (-1)

Setting the result to zero, applying the sigma to each term, and dividing by -2 yields:

sigma x * m  + N * b = sigma y


Putting this into AX = B matrix form yields:

| sigma x^2    sigma x | | m |   | sigma xy |
|                      | |   | = |          |
| sigma x      N       | | b |   |  sigma y |

Solve this for X to get optimal values of `m` and `b`.

## Scaling To More Complex Features
Feature fitting is conceptually simple - choose parameters that minimize total model error.  For a line, the model is simple, the partial derivatives are simple, and the solution is simple.  Consider the next level - a circle.  For a circle located at (a, b) of radius r, the model is:

(x-a)^2 + (y-b)^2 = r^2

And the error function is:

E = sigma ((x-a)^2 + (y-b)^2 - r^2))^2

With this slightly more complex error function, the math becomes far more complex.  The algebra becomes error-prone.  For a plane, the math becomes a mess, and for a sphere, a disaster.

TRUE CONFESSION:  I tried to derive the circle equations like I did with the line, and got quite lost...

There is a simpler alternative - the Minimization feature in the Gnu Scientific Library (GSL).  Given the model and optional gradient of the model (the gradient is the set of partial derivatives), the GSL Minimizer can find the optimal set of parameters by minimizing total error.  That will be fun to play with.
