#ifndef OPERATOR_INTERNAL_IOSTREAM_IMPLS_HPP
#define OPERATOR_INTERNAL_IOSTREAM_IMPLS_HPP
#include <operator/builtin.hpp>
#include <operator/impl.hpp>
#include <operator/util.hpp>

// 3rd Party
// STL
#include <iostream>

namespace Operator
{
  template <> struct Impl<builtin::cin>
  {
    template <typename... LHS>
    static void
    invoke(LHS&&... lhs)
    {
      ((std::cin >> util::deref(std::forward<LHS>(lhs))), ...);
    }
  };

  template <> struct Impl<builtin::wcin>
  {
    template <typename... LHS>
    static void
    invoke(LHS&&... lhs)
    {
      ((std::wcin >> util::deref(std::forward<LHS>(lhs))), ...);
    }
  };

  template <> struct Impl<builtin::cout>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::cout << args), ...);
    }
  };

  template <> struct Impl<builtin::wcout>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::wcout << args), ...);
    }
  };

  template <> struct Impl<builtin::cerr>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::cerr << args), ...);
    }
  };

  template <> struct Impl<builtin::wcerr>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::wcerr << args), ...);
    }
  };

  template <> struct Impl<builtin::clog>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::clog << args), ...);
    }
  };

  template <> struct Impl<builtin::wclog>
  {
    template <typename... Args>
    static void
    invoke(Args&&... args)
    {
      ((std::wclog << args), ...);
    }
  };
} // namespace Operator
#endif // OPERATOR_INTERNAL_IOSTREAM_IMPLS_HPP
