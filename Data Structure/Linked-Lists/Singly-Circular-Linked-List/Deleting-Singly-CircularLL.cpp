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

  // Function to insert a node at the end of the list
  void InsertNode(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      newNode->next = head;
    } else {
      Node* temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
    }
  }

  // Function to delete a node at a given position
  void DeleteAtPosition(int position) {
    // Case 1: If the list is empty
    if (head == nullptr) {
      return;
    } 
    // Case 2: If position is 0, delete head
    else if (position == 0) {
      Node* temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      if (head == temp) {
        delete head;
        head = nullptr;
      } else {
        temp->next = head->next;
        delete head;
        head = temp->next;
      }
    } 
    // Case 3: Any other position
    else {
      Node* prev = head;
      for (int i = 0; i < position - 1; i++) {
        prev = prev->next;
      }
      Node* temp = prev->next;
      prev->next = temp->next;
      delete temp;
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
  list.InsertNode(1);
  list.InsertNode(2);
  list.InsertNode(3);
  list.InsertNode(4);

  // Display the list
  std::cout << "Original List: ";
  list.Display();

  // Delete nodes from the list
  list.DeleteAtPosition(0);  // Delete node at position 0 (head node)
  list.DeleteAtPosition(1);  // Delete node at position 1

  // Display the list after deletion
  std::cout << "List after deletion: ";
  list.Display();

  return 0;
}
