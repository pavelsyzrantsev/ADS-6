// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* head_;

 public:
  explicit TPQueue() : head_(nullptr) {}

  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T& item) {
    Node* new_node = new Node;
    new_node->data = item;
    new_node->next = nullptr;

    if (isEmpty() || item.prior > head_->data.prior) {
      new_node->next = head_;
      head_ = new_node;
      return;
    }

    Node* current = head_;
    while (current->next != nullptr &&
           current->next->data.prior >= item.prior) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }

  T pop() {
    if (isEmpty()) {
      return T();
    }
    Node* temp = head_;
    T result = head_->data;
    head_ = head_->next;
    delete temp;
    return result;
  }

  bool isEmpty() const {
    return head_ == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
