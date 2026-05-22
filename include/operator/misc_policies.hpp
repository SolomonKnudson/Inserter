#ifndef OPERATOR_MISC_POLICIES_HPP
#define OPERATOR_MISC_POLICIES_HPP
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

namespace Operator::policies
{
  template <> struct Operator<tags::DisplayContainer>
  {
    template <typename Container, typename Printer>
    static void
    operation(Container&& container, Printer&& printer)
    {
      util::display(std::forward<Container>(container),
                    std::forward<Printer>(printer));
    }
  };

  template <> struct Operator<tags::NoOp>
  {
    template <typename... Args>
    static void
    operation(Args&&...)
    {
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_MISC_POLICIES_HPP

