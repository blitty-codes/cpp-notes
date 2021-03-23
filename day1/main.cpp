// 06/02/2021
#include <iostream>
#include <limits>

// a object-like with substitution text
// do not use them as constants (like here)
#define AUTHOR "blitty-codes"
#define PREPROCESSOR_WHITHOUT

// there is no need to import the .cpp
// if you just use the header of the function
// to day the program that it is else where

// compile as
// g++ -Wall day1.cpp add.cpp -o day1
int add (int a, int b);

int main () {
  std::cout << "Gello\n";

  std::cout << add(5, 2) << '\n';

#ifdef PREPROCESSOR_WHITHOUT
  std:: cout << AUTHOR << '\n';
#endif

#ifndef PETER
  std::cout << "Sorry, but PETER has not been defined\n";
#endif

#if 0
  std::string p = "Sorry, I am not going to be compiled";
  std::string sad_face = ":(";
#endif

// YES is defined in add.cpp, but it does not care, so it will compile the ifndef one
#ifdef YES
  std::cout << "YES\n";
#endif

#ifndef YES
  std::cout << "NO YES :(\n";
#endif

/*
  // don't close the program
  std::cin.clear(); // reset any error flags
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
  std::cin.get(); // get one more char from the user
*/
  return 0;
}