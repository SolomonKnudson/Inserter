#ifndef OPERATOR_MISC_POLICIES_HPP
#define OPERATOR_MISC_POLICIES_HPP
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

// 3rd Party
#include <type_traits/type_traits.hpp>
// STL
#include <functional>

namespace Operator::policies
{
  template <> struct Policy<tags::Invoke>
  {
    template <typename Function,
              typename... Args,
              typename = type_traits::enable_if_invocable<Function, Args...>>
    static decltype(auto)
    operation(Function&& function, Args&&... args)
    {
      return std::invoke(std::forward<Function>(function),
                         std::forward<Args>(args)...);
    }
  };

  template <> struct Policy<tags::FoldInvoke>
  {
    template <
        typename Function,
        typename... Args,
        typename =
            type_traits::enable_if_separate_args_invocable<Function, Args...>>
    static decltype(auto)
    operation(Function&& function, Args&&... args)
    {
      return (std::invoke(std::forward<Function>(function),
                          std::forward<Args>(args)),
              ...);
    }
  };

  template <> struct Policy<tags::DisplayContainer>
  {
    template <typename Container, typename Printer>
    static void
    operation(Container&& container, Printer&& printer)
    {
      util::display(std::forward<Container>(container),
                    std::forward<Printer>(printer));
    }
  };

  template <> struct Policy<tags::NoOp>
  {
    template <typename... Args>
    static void
    operation(Args&&...)
    {
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_MISC_POLICIES_HPP

