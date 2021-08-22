#pragma once

// Particle headers
#include "transform.hpp"

namespace vmath
{
  template <typename L, typename R>
  auto add(L&& lhs, R&& rhs)
  {
    return transform(
      std::forward<L>(lhs)
      , std::forward<R>(rhs)
      , [](auto lhs, auto rhs) { return lhs + rhs; } );
  }
} // namespace vmath