#pragma once

#include "../sub.hpp"

namespace vmath
{
  namespace operators
  {
    template <typename L, typename R>
    auto operator-(L&& lhs, R&& rhs)
    {
      return sub(lhs, rhs);
    }
  }
}