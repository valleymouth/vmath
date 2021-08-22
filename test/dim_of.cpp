#include <vmath/dim_of.hpp>

int main(int argc, char* argv[])
{
  static_assert(vmath::traits::dim_of<int>::value == 1);
  static_assert(vmath::traits::dim_of<int&>::value == 1);
  static_assert(vmath::traits::dim_of<int&&>::value == 1);
  static_assert(vmath::traits::dim_of<int const>::value == 1);
  static_assert(vmath::traits::dim_of<int const &>::value == 1);
  return 0;
}