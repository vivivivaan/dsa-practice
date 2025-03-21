#include <iostream>
#include <set>

int main() {
  std::multiset<int> ms;

  for (int i = 1; i <= 7; i++) {
    // Allows duplicates.
    ms.insert(i * 100);
    ms.insert(i * 100);
  }

  std::cout << "Set elements: ";

  for (auto x = ms.begin(); x != ms.end(); x++) {
    std::cout << *(x) << " ";
  }

  std::cout << " | Size: " << ms.size() << std::endl;

  // lower_bound(): should not return less than the key.
  // Returns the key or the immediate value greater than the key available in
  // the set.
  std::cout << "Lower Bound: " << *(ms.lower_bound(279)) << std::endl;
  // Sends s.end() or garbage value.
  std::cout << "LB: " << *(ms.lower_bound(750)) << std::endl;

  // upper_bound(): should return greater than key.
  // Returns the key or the immediate value greater than the key available in
  // the set.
  std::cout << "Upper Bound: " << *(ms.upper_bound(350)) << std::endl;
  // Sends s.end() or garbage value.
  std::cout << "UB: " << *(ms.upper_bound(750)) << std::endl;

  // Other functions:
  // insert(), emplace()
  // count(), erase(),
  // find(), size(),
  // empty()
}