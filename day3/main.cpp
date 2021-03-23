#include <iostream>
#include <iomanip> // for std::setprecision()

int main () {
  std::cout << sizeof(int) << '\n';

  // fast and least variables
  // also there are least and fast for uint
  std::cout << "fast 8: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
  std::cout << "fast 64: " << sizeof(std::int_fast64_t) * 8 << " bits\n";

	std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
  std::cout << "least 64: " << sizeof(std::int_least64_t) * 8 << " bits\n";

  std::int8_t i {65}; // 65 == 'A'
  std::cout << i << '\n';

  std::cout << std::setprecision(16); // show 16 digits of precision
  std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
  std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

  char ch {'d'};
  std::cout << static_cast<int>(ch) << '\n'; // prints the ASCII code

  constexpr double gravity { 9.8 };
  constexpr int num { 7 + 9 };

  /*
  int age;
  std::cin >> age;
  constexpr int ageConst { age }; // not okey, it cannot be resolved at compile time
  */
  return 0;
}