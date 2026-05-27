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

  // IOstream
  OPERATOR_CREATE_TAG(cin);
  OPERATOR_CREATE_TAG(wcin);

  OPERATOR_CREATE_TAG(cout);
  OPERATOR_CREATE_TAG(wcout);

  OPERATOR_CREATE_TAG(cerr);
  OPERATOR_CREATE_TAG(wcerr);

  OPERATOR_CREATE_TAG(clog);
  OPERATOR_CREATE_TAG(wclog);

  // Misc
  OPERATOR_CREATE_TAG(DisplayContainer);
  OPERATOR_CREATE_TAG(NoOp)
} // namespace Operator::tags
#endif // OPERATOR_TAGS_HPP
