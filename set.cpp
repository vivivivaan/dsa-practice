// O(log_n)

#include <iostream>
#include <set>

int main() {
  std::set<int> s;

  for (int i = 1; i <= 7; i++) {
    s.insert(i * 100);
    s.insert(i * 100);
  }

  std::cout << "Set elements: ";

  for (auto x = s.begin(); x != s.end(); x++) {
    std::cout << *(x) << " ";
  }

  std::cout << " | Size: " << s.size() << std::endl;

  // lower_bound(): should not return less than the key.
  // Returns the key or the immediate value greater than the key available in
  // the set.
  std::cout << "Lower Bound: " << *(s.lower_bound(279)) << std::endl;
  // Sends s.end() or garbage value.
  std::cout << "LB: " << *(s.lower_bound(750)) << std::endl;

  // upper_bound(): should return greater than key.
  // Returns the key or the immediate value greater than the key available in
  // the set.
  std::cout << "Upper Bound: " << *(s.upper_bound(350)) << std::endl;
  // Sends s.end() or garbage value.
  std::cout << "UB: " << *(s.upper_bound(750)) << std::endl;

  // Other functions:
  // insert(), emplace()
  // count(), erase(),
  // find(), size(),
  // empty()
}