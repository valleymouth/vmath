#include <vmath/adapted/std_array.hpp>
#include <vmath/div.hpp>

int main(int argc, char* argv[])
{
  {
    std::array<int, 2> v1{4, 6};
    std::array<int, 2> v2{2, 3};
    auto v3 = vmath::div(v1, v2);
    if (vmath::elem<0>(v3) != 2) return 1;
    if (vmath::elem<1>(v3) != 2) return 1;
  }

  {
    auto v1 = vmath::div(std::array<int, 2>{4, 6}, std::array<int, 2>{2, 3});
    if (vmath::elem<0>(v1) != 2) return 1;
    if (vmath::elem<1>(v1) != 2) return 1;
  }

  {
    std::array<int, 2> v1{4, 6};
    auto v2 = vmath::div(v1, 2);
    if (vmath::elem<0>(v2) != 2) return 1;
    if (vmath::elem<1>(v2) != 3) return 1;
  }

  {
    auto v1 = vmath::div(std::array<int, 2>{4, 6}, 2);
    if (vmath::elem<0>(v1) != 2) return 1;
    if (vmath::elem<1>(v1) != 3) return 1;
  }

  // Those must not compile
  // {
  //   std::array<int, 2> v1{1, 2};
  //   auto v2 = vmath::div(2, v1);
  //   if (vmath::elem<0>(v2) != 2) return 1;
  //   if (vmath::elem<1>(v2) != 4) return 1;
  // }
  
  // {
  //   auto v1 = vmath::div(2, std::array<int, 2>{1, 2});
  //   if (vmath::elem<0>(v1) != 2) return 1;
  //   if (vmath::elem<1>(v1) != 4) return 1;
  // }

  return 0;
}