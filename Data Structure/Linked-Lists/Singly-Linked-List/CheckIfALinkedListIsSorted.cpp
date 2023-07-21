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

  // Function to insert a node at a specific position
  void InsertAtPosition(int data, int position) {
    // Creating a new node
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    // If the position is 0, insert at the head
    if (position == 0) {
      new_node->next = head;
      head = new_node;
      return;
    }

    // Find the node before the position
    Node *previous_node = head;
    for (int i = 0; previous_node != nullptr && i < position - 1; i++) {
      previous_node = previous_node->next;
    }

    // If we're not at the end of the list, insert the new node
    if (previous_node != nullptr) {
      new_node->next = previous_node->next;
      previous_node->next = new_node;
    }
  }

  // Function to check if the list is sorted
  bool IsSorted() {
    if (head == nullptr || head->next == nullptr) {
      // An empty list or a list with only one node is considered sorted
      return true;
    }

    Node *current = head;
    while (current->next != nullptr) {
      // If the next node's data is less than the current node's data, the list
      // is not sorted
      if (current->next->data < current->data) {
        return false;
      }
      current = current->next;
    }

    // If we've reached the end of the list without finding any out-of-order
    // nodes, the list is sorted
    return true;
  }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.InsertAtPosition(10, 0); // List: 10
  ll.InsertAtPosition(20, 1); // List: 10 -> 20
  ll.InsertAtPosition(30, 2); // List: 10 -> 20 -> 30
  ll.InsertAtPosition(40, 3); // List: 10 -> 20 -> 30 -> 40
  ll.InsertAtPosition(50, 4); // List: 10 -> 20 -> 30 -> 40 -> 50

  // Check if the list is sorted
  cout << (ll.IsSorted() ? "The list is sorted." : "The list is not sorted.")
       << endl;

  // Add an element out of order
  ll.InsertAtPosition(25, 2); // List: 10 -> 20 -> 25 -> 30 -> 40 -> 50

  // Check if the list is sorted
  cout << (ll.IsSorted() ? "The list is sorted." : "The list is not sorted.")
       << endl;

  return 0;
}
