#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> stackVector;

public:
  vector<int> &getStackVector() { return stackVector; }

  void printStack() {
    // for (int i = stackVector.size() - 1; i >= 0; i--) {
    //   cout << stackVector[i] << endl;
    // }

    for (auto itr = stackVector.end() - 1; itr >= stackVector.begin(); itr--) {
      cout << *itr << endl;
    }
  }

  bool isEmpty() { return stackVector.size() == 0; }

  int peek() {
    if (isEmpty()) {
      return int();
    } else {
      return stackVector[stackVector.size() - 1];
    }
  }

  int size() { return stackVector.size(); }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This method adds a new element to the top         |
  //   |   of the stack (push).                              |
  //   | - Inserts 'value' to the end of 'stackVector'.      |
  //   | - Return type: void                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Use vector's push_back() method to add            |
  //   |   the value to the end of the vector.               |
  //   | - No return value is needed.                        |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  void push(int value) { stackVector.push_back(value); }
};

int main() {
  Stack *stk = new Stack();

  cout << "Is Empty? " << stk->isEmpty() << endl;
  cout << "Adding elements to the stack .." << endl;

  for (int i = 1; i <= 7; i++) {
    stk->push(i*20);
  }

  cout << "TOS: " << stk->peek() << endl;

  cout << "The elements are: " << std::endl;
  stk->printStack();

  cout << "Size: " << stk->size() << endl;
}
