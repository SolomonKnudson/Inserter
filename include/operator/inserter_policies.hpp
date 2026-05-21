#ifndef OPERATOR_INSERTER_POLICIES_HPP
#define OPERATOR_INSERTER_POLICIES_HPP
#include <operator/concepts.hpp>
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

namespace Operator::policies
{
  template <> struct Operator<tags::push_front>
  {
    template <typename Container, typename Value>
    OPERATOR_CREATE_REQUIRES(concepts::HasPushFront<Container, Value>)
    static auto operation(Container&& container, Value&& value)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .push_front(std::forward<Value>(value))))
    {
      return util::deref(std::forward<Container>(container))
          .push_front(std::forward<Value>(value));
    }
  };

  template <> struct Operator<tags::emplace_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasEmplaceFront<Container, Args...>)
    static auto operation(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .emplace_front(std::forward<Args>(args)...)))
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

  template <> struct Operator<tags::push_back>
  {
    template <typename Container, typename Value>
    OPERATOR_CREATE_REQUIRES(concepts::HasPushBack<Container, Value>)
    static auto operation(Container&& container, Value&& value)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .push_back(std::forward<Value>(value))))
    {
      return util::deref(std::forward<Container>(container))
          .push_back(std::forward<Value>(value));
    }
  };

  template <> struct Operator<tags::emplace_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasEmplaceBack<Container, Args...>)
    static auto operation(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .emplace_back(std::forward<Args>(args)...)))
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
} // namespace Operator::policies
#endif // OPERATOR_INSERTER_POLICIES_HPP

