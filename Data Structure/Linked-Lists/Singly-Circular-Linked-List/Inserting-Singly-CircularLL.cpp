#include <iostream>

// Node class to represent each element in the linked list
class Node {
 public:
  int data;  // Integer data for simplicity. Can be any data type
  Node* next;  // Pointer to the next node

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

// LinkedList class that will implement the singly linked list
class LinkedList {
 public:
  Node* head;  // Head of the list

  LinkedList() {
    head = nullptr;
  }

  // Function to insert a node at a given position
  void InsertAtPosition(int data, int position) {
    // Create a new node
    Node* newNode = new Node(data);
    
    // Case 1: If the list is empty
    if (head == nullptr) {
      head = newNode;
      newNode->next = head;
    } else if (position == 0) {
      // Case 2: If position is 0, insert before head
      Node* temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      newNode->next = head;
      temp->next = newNode;
      head = newNode;
    } else {
      // Case 3: Any other position
      Node* prev = head;
      for (int i = 0; i < position - 1; i++) {
        prev = prev->next;
      }
      newNode->next = prev->next;
      prev->next = newNode;
    }
  }

  // Function to display the list iteratively
  void Display() {
    if (head != nullptr) {
      Node* temp = head;
      do {
        std::cout << temp->data << " ";
        temp = temp->next;
      } while (temp != head);
    }
    std::cout << std::endl;
  }
};

int main() {
  LinkedList list;

  // Insert nodes into the list
  list.InsertAtPosition(1, 0);  // Insert 1 at position 0
  list.InsertAtPosition(2, 1);  // Insert 2 at position 1
  list.InsertAtPosition(3, 2);  // Insert 3 at position 2
  list.InsertAtPosition(4, 0);  // Insert 4 at position 0 (before the current head)

  // Display the list
  std::cout << "List: ";
  list.Display();

  return 0;
}
