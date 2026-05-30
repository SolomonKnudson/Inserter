#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/internal/impl/impls.hpp>

// STL
#include <utility>

namespace Operator
{
  template <typename ImplTag,
            typename... ImplTemplateArgs,
            typename... ImplArgs>
  [[nodiscard]] static decltype(auto)
  operation(ImplArgs&&... args)
  {
    if constexpr (sizeof...(ImplTemplateArgs) == 0)
    {
      return Impl<ImplTag>::invoke(std::forward<ImplArgs>(args)...);
    }
    else
    {
      return Impl<ImplTag>::template invoke<ImplTemplateArgs...>(
          std::forward<ImplArgs>(args)...);
    }
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP
