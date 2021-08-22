// Particle headers
#include <vmath/adapted/std_array.hpp>
#include <vmath/transform.hpp>

int main(int argc, char* argv[])
{
  {
    std::array<int, 3> v1{1, 2, 3};
    auto v2 = vmath::transform(v1, [](int x) { return 2 * x; });

    static_assert(vmath::traits::dim_of<decltype(v2)>::value == 3);
    static_assert(vmath::traits::is_scalar<decltype(v2)>::value == false);
    static_assert(vmath::traits::is_vector<decltype(v2)>::value == true);
    static_assert(std::is_same<vmath::traits::value_type<decltype(v2)>::type, int>::value);

    if (vmath::elem<0>(v2) != 2) return 1;
    if (vmath::elem<1>(v2) != 4) return 1;
    if (vmath::elem<2>(v2) != 6) return 1;
  }

  {
    auto v = vmath::transform(std::array<int, 3>{1, 2, 3}, [](int x) { return 2 * x; });

    if (vmath::elem<0>(v) != 2) return 1;
    if (vmath::elem<1>(v) != 4) return 1;
    if (vmath::elem<2>(v) != 6) return 1;
  }

  {
    std::array<int, 3> v1{1, 2, 3};
    std::array<int, 3> v2{4, 5, 6};
    auto v3 = vmath::transform(v1, v2, [](int x1, int x2) { return x1 + x2; });

    static_assert(vmath::traits::dim_of<decltype(v2)>::value == 3);
    static_assert(vmath::traits::is_scalar<decltype(v2)>::value == false);
    static_assert(vmath::traits::is_vector<decltype(v2)>::value == true);
    static_assert(std::is_same<vmath::traits::value_type<decltype(v2)>::type, int>::value);

    if (vmath::elem<0>(v3) != 5) return 1;
    if (vmath::elem<1>(v3) != 7) return 1;
    if (vmath::elem<2>(v3) != 9) return 1;
  }

  {
    auto v = vmath::transform(
      std::array<int, 3>{1, 2, 3},
      vmath::transform(std::array<int, 3>{1, 2, 3}, [](int x) { return 2 * x; }),
      [](int x1, int x2) { return x1 + x2; });

    if (vmath::elem<0>(v) != 3) return 1;
    if (vmath::elem<1>(v) != 6) return 1;
    if (vmath::elem<2>(v) != 9) return 1;
  }

  {
    // This should fail to compile
    // std::array<int, 2> v1{1, 2};
    // std::array<int, 3> v2{4, 5, 6};
    // auto v3 = vmath::transform(v1, v2, [](int x1, int x2) { return x1 + x2; });
  }
  return 0;
}
