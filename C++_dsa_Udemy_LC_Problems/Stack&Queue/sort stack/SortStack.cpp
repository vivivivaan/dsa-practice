#include "SortStack.h"
#include <algorithm>
#include <functional>
#include <vector>

void sortStack(stack<int> &inputStack) {
  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - This function sorts the input stack 'inputStack'.  |
  //   | - Uses an additional stack for sorting.              |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Create an additional stack.                        |
  //   | - Pop elements from 'inputStack' and push them       |
  //   |   into 'additionalStack' in sorted order.            |
  //   | - Use a temporary variable to hold the top element   |
  //   |   of 'inputStack'.                                   |
  //   | - Move elements back to 'additionalStack' if needed. |
  //   | - Finally, move all elements back to 'inputStack'.   |
  //   | - Check output from Test.cpp in "User logs".         |
  //   +======================================================+

  std::vector<int> nums;

  while (!inputStack.empty()) {
    nums.push_back(inputStack.top());
    inputStack.pop();
  }

  std::sort(nums.begin(), nums.end());

  for (auto itr = nums.begin(); itr != nums.end(); itr++) {
    inputStack.push(*itr);
  }
}
