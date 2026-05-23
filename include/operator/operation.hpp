#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/deleter_policies.hpp>
#include <operator/inserter_policies.hpp>
#include <operator/misc_policies.hpp>

// STL
#include <utility>

namespace Operator
{
  template <typename Tag, typename... Args>
  [[nodiscard]] static decltype(auto)
  operation(Args&&... args)
  {
    return policies::Policy<Tag>::operation(std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP

