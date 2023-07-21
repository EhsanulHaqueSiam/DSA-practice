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

  // Function to insert a node in sorted position using two pointers
  void InsertSortedTwoPointers(int data) {
    // Create a new node
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    // Create two pointers to traverse the list and find the insert position
    Node *current = head;
    Node *previous = nullptr;

    // While we're not at the end of the list and the current node's data is
    // less than the new node's data
    while (current != nullptr && current->data < new_node->data) {
      // Move the two pointers forward
      previous = current;
      current = current->next;
    }

    // If previous is null, the new node should be inserted at the head
    if (previous == nullptr) {
      new_node->next = head;
      head = new_node;
    } else {
      // Otherwise, insert the new node after the previous node
      new_node->next = previous->next;
      previous->next = new_node;
    }
  }

  // Function to insert a node in sorted position using one pointer
  void InsertSortedOnePointer(int data) {
    // Create a new node
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    // If the list is empty or the new node's data is less than the head's data,
    // insert at the head
    if (head == nullptr || new_node->data < head->data) {
      new_node->next = head;
      head = new_node;
    } else {
      // Otherwise, find the node to insert after
      Node *current = head;
      while (current->next != nullptr && current->next->data < new_node->data) {
        current = current->next;
      }

      // Insert the new node after the current node
      new_node->next = current->next;
      current->next = new_node;
    }
  }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.InsertSortedTwoPointers(10);
  ll.InsertSortedTwoPointers(20);
  ll.InsertSortedTwoPointers(15);

  // Now the list is 10 -> 15 -> 20

  ll.InsertSortedOnePointer(5);
  ll.InsertSortedOnePointer(25);
  ll.InsertSortedOnePointer(18);

  // Now the list is 5 -> 10 -> 15 -> 18 -> 20 -> 25

  return 0;
}
