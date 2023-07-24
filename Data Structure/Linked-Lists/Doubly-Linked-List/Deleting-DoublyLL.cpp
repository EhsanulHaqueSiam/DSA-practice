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

  // Inserting a node at a given position
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

  // Deleting a node at a given position
  void Delete(int position) {
    // Empty list case
    if (head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }

    Node* ptr = head;

    // Special case for head
    if (position == 0) {
      head = ptr->next;
      if (ptr->next != nullptr) {
        ptr->next->prev = nullptr;
      }
      delete ptr;
      return;
    }

    // Locate the node before the point of deletion
    for (int i = 0; ptr != nullptr && i < position; i++) {
      ptr = ptr->next;
    }

    // If position is more than the number of nodes
    if (ptr == nullptr) {
      std::cout << "Position is greater than the length of the list\n";
      return;
    }

    // Node deletion
    ptr->prev->next = ptr->next;
    if (ptr->next != nullptr) {
      ptr->next->prev = ptr->prev;
    }
    delete ptr;
  }

  void PrintList() {
    Node* temp = head;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
};

int main() {
  DoublyLinkedList list;

  list.Insert(10, 0);
  list.Insert(20, 1);
  list.Insert(30, 2);
  list.Insert(15, 1);
  list.Insert(5, 0);

  list.PrintList();  // 5 10 15 20 30

  list.Delete(0);
  list.PrintList();  // 10 15 20 30

  list.Delete(2);
  list.PrintList();  // 10 15 30

  return 0;
}
