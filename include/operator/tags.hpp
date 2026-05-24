#ifndef OPERATOR_TAGS_HPP
#define OPERATOR_TAGS_HPP

#define OPERATOR_CREATE_TAG(name)                                              \
  struct name                                                                  \
  {                                                                            \
  };

namespace Operator::tags
{
  // Insertions
  OPERATOR_CREATE_TAG(push_front);
  OPERATOR_CREATE_TAG(emplace_front);

  // Back Insertions
  OPERATOR_CREATE_TAG(push_back);
  OPERATOR_CREATE_TAG(emplace_back);

  // Invoke
  OPERATOR_CREATE_TAG(Invoke);
  OPERATOR_CREATE_TAG(FoldInvoke);

  // Misc
  OPERATOR_CREATE_TAG(DisplayContainer);
  OPERATOR_CREATE_TAG(NoOp)
} // namespace Operator::tags
#endif // OPERATOR_TAGS_HPP
