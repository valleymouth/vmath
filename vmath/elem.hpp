#pragma once

// Particle headers
#include "tag_of.hpp"

// Std headers
#include <utility> // for std::forward

namespace vmath
{
  namespace detail
  {
    template <typename T>
    struct elem_impl;
  } // namespace detail

  template <std::size_t I, typename T>
  decltype(auto) elem(T&& vec)
  {
    return detail::elem_impl<
      typename traits::tag_of<T>::type
      >::template apply<T, I>::call(std::forward<T>(vec));
  }
} // namespace vmath
