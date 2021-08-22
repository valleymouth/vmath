#pragma once

// Particle headers
#include "dim_of.hpp"
#include "elem.hpp"
#include "is_vector.hpp"
#include "tag_of.hpp"

namespace vmath
{
  namespace detail
  {
    template <typename T, typename F>
    struct unary_transform_t
    {
      T vec;
      F f;

      unary_transform_t(T x, F f)
        : vec(x)
        , f(f)
      {}
    };

    template <typename T0, typename T1, typename F>
    struct binary_transform_t
    {
      T0 vec0;
      T1 vec1;
      F f;

      binary_transform_t(T0 x0, T1 x1, F f)
        : vec0(x0)
        , vec1(x1)
        , f(f)
      {}
    };
  } // namespace detail

  namespace traits
  {
    struct unary_transform_tag;
    struct binary_transform_tag;

    template <typename T, typename F>
    struct tag_of<detail::unary_transform_t<T, F>>
    {
      using type = unary_transform_tag;
    };

    template <typename T, typename F>
    struct dim_of<detail::unary_transform_t<T, F>>
    {
      static constexpr int value = dim_of<T>::value;
    };

    template <typename T, typename F>
    struct is_vector<detail::unary_transform_t<T, F>>
    {
      static constexpr int value = true;
    };

    template <typename T, typename F>
    struct value_type<detail::unary_transform_t<T, F>>
    {
      using type = typename value_type<T>::type;
    };

    template <typename T0, typename T1, typename F>
    struct tag_of<detail::binary_transform_t<T0, T1, F>>
    {
      using type = binary_transform_tag;
    };

    template <typename T0, typename T1, typename F>
    struct dim_of<detail::binary_transform_t<T0, T1, F>>
    {
      static constexpr int value = dim_of<T0>::value;
    };

    template <typename T0, typename T1, typename F>
    struct is_vector<detail::binary_transform_t<T0, T1, F>>
    {
      static constexpr int value = true;
    };

    template <typename T0, typename T1, typename F>
    struct value_type<detail::binary_transform_t<T0, T1, F>>
    {
      using type = typename std::result_of<F(T0, T1)>::type;
    };
  } // namespace traits

  namespace detail
  {
    template <>
    struct elem_impl<traits::unary_transform_tag>
    {
      template <typename T, std::size_t I>
      struct apply
      {
        static decltype(auto) call(T&& x)
        {
          return x.f(elem<I>(x.vec));
        }
      };
    };

    template <>
    struct elem_impl<traits::binary_transform_tag>
    {
      template <typename T, std::size_t I>
      struct apply
      {
        static decltype(auto) call(T&& x)
        {
          return x.f(elem<I>(x.vec0), elem<I>(x.vec1));
        }
      };
    };
  } // namespace detail
  
  template <typename T, typename F>
  auto transform(T x, F f)
  {
    return detail::unary_transform_t<T, F>(x, f);
  }

  template <typename T0,
    typename T1,
    typename F,
    typename = std::enable_if_t<
      traits::dim_of<T0>::value == traits::dim_of<T1>::value>>
  auto transform(T0 x0, T1 x1, F f)
  {
    return detail::binary_transform_t<T0, T1, F>(x0, x1, f);
  }
} // namespace vmath
