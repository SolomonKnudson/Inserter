#include <operator/operator.hpp>

// STL
#include <iostream>
#include <list>

OPERATOR_CREATE_TAG(Test);
template <> struct Operator::policy::Policy<Test>
{
  template <typename... Args>
  static void
  invoke(Args&&...)
  {
    std::cout << "'3rd party' Operator<Tag>::operation() test\n";
  }
};

int
main(int argc, char* argv[])
{
  using namespace Operator;
  using namespace Operator::tags;

  std::cout << "Can deref int*: " << std::boolalpha
            << type_traits::can_deref_v<int*> << '\n';

  std::list<int> test{};
  // std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  auto well{operation<emplace_front>(&test, 20, 54, 50)};
  auto ref{operation<emplace_back>(&test, 17)};

  std::cout << "Container<int>::emplace_front(): " << well << '\n';
  std::cout << "Container<int>::emplace_back(): " << ref << '\n';

  operation<push_back>(&test, 90);

  operation<NoOp>(&test, 17, 43, 50, 23, 99);
  operation<Test>(&test, 17, 43, 50, 23, 99);

  operation<Invoke>(
      // NOTE: Policy:Invoke will not handle arg pack
      [](const auto... elem)
      {
        std::cout << "operation<Invoke>(): ";
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
      { std::cout << "operation<FoldInvoke>(): " << elem << '\n'; },
      90,
      200,
      40,
      50);

  operation<Invoke>(
      // NOTE: Policy:Invoke/FoldInvoke must have
      // template functions passed as forwarding lambdas
      [](auto&& container)
      {
        return util::display(
            std::forward<decltype(container)>(container),
            [](const auto& elem) { std::cout << elem << ' '; },
            "operation<Invoke>(util::display, container): ");
      },
      &test);
  operation<DisplayContainer>(
      test,
      [](const auto& elem) { std::cout << elem << ' '; },
      "operation<DisplayContainer>(container, printer): ");
  // util::display(&test, [](const auto& elem) { std::cout << elem << ' '; });
  return 0;
}

