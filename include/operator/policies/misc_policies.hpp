#ifndef OPERATOR_MISC_POLICIES_HPP
#define OPERATOR_MISC_POLICIES_HPP
#include <operator/policies/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

// 3rd Party
#include <type_traits/type_traits.hpp>

namespace Operator::policies
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
} // namespace Operator::policies
#endif // OPERATOR_MISC_POLICIES_HPP

