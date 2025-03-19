#include <deque>
#include <iostream>

// Deque is sequential container.
// Quite similar to std::list, Push, Pop and Emplace is possible from both front
// & back. Implemented as dynamic arrays which makes the random access possible
// in deque which is not possible in std::list.

int main() {

  std::deque<int> deq;

  std::cout << "Deque with push front and back: ";
  for (int i = 1; i <= 6; i++) {
    deq.push_back(i * 5);
    deq.push_front(i * 10);
  }

  for (auto itr = deq.begin(); itr != deq.end(); itr++) {
    std::cout << *(itr) << " ";
  }
  std::cout << " | Size : " << deq.size() << " | Front value: " << deq.front()
            << " | Back value: " << deq.back() << std::endl;

  // Popping the last element.
  deq.pop_back();
  std::cout << "Popped the last element: ";
  for (int i : deq) {
    std::cout << i << " ";
  }
  std::cout << " | Size : " << deq.size() << " | Front value: " << deq.front()
            << " | Back value: " << deq.back() << std::endl;

  // Popping the first element.
  deq.pop_front();
  std::cout << "Popped the first element: ";
  for (int i : deq) {
    std::cout << i << " ";
  }
  std::cout << " | Size : " << deq.size() << " | Front value: " << deq.front()
            << " | Back value: " << deq.back() << std::endl;

  std::cout << "Randomly accessing even elements in a Deque: ";
  for (int i = 0; i < deq.size(); i++) {
    if (i % 2 == 0) {
      std::cout << deq[i] << " ";
    }
  }
  std::cout << " | Size : " << deq.size() << " | Front value: " << deq.front()
            << " | Back value: " << deq.back() << std::endl;

  // Majority of the remaining functions are all same as std::list.
  // Examples: .size(), erase(), clear(), begin(), end(), rbegin(), rend(),
  // insert, front(), back()
  return 0;
}