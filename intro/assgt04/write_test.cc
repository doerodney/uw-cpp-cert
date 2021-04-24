// build:  g++ -Wall -o write_test write_test.cc write.cpp
#include <iostream>
#include "write.h"

int main()
{
    int ival = 17;
    float fval = 18.0;
    std::string sval("19.0");

    std::cout << "\n" << "int test:" << std::endl;
    write(std::cout, ival);

    std::cout << "\n" << "float test:" << std::endl;
    write(std::cout, fval);

    std::cout << "\n" << "std::string test:" << std::endl;
    write(std::cout, sval);

    std::cout << std::endl;
}
