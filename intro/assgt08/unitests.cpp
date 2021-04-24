#include "TestHarness.h"

// To add your own unit tests
// 
// 1) Rename this file using a name that describes the software entity under test. E.g., if you were testing std::vector
//    rename this file as VectorTest.cpp
// 2) Add additional test files as needed. E.g., if you were testing a class named Animal and another class named Zoo you
//    would have two test files. AnimalTest.cpp and ZooTest.cpp
// 3) Remove the sample tests from this file

#include "Shape.h"
#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>
#include <memory>
#include <sstream>


TEST(Point, Getters) {
	double x = 3.0, y = 4.0, tol = 0.001;
	Point pt{x, y};
	CHECK_DOUBLES_EQUAL(x, pt.GetX(), tol);
	CHECK_DOUBLES_EQUAL(y, pt.GetY(), tol);
}


TEST(Point, Stream)
{
	double x = 3.0, y = 4.0;
	Point pt(x, y);
	std::stringstream ss;
	
	ss << pt;
	CHECK_EQUAL(std::string("3,4"), ss.str());
}


TEST(drawUnique, Shape)
{
    std::vector<std::unique_ptr<Shape>> shapes;

    std::stringstream canvas;

    shapes.push_back(std::make_unique<Triangle>(Point(11.1, 22.2), Point(33.3, 44.4), Point(55.5, 66.6), canvas));
    shapes.push_back(std::make_unique<Rectangle>(Point(11.1, 22.2), Point(33.3, 44.4), canvas));
    shapes.push_back(std::make_unique<Circle>(Point(111.1, 222.2), 333.3, canvas));

    for (auto& shape: shapes)
    {
        shape->draw();
    }

    CHECK_EQUAL("draw triangle: 11.1,22.2,33.3,44.4,55.5,66.6draw rectangle: 11.1,22.2,33.3,44.4draw circle: 111.1,222.2,333.3", canvas.str());
}


