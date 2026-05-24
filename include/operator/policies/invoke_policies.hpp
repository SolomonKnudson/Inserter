#ifndef OPERATOR_INVOKE_POLICIES_HPP
#define OPERATOR_INVOKE_POLICIES_HPP
#include <operator/policies/policies.hpp>
#include <operator/tags.hpp>

// 3rd Party
#include <type_traits/type_traits.hpp>
// STL
#include <functional>

namespace Operator::policies
{
  // NOTE: Policy:Invoke/FoldInvoke must have
  // template functions passed as forwarding lambdas
  template <> struct Policy<tags::Invoke>
  {
    template <typename Function,
              typename... Args,
              typename = type_traits::enable_if_invocable<Function, Args...>>
    static decltype(auto)
    invoke(Function&& function, Args&&... args)
    {
      // NOTE: Policy:Invoke will not handle arg pack
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
    invoke(Function&& function, Args&&... args)
    {
      // NOTE: Policy:FoldInvoke will handle arg pack
      return (std::invoke(std::forward<Function>(function),
                          std::forward<Args>(args)),
              ...);
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_INVOKE_POLICIES_HPP

