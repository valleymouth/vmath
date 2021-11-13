#include <vmath/adapted/std_array.hpp>
#include <vmath/dim_of.hpp>

int main(int argc, char* argv[])
{
  static_assert(vmath::traits::dim_of<std::array<int, 1>>::value == 1);
  static_assert(vmath::traits::dim_of<std::array<int, 2>>::value == 2);
  static_assert(vmath::traits::dim_of<std::array<int, 3>>::value == 3);
  static_assert(vmath::traits::dim_of<std::array<int, 4>>::value == 4);
  return 0;
}