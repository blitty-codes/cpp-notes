#include <iostream>
#include <bitset>
#include "uwu.cpp"
#include "nested.cpp"

namespace ugu
{
  int sayHi(int a, int b, int c)
  {
    return 0;
  }
}

int sayHi(int a, int b, int c)
{
  return -a-b-c;
}

int main () {
  std::bitset<2> x{ 0b11 };
  std::bitset<2> y { 10 };
  std::bitset<2> xy = 0b01;

  std::cout << x << '\n';

  std::cout << x.test(0) << '\n';
  x.reset(0);
  std::cout << x.test(0) << '\n';
  std::cout << xy << '\n';
  xy.set(1);
  std::cout << xy << '\n';

  // bitmask
  constexpr std::uint_fast8_t mask0{0b0000'0001}; // represents bit 0
  constexpr std::uint_fast8_t mask1{0b0000'0010}; // represents bit 1
  constexpr std::uint_fast8_t mask2{0b0000'0100}; // represents bit 2
  constexpr std::uint_fast8_t mask3{0b0000'1000}; // represents bit 3
  constexpr std::uint_fast8_t mask4{0b0001'0000}; // represents bit 4
  constexpr std::uint_fast8_t mask5{0b0010'0000}; // represents bit 5
  constexpr std::uint_fast8_t mask6{0b0100'0000}; // represents bit 6
  constexpr std::uint_fast8_t mask7{0b1000'0000}; // represents bit 7

  std::uint_fast8_t flags{0b0000'0101}; // 8 bits in size means room for 8 flags

  std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
  std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

  // set a bit
  flags |= (mask5 | mask6);
  // turn off a bit
  flags &= ~mask2;
  // turn on two at the same time
  flags |= (mask0 | mask7);
  // turn off two at the same time
  flags &= ~(mask5 | mask6);
  // flip bits
  flags ^= mask5;

  std::cout << "bit 7: " << ((flags & mask7) ? "on\n" : "off\n");
  std::cout << "bit 2: " << ((flags & mask2) ? "on\n" : "off\n");
  std::cout << "bit 5: " << ((flags & mask5) ? "on\n" : "off\n");

  flags ^= mask5;

  std::cout << "bit 5 has been fliped\n";
  std::cout << "bit 5: " << ((flags & mask5) ? "on\n" : "off\n");

  std::cout << "---------------------------------------\n";

  // bitmask with bitset
  // bitmask supports the bitwise operators, so you have 2 forms to change a bit
  constexpr std::bitset<2> bmask0 { 0b01 };
  constexpr std::bitset<2> bmask1 { 0b10 };

  constexpr std::bitset<2> bflag { 0b11 };

  std::cout << "flag: " << bflag << "\nbit 0 is " << ((bflag.test(0)) ? "on\n" : "off\n");

  std::cout << "---------------------------------------\n";

  // using uwu namespace
  std::cout << "Using UwU namespace\n";
  std::cout << uwu::sayHi(4, 3, 1) << '\n';

  std::cout << "Using UgU namespace\n";
  std::cout << ugu::sayHi(4, 3, 1) << '\n';

  std::cout << "Using global namespace\n";
  std::cout << ::sayHi(4, 3, 1) << '\n';

  std::cout << "Using nested old style ;)\n";
  nested::nameSpace::print();

  std::cout << "Using nested new style ;D\n";
  just::burn::print();

  // namespace aliases
  namespace alias = just::burn;
  std::cout << "Using alias\n";
  alias::print();

  return 0;
}