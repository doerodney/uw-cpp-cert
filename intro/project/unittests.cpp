#include "TestHarness.h"

#include <cmath>
#include <memory>
#include <vector>

#include "CircleFitter.h"
#include "LineFitter.h"
#include "mathutils.h"
#include "matrix.h"
#include "Point.h"

const double epsilon = 0.02;
const double quarter = 0.25;
const double dime = 0.10;
const double nickel = 0.05; 

TEST(CIrcleFitter, OriginUnitCircle) {
	// Add points from a unit circle to fit.
	std::unique_ptr<CircleFitter> cf(new CircleFitter());
	cf->AddData(Point(1,0));
	cf->AddData(Point(0,1));
	cf->AddData(Point(-1,0));
	cf->AddData(Point(0,-1));
	cf->Fit();

	CHECK_DOUBLES_EQUAL(0.0, cf->GetCenterX(), epsilon);
	CHECK_DOUBLES_EQUAL(0.0, cf->GetCenterY(), epsilon);
	CHECK_DOUBLES_EQUAL(1.0, cf->GetRadius(), epsilon);
}


TEST(CircleFitter, RoughCircle) {
	// Circle of radius 2.0 at (2,2)
	std::unique_ptr<CircleFitter> cf(new CircleFitter());
	cf->AddData(Point(4.05, 2.03));
	cf->AddData(Point(1.95, 3.97));
	cf->AddData(Point(-0.03, 1.98));
	cf->AddData(Point(2.02, -0.03));
	cf->Fit();

	CHECK_DOUBLES_EQUAL(2.0, cf->GetCenterX(), 2.0 * epsilon);
	CHECK_DOUBLES_EQUAL(2.0, cf->GetCenterY(), 2.0 * epsilon);
	CHECK_DOUBLES_EQUAL(2.0, cf->GetRadius(), 2.0 * epsilon);
}


TEST(CircleFitter, NAN) {
	std::unique_ptr<CircleFitter> cf(new CircleFitter());
	bool isNan = std::isnan(cf->GetCenterX());
	CHECK_EQUAL(true, isNan);

	isNan = std::isnan(cf->GetCenterY());
	CHECK_EQUAL(true, isNan);

	isNan = std::isnan(cf->GetRadius());
	CHECK_EQUAL(true, isNan);
}


TEST(LineFitter, AddData) {
	LineFitter lf;

	Point pt(0.0, 0.0);
	std::size_t size = 1;
	lf.AddData(pt);
	CHECK_EQUAL(size, lf.GetDataCount())

	std::vector<Point> pts;
	for (int i = 0; i < 4; i++) {
		pts.push_back(pt);
		size++;
	}
	lf.AddData(pts);
	CHECK_EQUAL(size, lf.GetDataCount());
}


TEST(LineFitter, NAN) {
	std::unique_ptr<LineFitter> lf(new LineFitter());
	bool isNan = std::isnan(lf->GetIntercept());
	CHECK_EQUAL(true, isNan);

	isNan = std::isnan(lf->GetSlope());
	CHECK_EQUAL(true, isNan);
}

TEST(LineFitter, horizontal) {
	// Points that generate a line of slope 0 and intercept 1:
	LineFitter lf;
	lf.AddData(Point(-1.0, 1.0));
	lf.AddData(Point(1.0, 1.0));
	lf.AddData(Point(2.0, 1.1));
	lf.AddData(Point(3.0, 0.9));

	lf.Fit();
	double m = lf.GetSlope();
	double b = lf.GetIntercept();

	CHECK_DOUBLES_EQUAL(0.0, m, epsilon);
	CHECK_DOUBLES_EQUAL(1.0, b, epsilon);
}


TEST(LineFitter, positive) {
	// Points that generate a line of slope 1 and intercept 1:
	LineFitter lf;
	lf.AddData(Point(0.0, 1.0));
	lf.AddData(Point(1.0, 2.0));
	lf.AddData(Point(2.0, 3.0));
	lf.AddData(Point(3.0, 3.9));
	lf.AddData(Point(4.0, 5.1));

	lf.Fit();
	double m = lf.GetSlope();
	double b = lf.GetIntercept();

	CHECK_DOUBLES_EQUAL(1.0, m, epsilon);
	CHECK_DOUBLES_EQUAL(1.0, b, epsilon);
}


TEST(matrix, unique_ptr) {
	std::size_t r = 0;
	std::size_t c = 0;
	std::size_t rows = 3;
	std::size_t cols = 3;
	std::size_t size = rows * cols;

	std::unique_ptr<Matrix> p(new Matrix(rows, cols));

	CHECK_EQUAL(size, p->Size());

	double value = 0.0;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			p->Set(r, c, value);
			value++;
		} 
	}

	value = 0.0;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			CHECK_DOUBLES_EQUAL(value, p->Get(r, c), epsilon);
			value++;
		} 
	}
}


TEST(matrix, ctor) {
	std::size_t rows = 3;
	std::size_t cols = 3;
	std::size_t size = rows * cols;

	Matrix m(rows, cols);
	CHECK_EQUAL(size, m.Size());
}

TEST(matrix, values) {
	std::size_t rows = 3;
	std::size_t cols = 3;
	std::size_t r = 0;
	std::size_t c = 0;
	Matrix m(rows, cols);

	double value = 0.0;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			m.Set(r, c, value);
			value++;
		} 
	}

	value = 0.0;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			CHECK_DOUBLES_EQUAL(value, m.Get(r, c), epsilon);
			value++;
		} 
	}
}


TEST(math, CoreDeterminant) {
	
	double expected = 90.0;
	double result = determinant(5.0, 10.0, 1.0, 20.0);
	CHECK_DOUBLES_EQUAL(expected, result, epsilon);	
}

TEST(math, ArrDeterminant2d) {
	double r1[] = {5.0, 10.0};
	double r2[] = {1.0, 20.0};
	double expected = 90.0;
	double observed = determinant(r1, r2);
	CHECK_DOUBLES_EQUAL(expected, observed, epsilon);
}

TEST(math, ArrDeterminant3d) {
	double r1[] = {-3.0, 9.0, 5.0};
	double r2[] = {-4.0, 0.0, 1.0};
	double r3[] = {6.0, 3.0, 0.0};

	double expected = 3.0;
	double observed = determinant(r1, r2, r3);
	CHECK_DOUBLES_EQUAL(expected, observed, epsilon);
}

TEST(solve, happypath2d) {
	// quarters and dimes
	double a1[] = {1, 1};
	double a2[] = {2, 3};
	double b[] = {0.35, 0.80};
	std::size_t nResults = 2;

	std::vector<double> x; 
	solve(a1, a2, x, b);
	CHECK_EQUAL(nResults, x.size());
	if (nResults == x.size()) {
		CHECK_DOUBLES_EQUAL(quarter, x[0], epsilon);
		CHECK_DOUBLES_EQUAL(dime, x[1], epsilon);
	}
}

TEST(solve, baddata2d) {
	// quarters and dimes
	double a1[] = {1, 1};
	double a2[] = {2, 2};
	double b[] = {0.35, 0.80};
	std::size_t nResults = 0;

	std::vector<double> x; 
	solve(a1, a2, x, b);
	CHECK_EQUAL(nResults, x.size());
}

TEST(solve, happypath3d) {
		// quarters, dimes, nickels
	double a1[] = {1, 1, 1};
	double a2[] = {2, 1, 1};
	double a3[] = {3, 1, 2};
	double b[] = {0.40, 0.65, 0.95};
	std::size_t nResults = 3;

	std::vector<double> x; 
	solve(a1, a2, a3, x, b);
	CHECK_EQUAL(nResults, x.size());
	if (nResults == x.size()) {
		CHECK_DOUBLES_EQUAL(quarter, x[0], epsilon);
		CHECK_DOUBLES_EQUAL(dime, x[1], epsilon);
		CHECK_DOUBLES_EQUAL(nickel, x[2], epsilon);
	}
}

TEST(solve, baddata3d) {
		// quarters, dimes, nickels
	double a1[] = {1, 1, 1};
	double a2[] = {2, 2, 2};
	double a3[] = {3, 3, 3};
	double b[] = {0.40, 0.80, 1.20};
	std::size_t nResults = 0;

	std::vector<double> x; 
	solve(a1, a2, a3, x, b);
	CHECK_EQUAL(nResults, x.size());
}
