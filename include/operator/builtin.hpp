#ifndef OPERATOR_BUILTIN_TAGS_HPP
#define OPERATOR_BUILTIN_TAGS_HPP

#define OPERATOR_CREATE_IMPL_TAG(name)                                         \
  struct name                                                                  \
  {                                                                            \
  };

namespace Operator::builtin
{
  // Insertions
  OPERATOR_CREATE_IMPL_TAG(push_front);
  OPERATOR_CREATE_IMPL_TAG(emplace_front);

  // Back Insertions
  OPERATOR_CREATE_IMPL_TAG(push_back);
  OPERATOR_CREATE_IMPL_TAG(emplace_back);

  // Invoke
  OPERATOR_CREATE_IMPL_TAG(Invoke);
  OPERATOR_CREATE_IMPL_TAG(FoldInvoke);

  // IOstream
  OPERATOR_CREATE_IMPL_TAG(cin);
  OPERATOR_CREATE_IMPL_TAG(wcin);

  OPERATOR_CREATE_IMPL_TAG(cout);
  OPERATOR_CREATE_IMPL_TAG(wcout);

  OPERATOR_CREATE_IMPL_TAG(cerr);
  OPERATOR_CREATE_IMPL_TAG(wcerr);

  OPERATOR_CREATE_IMPL_TAG(clog);
  OPERATOR_CREATE_IMPL_TAG(wclog);

  // Misc
  OPERATOR_CREATE_IMPL_TAG(DisplayContainer);
  OPERATOR_CREATE_IMPL_TAG(NoOp);
} // namespace Operator::builtin
#endif // OPERATOR_BUILTIN_TAGS_HPP
