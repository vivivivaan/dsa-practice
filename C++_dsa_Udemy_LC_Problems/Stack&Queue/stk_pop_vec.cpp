#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> stackVector;

public:
  vector<int> &getStackVector() { return stackVector; }

  //   void printStack() {
  //     for (int i = stackVector.size() - 1; i >= 0; i--) {
  //       cout << stackVector[i] << endl;
  //     }
  //   }

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

  void push(int value) { stackVector.push_back(value); }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This method removes the top element               |
  //   |   from the stack (pop).                             |
  //   | - Updates 'stackVector' by removing last element.   |
  //   | - Return type: void                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Use vector's pop_back() to remove the element     |
  //   |   from the end.                                     |
  //   | - Make sure to check if the stack is empty          |
  //   |   before trying to pop.                             |
  //   | - No return value is needed.                        |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  void pop() {
    if (!isEmpty()) {
      stackVector.pop_back();
    }
  }
};

int main() {
  Stack *stk = new Stack();

  cout << "Is Empty? " << stk->isEmpty() << endl;
  cout << "Adding elements to the stack .." << endl;

  for (int i = 1; i <= 7; i++) {
    stk->push(i * 20);
  }

  cout << endl;

  cout << "TOS: " << stk->peek() << endl << endl;

  cout << "The elements are: " << endl;

  stk->printStack();

  cout << endl;

  cout << "Size: " << stk->size() << endl;

  cout << endl;

  cout << "Popping the top or last element: " << endl << endl;

  stk->pop();

  cout << "Post pop size: " << stk->size() << endl << endl;

  cout << "TOS: " << stk->peek() << endl << endl;

  cout << "The elements are: " << std::endl;
  stk->printStack();
}