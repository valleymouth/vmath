#pragma once

#include "../add.hpp"

namespace vmath
{
  namespace operators
  {
    template <typename L, typename R>
    auto operator+(L&& lhs, R&& rhs)
    {
      return add(lhs, rhs);
    }
  }
}