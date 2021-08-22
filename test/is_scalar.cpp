#include <vmath/is_scalar.hpp>

int main(int argc, char* argv[])
{
  static_assert(vmath::traits::is_scalar<int>::value);
  static_assert(vmath::traits::is_scalar<int&>::value);
  static_assert(vmath::traits::is_scalar<int&&>::value);
  static_assert(vmath::traits::is_scalar<int const &>::value);
  static_assert(vmath::traits::is_scalar<float>::value);
  static_assert(vmath::traits::is_scalar<float&>::value);
  static_assert(vmath::traits::is_scalar<float&&>::value);
  static_assert(vmath::traits::is_scalar<float const &>::value);
  static_assert(!vmath::traits::is_scalar<int*>::value);
  static_assert(!vmath::traits::is_scalar<int[]>::value);
  return 0;
}