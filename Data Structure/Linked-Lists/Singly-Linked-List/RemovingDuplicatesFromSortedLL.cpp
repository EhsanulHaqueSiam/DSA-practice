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
  void Insert(int data) {
    // Creating a new node
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    // If the list is empty, make the new node the head
    if (head == nullptr) {
      head = new_node;
      return;
    }

    // Otherwise, find the last node
    Node *last_node = head;
    while (last_node->next != nullptr) {
      last_node = last_node->next;
    }

    // Insert the new node at the end of the list
    last_node->next = new_node;
  }

  // Function to remove duplicates from a sorted list using two pointers
  void RemoveDuplicatesTwoPointers() {
    Node *current = head;
    Node *next_next;

    // If list is empty
    if (current == nullptr) {
      return;
    }

    while (current->next != nullptr) {
      // Compare current node with next node
      if (current->data == current->next->data) {
        // The nodes are duplicate. Delete the next node.
        next_next = current->next->next;
        free(current->next);
        current->next = next_next;
      } else {
        // The nodes are not duplicates. Move to the next node.
        current = current->next;
      }
    }
  }

  // Function to remove duplicates from a sorted list without using two pointers
  void RemoveDuplicates() {
    Node *current = head;

    // If list is empty
    if (current == nullptr) {
      return;
    }

    while (current != nullptr && current->next != nullptr) {
      // Compare current node with next node
      if (current->data == current->next->data) {
        // The nodes are duplicate. Delete the next node.
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
      } else {
        // The nodes are not duplicates. Move to the next node.
        current = current->next;
      }
    }
  }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.Insert(10);
  ll.Insert(20);
  ll.Insert(20);
  ll.Insert(30);
  ll.Insert(30);
  ll.Insert(40);

  // Remove duplicates using two pointers
  ll.RemoveDuplicatesTwoPointers();

  // Add some elements to the list again
  ll.Insert(30);
  ll.Insert(30);
  ll.Insert(40);

  // Remove duplicates without using two pointers
  ll.RemoveDuplicates();

  return 0;
}
