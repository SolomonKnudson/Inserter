#include <operator/operator.hpp>

// STL
#include <iostream>
#include <list>

OPERATOR_CREATE_TAG(Test);
template <> struct Operator::policies::Operator<Test>
{
  template <typename... Args>
  static void
  operation(Args&&...)
  {
    std::cout << "'3rd party' Operator<Tag>::operation() test\n";
  }
};

// Just for testing custom deleter operation
template <typename T>
static void
delete_set_nullptr(T*& ptr)
{
  delete ptr;
  ptr = nullptr;
}

int
main(int argc, char* argv[])
{
  using namespace Operator;
  using namespace Operator::tags;
  using namespace Operator::policies;

  std::cout << "Can deref int*: " << std::boolalpha
            << type_traits::can_deref_v<int*> << '\n';

  std::list<int> test{};
  // std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  auto delete_single_test{new int{100}};
  auto delete_array_test{new int[10]{}};

  auto well{operation<emplace_front>(&test, 20, 54, 50)};
  auto ref{operation<emplace_back>(&test, 17)};

  std::cout << "Container<int>::emplace_front(): " << well << '\n';
  std::cout << "Container<int>::emplace_back(): " << ref << '\n';

  operation<push_back>(&test, 90);
  // operation<DeleteScalar>(delete_single_test, true);
  operation<DeleteArray>(delete_array_test, true);

  operation<CustomDeleter>(
      delete_set_nullptr<
          type_traits::remove_pointer<decltype(delete_single_test)>>,
      delete_single_test);

  if (!delete_single_test)
  {
    std::cout << "delete_single_test deleted and set to nullptr\n";
  }

  if (!delete_array_test)
  {
    std::cout << "delete_array_test deleted and set to nullptr\n";
  }

  operation<NoOp>(&test, 17, 43, 50, 23, 99);
  operation<Test>(&test, 17, 43, 50, 23, 99);

  operation(
      // NOTE: must handle arg packs. operation() will not call func per arg
      [](const auto... elem)
      {
        std::cout << "operation<Function, Args>() test\n";
        ((std::cout << elem << ' '), ...);
        std::cout << '\n';
      },
      90,
      200,
      40,
      50);

  operation(
      // NOTE: must pass template functions as forwarding lambdas
      [](auto&& container)
      {
        return util::display(std::forward<decltype(container)>(container),
                             [](const auto& elem)
                             { std::cout << elem << ' '; });
      },
      test);

  // operation<DisplayContainer>(
  //     &test, [](const auto& elem) { std::cout << elem << ' '; });
  // util::display(&test, [](const auto& elem) { std::cout << elem << ' '; });
  return 0;
}

