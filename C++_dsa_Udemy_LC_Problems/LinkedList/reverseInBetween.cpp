#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
  int length;

public:
  LinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    length = 1;
  }

  ~LinkedList() {
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
      cout << "empty";
    } else {
      while (temp != nullptr) {
        cout << temp->value;
        temp = temp->next;
        if (temp != nullptr) {
          cout << " -> ";
        }
      }
    }
    cout << endl;
  }

  Node *getHead() { return head; }

  int getLength() { return length; }

  void makeEmpty() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
    length = 0;
  }

  void append(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *currentNode = head;
      while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
    }
    length++;
  }

  void deleteFirst() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
    } else {
      head = head->next;
    }
    delete temp;
    length--;
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Reverse nodes between positions m and n            |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Create a dummy node and set its next to head       |
  //   | - Use 'prev' pointer to go to m-th node              |
  //   | - Use 'current' pointer for m+1 to n nodes           |
  //   | - Loop to reverse m+1 to n nodes                     |
  //   | - Update original list's head                        |
  //   | - Free dummy node memory                             |
  //   +======================================================+

  void reverseBetween(int m, int n) {
    if (head == nullptr) {
      return;
    }

    Node *dummy(0);
    dummy->next = head;
    Node *prev = dummy;

    for (int i = 0; i < m; i++) {
      prev = prev->next;
    }

    Node *current = prev->next;

    for (int i = 0; i < n - m; i++) {
      Node *temp = current->next;
      current->next = temp->next;
      temp->next = prev->next;
      prev->next = temp;
    }

    head = dummy->next;
    delete dummy;
  }
};
