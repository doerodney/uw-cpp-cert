// Build:  g++ -Wall -o userio q02.cpp
// Run: ./userio

#include <iostream>
#include <string>

using namespace std;

int main() {
  // Get an integer from the user:
  int i;
  cout << "\nEnter an integer: ";
  cin >> i;
  cout << "You entered: " << i << "\n";

  // Get a double from the user:
  double d;
  cout << "\nEnter a double: ";
  cin >> d;
  cout << "You entered: " << d << "\n";
  
  // Get a string from the user:
  string s;
  cout << "\nEnter a string: ";
  cin >> s;
  cout << "You entered: " << s << "\n";

}
