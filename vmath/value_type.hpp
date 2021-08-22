#pragma once

// Std headers
#include <type_traits>

namespace vmath
{
  namespace traits
  {
    template <typename, typename Enable = void>
    struct value_type;

    template <typename T>
    struct value_type<T, typename std::enable_if_t<is_scalar<T>::value>>
    {
      using type = T;
    };

    template <typename T>
    struct value_type<T const,
      typename std::enable_if<!is_scalar<T>::value>::type>: value_type<T> {};
    template <typename T>
    struct value_type<T&,
      typename std::enable_if<!is_scalar<T>::value>::type>: value_type<T> {};
    template <typename T>
    struct value_type<T&&,
      typename std::enable_if<!is_scalar<T>::value>::type>: value_type<T> {};
  } // namespace traits
} // namespace vmath