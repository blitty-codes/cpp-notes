#include <iostream>

namespace nested
{
  namespace nameSpace
  {
    void print()
    {
      std::cout << "Yeah! I am nested\n";
    }
  }
}

// C++17 style
namespace just::burn
{
  void print()
  {
    std::cout << "Yeah! Nested with C++17 style\n";
  }  
}
