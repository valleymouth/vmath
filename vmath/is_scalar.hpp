#pragma once

// Std headers
#include <type_traits>

namespace vmath
{
  namespace traits
  {
    template <typename T>
    struct is_scalar
    {
      static constexpr bool value = std::is_arithmetic<
        typename std::remove_reference<T>::type>::value;
    };
  } // namespace traits
} // namespace vmath