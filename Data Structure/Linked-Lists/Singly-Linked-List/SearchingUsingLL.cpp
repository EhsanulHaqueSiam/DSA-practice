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

  // Linear Search for an element in the list iteratively
  Node *Search(int key) {
    // Start with the head node
    Node *ptr = head;
    // Traverse the list
    while (ptr != nullptr) {
      // If the current node's data matches the key, return the current node
      if (ptr->data == key) {
        return ptr;
      }
      // Move to the next node
      ptr = ptr->next;
    }
    // If we've reached here, then the key is not in the list, so return null
    return nullptr;
  }

  // Linear Search for an element in the list recursively
  Node *RSearch(Node *node, int key) {
    // Base case: if the node is null, return null
    if (node == nullptr) {
      return nullptr;
    }
    // If the node's data equals the key, return the node
    if (node->data == key) {
      return node;
    }
    // Recurse for the next node
    return RSearch(node->next, key);
  }

  // Public function to call the recursive search function without passing the
  // head as a parameter
  Node *RSearch(int key) {
    // Call the recursive search function with the head node and the key
    return RSearch(head, key);
  }

  // Linear Search with transposition
  Node *TranspositionSearch(int key) {
    // Start with the head node
    Node *ptr = head;
    // We'll need to keep track of the previous node for the transposition,
    // initialize it to null
    Node *qtr = nullptr;
    // Traverse the list
    while (ptr != nullptr) {
      // If the current node's data matches the key
      if (ptr->data == key) {
        // If it's not the head node
        if (qtr != nullptr) {
          // Swap the data of the current node and the previous node
          int temp = qtr->data;
          qtr->data = ptr->data;
          ptr->data = temp;
        }
        // Return the current node
        return ptr;
      }
      // Move to the next node
      qtr = ptr;
      ptr = ptr->next;
    }
    // If we've reached here, then the key is not in the list, so return null
    return nullptr;
  }

  // Linear Search with move to head
  Node *MoveToHeadSearch(int key) {
    // Start with the head node
    Node *ptr = head;
    // We'll need to keep track of the previous node to adjust the links,
    // initialize it to null
    Node *qtr = nullptr;
    // Traverse the list
    while (ptr != nullptr) {
      // If the current node's data matches the key
      if (ptr->data == key) {
        // If it's not the head node
        if (qtr != nullptr) {
          // Link the previous node to the current node's next node
          qtr->next = ptr->next;
          // Link the current node to the head
          ptr->next = head;
          // Make the current node the head
          head = ptr;
        }
        // Return the current (now head) node
        return head;
      }
      // Move to the next node
      qtr = ptr;
      ptr = ptr->next;
    }
    // If we've reached here, then the key is not in the list, so return null
    return nullptr;
  }
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

  // Search for an element iteratively
  cout << "Search 3 (Iterative): "
       << (ll.Search(3) != nullptr ? "Found" : "Not Found") << endl;

  // Search for an element recursively
  cout << "Search 3 (Recursive): "
       << (ll.RSearch(3) != nullptr ? "Found" : "Not Found") << endl;

  // Search for an element with transposition
  cout << "Search 3 (Transposition): "
       << (ll.TranspositionSearch(3) != nullptr ? "Found" : "Not Found")
       << endl;

  // Search for an element with move to head
  cout << "Search 3 (Move to Head): "
       << (ll.MoveToHeadSearch(3) != nullptr ? "Found" : "Not Found") << endl;

  return 0;
}
