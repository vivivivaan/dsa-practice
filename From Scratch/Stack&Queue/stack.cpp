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
      temp = temp->next;
      delete node;
    }
    height = 0;
  }

  int getHeight() { return height; }

  Node *getTop() { return top; }

  bool isEmpty() { return height == 0; }

  void print_stack() {
    Node *temp = top;
    while (temp != nullptr) {
      std::cout << temp->value;
      temp = temp->next;
      if (temp != nullptr) {
        std::cout << " -> ";
      } else {
        std::cout << " -> nullptr" << std::endl;
      }
    }
  }

  void push(int value) {
    Node *node = new Node(value);
    node->next = top;
    top = node;
    height++;
  }

  Node *pop() {
    Node *node = top;
    if (height == 0)
      return node;

    top = node->next;
    node->next = nullptr;
    height--;
    return node;
  }
};

int main() {
  Stack *stk = new Stack(100);

  std::cout << "\nPushing elements onto the stack.." << std::endl;

  for (int i = 2; i <= 7; i++) {
    stk->push(i * 100);
  }

  std::cout << "\nThe elements are: " << std::endl;
  stk->print_stack();
  std::cout << "Stack Top: " << stk->getTop()->value
            << " | Stack Height: " << stk->getHeight() << std::endl
            << std::endl;

  std::cout << "Popped the top: " << stk->pop()->value
            << " | Height: " << stk->getHeight() << std::endl
            << std::endl;

  std::cout << "The elements are: " << std::endl;
  stk->print_stack();
  std::cout << "Stack Top: " << stk->getTop()->value
            << " | Stack Height: " << stk->getHeight() << std::endl
            << std::endl;
}