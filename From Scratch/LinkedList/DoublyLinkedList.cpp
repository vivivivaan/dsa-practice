#include <iostream>
#include <stdexcept>

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
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    len = 0;
  }

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
    if (index < 0 || index >= len)
      return nullptr;

    if (index == 0)
      return head;

    if (index == len - 1)
      return tail;

    Node *current;
    if (index < len / 2) {
      current = head;
      for (int i = 0; i < index; i++) {
        current = current->next;
      }
    } else {
      current = tail;
      for (int i = len - 1; i > index; i--) {
        current = current->previous;
      }
    }
    return current;
  }

  //   Node *get(int index) {
  //     if (index < 0 || index >= len)
  //       return nullptr;

  //     if (index == 0)
  //       return head;

  //     if (index == len - 1)
  //       return tail;

  //     Node *current;
  //     int mid = len / 2 + 1;
  //     if (index < mid) {
  //       current = head;
  //       for (int i = 0; i < index; i++) {
  //         current = current->next;
  //       }
  //     } else {
  //       current = tail;
  //       for (int i = len - 1; i > index; i--) {
  //         current = current->previous;
  //       }
  //     }
  //     return current;
  //   }

  bool set(int index, int data) {
    Node *temp = get(index);
    if (temp) {
      temp->data = data;
      return true;
    }
    return false;
  }

  //   bool set(int index, int data) {
  //     if (index == 0) {
  //       setHead(data);
  //       return true;
  //     }

  //     if (index == len - 1) {
  //       setTail(data);
  //       return true;
  //     }

  //     Node *temp = get(index);
  //     if (temp) {
  //       temp->data = data;
  //       return true;
  //     }
  //     return false;
  //   }

  bool insert(int index, int data) {
    if (index < 0 || index > len)
      return false;

    if (index == 0) {
      prepend(data);
      return true;
    }

    if (index == len) {
      append(data);
      return true;
    }

    Node *node = new Node(data);
    Node *before = get(index - 1);
    Node *after = before->next;
    node->previous = before;
    node->next = after;
    before->next = node;
    after->previous = node;
    len++;
    return true;
  }

  // Node *del(int index) {
  //   if (index < 0 || index >= len) {
  //     return nullptr;
  //   }

  //   if (index == 0)
  //     return pop_head();

  //   if (index == len - 1)
  //     return pop_tail();

  //   Node *prev = get(index - 1);
  //   Node *current = prev->next;
  //   Node *after = current->next;
  //   prev->next = after;
  //   after->previous = prev;
  //   current->next = nullptr;
  //   len--;
  //   return current;
  // }

  Node *del(int index) {
    if (index < 0 || index >= len) {
      return nullptr;
    }

    if (index == 0)
      return pop_head();

    if (index == len - 1)
      return pop_tail();

    Node *temp = get(index);
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    temp->previous = nullptr;
    temp->next = nullptr;
    len--;
    return temp;
  }

  void merge(DoublyLinkedList *list1, DoublyLinkedList *list2) {
    if (this == list1 || this == list2) {
      throw std::runtime_error("Cannot merge a list with itself.");
    }

    if (list1->isEmpty()) {
      this->head = list2->head;
      this->tail = list2->tail;
      this->len = list2->len;
    } else if (list2->isEmpty()) {
      this->head = list1->head;
      this->tail = list2->tail;
      this->len = list2->len;
    } else {
      this->head = list1->head;
      this->tail = list2->tail;
      this->len = list1->len + list2->len;

      list1->tail->next = list2->head;
      list2->head->previous = list1->tail;
    }

    list1->head = list1->tail = nullptr;
    list1->len = 0;
    list2->head = list2->tail = nullptr;
    list2->len = 0;
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

  std::cout << "The 6th node data or index [5] is " << dll->get(1)->data
            << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Updating 4th node data or index [3] data.." << std::endl;
  dll->set(3, 450);
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Adding 750 to 5th node or index [4].. " << std::endl;
  dll->insert(4, 750);
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout << "Adding 800 to 5th node or index [4].. " << std::endl;
  dll->insert(4, 800);
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  std::cout
      << "Deleting the previously added 800 data in 5th node or index [4]: "
      << dll->del(4)->data << std::endl;
  std::cout << "The linkedlist is: ";
  dll->print_linkedlist();
  std::cout << std::endl;
  std::cout << "New length of the linkedlist is " << dll->length()
            << " | Head: " << dll->getHead()->data
            << " | Tail: " << dll->getTail()->data << std::endl
            << std::endl;

  DoublyLinkedList *dll2 = new DoublyLinkedList(1000);

  for (int i = 2; i <= 7; i++)
    dll2->append(i * 1000);

  DoublyLinkedList merged;

  std::cout << "Merging two doubly linked lists.." << std::endl;
  merged.merge(dll, dll2);
  std::cout << "The doublylinkedlist is: ";
  merged.print_linkedlist();
  std::cout << " | Head: " << merged.getHead()->data
            << " | Tail: " << merged.getTail()->data
            << " | Length: " << merged.length() << std::endl;
  std::cout << "The indexed elements post merger are: " << std::endl;
  for (int i = 0; i < merged.length(); i++)
    std::cout << "[" << i << "] => " << merged.get(i)->data << std::endl;
  std::cout << "7th element OR 7th node OR element at index [6] is: "
            << merged.get(6)->data << std::endl;

  delete dll;
  delete dll2;
}