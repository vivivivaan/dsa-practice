#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> uos;

  for (int i = 1; i <= 7; i++) {
    // Only unsorted unique elements.
    uos.insert(i * 100);
    uos.insert(i * 100);
  }

  std::cout << "Set elements: ";

  for (auto x = uos.begin(); x != uos.end(); x++) {
    std::cout << *(x) << " ";
  }

  std::cout << " | Size: " << uos.size() << std::endl;

  // lower_bound() and upper_bound() don't work for unordered_set as it it
  // unsorted.

  //   // lower_bound(): should not return less than the key.
  //   // Returns the key or the immediate value greater than the key available
  //   in
  //   // the set.
  //   std::cout << "Lower Bound: " << *(uos.lower_bound(279)) << std::endl;
  //   // Sends s.end() or garbage value.
  //   std::cout << "LB: " << *(uos.lower_bound(750)) << std::endl;

  //   // upper_bound(): should return greater than key.
  //   // Returns the key or the immediate value greater than the key available
  //   in
  //   // the set.
  //   std::cout << "Upper Bound: " << *(uos.upper_bound(350)) << std::endl;
  //   // Sends s.end() or garbage value.
  //   std::cout << "UB: " << *(uos.upper_bound(750)) << std::endl;

  // Other functions:
  // insert(), emplace()
  // count(), erase(),
  // find(), size(),
  // empty()
}