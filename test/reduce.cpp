// Particle headers
#include <vmath/adapted/std_array.hpp>
#include <vmath/reduce.hpp>

int main(int argc, char* argv[])
{
  {
    std::array<int, 3> v{1, 2, 3};
    {
      int sum = vmath::reduce(v, 0, std::plus<int>());
      if (sum != 6) return 1;
    }
    {
      int sum = vmath::reduce(v, 10, std::plus<int>());
      if (sum != 16) return 1;
    }
  }

  {
    int sum = vmath::reduce(std::array<int, 3>{1, 2, 3}, 1, std::plus<int>());
    if (sum != 7) return 1;
  }

  return 0;
}
