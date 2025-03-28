#include <iostream>

class Node {
public:
  Node *previous;
  Node *next;
  int data;
  Node(int data) {
    this->data = data;
    previous = nullptr;
    next = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int len;

public:
  DoublyLinkedList() {}

  DoublyLinkedList(int data) {
    Node *node = new Node(data);
    head = node;
    tail = node;
    len += 1;
  }

  ~DoublyLinkedList() {
    Node *node1 = head;
    Node *node2 = tail;

    // Traverse from both ends and delete nodes until they meet or cross
    while (node1 != nullptr && node2 != nullptr && node1 != node2) {
      Node *temp1 = node1;
      Node *temp2 = node2;

      node1 = node1->next;     // Move node1 forward (head to tail)
      node2 = node2->previous; // Move node2 backward (tail to head)

      delete temp1; // Delete node from the head side
      delete temp2; // Delete node from the tail side
    }

    // If there's one node left in the middle (node1 == node2), delete it
    if (node1 == node2 && node1 != nullptr) {
      delete node1;
    }

    // Reset head and tail to nullptr after destruction
    head = nullptr;
    tail = nullptr;
  }

  int getLen() { return len; }

  bool isEmpty() { return len == 0; }

  int length() { return len; }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  void setHead(int data) {
    if (!isEmpty()) {
      head->data = data;
    } else {
      Node *node = new Node(data);
      head = node;
      tail = node;
      len++;
    }
  }

  void setTail(int data) {
    if (!isEmpty()) {
      tail->data = data;
    } else {
      Node *node = new Node(data);
      head = node;
      tail = node;
      len++;
    }
  }

  void print_linkedlist() {
    Node *node = head;
    if (node == nullptr) {
      std::cout << "Doubly Linked List is empty." << std::endl;
    }
    while (node != nullptr) {
      std::cout << node->data << " ";
      node = node->next;
    }
  }

  void append(int data) {
    Node *node = new Node(data);
    if (isEmpty()) {
      head = node;
      tail = node;
    } else {
      Node *node = new Node(data);
      tail->next = node;
      node->previous = tail;
      tail = node;
      len++;
    }
  }

  void prepend(int data) {
    Node *node = new Node(data);
    if (isEmpty()) {
      head = node;
      tail = node;
    } else {
      node->next = head;
      head->previous = node;
      head = node;
      len++;
    }
  }

  Node *pop_tail() {
    if (isEmpty()) {
      return nullptr;
    }

    Node *back = tail;

    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail = back->previous;
      tail->next = nullptr;
    }
    back->previous = nullptr;
    len--;
    return back;
  }

  Node *pop_head() {
    if (isEmpty()) {
      return nullptr;
    }

    Node *front = head;

    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = front->next;
      head->previous = nullptr;
    }
    front->next = nullptr;
    len--;
    return front;
  }

  Node *get(int index) {
    if (index < 0 || index >= len) {
      return nullptr;
    } else if (index == 0) {
      return head;
    } else if (index == len - 1) {
      return tail;
    } else {
      Node *temp;
      int mid = len / 2 + 1;

      if (len < mid) {
        temp = head;
        for (int i = 0; i < index; i++) {
          temp = temp->next;
        }
        return temp;
      } else {
        temp = tail;
        for (int i = len - 1; i > index; i--) {
          temp = temp->previous;
        }
        return temp;
      }
    }
  }
};

int main() {
  DoublyLinkedList *dll = new DoublyLinkedList(100);

  for (int i = 2; i <= 7; i++) {
    dll->prepend(i * 100);
  }

  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "Length of the Linkedlist is " << dll->length() << std::endl
            << std::endl;

  std::cout << "Appending 600 to the list and the new list is: ";
  dll->append(600);
  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Prepending 6000 to the list and the new list is: ";
  dll->prepend(6000);
  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Deleted the tail: " << dll->pop_tail()->data << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Deleted the head: " << dll->pop_head()->data << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "The n-th node data or index [i] is " << dll->get(6)->data
            << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;
}