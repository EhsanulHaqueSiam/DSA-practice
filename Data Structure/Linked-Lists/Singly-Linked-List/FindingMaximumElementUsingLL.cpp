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

  // Add a new element to the list
  void Add(int data) {
    // Create a new node
    Node *new_node = new Node;
    // Initialize its data and next pointer
    new_node->data = data;
    new_node->next = nullptr;

    // If the list is empty
    if (head == nullptr) {
      // Set the new node as the head
      head = new_node;
    } else {
      // If the list is not empty, find the last node
      Node *last_node = head;
      while (last_node->next != nullptr) {
        last_node = last_node->next;
      }
      // Link the new node to the last node
      last_node->next = new_node;
    }
  }

  // Find the maximum element in the list iteratively
  int Max() {
    Node *ptr = head;
    int max = INT_MIN;
    while (ptr != nullptr) {
      if (ptr->data > max) {
        max = ptr->data;
      }
      ptr = ptr->next;
    }
    return max;
  }

  // Find the maximum element in the list recursively
  int RMax(Node *node) {
    // Base case: if the node is null, return INT_MIN
    if (node == nullptr) {
      return INT_MIN;
    }
    // Recurse for the next node
    int x = RMax(node->next);
    // Return the maximum of the current node's data and the maximum of the
    // remaining list
    return max(x, node->data);
  }

  // Public function to call the recursive max function without passing
  // parameters
  int RMax() { return RMax(head); }
};

int main() {
  // Create a new linked list
  LinkedList ll;

  // Add some elements to the list
  ll.Add(1);
  ll.Add(2);
  ll.Add(3);
  ll.Add(4);
  ll.Add(5);

  // Find the maximum element iteratively
  cout << "Max (Iterative): " << ll.Max() << endl;

  // Find the maximum element recursively
  cout << "Max (Recursive): " << ll.RMax() << endl;

  return 0;
}
