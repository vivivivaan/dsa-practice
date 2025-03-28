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

  bool isEmpty() { return len == 0 ? true : false; }

  int length() { return len; }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  void setHead(int data) { head->data = data; }

  void setTail(int data) { tail->data = data; }

  Node *getNext(Node *node) {
    if (node->next != nullptr) {
      return node->next;
    }
    return nullptr;
  }

  Node *getPrevious(Node *node) {
    if (node->previous != nullptr) {
      return node->previous;
    }
    return nullptr;
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
    std::cout << std::endl;
  }
};

int main() {
  
}