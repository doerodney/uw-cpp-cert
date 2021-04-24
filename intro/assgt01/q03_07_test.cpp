#include "TestHarness.h"

// To add your own unit tests
// 
// 1) Rename this file using a name that describes the software entity under test. E.g., if you were testing std::vector
//    rename this file as VectorTest.cpp
// 2) Add additional test files as needed. E.g., if you were testing a class named Animal and another class named Zoo you
//    would have two test files. AnimalTest.cpp and ZooTest.cpp
// 3) Remove the sample tests from this file


#include <array>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

// q03 - test read/write a double
TEST(stringstream, double)
{
  std::stringstream ss;

  ss << 3.1415927;
  
  double pi;
  ss >> pi;

	CHECK_DOUBLES_EQUAL(pi, 3.1415927, 0.01);
}


// q03 - test read/write a float
TEST(stringstream, float)
{
  std::stringstream ss;

  ss << 3.14;
  
  float pi;
  ss >> pi;

	CHECK_DOUBLES_EQUAL(pi, 3.14f, 0.01f);
}


// q03 - test read/write a string
TEST(stringstream, string)
{
  std::stringstream ss;

  std::string in = "Bonjour";
  ss << in;
  
  std::string out;
  ss >> out;

	CHECK_EQUAL(in, out);
}


// q03 - test read/write a string to an int
TEST(stringstream, badstring)
{
  std::stringstream ss;

  std::string in = "Bonjour";
  ss << in;
  
  int out;
  ss >> out;

	CHECK(ss.fail());
}


// q04 - test array of integers allocated with new
TEST(new, integers)
{
  const int count = 10;
  int *p = new int[count];
  for (int i = 0; i < count; i++) {
    p[i] = i;
  }

  for (int i = 0; i < count; i++) {
    CHECK_EQUAL(i, p[i]);
  }

  delete[] p;
}


// q05 - new school allocation of array
TEST(newschool, integers)
{
  const int count = 10;
  auto intValues = std::make_unique<int[]>(count);

  for (int i = 0; i < count; i++) {
    intValues[i] = i;
  }

  for (int i = 0; i < count; i++) {
    CHECK_EQUAL(i, intValues[i]);
  }
}


// q06 - std::vector
TEST(vector, int)
{
  const int count = 10;
  auto v = std::vector<int>(count);

  for (int i = 0; i < count; i++) {
    v[i] = i;
  }

  for (int i = 0; i < count; i++) {
    CHECK_EQUAL(i, v[i]);
  }
}


// q07 - std::array
TEST(array, float)
{
  const int count = 10;
  auto a = std::array<float, count>();

  for (int i = 0; i < count; i++) {
    a[i] = static_cast<float>(i);
  }


  for (int i = 0; i < count; i++) {
    CHECK_DOUBLES_EQUAL(a[i], static_cast<float>(i), 0.01f);
  }
}

