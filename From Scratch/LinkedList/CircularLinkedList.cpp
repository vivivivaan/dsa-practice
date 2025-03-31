#include <iostream>

class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    next = this;
  }
};

class CircularLinkedList {
private:
  Node *head;
  Node *tail;
  int len;

public:
  CircularLinkedList() {
    head = nullptr;
    tail = nullptr;
    len = 0;
  }

  CircularLinkedList(int data) {
    Node *node = new Node(data);
    head = node;
    tail = node;
    len += 1;
  }

  ~CircularLinkedList() {
    if (head == nullptr)
      return;

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
    if (len == 0) {
      std::cout << "CLL is empty.. " << std::endl;
      return;
    }
    Node *itr = head;
    while (itr != nullptr) {
      std::cout << itr->data << " ";
      itr = itr->next;
      if (itr == head) {
        std::cout << itr->data << std::endl;
        break;
      }
    }
  }

  void append(int data) {
    Node *node = new Node(data);
    if (len == 0) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      node->next = head;
      tail = node;
    }
    len++;
  }

  void prepend(int data) {
    Node *node = new Node(data);
    if (len == 0) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      node->next = head;
      head = node;
    }
    len++;
  }

  Node *pop_tail() {
    if (len == 0) {
      return nullptr;
    }

    Node *end = tail;

    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      Node *temp = head;

      //   for (int i = 0; i < len - 2; i++) {
      //     temp = temp->next;
      //   }

      while (temp->next != end) {
        temp = temp->next;
      }

      if (temp->next == end) {
        temp->next = head;
        tail = temp;
        end->next = nullptr;
      }
    }

    len--;
    return end;
  }

  Node *pop_head() {
    if (len == 0) {
      return nullptr;
    }

    Node *begin = head;

    if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = begin->next;
      tail->next = head;
      begin->next = nullptr;
    }
    len--;
    return begin;
  }

  // Many other functions such as:
  // get, set, insert, delete, merge, reverse, and more
  // are almost same as other linked lists.
};

int main() {
  CircularLinkedList *cll = new CircularLinkedList(100);

  for (int i = 2; i <= 7; i++) {
    cll->append(i * 100);
  }

  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  cll->print_linkedlist();
  std::cout << "Length of the Linkedlist is " << cll->length()
            << " | Head: " << cll->getHead()->data
            << " | Tail: " << cll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Appending 800 to the list and the new list is..";
  cll->append(800);
  std::cout << std::endl;
  cll->print_linkedlist();
  std::cout << "Length of the Linkedlist is " << cll->length()
            << " | Head: " << cll->getHead()->data
            << " | Tail: " << cll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Prepending 6000 to the list and the new list is..";
  cll->prepend(6000);
  std::cout << std::endl;
  cll->print_linkedlist();
  std::cout << "Length of the Linkedlist is " << cll->length()
            << " | Head: " << cll->getHead()->data
            << " | Tail: " << cll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Deleted the tail: " << cll->pop_tail()->data << std::endl;
  std::cout << "The linkedlist is: ";
  cll->print_linkedlist();
  std::cout << "New length of the linkedlist is " << cll->length()
            << " and new tail is " << cll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Deleted the head: " << cll->pop_head()->data << std::endl;
  std::cout << "The linkedlist is: ";
  cll->print_linkedlist();
  std::cout << "New length of the linkedlist is " << cll->length()
            << " and new head is " << cll->getHead()->data << std::endl
            << std::endl;
}