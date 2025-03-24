#include <iostream>

class Node {
public:
  Node *next;
  int data;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int data;
  int len = 0;

public:
  LinkedList(int data) {
    Node *node = new Node(data);
    head = node;
    tail = node;
    len += 1;
  }

  ~LinkedList() {
    Node *node = head;
    while (node != nullptr) {
      Node *temp = node;
      node = node->next;
      delete temp;
    }
    head = nullptr;
    tail = nullptr;
    node = nullptr;
  }

  bool isEmpty() { return len == 0 ? true : false; }

  int length() { return len; }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  void print_linkedlist() {
    Node *node = head;
    if (node == nullptr) {
      std::cout << "LinkedList is empty." << std::endl;
    }
    while (node != nullptr) {
      std::cout << node->data << " ";
      node = node->next;
    }
  }

  void append(int data) {
    Node *node = new Node(data);
    if (len >= 1) {
      tail->next = node;
      tail = node;
    } else {
      head = node;
      tail = node;
    }
    len++;
  }

  void prepend(int data) {
    Node *node = new Node(data);
    if (len >= 1) {
      node->next = head;
      head = node;
    } else {
      head = node;
      tail = node;
    }
    len++;
  }

  Node *pop_tail() {
    if (len == 1) {
      Node *temp = tail;
      head = nullptr;
      tail = nullptr;
      len--;
      return temp;
    } else if (len > 1) {
      Node *temp = head;
      Node *end = tail;
      while (temp->next != tail) {
        temp = temp->next;
      }
      tail = temp;
      temp->next = nullptr;
      len--;
      return end;

    } else {
      return nullptr;
    }
  }

  Node *pop_head() {
    if (len == 1) {
      Node *temp = head;
      head = nullptr;
      tail = nullptr;
      len--;
      return temp;
    } else if (len > 1) {
      Node *temp = head;
      head = head->next;
      temp->next = nullptr;
      len--;
      return temp;
    } else {
      return nullptr;
    }
  }

  // Retrieval at index is possible which starts from 0 to len - 1.
  // But, retrieval at length valued index is not possible as that
  // node and consequently, index doesn't exist yet.
  Node *get(int index) {
    if (index < 0 || index >= len) {
      return nullptr;
    } else if (index == 0) {
      return getHead();
    } else if (index == len - 1) {
      return getTail();
    } else {
      Node *temp = head;
      for (int i = 1; i < index; i++) {
        temp = temp->next;
      }
      return temp;
    }
  }

  bool set(int index, int data) {
    Node *node = get(index);
    if (node != nullptr) {
      node->data = data;
      return true;
    }
    return false;
  }

  // Insertion at the length valued index essentially means appending.
  // So, the index can be length value but never below or beyond length.
  bool insert(int index, int data) {
    if (index < 0 || index > len) {
      return false;
    } else if (index == 0) {
      prepend(data);
      return true;
    } else if (index == len) {
      append(data);
      return true;
    } else {
      Node *node = new Node(data);
      Node *temp = get(index - 1);
      node->next = temp->next;
      temp->next = node;
      len++;
      return true;
    }
  }

  // Deletion at 0th index or 1st node is pop_head() or pop_tail() if index is
  // len - 1. But index can't be equal to length as that node doesn't exist yet.
  
  bool del(int index) {
    if (index < 0 || index >= len) {
      return false;
    }
    else if (index == 0) {
      pop_head();
      return true;
    }
    else if (index == len-1) {
      pop_tail();
      return false;
    } else {
      Node* 
    }
  }
};

int main() {
  LinkedList *ll = new LinkedList(100);

  for (int i = 2; i <= 5; i++) {
    ll->append(i * 100);
  }

  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "Length of the Linkedlist is " << ll->length() << std::endl
            << std::endl;

  std::cout << "Appending 600 to the list and the new list is: ";
  ll->append(600);
  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << ll->length() << std::endl
            << std::endl;

  std::cout << "Prepending 6000 to the list and the new list is: ";
  ll->prepend(6000);
  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << ll->length() << std::endl
            << std::endl;

  std::cout << "Deleted the tail: " << ll->pop_tail()->data << std::endl;
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << ll->length()
            << " and new tail is " << ll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Deleted the head: " << ll->pop_head()->data << std::endl;
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << ll->length()
            << " and new head is " << ll->getHead()->data << std::endl
            << std::endl;

  std::cout << "The 3rd node data or index [2] is " << ll->get(3)->data
            << std::endl;
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl << std::endl;

  std::cout << "Updating 3rd node data or index [2] data.." << std::endl;
  ll->set(3, 350);
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl << std::endl;

  std::cout << "Adding 750 to 4th node or index [3].. " << std::endl;
  ll->insert(4, 750);
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl << std::endl;

  delete ll;
}