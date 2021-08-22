#include <vmath/adapted/std_array.hpp>
#include <vmath/add.hpp>

int main(int argc, char* argv[])
{
  {
    std::array<int, 2> v1{1, 2};
    std::array<int, 2> v2{2, 3};
    auto v3 = vmath::add(v1, v2);
    if (vmath::elem<0>(v3) != 3) return 1;
    if (vmath::elem<1>(v3) != 5) return 1;
  }

  {
    auto v3 = vmath::add(std::array<int, 2>{1, 2}, std::array<int, 2>{2, 3});
    if (vmath::elem<0>(v3) != 3) return 1;
    if (vmath::elem<1>(v3) != 5) return 1;
  }

  return 0;
}