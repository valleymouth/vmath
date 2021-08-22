#pragma once

// Particle headers
#include "dim_of.hpp"
#include "elem.hpp"

namespace vmath
{
  namespace detail
  {
    template <int I, int N>
    struct reduce_impl_
    {
      template <typename T, typename F>
      static auto apply(const T& x, F f)
      {
        return f(
          elem<I>(x)
          , reduce_impl_<I + 1, N>::apply(x, f));
      }
    };

    template <int N>
    struct reduce_impl_<N, N>
    {
      template <typename T, typename F>
      static auto apply(const T& x, F)
      {
        return elem<N>(x);
      }
    };

    template <typename T, typename S, typename F>
    auto reduce_impl(const T& x, const S& s, F f)
    {
      return f(
        s
        , detail::reduce_impl_<
        0
        , traits::dim_of<T>::value - 1
        >::apply(x, f));
    }
  }

  template <typename T, typename S, typename F>
  auto reduce(const T& x, const S& s, F f)
  {
    return detail::reduce_impl(x, s, f);
  }
} // namespace vmath