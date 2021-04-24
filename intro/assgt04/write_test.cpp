#include <iostream>
#include <sstream>

#include "TestHarness.h"
#include "write.h"


TEST(write, int) {
  std::stringstream ss;
  int value = 81;
  std::string svalue("81");

  write(ss, value);
  CHECK_EQUAL(svalue, ss.str());
}


TEST(write, float) {
  std::stringstream ss;
  float value = 3.14;
  std::string svalue("3.14");

  write(ss, value);
  CHECK_EQUAL(svalue, ss.str());
}


TEST(write, string) { 
  std::stringstream ss;

  std::string value("Amber Alert!");

  write(ss, value);
  CHECK_EQUAL(value, ss.str());
}
