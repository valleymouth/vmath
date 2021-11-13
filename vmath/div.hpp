#pragma once

// Particle headers
#include "transform.hpp"

namespace vmath
{
  template <typename L, typename R>
  auto div(L&& lhs, R&& rhs)
  {
    if constexpr (traits::is_scalar<R>::value)
    {
      return transform(
        std::forward<L>(lhs)
        , [rhs](auto lhs) { return lhs / rhs; } );
    }
    else
    {
      return transform(
        std::forward<L>(lhs)
        , std::forward<R>(rhs)
        , [](auto lhs, auto rhs) { return lhs / rhs; } );
    }
  }
} // namespace vmath