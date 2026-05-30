#ifndef OPERATOR_INTERNAL_INSERTER_IMPLS_HPP
#define OPERATOR_INTERNAL_INSERTER_IMPLS_HPP
#include <operator/builtin.hpp>
#include <operator/impl.hpp>
#include <operator/internal/concepts.hpp>
#include <operator/util.hpp>

namespace Operator
{
  template <> struct Impl<builtin::push_front>
  {
    template <typename Container, typename... Values>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasPushFront<Container, Values...>)
    static OPERATOR_AUTO_RETURN
        invoke(Container&& container, Values&&... values)
            OPERATOR_CREATE_TRAILING_RETURN(
                decltype((util::deref(std::forward<Container>(container))
                              .push_front(std::forward<Values>(values)),
                          ...)))
    {
      static_assert(
          sizeof...(Values) > 0,
          "Operator::Impl<builtin::push_front>(container, values...): "
          "must be called with at least one value!");

      return (util::deref(std::forward<Container>(container))
                  .push_back(std::forward<Values>(values)),
              ...);
    }
  };

  template <> struct Impl<builtin::emplace_front>
  {
    template <typename Container, typename... Values>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasEmplaceFront<Container, Values...>)
    static OPERATOR_AUTO_RETURN
        invoke(Container&& container, Values&&... values)
            OPERATOR_CREATE_TRAILING_RETURN(
                decltype((util::deref(std::forward<Container>(container))
                              .emplace_front(std::forward<Values>(values)),
                          ...)))
    {
      if constexpr (sizeof...(Values) == 0)
      {
        return util::deref(std::forward<Container>(container)).emplace_front();
      }
      else
      {
        return (util::deref(std::forward<Container>(container))
                    .emplace_front(std::forward<Values>(values)),
                ...);
      }
    }
  };

  template <> struct Impl<builtin::push_back>
  {
    template <typename Container, typename... Values>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasPushBack<Container, Values...>)
    static OPERATOR_AUTO_RETURN
        invoke(Container&& container, Values&&... values)
            OPERATOR_CREATE_TRAILING_RETURN(
                decltype((util::deref(std::forward<Container>(container))
                              .push_back(std::forward<Values>(values)),
                          ...)))
    {
      static_assert(sizeof...(Values) > 0,
                    "Operator::Impl<builtin::push_back>(container, values...): "
                    "must be called with at least one value!");

      return (util::deref(std::forward<Container>(container))
                  .push_back(std::forward<Values>(values)),
              ...);
    }
  };

  template <> struct Impl<builtin::emplace_back>
  {
    template <typename Container, typename... Values>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasEmplaceBack<Container, Values...>)
    static OPERATOR_AUTO_RETURN
        invoke(Container&& container, Values&&... values)
            OPERATOR_CREATE_TRAILING_RETURN(
                decltype((util::deref(std::forward<Container>(container))
                              .emplace_back(std::forward<Values>(values)),
                          ...)))
    {
      if constexpr (sizeof...(Values) == 0)
      {
        return util::deref(std::forward<Container>(container)).emplace_back();
      }
      else
      {
        return (util::deref(std::forward<Container>(container))
                    .emplace_back(std::forward<Values>(values)),
                ...);
      }
    }
  };
} // namespace Operator
#endif // OPERATOR_INTERNAL_INSERTER_IMPLS_HPP
