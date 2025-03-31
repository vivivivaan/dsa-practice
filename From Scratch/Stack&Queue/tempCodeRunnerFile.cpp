 ~Queue() {
    Node *temp = first;
    while (temp != nullptr) {
      Node *node = temp;
      delete node;
      if (temp != nullptr) {
        temp = temp->next;
      }
    }
    first = nullptr;
    last = nullptr;
    len = 0;
  }