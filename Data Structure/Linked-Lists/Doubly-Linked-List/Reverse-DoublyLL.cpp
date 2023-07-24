#include <iostream>

class Node {
public:
  int data;
  Node* next;
  Node* prev;

  Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
public:
  Node* head;

  DoublyLinkedList() { 
    head = nullptr; 
  }

  void Insert(int data, int position) {
    Node* temp = new Node(data);

    if (position == 0) {
      temp->next = head;
      if (head != nullptr) {
        head->prev = temp;
      }
      head = temp;
    } else {
      Node* ptr = head;
      for (int i = 0; ptr != nullptr && i < position - 1; i++) {
        ptr = ptr->next;
      }

      if (ptr == nullptr) {
        std::cout << "Position is greater than the length of the list\n";
        delete temp;
        return;
      }

      temp->next = ptr->next;
      temp->prev = ptr;

      if (ptr->next != nullptr) {
        ptr->next->prev = temp;
      }
      ptr->next = temp;
    }
  }

  void DisplayIteratively() {
    Node* temp = head;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }

  // Reversing list iteratively
  void ReverseIteratively() {
    Node *current = head, *prev = nullptr, *next = nullptr;
    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      current->prev = next;
      prev = current;
      current = next;
    }
    head = prev;
  }

  // Helper function to reverse list recursively
  Node* ReverseRecursivelyHelper(Node* node) {
    if (!node) {
      return nullptr;
    }
    Node* next = node->next;
    node->next = node->prev;
    node->prev = next;
    if (!next) {
      return node;
    }
    return ReverseRecursivelyHelper(next);
  }

  // Reversing list recursively
  void ReverseRecursively() {
    head = ReverseRecursivelyHelper(head);
  }
};

int main() {
  DoublyLinkedList list;

  list.Insert(10, 0);
  list.Insert(20, 1);
  list.Insert(30, 2);
  list.Insert(15, 1);
  list.Insert(5, 0);

  std::cout << "Original list: ";
  list.DisplayIteratively();  // 5 10 15 20 30

  list.ReverseIteratively();
  std::cout << "Reversed list iteratively: ";
  list.DisplayIteratively();  // 30 20 15 10 5

  list.ReverseRecursively();
  std::cout << "Reversed list recursively: ";
  list.DisplayIteratively();  // 5 10 15 20 30

  return 0;
}
