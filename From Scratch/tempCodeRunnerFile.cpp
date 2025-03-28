  bool set(int index, int data) {
    Node *temp = get(index);
    if (temp) {
      temp->data = data;
      return true;
    }
    return false;
  }