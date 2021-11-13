#include <vmath/adapted/std_array.hpp>
#include <vmath/sub.hpp>

int main(int argc, char* argv[])
{
  {
    std::array<int, 2> v1{1, 2};
    std::array<int, 2> v2{2, 3};
    auto v3 = vmath::sub(v2, v1);
    if (vmath::elem<0>(v3) != 1) return 1;
    if (vmath::elem<1>(v3) != 1) return 1;
  }

  {
    auto v1 = vmath::sub(std::array<int, 2>{2, 3}, std::array<int, 2>{1, 2});
    if (vmath::elem<0>(v1) != 1) return 1;
    if (vmath::elem<1>(v1) != 1) return 1;
  }

  {
    std::array<int, 2> v1{2, 3};
    auto v2 = vmath::sub(v1, 2);
    if (vmath::elem<0>(v2) != 0) return 1;
    if (vmath::elem<1>(v2) != 1) return 1;
  }

  {
    auto v1 = vmath::sub(std::array<int, 2>{2, 3}, 2);
    if (vmath::elem<0>(v1) != 0) return 1;
    if (vmath::elem<1>(v1) != 1) return 1;
  }

  {
    std::array<int, 2> v1{2, 3};
    auto v2 = vmath::sub(2, v1);
    if (vmath::elem<0>(v2) != 0) return 1;
    if (vmath::elem<1>(v2) != -1) return 1;
  }

  {
    auto v1 = vmath::sub(2, std::array<int, 2>{2, 3});
    if (vmath::elem<0>(v1) != 0) return 1;
    if (vmath::elem<1>(v1) != -1) return 1;
  }

  return 0;
}