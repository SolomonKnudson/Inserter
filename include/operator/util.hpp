#ifndef OPERATOR_UTIL_HPP
#define OPERATOR_UTIL_HPP
#include <operator/macros.hpp>
#include <operator/type_traits.hpp>

// STL
#include <utility>

namespace Operator
{
  namespace util
  {
    template <typename T>
    constexpr decltype(auto)
    deref(T&& type)
    {
      if constexpr (type_traits::can_deref_v<T>)
      {
        return *type;
      }
      else
      {
        return std::forward<T>(type);
      }
    }

    template <typename Container, typename Printer>
    OPERATOR_CREATE_REQUIRES(requires(Container&& container) {
      deref(container).cbegin();
      deref(container).cend();
    })
    static auto display(Container&& container, Printer&& print)
        OPERATOR_CREATE_TRAILING_RETURN(decltype(deref(container).cbegin(),
                                                 deref(container).cend(),
                                                 void()))
    {
      for (const auto& item : deref(container))
      {
        print(item);
      }
    }
  } // namespace util
} // namespace Operator
#endif // OPERATOR_UTIL_HPP
