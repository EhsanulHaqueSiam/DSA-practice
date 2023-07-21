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
  Node *head = nullptr;

  // Function to add a node at a given position
  void Insert(int data, int position) {
    // Create a new node
    Node *new_node = new Node;
    // Initialize its data and next pointer
    new_node->data = data;
    new_node->next = nullptr;

    // If the list is empty or position is 0 (before the head)
    if (head == nullptr || position == 0) {
      // Make the new node the head and link the old head to the new node
      new_node->next = head;
      head = new_node;
    } else {
      // Find the node at the given position
      Node *node_at_position = head;
      // Also keep track of the previous node to link the new node
      Node *previous_node = nullptr;

      // Use a counter to find the position
      int counter = 0;
      while (counter < position && node_at_position != nullptr) {
        previous_node = node_at_position;
        node_at_position = node_at_position->next;
        counter++;
      }

      // If we're not at the end of the list
      if (previous_node != nullptr) {
        // Link the new node to the node at the position
        new_node->next = previous_node->next;
        // Link the previous node to the new node
        previous_node->next = new_node;
      }
    }
  }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.Insert(10, 0); // Insert 10 at position 0
  ll.Insert(20, 1); // Insert 20 at position 1
  ll.Insert(30, 0); // Insert 30 at position 0

  // Now the list is 30 -> 10 -> 20

  return 0;
}
