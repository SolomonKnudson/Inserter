#ifndef OPERATOR_IOSTREAM_POLICIES_HPP
#define OPERATOR_IOSTREAM_POLICIES_HPP
#include <operator/policy.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

// 3rd Party
// STL
#include <iostream>

namespace Operator::policy
{
  template <> struct Policy<tags::cin>
  {
    template <typename... LHS>
    static void
    invoke(LHS&&... lhs)
    {
      ((std::cin >> util::deref(std::forward<LHS>(lhs))), ...);
    }
  };

  template <> struct Policy<tags::wcin>
  {
    template <typename... LHS>
    static void
    invoke(LHS&&... lhs)
    {
      ((std::wcin >> util::deref(std::forward<LHS>(lhs))), ...);
    }
  };

  template <> struct Policy<tags::cout>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::cout << args), ...);
    }
  };

  template <> struct Policy<tags::wcout>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::wcout << args), ...);
    }
  };

  template <> struct Policy<tags::cerr>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::cerr << args), ...);
    }
  };

  template <> struct Policy<tags::wcerr>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::wcerr << args), ...);
    }
  };

  template <> struct Policy<tags::clog>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::clog << args), ...);
    }
  };

  template <> struct Policy<tags::wclog>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::wclog << args), ...);
    }
  };
} // namespace Operator::policy
#endif // OPERATOR_IOSTREAM_POLICIES_HPP

