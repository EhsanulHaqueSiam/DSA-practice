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

  // Create a linked list from an array
  void Create(int arr[], int n) {
    // Last node in the list
    Node *last_node;
    // If the list is empty
    if (head == nullptr) {
      // Create a new node
      head = new Node;
      // Initialize its data and next pointer
      head->data = arr[0];
      head->next = nullptr;
      // Set it as the last node
      last_node = head;
    } else {
      // If the list is not empty, find the last node
      last_node = head;
      while (last_node->next != nullptr) {
        last_node = last_node->next;
      }
    }
    // For each remaining element in the array
    for (int i = 1; i < n; i++) {
      // Create a new node
      Node *temp = new Node;
      // Initialize its data and next pointer
      temp->data = arr[i];
      temp->next = nullptr;
      // Link it to the last node
      last_node->next = temp;
      // Set it as the last node
      last_node = temp;
    }
  }

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

  // Display the contents of the list iteratively
  void Display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }

  // Display the contents of the list recursively
  void Display(Node *node) {
    // Base case: if the node is null, return
    if (node == nullptr) {
      cout << endl;
      return;
    }
    // Print the data of the current node
    cout << node->data << " ";
    // Recurse for the next node
    Display(node->next);
  }

  // Public function to call the recursive display function without passing
  // parameters
  void RDisplay() { Display(head); }
};

int main() {
  // Create a new linked list
  LinkedList ll;
  int arr[] = {1, 2, 3, 4, 5};
  // Create the linked list from the array
  ll.Create(arr, 5);
  // Display the list iteratively
  ll.Display();
  // Display the list recursively
  ll.RDisplay();

  // Add a new element to the list
  ll.Add(6);
  // Display the list iteratively
  ll.Display();
  // Display the list recursively
  ll.RDisplay();

  return 0;
}
