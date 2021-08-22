#pragma once

#include "is_scalar.hpp"

namespace vmath
{
  namespace traits
  {
    template <typename, typename Enable = void>
    struct dim_of;

    template <typename T>
    struct dim_of<T, typename std::enable_if_t<is_scalar<T>::value>>
    {
      static constexpr int value = 1;
    };

    template <typename T>
    struct dim_of<T const,
      typename std::enable_if<!is_scalar<T>::value>::type>: dim_of<T> {};
    template <typename T>
    struct dim_of<T&,
      typename std::enable_if<!is_scalar<T>::value>::type>: dim_of<T> {};
    template <typename T>
    struct dim_of<T&&,
      typename std::enable_if<!is_scalar<T>::value>::type>: dim_of<T> {};
  } // namespace traits
} // namespace vmath