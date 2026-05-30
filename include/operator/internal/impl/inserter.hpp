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
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasPushFront<Container, Args...>)
    static OPERATOR_AUTO_RETURN invoke(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype((util::deref(std::forward<Container>(container))
                          .push_front(std::forward<Args>(args)),
                      ...)))
    {
      // Args >=2 to account for container that must be passed
      static_assert(sizeof...(Args) >= 2,
                    "Operator::Impl<builtin::push_front>(args...): "
                    "container.push_front(value) must "
                    "be called with at least one value!");
      return (util::deref(std::forward<Container>(container))
                  .push_front(std::forward<Args>(args)),
              ...);
    }
  };

  template <> struct Impl<builtin::emplace_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasEmplaceFront<Container, Args...>)
    static OPERATOR_AUTO_RETURN invoke(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype((util::deref(std::forward<Container>(container))
                          .emplace_front(std::forward<Args>(args)),
                      ...)))
    {
      if constexpr (sizeof...(Args) == 0)
      {
        return util::deref(std::forward<Container>(container)).emplace_front();
      }
      else
      {
        return (util::deref(std::forward<Container>(container))
                    .emplace_front(std::forward<Args>(args)),
                ...);
      }
    }
  };

  template <> struct Impl<builtin::push_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasPushBack<Container, Args...>)
    static OPERATOR_AUTO_RETURN invoke(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype((util::deref(std::forward<Container>(container))
                          .push_back(std::forward<Args>(args)),
                      ...)))
    {
      // Args >=2 to account for container that must be passed
      static_assert(sizeof...(Args) >= 2,
                    "Operator::Impl<builtin::push_back>(args...): "
                    "container.push_back(value) must "
                    "be called with at least one value!");
      return (util::deref(std::forward<Container>(container))
                  .push_back(std::forward<Args>(args)),
              ...);
    }
  };

  template <> struct Impl<builtin::emplace_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasEmplaceBack<Container, Args...>)
    static OPERATOR_AUTO_RETURN invoke(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype((util::deref(std::forward<Container>(container))
                          .emplace_back(std::forward<Args>(args)),
                      ...)))
    {
      if constexpr (sizeof...(Args) == 0)
      {
        return util::deref(std::forward<Container>(container)).emplace_back();
      }
      else
      {
        return (util::deref(std::forward<Container>(container))
                    .emplace_back(std::forward<Args>(args)),
                ...);
      }
    }
  };
} // namespace Operator
#endif // OPERATOR_INTERNAL_INSERTER_IMPLS_HPP
