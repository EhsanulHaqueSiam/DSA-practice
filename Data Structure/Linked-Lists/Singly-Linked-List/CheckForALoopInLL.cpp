#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

class LinkedList {
public:
  Node *head = nullptr;

  // Function to insert at the end of the linked list
  void InsertAtEnd(int data) {
    Node *new_node = new Node; // Create a new node
    new_node->data = data;     // Set the data of the node to the passed data
    new_node->next =
        nullptr; // Initialize the next pointer of the node to nullptr

    // If the linked list is empty, make the new node the head
    if (head == nullptr) {
      head = new_node;
    } else {
      // If the linked list is not empty, iterate to the end of the list
      Node *last_node = head;
      while (last_node->next != nullptr) {
        last_node = last_node->next;
      }
      // Make the new node the next node of the last node
      last_node->next = new_node;
    }
  }

  // Function to check if the linked list has a loop
  bool HasLoop() {
    Node *slow_p = head; // Slow pointer, moves one step at a time
    Node *fast_p = head; // Fast pointer, moves two steps at a time

    // Continue while both pointers are not nullptr and the next node of the
    // fast pointer is not nullptr
    while (slow_p && fast_p && fast_p->next) {
      slow_p = slow_p->next;       // Move the slow pointer one step forward
      fast_p = fast_p->next->next; // Move the fast pointer two steps forward

      // If the slow pointer and the fast pointer point to the same node, then
      // there is a loop
      if (slow_p == fast_p) {
        return true; // Loop found
      }
    }

    // If the fast pointer reaches the end of the list (nullptr), then there is
    // no loop
    return false; // No loop
  }
};

int main() {
  LinkedList ll;

  // Creating a linked list with a loop for demonstration
  ll.InsertAtEnd(1);
  ll.InsertAtEnd(2);
  ll.InsertAtEnd(3);
  ll.InsertAtEnd(4);
  ll.InsertAtEnd(5);
  ll.head->next->next->next->next->next =
      ll.head->next; // Create a loop for testing

  // Check if the linked list has a loop
  if (ll.HasLoop()) {
    cout << "Loop found in linked list" << endl;
  } else {
    cout << "No loop found in linked list" << endl;
  }

  return 0;
}

/*Floyd's cycle detection algorithm (also known as the "tortoise and the hare"):

Imagine a race track. You have two racers, one (the hare) is twice as fast as
the other (the tortoise). If the track is a straight line (no loop), the hare
will reach the finish line while the tortoise is still on the track. But if the
track is a loop, no matter how far ahead the hare gets, it will eventually catch
up to (and pass) the tortoise.

Now, think of the linked list as this race track. The nodes are the steps on the
track, and the pointers are the racers. When we traverse the linked list with
two pointers (slow_p and fast_p), we're essentially setting up a race between
them on this track. If the linked list has a loop (cycle), the fast pointer
(hare) will eventually catch up to the slow pointer (tortoise). If there's no
loop, the fast pointer will reach the end of the list (finish line).*/
