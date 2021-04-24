# Project Specification
This project is a subset of a larger project, a future machine vision system to be used for inspection and/or metrology.  An essential capability of this system is to fit acquired data points to geometric features.  In this case, the geometric features will include a line and possibly a circle if I can work out the math. 

## System Description
This feature fit capability will be a component of a pipeline with these stages:
* Selection of feature type
* Description of data acquisition strategy
* Acquisition of data points
* Fit data points to feature
* Store feature

This project prototypes the Fit stage.  It's possibly the most clear-cut stage as it's just math.  Acquisition of data points can be mocked. The actual implementation of data could be a nice project for next quarter.

Classes will be used to implement a common interface, in which the interface is described by an abstract base class, and implemented by a concrete implementation class.  Methods in the interface include:
* AddDatum (accepts a single point) 
* AddData (accepts a vector of points)
* Fit (returns boolean success)
* GetError (Returns the specific error)
* GetResult (returns a struct that could be streamed to a database)

## Test Requirements
Test core math functionality:
* Solvable 2x2 and 3x3 sets of simultaneous equations
* Test ideal data feature fits
* Test typical (non-ideal data) feature fits
* Test to identify insufficient data situations

## Initial Design Strategy
Implement these classes:
* GeometricFeatureFitter(abstract base class)
* LineFitter (derives from GeometricFeatureFitter)
* CircleFitter (derives from GeometricFeatureFitter)
