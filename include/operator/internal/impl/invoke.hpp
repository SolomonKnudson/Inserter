#ifndef OPERATOR_INTERNAL_INVOKE_IMPLS_HPP
#define OPERATOR_INTERNAL_INVOKE_IMPLS_HPP
#include <operator/builtin.hpp>
#include <operator/impl.hpp>

// 3rd Party
// STL
#include <functional>
// Me :)
#include <type_traits/type_traits.hpp>

namespace Operator
{
  // NOTE: Impl:Invoke/FoldInvoke must have
  // template functions passed as forwarding lambdas
  template <> struct Impl<builtin::Invoke>
  {
    template <typename Function,
              typename... Args,
              typename = type_traits::enable_if_invocable<Function, Args...>>
    static decltype(auto)
    invoke(Function&& function, Args&&... args)
    {
      // NOTE: Impl:Invoke will not handle arg pack
      return std::invoke(std::forward<Function>(function),
                         std::forward<Args>(args)...);
    }
  };

  template <> struct Impl<builtin::FoldInvoke>
  {
    template <
        typename Function,
        typename... Args,
        typename =
            type_traits::enable_if_separate_args_invocable<Function, Args...>>
    static decltype(auto)
    invoke(Function&& function, Args&&... args)
    {
      // NOTE: Impl:FoldInvoke will handle arg pack
      return (std::invoke(std::forward<Function>(function),
                          std::forward<Args>(args)),
              ...);
    }
  };
} // namespace Operator
#endif // OPERATOR_INTERNAL_INVOKE_IMPLS_HPP
