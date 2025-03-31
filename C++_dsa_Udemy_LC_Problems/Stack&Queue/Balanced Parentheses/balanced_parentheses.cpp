#include "BalancedParentheses.h"

using namespace std;

bool isBalancedParentheses(const string &parentheses) {
  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This function checks if the input string          |
  //   |   'parentheses' has balanced parentheses.           |
  //   | - Uses a stack to hold the open parentheses.        |
  //   | - Return type: bool                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Use a stack to hold open parentheses.             |
  //   | - Push '(' onto the stack.                          |
  //   | - When encountering ')', check if stack is empty    |
  //   |   or top of stack is not '('. If so, return false.  |
  //   | - Otherwise, pop from the stack.                    |
  //   | - At the end, if stack is empty, return true.       |
  //   | - Otherwise, return false.                          |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  stack<char> pr;

  for (char c : parentheses) {
  }
}
