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

class Queue {
private:
  Node *first;
  Node *last;
  int len;

public:
  Queue() {
    first = nullptr;
    last = nullptr;
    len = 0;
  }

  Queue(int val) {
    Node *node = new Node(val);
    first = node;
    last = node;
    len++;
  }

  ~Queue() {
    while (first != nullptr) {
      Node *temp = first;
      first = first->next;
      delete temp;
    }
    first = nullptr;
    last = nullptr;
    len = 0;
  }

  int getLen() { return len; }

  Node *getFirst() { return first; }

  Node *getLast() { return last; }

  bool isEmpty() { return len == 0; }

  void print_q() {
    Node *temp = first;
    while (temp != nullptr) {
      std::cout << temp->value;
      temp = temp->next;
      if (temp)
        std::cout << "->";
    }
    std::cout << std::endl;
  }

  void enque(int value) {
    Node *node = new Node(value);
    if (len == 0) {
      first = node;
      last = node;
    } else {
      last->next = node;
      last = node;
    }
    len++;
  }

  Node *deque() {
    if (len == 0)
      return nullptr;

    Node *temp = first;

    if (len == 1) {
      first = nullptr;
      last = nullptr;
    } else {
      first = temp->next;
      temp->next = nullptr;
    }
    len--;
    return temp;
  }

  Node *get(int index) {
    if (index < 0 || index >= len) {
      return nullptr;
    }
    Node *current = first;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    return current;
  }
};

int main() {
  Queue *q = new Queue(100);

  std::cout << "\nEnqueuing elements into the queue.." << std::endl;

  for (int i = 2; i <= 7; i++) {
    q->enque(i * 100);
  }

  std::cout << std::endl;

  std::cout << "The elements are: " << std::endl;
  q->print_q();
  std::cout << "Queue first: " << q->getFirst()->value
            << " | Queue Last: " << q->getLast()->value
            << " | Length: " << q->getLen() << std::endl
            << std::endl;

  std::cout << "Popped the first: " << q->deque()->value
            << " | Length: " << q->getLen() << std::endl
            << std::endl;

  std::cout << "The elements are: " << std::endl;
  q->print_q();
  std::cout << "Queue first: " << q->getFirst()->value
            << " | Queue Last: " << q->getLast()->value
            << " | Length: " << q->getLen() << std::endl
            << std::endl;

  std::cout << "The 3rd element or element at index [2] is: "
            << q->get(2)->value << std::endl
            << std::endl;

  std::cout << "The elements with indices are: " << std::endl;
  for (int i = 0; i < q->getLen(); i++) {
    std::cout << "[" << i << "] => " << q->get(i)->value << std::endl;
  }
  std::cout << "Queue first: " << q->getFirst()->value
            << " | Queue Last: " << q->getLast()->value
            << " | Length: " << q->getLen() << std::endl
            << std::endl;
}