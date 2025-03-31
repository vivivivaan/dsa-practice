#include <iostream>
#include <stdexcept>

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
  int len;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    len = 0;
  }

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

  // Retrieves the node at 'index'. Valid indices: 0 (head) to len-1 (tail).
  // Returns nullptr if index is invalid (negative or >= len).
  Node *get(int index) {
    if (index < 0 || index >= len)
      return nullptr; // Out of bounds
    else if (index == 0)
      return head; // head access
    else if (index == len - 1)
      return tail; // tail access
    else {         // Traverse middle nodes
      Node *temp = head;
      for (int i = 1; i < index; i++)
        temp = temp->next;
      return temp;
    }
  }

  // Updates data at 'index'. Uses get() to validate the index.
  bool set(int index, int data) {
    Node *node = get(index);
    if (node)
      node->data = data;
    return node != nullptr; // True if index was valid
  }

  // Inserts a new node at 'index'. Valid indices: 0 (prepend) to len (append).
  // Returns false if index is invalid (negative or > len).
  bool insert(int index, int data) {
    if (index < 0 || index > len)
      return false; // Invalid position
    else if (index == 0)
      prepend(data); // Case: New head
    else if (index == len)
      append(data);                // Case: New tail
    else {                         // Case: Middle insertion
      Node *prev = get(index - 1); // Get node before insertion point
      Node *newNode = new Node(data);
      newNode->next = prev->next;
      prev->next = newNode;
      len++;
    }
    return true;
  }

  // Deletes the node at 'index'. Valid indices: 0 (head) to len-1 (tail).
  // No-op if index is invalid (negative or >= len).
  void del(int index) {
    if (index < 0 || index >= len)
      return; // Invalid index
    else if (index == 0)
      pop_head(); // Case: Remove head
    else if (index == len - 1)
      pop_tail(); // Case: Remove tail
    else {        // Case: Remove middle node
      Node *prev = get(index - 1);
      Node *target = prev->next;
      prev->next = target->next;
      delete target;
      len--;
    }
  }

  void reverse() {
    if (len == 0 || len == 1) {
      return;
    } else {
      // Swap head & tail.
      Node *temp = head;
      head = tail;
      tail = temp;

      // Swap the remaining nodes between head and tail.
      Node *after = temp->next;
      Node *before = nullptr;

      for (int i = 0; i < len; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
      }
    }
  }

  void merge(LinkedList *list1, LinkedList *list2) {
    // Prevent Self-merge
    if (this == list1 || this == list2)
      throw std::runtime_error("Cannot merge a list with itself.");

    if (list1->isEmpty()) {
      this->head = list2->head;
      this->tail = list2->tail;
      this->len = list2->len;
    } else if (list2->isEmpty()) {
      this->head = list1->head;
      this->tail = list1->tail;
      this->len = list1->len;
    } else {
      this->head = list1->head;
      list1->tail->next = list2->head;
      this->tail = list2->tail;
      this->len = list1->len + list2->len;
    }
    list1->head = list1->tail = nullptr;
    list1->len = 0;
    list2->head = list2->tail = nullptr;
    list2->len = 0;
  }

  // void merge(LinkedList *list1, LinkedList *list2) {
  // // Prevent Self-merge
  // if (this == list1 || this == list2)
  //   throw std::runtime_error("Cannot merge a list with itself.");
  //
  //   Node *h1 = list1->head;
  //   Node *h2 = list2->head;
  //   Node *t1 = list1->tail;
  //   Node *t2 = list2->tail;
  //   int l1 = list1->len;
  //   int l2 = list2->len;

  //   if (list1->isEmpty()) {
  //     this->head = h2;
  //     this->tail = t2;
  //     this->len = l2;
  //   } else if (list2->isEmpty()) {
  //     this->head = h1;
  //     this->tail = t2;
  //     this->len = l2;
  //   } else {
  //     this->head = h1;
  //     t1->next = h2;
  //     this->tail = t2;
  //     this->len = l1 + l2;
  //   }

  //   list1->head = list1->tail = nullptr;
  //   list1->len = 0;
  //   list2->head = list2->tail = nullptr;
  //   list2->len = 0;
  // }

  // void merge(LinkedList *list1, LinkedList *list2) {
  //   // Prevent Self-merge
  //   if (this == list1 || this == list2)
  //     throw std::runtime_error("Cannot merge a list with itself.");

  //   if (list1->isEmpty()) {
  //     this->head = list2->head;
  //     this->tail = list2->tail;
  //     this->len = list2->len;
  //   } else if (list2->isEmpty()) {
  //     this->head = list1->head;
  //     this->tail = list1->tail;
  //     this->len = list1->len;
  //   } else {
  //     LinkedList *res = new LinkedList();

  //     Node *h1 = list1->head;
  //     Node *h2 = list2->head;

  //     while (h1 != nullptr) {
  //       res->append(h1->data);
  //       h1 = h1->next;
  //     }

  //     while (h2 != nullptr) {
  //       res->append(h2->data);
  //       h2 = h2->next;
  //     }

  //     this->head = res->head;
  //     this->tail = res->tail;
  //     this->len = res->len;

  //     res->head = res->tail = nullptr;
  //     delete res;
  //   }

  //   list1->head = list1->tail = nullptr;
  //   list1->len = 0;
  //   list2->head = list2->tail = nullptr;
  //   list2->len = 0;
  // }
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

  std::cout << "Updating 4th node data or index [3] data.." << std::endl;
  ll->set(3, 350);
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl << std::endl;

  std::cout << "Adding 750 to 5th node or index [4].. " << std::endl;
  ll->insert(4, 750);
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << std::endl << std::endl;

  std::cout
      << "Deleting the previously added 750 data in 4th node or index [3].."
      << std::endl;
  ll->del(4);
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << " and length is " << ll->length() << std::endl << std::endl;

  std::cout << "Reversing the linked list.." << std::endl;
  ll->reverse();
  std::cout << "The linkedlist is: ";
  ll->print_linkedlist();
  std::cout << " | Head: " << ll->getHead()->data
            << " | Tail: " << ll->getTail()->data
            << " | Length: " << ll->length() << std::endl
            << std::endl;

  LinkedList *ll2 = new LinkedList(1);

  for (int i = 1; i <= 7; i++)
    ll2->append(i * 10);

  LinkedList merged;

  std::cout << "Merging two linked lists.." << std::endl;
  merged.merge(ll, ll2);
  std::cout << "The linkedlist is: ";
  merged.print_linkedlist();
  std::cout << " | Head: " << merged.getHead()->data
            << " | Tail: " << merged.getTail()->data
            << " | Length: " << merged.length() << std::endl;
  std::cout << "The indexed elements post merger are: " << std::endl;
  for (int i = 0; i < merged.length(); i++)
    std::cout << "[" << i << "] => " << merged.get(i)->data << std::endl;
  std::cout << "7th element OR 7th node OR element at index [6] is: "
            << merged.get(6)->data << std::endl;

  delete ll;
  delete ll2;
}