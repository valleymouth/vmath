#pragma once

#include "../mul.hpp"

namespace vmath
{
  namespace operators
  {
    template <typename L, typename R>
    auto operator*(L&& lhs, R&& rhs)
    {
      return mul(lhs, rhs);
    }
  }
}