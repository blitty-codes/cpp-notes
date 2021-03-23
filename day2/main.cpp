#include <iostream>
#include "maths.hpp"

// compile: g++ -Wall main.cpp maths.cpp -o main
// if you don't want the function sum, you can
// compile as: g++ -Wall main.cpp -o main

int multiply(int a, int b) {
  return a*b;
}

int main () {
  std::cout << multiply(10, 10) << '\n';

  std::cout << sum(10, 10) << '\n';

  return 0;
}