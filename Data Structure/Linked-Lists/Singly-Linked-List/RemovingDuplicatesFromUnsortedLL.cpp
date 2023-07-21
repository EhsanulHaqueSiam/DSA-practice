#include <iostream>
using namespace std;

// Node class to define the structure of each node in the linked list
class Node {
public:
  int data;   // to store the data
  Node *next; // to store the address of the next node
};

// LinkedList class
class LinkedList {
public:
  Node *head = nullptr; // initial head is null as the list is empty

  // function to insert a node at any given position
  void InsertAtPosition(int data, int position) {
    Node *new_node = new Node; // create a new node
    new_node->data = data;     // assign data to the new node
    new_node->next = nullptr;  // initially new node does not point to anything

    // if the position is 0, insert before the head
    if (position == 0) {
      new_node->next = head; // point new node to current head
      head = new_node;       // update head to point to the new node
      return;
    }

    // find the node before the position
    Node *previous_node = head;
    for (int i = 0; previous_node != nullptr && i < position - 1; i++) {
      previous_node = previous_node->next; // traverse the list
    }

    // if the previous node is not null, insert the new node after it
    if (previous_node != nullptr) {
      new_node->next = previous_node->next; // link new node with the next node
      previous_node->next = new_node; // link previous node with the new node
    }
  }

  // function to remove duplicates from an unsorted linked list
  void RemoveDuplicates() {
    Node *current = head; // start from the head
    // traverse the list with current
    while (current != nullptr) {
      Node *runner =
          current; // runner is used to check for duplicate for the current node
      // traverse the rest of list with runner
      while (runner->next != nullptr) {
        // if a duplicate is found
        if (runner->next->data == current->data) {
          Node *dup = runner->next;          // dup points to the duplicate node
          runner->next = runner->next->next; // remove the duplicate node
          delete dup;                        // deallocate memory
        } else {
          runner = runner->next; // move to the next node
        }
      }
      current = current->next; // move to the next node for current
    }
  }
};

int main() {
  LinkedList ll;
  ll.InsertAtPosition(5, 0); // Insert 5 at position 0
  ll.InsertAtPosition(3, 1); // Insert 3 at position 1
  ll.InsertAtPosition(2, 2); // Insert 2 at position 2
  ll.InsertAtPosition(3, 3); // Insert 3 at position 3
  ll.InsertAtPosition(4, 4); // Insert 4 at position 4
  ll.InsertAtPosition(2, 5); // Insert 2 at position 5
  ll.InsertAtPosition(5, 6); // Insert 5 at position 6
  ll.RemoveDuplicates();     // remove duplicates from the list

  return 0;
}
