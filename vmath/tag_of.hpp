#pragma once

#include "is_scalar.hpp"

namespace vmath
{
  namespace traits
  {
    template <typename, typename Enable = void>
    struct tag_of;

    struct scalar_tag;
  
    template <typename T>
    struct tag_of<T, typename std::enable_if_t<is_scalar<T>::value>>
    {
      using type = scalar_tag;
    };

    template <typename T>
    struct tag_of<T const,
      typename std::enable_if<!is_scalar<T>::value>::type>: tag_of<T> {};
    template <typename T>
    struct tag_of<T&,
      typename std::enable_if<!is_scalar<T>::value>::type>: tag_of<T> {};
    template <typename T>
    struct tag_of<T&&,
      typename std::enable_if<!is_scalar<T>::value>::type>: tag_of<T> {};
  } // namespace traits
} // namespace vmath