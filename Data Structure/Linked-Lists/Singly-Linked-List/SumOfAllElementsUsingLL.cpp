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

  // Calculate the sum of the elements in the list iteratively
  int Sum() {
    Node *ptr = head;
    int sum = 0;
    while (ptr != nullptr) {
      sum += ptr->data;
      ptr = ptr->next;
    }
    return sum;
  }

  // Calculate the sum of the elements in the list recursively
  int RSum(Node *node) {
    // Base case: if the node is null, return 0
    if (node == nullptr) {
      return 0;
    }
    // Recurse for the next node and add the current node's data
    return RSum(node->next) + node->data;
  }

  // Public function to call the recursive sum function without passing
  // parameters
  int RSum() { return RSum(head); }
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

  // Calculate the sum iteratively
  cout << "Sum (Iterative): " << ll.Sum() << endl;

  // Calculate the sum recursively
  cout << "Sum (Recursive): " << ll.RSum() << endl;

  return 0;
}
