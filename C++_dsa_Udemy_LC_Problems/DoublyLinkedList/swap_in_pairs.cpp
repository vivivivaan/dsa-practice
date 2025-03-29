#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  ~DoublyLinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList() {
    Node *temp = head;
    if (temp == nullptr) {
      cout << "empty" << endl;
      return;
    }
    while (temp->next != nullptr) {
      cout << temp->value << " <-> ";
      temp = temp->next;
    }
    cout << temp->value << endl;
  }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  int getLength() { return length; }

  void append(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - The swapPairs function swaps adjacent pairs       |
  //   |   of nodes in a doubly linked list.                 |
  //   | - Return type: void                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Utilizes a dummyNode to simplify edge cases.      |
  //   | - Uses pointers to navigate and swap nodes.         |
  //   | - Pay close attention to the 'next' and 'prev'      |
  //   |   pointers of the nodes.                            |
  //   | - Works in-place; doesn't create new nodes.         |
  //   | - Always checks if the list is empty or has only    |
  //   |   one node.                                         |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  void swapPairs() {
    Node dummyNode(0);
    dummyNode.next = head;
    Node *previousNode = &dummyNode;

    while (head != nullptr && head->next != nullptr) {
      Node *firstNode = head;
      Node *secondNode = head->next;

      previousNode->next = secondNode;
      firstNode->next = secondNode->next;
      secondNode->next = firstNode;

      secondNode->prev = previousNode;
      firstNode->prev = secondNode;
      if (firstNode->next != nullptr) {
        firstNode->next->prev = firstNode;
      }

      head = firstNode->next;
      previousNode = firstNode;
    }

    head = dummyNode.next;
    if (head)
      head->prev = nullptr;
  }
};
