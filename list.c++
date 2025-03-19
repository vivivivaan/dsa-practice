#include <iostream>
#include <list>

// List is a sequential container like Vector.
// List is internally implemented as Doubly Linked List.
// Random access is not possible.
// Push, Pop and Emplace is possible from both front & back.

int main() {

  std::list<int> list;

  for (int i = 1; i <= 6; i++) {
    list.push_back(i * 5);
    list.push_front(i * 10);
  }

  std::cout << "List with push front and back: ";

  for (auto itr = list.begin(); itr != list.end(); itr++) {
    std::cout << *(itr) << " ";
  }
  std::cout << " | Size : " << list.size() << " | Front value: " << list.front()
            << " | Back value: " << list.back() << std::endl;

  // Popping the last element.
  list.pop_back();
  std::cout << "Popped the last element: ";
  for (int i : list) {
    std::cout << i << " ";
  }
  std::cout << " | Size : " << list.size() << " | Front value: " << list.front()
            << " | Back value: " << list.back() << std::endl;

  // Popping the first element.
  list.pop_front();
  std::cout << "Popped the first element: ";
  for (int i : list) {
    std::cout << i << " ";
  }
  std::cout << " | Size : " << list.size() << " | Front value: " << list.front()
            << " | Back value: " << list.back() << std::endl;

  // Majority of the remaining functions are all same as std::vector.
  // Examples: .size(), erase(), clear(), begin(), end(), rbegin(), rend(),
  // insert, front(), back()
  return 0;
}