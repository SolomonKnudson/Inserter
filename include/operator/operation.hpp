#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/internal/policies/policies.hpp>

// STL
#include <utility>

namespace Operator
{
  template <typename PolicyTag,
            typename... PolicyTemplateArgs,
            typename... PolicyArgs>
  [[nodiscard]] static decltype(auto)
  operation(PolicyArgs&&... args)
  {
    if constexpr (sizeof...(PolicyTemplateArgs) == 0)
    {
      return policy::Policy<PolicyTag>::invoke(
          std::forward<PolicyArgs>(args)...);
    }
    else
    {
      return policy::Policy<PolicyTag>::template invoke<PolicyTemplateArgs...>(
          std::forward<PolicyArgs>(args)...);
    }
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP
