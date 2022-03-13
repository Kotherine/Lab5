#include <task1.hpp>
#include <task2.hpp>

int main() {
  Stack1<int> stack1;
  stack1.push(0);
  stack1.push(15);
  std::cout << stack1.head() << "\n";
  stack1.pop();
  std::cout << stack1.head() << "\n";
}