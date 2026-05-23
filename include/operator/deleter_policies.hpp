#ifndef OPERATOR_DELETER_POLICIES_HPP
#define OPERATOR_DELETER_POLICIES_HPP
#include <operator/concepts.hpp>
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

// 3rd Party
#include <type_traits/type_traits.hpp>
// STL
#include <functional>

namespace Operator::policies
{
  template <> struct Policy<tags::DeleteScalar>
  {
    template <typename T>
    static void
    operation(const T* const ptr)
    {
      delete ptr;
    }

    template <typename T>
    static void
    operation(T*& ptr, const bool set_nullptr)
    {
      operation(ptr);
      if (set_nullptr)
      {
        ptr = nullptr;
      }
    }
  };

  template <> struct Policy<tags::DeleteArray>
  {
    template <typename T>
    static void
    operation(const T* const ptr)
    {
      delete[] ptr;
    }

    template <typename T>
    static void
    operation(T*& ptr, const bool set_nullptr)
    {
      operation(ptr);
      if (set_nullptr)
      {
        ptr = nullptr;
      }
    }
  };

  template <> struct Policy<tags::CustomDeleter>
  {
    template <typename T,
              typename Deleter,
              typename = type_traits::enable_if_invocable<Deleter, T*&>>
    static decltype(auto)
    operation(Deleter&& deleter, T*& ptr)
    {
      return std::invoke(std::forward<Deleter>(deleter), ptr);
    }

    template <typename T,
              typename Deleter,
              typename = type_traits::enable_if_invocable<Deleter, T* const&>>
    static decltype(auto)
    operation(Deleter&& deleter, T* const& ptr)
    {
      return std::invoke(std::forward<Deleter>(deleter), ptr);
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_DELETER_POLICIES_HPP

