#include "ReverseString.h"
#include <stack>

string reverseString(const string &str) {
  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This function reverses the input string 'str'.    |
  //   | - Uses a stack to hold the characters.              |
  //   | - Pops from stack and appends to 'reversedString'.  |
  //   | - Return type: string                               |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Use a stack to hold each character of the string. |
  //   | - Push each character of 'str' onto the stack.      |
  //   | - Pop from the stack and append to 'reversedString' |
  //   |   until the stack is empty.                         |
  //   | - Return the reversed string.                       |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  std::stack<char> charStack;
  string reversedStr;

  for (char c : str) {
    charStack.push(c);
  }

  while (!charStack.empty()) {
    reversedStr.push_back(charStack.top());
    charStack.pop();
  }
  return reversedStr;
}
