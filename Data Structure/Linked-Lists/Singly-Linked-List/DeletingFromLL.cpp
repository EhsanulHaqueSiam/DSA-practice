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

  // Function to insert a node at the end of the list
  void InsertAtEnd(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr) {
      head = new_node;
    } else {
      Node *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = new_node;
    }
  }

  // Function to delete a node from any given position
  void DeleteAtPosition(int position) {
    // Check if the list is empty or if the position is negative
    if (head == nullptr || position < 0) {
      return;
    }

    // If the position is 0, we're deleting the head
    if (position == 0) {
      Node *old_head = head;
      head = head->next;
      delete old_head;
      return;
    }

    // Find the node before the position
    Node *previous_node = head;
    for (int i = 0; previous_node != nullptr && i < position - 1; i++) {
      previous_node = previous_node->next;
    }

    // If we're not at the end of the list and the node at the position exists
    if (previous_node != nullptr && previous_node->next != nullptr) {
      Node *node_to_delete = previous_node->next;
      previous_node->next = previous_node->next->next;
      delete node_to_delete;
    }
  }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.InsertAtEnd(10);
  ll.InsertAtEnd(20);
  ll.InsertAtEnd(30);
  ll.InsertAtEnd(40);
  ll.InsertAtEnd(50);

  // Now the list is 10 -> 20 -> 30 -> 40 -> 50

  ll.DeleteAtPosition(0); // Deletes 10, list becomes 20 -> 30 -> 40 -> 50
  ll.DeleteAtPosition(2); // Deletes 40, list becomes 20 -> 30 -> 50
  ll.DeleteAtPosition(
      4); // No operation as the position is larger than the size of the list

  return 0;
}
