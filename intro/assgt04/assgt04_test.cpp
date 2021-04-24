// copyright 2021 cpplint user
#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>

#include "TestHarness.h"


// Q01:  Fun with Date
struct Date {
  Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }

  int year;
  int month;
  int day;
};

// The next two functions are common code used in each addOne* function.
// Decided to isolate and test rather than copy and paste. 
// Converts from Date to std::tm.
std::tm date_to_tm(const Date& date) {
  std::tm d = {};
  d.tm_year = date.year - 1900;
  d.tm_mon = date.month - 1;
  d.tm_mday = date.day;

  return d;
}


TEST(date, tm) {
  auto d = Date(2021, 2, 14);
  auto ts = date_to_tm(d);

  CHECK_EQUAL(121, ts.tm_year);
  CHECK_EQUAL(1, ts.tm_mon);
  CHECK_EQUAL(14, ts.tm_mday);
}


// Converts from std::tm to Date.
Date tm_to_date(const std::tm& t) {
  auto result = Date(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
  return result;
}

TEST(tm, date) {
  std::tm ts = {};
  ts.tm_year = 121;
  ts.tm_mon = 1;
  ts.tm_mday = 14;

  auto d = tm_to_date(ts);

  CHECK_EQUAL(2021, d.year);
  CHECK_EQUAL(2, d.month);
  CHECK_EQUAL(14, d.day);
}


Date addOneDay(const Date& date) {
  auto tm = date_to_tm(date);

  tm.tm_mday += 1;
  std::mktime(&tm);

  auto result = tm_to_date(tm);

  return result;
}

TEST(date, addDay) {
  // Check today:
  auto today = Date{2021, 2, 13};
  auto tomorrow = addOneDay(today);

  CHECK_EQUAL(14, tomorrow.day);
  CHECK_EQUAL(2021, tomorrow.year);
  CHECK_EQUAL(2, tomorrow.month);

  // Check year end:
  auto yearEnd = std::make_unique<Date>(2020, 12, 31);  // required ctor
  auto newYearsDay = addOneDay(*yearEnd);

  CHECK_EQUAL(1, newYearsDay.day);
  CHECK_EQUAL(1, newYearsDay.month);
  CHECK_EQUAL(2021, newYearsDay.year);

  // Check leap year:
  auto beforeLeapDay = Date(2020, 2, 28);
  auto leapDay = addOneDay(beforeLeapDay);

  CHECK_EQUAL(29, leapDay.day);
  CHECK_EQUAL(2, leapDay.month);
  CHECK_EQUAL(2020, leapDay.year);
}



Date addOneMonth(const Date& date) {
  auto tm = date_to_tm(date);

  tm.tm_mon += 1;
  std::mktime(&tm);

  auto d = tm_to_date(tm);

  return d;
}


TEST(date, addMonth) {
  auto now = Date{2021, 2, 15};
  auto later = addOneMonth(now);

  // Test simple case:
  CHECK_EQUAL(now.year, later.year);
  CHECK_EQUAL(now.month + 1, later.month);
  CHECK_EQUAL(now.day, later.day);

  // Test year boundary:
  now = Date{2121, 12, 26};
  later =  addOneMonth(now);

  CHECK_EQUAL(now.year + 1, later.year);
  CHECK_EQUAL(1, later.month);
  CHECK_EQUAL(now.day, later.day);

  // Test leap year behavior:
  now = Date{2020, 2, 29};  // leap day
  later = addOneMonth(now);
  CHECK_EQUAL(now.year, later.year);
  CHECK_EQUAL(now.month + 1, later.month);
  CHECK_EQUAL(now.day, later.day);

  now = Date(2021, 1, 29);   // no leap year
  later = addOneMonth(now);
  CHECK_EQUAL(now.year, later.year);
  CHECK_EQUAL(3, later.month);
  CHECK_EQUAL(1, later.day);
}



Date addOneYear(const Date& date) {
  auto tm = date_to_tm(date);

  tm.tm_year += 1;
  std::mktime(&tm);

  auto d = tm_to_date(tm);

  return d;
}


TEST(date, addYear) {
  auto now = Date{2021, 2, 15};
  auto later = addOneYear(now);

  // Test simple case:
  CHECK_EQUAL(now.year + 1, later.year);
  CHECK_EQUAL(now.month, later.month);
  CHECK_EQUAL(now.day, later.day);

  // Test leap year behavior:
  now = Date{2020, 2, 29};  // leap day
  later = addOneYear(now);
  CHECK_EQUAL(now.year + 1, later.year);
  CHECK_EQUAL(3, later.month);
  CHECK_EQUAL(1, later.day);
}


// NOTE: Q02 is implemented in: 
// write.cpp - the implementation
// write_test.cpp - the unit tests
// write_test.cc - a stand-alone that writes to std::cout.
// NOTE: Used .cc instead of .cpp because my makefile generator looks for *.cpp.

// Q03:  Lambda 
TEST(lambdaTestProblem, lambdas)
{
    auto values = { 2, 4, 6, 8, 10, 12 };
    auto sum = 0;

    std::for_each(values.begin(), values.end(), [&sum] (auto x) {
      sum += x;
    });

    CHECK_EQUAL(42, sum);
}

// Q04:  SimpleClass constructor/destructor invocation counts:
/*---
Implemented in simple_class.cc
NOTE: Used .cc instead of .cpp because my makefile generator looks for *.cpp.

g++ -Wall -o simple_class_test simple_class.cc
./simple_class_test  (Results in five constructor and five destructor invocations) 
in default constructor
in copy constructor
in default constructor
in copy constructor
in copy constructor
in destructor
in destructor
in destructor
in destructor
in destructor

---*/


// Q05:  Bank Account
/*---
Use cases:
* A user opens an account at a bank.
* A user makes a deposit into an account.
* A user makes a withdrawl from an account.
* A user transfers money between accounts.
* A user closes an account.
* Add a contact to an account owner.
* Remove a contact from an account.

A bank:
* Implements: 
  * Customer accounts

A customer account:
* Implements a set of contacts for the account
* Has these attributes: 
  * Checking account
  * Savings account

A financial account:
* Maintains a balance
* Accepts deposits
* Allows withdrawls
* Pays a periodic interest rate

A savings account:
* Is an account

A checking accout:
* Is an account
* Implements withdrawl by check 

---*/