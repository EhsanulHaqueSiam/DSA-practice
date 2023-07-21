#include <iostream>
using namespace std;

// Node class to represent the elements of the linked list
class Node {
public:
  // Integer data
  int data;
  // Pointer to the next node
  Node *next;
};

// LinkedList class to handle operations on the linked list
class LinkedList {
public:
  // Head of the list
  Node *head;
  // Tail of the list
  Node *tail;

  // Constructor
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // Function to add a node at the end of the list
  void InsertAtEnd(int data) {
    // Create a new node
    Node *new_node = new Node;
    // Initialize its data and next pointer
    new_node->data = data;
    new_node->next = nullptr;

    // If the list is empty, make the new node the head and the tail
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      // If the list is not empty, link the new node to the tail and update the
      // tail
      tail->next = new_node;
      tail = new_node;
    }
  }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.InsertAtEnd(10); // Insert 10 at the end
  ll.InsertAtEnd(20); // Insert 20 at the end
  ll.InsertAtEnd(30); // Insert 30 at the end

  // Now the list is 10 -> 20 -> 30

  return 0;
}
