#include <vmath/adapted/std_array.hpp>
#include <vmath/operators.hpp>

int main(int argc, char* argv[])
{
  using vmath::operators::operator+;
  using vmath::operators::operator-;
  using vmath::operators::operator*;
  using vmath::operators::operator/;

  {
    std::array<int, 2> v1{1, 2};
    std::array<int, 2> v2{2, 3};
    auto v3 = v1 + v2;
    if (vmath::elem<0>(v3) != 3) return 1;
    if (vmath::elem<1>(v3) != 5) return 1;
  }

  {
    auto v1 = std::array<int, 2>{1, 2} + std::array<int, 2>{2, 3};
    if (vmath::elem<0>(v1) != 3) return 1;
    if (vmath::elem<1>(v1) != 5) return 1;
  }

  {
    auto v1 = std::array<int, 2>{1, 2} + std::array<int, 2>{2, 3} + 5;
    if (vmath::elem<0>(v1) != 8) return 1;
    if (vmath::elem<1>(v1) != 10) return 1;
  }

  {
    std::array<int, 2> v1{4, 5};
    std::array<int, 2> v2{2, 3};
    auto v3 = v1 - v2;
    if (vmath::elem<0>(v3) != 2) return 1;
    if (vmath::elem<1>(v3) != 2) return 1;
  }

  {
    auto v1 = std::array<int, 2>{4, 5} - std::array<int, 2>{2, 3};
    if (vmath::elem<0>(v1) != 2) return 1;
    if (vmath::elem<1>(v1) != 2) return 1;
  }

  {
    auto v1 = std::array<int, 2>{4, 5} - std::array<int, 2>{2, 3} - 5;
    if (vmath::elem<0>(v1) != -3) return 1;
    if (vmath::elem<1>(v1) != -3) return 1;
  }

  {
    std::array<int, 2> v1{4, 5};
    std::array<int, 2> v2{2, 3};
    auto v3 = v1 * v2;
    if (vmath::elem<0>(v3) != 8) return 1;
    if (vmath::elem<1>(v3) != 15) return 1;
  }

  {
    auto v1 = std::array<int, 2>{4, 5} * std::array<int, 2>{2, 3};
    if (vmath::elem<0>(v1) != 8) return 1;
    if (vmath::elem<1>(v1) != 15) return 1;
  }

  {
    auto v1 = std::array<int, 2>{4, 5} * std::array<int, 2>{2, 3} * 2;
    if (vmath::elem<0>(v1) != 16) return 1;
    if (vmath::elem<1>(v1) != 30) return 1;
  }

  {
    std::array<int, 2> v1{4, 6};
    auto v2 = v1 / 2;
    if (vmath::elem<0>(v2) != 2) return 1;
    if (vmath::elem<1>(v2) != 3) return 1;
  }

  {
    auto v1 = std::array<int, 2>{4, 6} / 2;
    if (vmath::elem<0>(v1) != 2) return 1;
    if (vmath::elem<1>(v1) != 3) return 1;
  }

  {
    auto v1 = 4 * (std::array<int, 2>{4, 6} + std::array<int, 2>{4, 2} - 2) / 3;
    if (vmath::elem<0>(v1) != 8) return 1;
    if (vmath::elem<1>(v1) != 8) return 1;
  }

  return 0;
}