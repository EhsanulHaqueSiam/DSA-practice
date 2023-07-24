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

  // Function to display the list recursively
  void DisplayRecursive(Node* temp) {
    if (temp != head || head == nullptr) {
      std::cout << temp->data << " ";
      DisplayRecursive(temp->next);
    }
  }

  // Function to display the list iteratively
  void DisplayIterative() {
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

  // Display the list recursively
  std::cout << "Recursive Display: ";
  list.DisplayRecursive(list.head);
  std::cout << std::endl;

  // Display the list iteratively
  std::cout << "Iterative Display: ";
  list.DisplayIterative();

  return 0;
}
