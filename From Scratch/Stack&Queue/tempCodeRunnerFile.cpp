#include <iostream>

class Node {
public:
  int value;
  Node *next;
  Node(int value) {
    this->value = value;
    next = nullptr;
  }
};

class Stack {
private:
  int height;
  Node *top;

public:
  Stack() {
    top = nullptr;
    height = 0;
  }

  Stack(int value) {
    Node *node = new Node(value);
    top = node;
    height += 1;
  }

  ~Stack() {
    Node *temp = top;
    while (temp != nullptr) {
      Node *node = temp;
      delete node;
      temp = temp->next;
    }
    height = 0;
  }

  void print_stack() {
    Node *node = top;
    while (node != nullptr) {
      std::cout << node->value << " ";
      node = node->next;
    }
  }

  void push(int value) {
    Node *node = new Node(value);
    node->next = node;
    top = node;
    height++;
  }
};

int main() {
  Stack *stk = new Stack(100);

  std::cout << "\nAdding elements onto the stack.." << std::endl;

  // for (int i = 2; i <= 7; i++) {
  //   stk->push(i * 100);
  // }

  stk->push(200);
  stk->push(300);
  stk->push(400);
  stk->push(500);

  std::cout << "The elements are: " << std::endl;

  stk->print_stack();
}