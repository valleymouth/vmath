#include <vmath/adapted/std_array.hpp>
#include <vmath/length.hpp>

int main(int argc, char* argv[])
{
  {
    std::array<int, 2> v{3, 4};
    if (vmath::length_square(v) != 25) return 1;
    if (vmath::length(v) != 5) return 1;
  }

  {
    if (vmath::length_square(std::array<int, 2>{3, 4}) != 25) return 1;
    if (vmath::length(std::array<int, 2>{3, 4}) != 5) return 1;
  }

  return 0;
}