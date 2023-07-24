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

  // Displaying list iteratively
  void DisplayIteratively() {
    Node* temp = head;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }

  // Helper function to display list recursively
  void DisplayRecursivelyHelper(Node* node) {
    if (!node) {
      return;
    }
    std::cout << node->data << " ";
    DisplayRecursivelyHelper(node->next);
  }

  // Display list recursively
  void DisplayRecursively() {
    DisplayRecursivelyHelper(head);
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

  std::cout << "Displaying list iteratively: ";
  list.DisplayIteratively();  // 5 10 15 20 30

  std::cout << "Displaying list recursively: ";
  list.DisplayRecursively();  // 5 10 15 20 30

  return 0;
}
