// copyright 2021 cpplint user
// To build: g++ -Wall -o simple_class_test simple_class.cc
#include <iostream>


class SimpleClass {
  public:
    SimpleClass() {
      std::cout << "in default constructor" << std::endl;
    }

    SimpleClass(const SimpleClass &src) {
      std::cout << "in copy constructor" << std::endl;
    }

    ~SimpleClass() {
      std::cout << "in destructor" << std::endl;
    }
};


void f1(SimpleClass aSimpleClass);
void f2(SimpleClass aSimpleClass);
void f3(SimpleClass& aSimpleClass);
void f4(SimpleClass* aSimpleClass);


void f1(SimpleClass aSimpleClass) {
  SimpleClass inst;
  f2(inst);
}

void f2(SimpleClass aSimpleClass) {
  SimpleClass inst(aSimpleClass);
  f3(inst);
}

void f3(SimpleClass& aSimpleClass) {
  f4(&aSimpleClass);
}

void f4(SimpleClass* aSimpleClass) {}

int main() {

  SimpleClass inst;
  f1(inst);

  return 0;
}
