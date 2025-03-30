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
  Node *top;
  int height;

public:
  Stack() {}

  Stack(int value) {
    Node *node = new Node(value);
    top = node;
    height += 1;
  }

  void print() {
    Node *temp = top;
    while (temp != nullptr) {
      std::cout << temp->value << " ";
      temp = temp->next;
    }
  }
};

int main() {}