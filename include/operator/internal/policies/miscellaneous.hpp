#ifndef OPERATOR_MISCELLANEOUS_POLICIES_HPP
#define OPERATOR_MISCELLANEOUS_POLICIES_HPP
#include <operator/policy.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

// 3rd Party
#include <type_traits/type_traits.hpp>

namespace Operator::policy
{
  template <> struct Policy<tags::DisplayContainer>
  {
    template <typename Container, typename Printer>
    static void
    invoke(Container&& container,
           Printer&& printer,
           const std::string& prefix = "")
    {
      util::display(std::forward<Container>(container),
                    std::forward<Printer>(printer),
                    prefix);
    }
  };

  template <> struct Policy<tags::NoOp>
  {
    template <typename... Args>
    static void
    invoke(Args&&...)
    {
    }
  };
} // namespace Operator::policy
#endif // OPERATOR_MISCELLANEOUS_POLICIES_HPP

