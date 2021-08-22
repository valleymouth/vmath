#include <vmath/tag_of.hpp>

int main(int argc, char* argv[])
{
  static_assert(std::is_same<
    vmath::traits::tag_of<int>::type,
    vmath::traits::scalar_tag>::value);
  static_assert(std::is_same<
    vmath::traits::tag_of<int&>::type,
    vmath::traits::scalar_tag>::value);
  static_assert(std::is_same<
    vmath::traits::tag_of<int&&>::type,
    vmath::traits::scalar_tag>::value);
  static_assert(std::is_same<
    vmath::traits::tag_of<int const &>::type,
    vmath::traits::scalar_tag>::value);
  return 0;
}