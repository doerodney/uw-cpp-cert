#include "TestHarness.h"

#include <memory>
#include <optional>
#include <string>
#include <sstream>
#include <vector>

// NOTE:  This week I wrote a bash shell script that generates explicit 
// makefile content.  This is quite handy!  It uses the g++ -MM feature
// to identify dependencies.  Posted it to the discussion channel.

// Q01: Swap functions and their unit tests:
void swap_with_pointers(int *a, int *b) {
  // Verify no NULL pointers passed as arguments.
  if (a && b) {
    int temp = *b;
    *b = *a;
    *a = temp;
  }
}


void swap_with_references(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}


TEST(swap, pointers)
{
  int a_ref = 10;
  int b_ref = 20;

  int a = a_ref;
  int b = b_ref;


  CHECK_EQUAL(a_ref, a);
  CHECK_EQUAL(b_ref, b);  
  
  swap_with_pointers(&a, &b);
  
  CHECK_EQUAL(b_ref, a);
  CHECK_EQUAL(a_ref, b);
}


TEST(swap, references) {
  int a_ref = 10;
  int b_ref = 20;

  int a = a_ref;
  int b = b_ref;

  CHECK_EQUAL(a_ref, a);
  CHECK_EQUAL(b_ref, b);  
  
  swap_with_references(a, b);
  
  CHECK_EQUAL(b_ref, a);
  CHECK_EQUAL(a_ref, b);
}


// Q02: Factorial and unit test
constexpr int factorial(int n) {
  int f = 1;
  for (int i = 2; i <= n; i++) {
    f *= i;
  }

  return f;
}  


/* ---
 * Discussion:
 * I tried to build this using C++20, but my g++ does not yet support it.  The
 * plan was to use the std::is_constant_evaluated() function.
 *
 * I used static_assert to test executions of the factorial function using 
 * g++17.  The factorial function was evaluated at all values of n that did not
 * result in int overflow.  factorial(13) caused overflow, and the static_assert
 * broke the build for that.
 */

TEST(factorial, int) {
  CHECK_EQUAL(6, factorial(3));
  CHECK_EQUAL(720, factorial(6));
  CHECK_EQUAL(479001600, factorial(12));
  // CHECK_EQUAL(6227020800, factorial(13));

  static_assert(factorial(3) == 6, "constexpr not evaluated during compile" );
  static_assert(factorial(12) == 479001600, "constexpr not evaluated during compile" );
  // static_assert(factorial(13) == 6227020800, "constexpr not evaluated during compile" );
}

// Q03: calendar functions:
std::stringstream get_calendar_with_arrays() {
  const char *month_names[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };

  const int month_days[] = {
    31,  // jan 
    28,  // feb
    30,  // mar
    30,  // apr
    31,  // may
    30,  // jun
    31,  // jul
    31,  // aug
    30,  // sep
    31,  // oct
    30,  // nov
    31   // dec
  };

  std::stringstream ss;
  for (int i = 0; i < 12; i++) {
    ss << month_names[i] << " " << month_days[i] << std::endl;
  }

  return ss;  
}

TEST(calendar, arrays) {
  std::stringstream ss = get_calendar_with_arrays();
  
  std::string content = ss.str();

  CHECK(content.find("January") >= 0);
  CHECK(content.find("December") > 0);
}


typedef struct {
  const char* month_name;
  const int month_days;
} month_t;


std::stringstream get_calendar_with_structs() {
  std::stringstream ss;
  const month_t months[] = {
    {"January", 31},
    {"February", 28},
    {"March", 31} ,
    {"April", 30} ,
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"Decempber", 31}
  };

  for (const auto item: months) {
    ss << item.month_name << " " << item.month_days << std::endl;
  }
  
  return ss;
}


TEST(calendar, structs) {
  std::stringstream ss = get_calendar_with_structs();
  
  std::string content = ss.str();

  CHECK(content.find("January") >= 0);
  CHECK(content.find("December") > 0);
}

// Q04: Herding cats:
std::unique_ptr<char[]> cat_with_pointers(const char *a, const char *b) {
  // Determine storage for combined strings:
  int len_required = strlen(a) + strlen(b) + 1;
  
  // Create the unique_ptr:
  auto buf = std::make_unique<char[]>(len_required);

  // Load the content to the unique_ptr storage:
  // string a:
  for (size_t i = 0; i < strlen(a); i++) {
    buf[i] = a[i];
  }

  // string b:
  for (size_t i = strlen(a); i < (strlen(a) + strlen(b)); i++) {
    buf[i] = b[i];
  }
  
  return buf;
}


TEST(cat, pointers) {
  const char* a = "Buccaneers";
  const char* b = "Chiefs";

  const auto buf = cat_with_pointers(a, b);

  std::string s(buf.get());
  CHECK(s.find("Buc") >= 0);
  CHECK(s.find("Chi") > 0);
}


std::string cat_with_strings(const std::string &a, const std::string&b) {
  std::stringstream ss;
  ss << a << b;

  std::string result(ss.str());
  return result;
}

TEST(cat, strings) {
  std::string a("Buccaneers");
  std::string b("Chiefs");
  
  std::string result = cat_with_strings(a, b);

  CHECK(result.find("Buc") >= 0);
  CHECK(result.find("Chi") > 0);
}

/*---
 * Observations:
 * The implementation of cat using char* arguments was a bit of a mess. It was
 * necessary to create a new buffer of the appropriate length, and it felt very
 * C-ish.  I should have checked the pointers for non-NULL, but didn't.
 * The implementation with the references to std strings was a lot cleaner.
 * Conclusion:
 * Sometimes, having a long, gray C beard may be a disadvantage.  Use the new 
 * way.
 */ 

// Q05:  ParseInt
std::optional<int> ParseInt(const std::string& s) {
  std::stringstream parser;

  parser << s;
  int i;
  parser >> i;

  if (parser.fail()) {
    return std::nullopt;
  } else {
    return i;
  }
}


TEST(ParseIntSuccess, Parse) {
  auto result = ParseInt("99");
  CHECK(result.has_value());
  CHECK_EQUAL(99, *result);
}


TEST(ParseIntFailure, Parse) {
  auto result = ParseInt("Hello");
  CHECK(!result.has_value());
}


TEST(ParseIntValueOr, Parse) {
  int def_val = -1;
  auto result = ParseInt("Bonjour");
  CHECK_EQUAL(def_val, result.value_or(def_val));
}

