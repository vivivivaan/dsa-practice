#include <iostream>
#include <vector>

int main() {

  std::vector<int> nums;

  // vector.push_back()
  for (int i = 1; i <= 7; i++) {
    nums.push_back(i * 10);
  }

  for (int i : nums) {
    std::cout << i << " ";
  }

  // vector.size() and vector.capacity()
  std::cout << " || Size: " << nums.size()
            << " || Capacity: " << nums.capacity() << "\n";

  // vector.pop_back()
  nums.pop_back();

  // vector.emplace_back()
  for (auto i = 1; i <= 5; i++) {
    nums.emplace_back(i * 100);
  }

  for (int i : nums) {
    std::cout << i << " ";
  }

  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  // .at() and [] - value retrieval.
  std::cout << "Value at index [2]: " << nums[2]
            << " || Value at index .at(4): " << nums.at(4) << std::endl;

  // vector.front() and vector.back()
  std::cout << "Front value: " << nums.front()
            << " || Back value: " << nums.back() << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  // vector initialization.
  // vector<int> vec {}
  std::vector<int> vec{10, 20, 30, 100, 500, 1000};
  std::cout << "Init using vector<int> vec: ";
  for (int i : vec) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  // vector<int> vec2 = {}
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6};
  std::cout << "Init using vector<int> vec2: ";
  for (int i : vec2) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  // vector<int> vec3()
  std::vector<int> vec3(7, 5);
  std::cout << "Init using vector<int> vec3(): ";
  for (int i : vec3) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  // vector<int> vec4(nums)
  std::vector<int> vec4(nums);
  std::cout << "Init using vector<int> vec4(nums): ";
  for (int i : vec4) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  // vector.erase() and vector.insert() - computationally expensive - O(n)
  std::cout << "After erasing or removing first element from vec: ";
  vec.erase(vec.begin()); // removes first element
  for (int i : vec) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  std::cout << "After erasing or removing 2nd and 3rd element from vec: ";
  vec.erase(vec.begin() + 1, vec.begin() + 3);
  for (int i : vec) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  return 0;
}
