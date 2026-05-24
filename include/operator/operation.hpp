#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/policies/inserter_policies.hpp>
#include <operator/policies/invoke_policies.hpp>
#include <operator/policies/misc_policies.hpp>

// STL
#include <utility>

namespace Operator
{
  template <typename Tag, typename... Args>
  [[nodiscard]] static decltype(auto)
  operation(Args&&... args)
  {
    return policies::Policy<Tag>::invoke(std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP

