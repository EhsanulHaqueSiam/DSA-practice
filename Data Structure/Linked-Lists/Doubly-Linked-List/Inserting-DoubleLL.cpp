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

  // Inserts a node at a given position
  void Insert(int data, int position) {
    Node* temp = new Node(data);

    // Special case for head end
    if (position == 0) {
      temp->next = head;
      if (head != nullptr) {
        head->prev = temp;
      }
      head = temp;
    } else {
      Node* ptr = head;
      // Locate the node before the point of insertion
      for (int i = 0; ptr != nullptr && i < position - 1; i++) {
        ptr = ptr->next;
      }
      // Check if node is not null
      if (ptr == nullptr) {
        std::cout << "Position is greater than the length of the list\n";
        delete temp;
        return;
      }
      // Insert node
      temp->next = ptr->next;
      temp->prev = ptr;

      if (ptr->next != nullptr) {
        ptr->next->prev = temp;
      }
      ptr->next = temp;
    }
  }

  // Helper function to print the list
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
  list.PrintList();  // 10

  list.Insert(20, 1);
  list.PrintList();  // 10 20

  list.Insert(30, 2);
  list.PrintList();  // 10 20 30

  list.Insert(15, 1);
  list.PrintList();  // 10 15 20 30

  list.Insert(5, 0);
  list.PrintList();  // 5 10 15 20 30

  return 0;
}
