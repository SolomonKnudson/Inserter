#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/internal/policies/policies.hpp>

// STL
#include <utility>

namespace Operator
{
  template <typename Tag, typename... Args>
  [[nodiscard]] static decltype(auto)
  operation(Args&&... args)
  {
    return policy::Policy<Tag>::invoke(std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP

