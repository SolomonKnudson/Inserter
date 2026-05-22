#ifndef OPERATOR_DELETER_POLICIES_HPP
#define OPERATOR_DELETER_POLICIES_HPP
#include <operator/concepts.hpp>
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

// STL
#include <functional>

namespace Operator::policies
{
  template <> struct Operator<tags::DeleteScalar>
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

  template <> struct Operator<tags::DeleteArray>
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

  template <> struct Operator<tags::CustomDeleter>
  {
    template <
        typename T,
        typename Deleter,
        typename = std::enable_if_t<std::is_invocable<Deleter, T*&>::value>>
    static decltype(auto)
    operation(Deleter&& deleter, T*& ptr)
    {
      return std::invoke(std::forward<Deleter>(deleter), ptr);
    }

    template <typename T,
              typename Deleter,
              typename = std::enable_if_t<
                  std::is_invocable<Deleter, T* const&>::value>>
    static decltype(auto)
    operation(Deleter&& deleter, T* const& ptr)
    {
      return std::invoke(std::forward<Deleter>(deleter), ptr);
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_DELETER_POLICIES_HPP

