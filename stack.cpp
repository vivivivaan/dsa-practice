#include <iostream>
#include <stack>

// LIFO

int main() {

  std::stack<int> stack;

  // push()
  for (int i = 1; i <= 7; i++) {
    stack.push(i * 5);
  }

  std::cout << "Stack size: " << stack.size() << std::endl;
  std::cout << "Stack using push: ";

  // empty(), top(), pop()
  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }

  // size()
  std::cout << "\nStack size now: " << stack.size() << std::endl;

  // emplace()
  for (int j = 1; j <= 8; j++) {
    stack.emplace(j * 10);
  }

  std::cout << "Stack size: " << stack.size() << std::endl;
  std::cout << "Stack using emplace: ";

  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }

  std::cout << "\nStack size now: " << stack.size() << std::endl;

  // Swapping stacks.
  std::stack<int> s1, s2;

  for (int i = 1; i <= 5; i++) {
    s2.push(i * 15);
  }

  std::cout << "Before swapping: s2 size: " << s2.size()
            << " , s1 size: " << s1.size() << std::endl;

  s1.swap(s2);

  std::cout << "After swapping s1 and s2: " << "s2 size: " << s2.size()
            << " , s1 size: " << s1.size() << std::endl;
  std::cout << "Elements after swapping: ";

  while (!s1.empty()) {
    std::cout << s1.top() << " ";
    s1.pop();
  }

  std::cout << "\ns1 size now: " << s1.size() << " , s2 size now: " << s2.size()
            << std::endl;
}