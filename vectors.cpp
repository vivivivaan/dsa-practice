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

  std::cout << "Adding back the 1st value: ";
  vec.insert(vec.begin(), 10);
  for (int i : vec) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  std::cout << "Adding back the 3rd value: ";
  vec.insert(vec.begin() + 2, 30);
  for (int i : vec) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  std::cout << "Is vector empty? " << vec.empty() << std::endl;

  std::cout << "Clearing the vector .. ";
  vec.clear();
  for (int i : vec) {
    std::cout << i << " ";
  }
  std::cout << " || Size : " << nums.size()
            << " || Capacity: " << nums.capacity() << std::endl;

  std::cout << "Is vector empty? " << vec.empty() << std::endl;

  // Vector Iterators - vec.begin() and vec.end().
  // vec.beging() points directly to the memory loc and so, returns the memory.
  // vec.end() doesn't point to n-1 index, but the next value which can be a
  // random value or zero or garbage value based on the compiler.
  std::vector<int> temp{100, 200, 500, 400, 700, 800};
  std::cout << "Before insertion: ";
  for (int k : temp) {
    std::cout << k << " ";
  }
  std::cout << "\nAfter inserting at the 3rd position: ";
  vec.insert(temp.begin() + 2, 1000);
  for (int i : temp) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::cout << "Values with indices: " << "[0] = " << *(temp.begin());
  for (int i = 1; i < temp.size(); i++) {
    std::cout << ", [" << i << "] = " << *(temp.begin() + i);
  }
  std::cout << std::endl;

  std::cout << "Forward Iterator looping .." << std::endl;
  std::cout << "Loops from forward: " << std::endl;

  // Explicit iterator declaration (Optional, but demonstrates the concept)
  std::vector<int>::iterator itr;
  std::cout << "Explicit iterator: ";
  for (itr = temp.begin(); itr != temp.end(); itr++) {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;

  // In-loop iterator declaration
  std::cout << "In-loop iterator: ";
  for (auto i = temp.begin(); i != temp.end(); i++) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;

  std::cout << "Backward Iterator looping .. " << std::endl;
  std::cout << "Loops from backward: ";
  for (auto it = temp.rbegin(); it != temp.rend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
