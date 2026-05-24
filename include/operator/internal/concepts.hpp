#ifndef OPERATOR_CONCEPTS_HPP
#define OPERATOR_CONCEPTS_HPP
#if defined(__cpp_concepts)
#include <operator/macros.hpp>
#include <operator/util.hpp>

namespace Operator::concepts
{
  /*  HasMethod Concepts
       *  template <typename Type, typename... Args>
       *  concept HasPushFront = requires(Type type, Args... args)
       *  {
       *    util::deref(type).push_front(args...);
       *  };
       *  CREATE_HAS__METHOD_CONCEPT example output
       */

  //Front insertions
  OPERATOR_CREATE_HAS_METHOD_CONCEPT(PushFront, push_front);
  OPERATOR_CREATE_HAS_METHOD_CONCEPT(EmplaceFront, emplace_front);

  //Back insertions
  OPERATOR_CREATE_HAS_METHOD_CONCEPT(PushBack, push_back);
  OPERATOR_CREATE_HAS_METHOD_CONCEPT(EmplaceBack, emplace_back);
} // namespace Operator::concepts
#endif // __cpp_concepts
#endif // OPERATOR_CONCEPTS_HPP
