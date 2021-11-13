#pragma once

#include "../div.hpp"

namespace vmath
{
  namespace operators
  {
    template <typename L, typename R>
    auto operator/(L&& lhs, R&& rhs)
    {
      return div(lhs, rhs);
    }
  }
}