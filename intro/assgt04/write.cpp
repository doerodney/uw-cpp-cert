#include <iostream>
#include <sstream>

#include "write.h"


void write(std::ostream& os, int value) {
  os << value;
}


void write(std::ostream& os, float value) {
  os << value;
}

void write(std::ostream& os,  std::string value) {
  os << value;
}


