#include <operator/operator.hpp>

// STL
#include <iostream>
#include <list>

OPERATOR_CREATE_TAG(Test);
template <> struct Operator::policy::Policy<Test>
{
  template <typename... Args>
  static void
  invoke(Args&&... args)
  {
    (Operator::operation<Operator::tags::cout>(
         "operation<Test>(args...): ", std::forward<Args>(args), '\n'),
     ...);
  }
};

int
main(int argc, char* argv[])
{
  using namespace Operator;
  using namespace Operator::tags;

  operation<tags::cout>(
      "Can deref int*: ", std::boolalpha, type_traits::can_deref_v<int*>, '\n');

  std::list<int> test{};
  //std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  auto well{operation<emplace_front>(&test, 20, 16)};
  auto ref{operation<emplace_back>(&test, 17, 90)};

  operation<cout>("Container<int>::emplace_front(): ", well, '\n');
  operation<cout>("Container<int>::emplace_back(): ", ref, '\n');

  std::string test_string{};
  int test_int{};

  operation<cout>("Enter string: ");
  operation<cin>(&test_string);

  operation<cout>("Enter number: ");
  operation<cin>(&test_int);

  operation<cout>("Test string: ", test_string, '\n');
  operation<cout>("Test int: ", test_int, '\n');

  // Assert check
  //operation<push_back>(test);
  //operation<push_front>(&test);

  operation<push_back>(test, 999, 444);
  operation<push_front>(&test, 0, 4);

  operation<NoOp>(&test, 17, 43, 50, 23, 99);
  operation<Test>(17, 43, 50, 23, 99);

  operation<Invoke>(
      // NOTE: Policy:Invoke will not handle arg pack
      [](const auto... elem)
      {
        std::cout << "operation<Invoke>(args...): ";
        ((std::cout << elem << ' '), ...);
        std::cout << '\n';
      },
      90,
      200,
      40,
      50);

  operation<FoldInvoke>(
      // NOTE: Policy:FoldInvoke will handle arg pack
      [](const auto& elem)
      { std::cout << "operation<FoldInvoke>(args...): " << elem << '\n'; },
      90,
      200,
      40,
      50);

  operation<Invoke>(
      // NOTE: Policy:Invoke/FoldInvoke must have
      // template functions passed as forwarding lambdas
      [](auto&& container)
      {
        return util::display_container(
            std::forward<decltype(container)>(container),
            [](const auto& elem) { std::cout << elem << ' '; },
            "operation<Invoke>(util::display, container): ");
      },
      &test);

  operation<DisplayContainer>(
      test,
      [](const auto& elem) { std::cout << elem << ' '; },
      "operation<DisplayContainer>(container, printer): ");

  util::display_container(
      &test,
      [](const auto& elem) { std::cout << elem << ' '; },
      "util::display_container(container, printer): ");

  return 0;
}
