#pragma once

// Particle headers
#include "reduce.hpp"
#include "transform.hpp"

#include <cmath>

namespace vmath
{
  template <typename T>
  auto length_square(T&& x)
  {
    return reduce(
      transform(
        std::forward<T>(x)
        , [](auto e) { return e * e; })
      , 0
      , [](auto s, auto x) { return s + x; });
  }

  template <typename T>
  auto length(T&& x)
  {
    return std::sqrt(length_square(std::forward<T>(x)));
  }
} // namespace vmath