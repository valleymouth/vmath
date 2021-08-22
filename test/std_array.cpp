// Particle headers
#include <vmath/adapted/std_array.hpp>

int main(int argc, char* argv[])
{
  static_assert(
    vmath::traits::is_scalar<std::array<int, 2>>::value == false);
  static_assert(
    vmath::traits::is_vector<std::array<int, 2>>::value == true);
  static_assert(vmath::traits::dim_of<std::array<int, 2>>::value == 2);
  static_assert(vmath::traits::dim_of<std::array<int, 3>>::value == 3);
  static_assert(
    std::is_same<vmath::traits::value_type<std::array<int, 3>>::type,
    int>::value);

  std::array<int, 3> v1{1, 2, 3};
  if (vmath::elem<0>(v1) != 1) return 1;
  if (vmath::elem<1>(v1) != 2) return 1;
  if (vmath::elem<2>(v1) != 3) return 1;
  if (vmath::elem<0>(std::array<int, 3>{1, 2, 3}) != 1) return 1;

  return 0;
}
