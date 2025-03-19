#include <iostream>
#include <queue>

// FIFO - add from rear/back/end and remove from front/start/begining.

int main() {

  std::queue<int> q;

  // push()
  for (int i = 1; i <= 7; i++) {
    q.push(i * 100);
  }

  // size()
  std::cout << "Queue size: " << q.size() << std::endl;

  std::cout << "Queue elements: ";
  // empty(), pop()
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;

  // Remaining all methods are same as in stack.
  // emplace(), swap(), back() is to display last element.
}