#include <iostream>

class Node {
public:
  int data;
  Node *next;
  Node *prev;
  Node() {}
  Node(int data) {
    this->data = data;
    prev = this;
    next = this;
  }
};

class DoublyCircularLinkedList {
private:
  Node *head;
  Node *tail;
  int len;

public:
  DoublyCircularLinkedList() {}

  DoublyCircularLinkedList(int data) {
    Node *node = new Node(data);
    head = node;
    tail = node;
    len += 1;
  }

  ~DoublyCircularLinkedList() {
    if (head == nullptr)
      return;

    Node *current = head;
    while (current) {
      Node *next = current->next;
      delete current;
      current = next;
      if (current == head)
        break;
    }

    head = nullptr;
    tail = nullptr;
    len = 0;
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
    if (len == 0) {
      std::cout << "DCLL is empty.. " << std::endl;
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

  void prepend(int data) {
    Node *node = new Node(data);
    if (len == 0) {
      head = node;
      tail = node;
    } else {
      head->prev = node;
      node->next = head;
      head = node;
      node->prev = tail;
      tail->next = node;
    }
    len++;
  }

  void append(int data) {
    Node *node = new Node(data);
    if (len == 0) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      node->prev = tail;
      tail = node;
      node->next = head;
      head->prev = node;
    }
    len++;
  }

  Node *pop_head() {
    Node *start = head;
    if (len == 0) {
      return nullptr;
    } else if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = start->next;
      tail->next = head;
      head->prev = tail;
      start->prev = nullptr;
      start->next = nullptr;
    }
    len--;
    return start;
  }

  Node *pop_tail() {
    Node *end = tail;
    if (len == 0) {
      return nullptr;
    } else if (len == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail = end->prev;
      tail->next = head;
      head->prev = tail;
      end->prev = nullptr;
      end->next = nullptr;
    }
    len--;
    return end;
  }

  void merge(DoublyCircularLinkedList *dcl1, DoublyCircularLinkedList *dcl2) {
    if (this == dcl1 || this == dcl2) {
      throw std::runtime_error("Cannot merge a list with itself.");
    }

    if (dcl1->isEmpty()) {
      this->head = dcl2->head;
      this->tail = dcl2->tail;
      this->len = dcl2->len;
    } else if (dcl2->isEmpty()) {
      this->head = dcl1->head;
      this->tail = dcl1->tail;
      this->len = dcl1->len;
    } else {
      this->head = dcl1->head;
      this->tail = dcl2->tail;
      this->len = dcl1->len + dcl2->len;

      // dcl1
      dcl1->head->prev = dcl2->tail;
      dcl1->tail->next = dcl2->head;

      // dcl2
      dcl2->head->prev = dcl1->tail;
      dcl2->tail->next = dcl1->head;
    }
    dcl1->head = dcl1->tail = nullptr;
    dcl1->len = 0;
    dcl2->head = dcl2->tail = nullptr;
    dcl2->len = 0;
  }
};

int main() {
  DoublyCircularLinkedList *dcll = new DoublyCircularLinkedList(100);

  for (int i = 2; i <= 7; i++) {
    dcll->append(i * 100);
  }

  std::cout << std::endl;
  std::cout << "The linkedlist is: ";
  dcll->print_linkedlist();
  std::cout << "Length of the Linkedlist is " << dcll->length()
            << " | Head: " << dcll->getHead()->data
            << " | Tail: " << dcll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Appending 800 to the list and the new list is..";
  dcll->append(800);
  std::cout << std::endl;
  dcll->print_linkedlist();
  std::cout << "Length of the Linkedlist is " << dcll->length()
            << " | Head: " << dcll->getHead()->data
            << " | Tail: " << dcll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Prepending 6000 to the list and the new list is..";
  dcll->prepend(6000);
  std::cout << std::endl;
  dcll->print_linkedlist();
  std::cout << "Length of the Linkedlist is " << dcll->length()
            << " | Head: " << dcll->getHead()->data
            << " | Tail: " << dcll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Popped the previous head: " << dcll->pop_head()->data
            << std::endl;
  std::cout << "The linkedlist is: ";
  dcll->print_linkedlist();
  std::cout << "New length of the linkedlist is " << dcll->length()
            << " | Head: " << dcll->getHead()->data
            << " | Tail: " << dcll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Popped the previous tail: " << dcll->pop_tail()->data
            << std::endl;
  std::cout << "The linkedlist is: ";
  dcll->print_linkedlist();
  std::cout << "New length of the linkedlist is " << dcll->length()
            << " | Head: " << dcll->getHead()->data
            << " | Tail: " << dcll->getTail()->data << std::endl
            << std::endl;

  DoublyCircularLinkedList *dcll2 = new DoublyCircularLinkedList(1000);

  for (int i = 2; i <= 7; i++)
    dcll2->append(i * 1000);

  DoublyCircularLinkedList merged;

  std::cout << "Merging two doubly circular linked lists.." << std::endl;
  merged.merge(dcll, dcll2);
  std::cout << "The doubly circular linked list is: ";
  merged.print_linkedlist();
  std::cout << " | Head: " << merged.getHead()->data
            << " | Tail: " << merged.getTail()->data
            << " | Length: " << merged.length() << std::endl;
  // std::cout << "The indexed elements post merger are: " << std::endl;
  // for (int i = 0; i < merged.length(); i++)
  //   std::cout << "[" << i << "] => " << merged.get(i)->data << std::endl;
  // std::cout << "7th element OR 7th node OR element at index [6] is: "
  //           << merged.get(6)->data << std::endl;

  delete dcll;
  delete dcll2;
}