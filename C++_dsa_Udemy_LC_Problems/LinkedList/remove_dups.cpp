#include <iostream>
#include <unordered_set>

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

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Remove duplicate nodes from the list               |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Use two pointers: 'current' and 'runner'           |
  //   | - 'current' scans each node                          |
  //   | - 'runner' checks for duplicates ahead               |
  //   | - If duplicate found, delete it                      |
  //   | - Update 'next' pointers and reduce length           |
  //   | - No return value, list updated in-place             |
  //   +======================================================+

  void removeDuplicates() {
    // Get the head of the linkedlist.
    Node *current = head;
    // check if the current node or head is not a nullptr or doesn't point
    // to one.
    while (current != nullptr) {
      // Set a runner node pointing to next of the current node.
      Node *runner = current->next;

      // check if the runner node isn't a nullptr or doesn't point to one.
      while (runner->next != nullptr) {
        // check if the runner node value one ahead of the current value is
        // same as the current node value.
        if (runner->next->value == current->value) {
          // create a temporary node.
          Node *temp = runner->next;
          runner->next = runner->next->next;
          delete temp;
          length -= 1;
        } else {
          runner = runner->next;
        }
        current = current->next;
      }
    }
  }

  // void removeDuplicates() {
  //   unordered_set<int> values;

  //   Node *previous = nullptr;
  //   Node *current = head;

  //   while (current != nullptr) {
  //     if (values.find(current->value) != values.end()) {
  //       previous->next = current->next;
  //       delete current;
  //       current = previous->next;
  //       length -= 1;
  //     } else {
  //       values.insert(current->value);
  //       previous = current;
  //       current = current->next;
  //     }
  //   }
  // }
};
