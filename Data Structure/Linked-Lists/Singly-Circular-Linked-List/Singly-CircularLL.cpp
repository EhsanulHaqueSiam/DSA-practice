#include <iostream>
using namespace std;

// Node class, representing each individual node in our linked list.
class Node {
public:
  int data;   // The data contained in this node.
  Node *next; // Pointer to the next node in the list.
};

// CircularLinkedList class, which encapsulates the behavior of a circular
// linked list.
class CircularLinkedList {
private:
  Node *head; // The head node of the linked list.

  // Helper function to recursively display the list, starting from the given
  // node.
  void DisplayRecursivelyHelper(Node *node) {
    if (node == nullptr)
      return;
    cout << node->data << " ";
    if (node->next != head)
      DisplayRecursivelyHelper(node->next);
  }

public:
  // Constructor initializes head to nullptr to represent an empty list.
  CircularLinkedList() : head(nullptr) {}

  // Function to display the circular linked list iteratively.
  void DisplayIteratively() {
    if (head == nullptr)
      return; // If list is empty, nothing to display.
    Node *node = head;
    do {
      cout << node->data << " ";
      node = node->next;
    } while (node != head); // Loop until we've circled back to the head.
    cout << endl;
  }

  // Function to display the circular linked list recursively.
  void DisplayRecursively() {
    DisplayRecursivelyHelper(head);
    cout << endl;
  }

  // Function to create a circular linked list from an array.
  void CreateFromArray(int arr[], int length) {
    if (length <= 0)
      return; // If array is empty, nothing to do.

    // Create head node to start.
    head = new Node;
    head->data = arr[0];
    head->next = head; // Single node points to itself.

    Node *last = head;
    for (int i = 1; i < length; i++) {
      Node *node = new Node;
      node->data = arr[i];
      node->next = last->next;
      last->next = node;
      last = node;
    }
  }

  // Function to get the length of the list.
  int Length() {
    if (head == nullptr)
      return 0; // Empty list has length 0.
    Node *node = head;
    int length = 0;
    do {
      length++;
      node = node->next;
    } while (node != head); // Loop until we've circled back to the head.
    return length;
  }

  // Function to insert a new element at a given position.
  void Insert(int index, int element) {
    if (index < 0 || index > Length())
      return;

    Node *node = new Node;
    node->data = element;
    Node *p = head;

    if (index == 0) {        // Inserting at the head.
      if (head == nullptr) { // If list is empty, new node becomes the single
                             // node, pointing to itself.
        head = node;
        head->next = head;
      } else {
        // Otherwise, insert before current head and adjust pointers to maintain
        // circularity.
        while (p->next != head)
          p = p->next;
        p->next = node;
        node->next = head;
        head = node;
      }
    } else {
      // Find the node just before the insertion point.
      for (int i = 0; i < index - 1; i++)
        p = p->next;
      node->next = p->next;
      p->next = node;
    }
  }

  // Function to delete an element at a given position.
  void Delete(int index) {
    if (index < 0 || index >= Length())
      return;

    Node *p = head, *q;

    if (index == 0) { // Deleting the head node.
      while (p->next != head)
        p = p->next;   // Find the last node.
      if (head == p) { // If there's only one node, deleting it results in an
                       // empty list.
        delete head;
        head = nullptr;
      } else {
        // Otherwise, remove the head and adjust pointers to maintain
        // circularity.
        p->next = head->next;
        delete head;
        head = p->next;
      }
    } else {
      // Find the node just before the deletion point.
      for (int i = 0; i < index - 1; i++)
        p = p->next;
      q = p->next;
      p->next = q->next;
      delete q;
    }
  }
};

int main() {
  CircularLinkedList list;
  int arr[] = {1, 2, 3, 4, 5};
  list.CreateFromArray(arr,
                       5); // Creates a circular linked list from the array.

  // The list should now be: 1 2 3 4 5
  list.DisplayIteratively();

  // Inserting 0 at the head of the list, should now be: 0 1 2 3 4 5
  list.Insert(0, 0);
  list.DisplayIteratively();

  // Inserting 6 at the end of the list, should now be: 0 1 2 3 4 5 6
  list.Insert(6, 6);
  list.DisplayIteratively();

  // Deleting the head of the list, should now be: 1 2 3 4 5 6
  list.Delete(0);
  list.DisplayIteratively();

  // Deleting the end of the list, should now be: 1 2 3 4 5
  list.Delete(5);
  list.DisplayIteratively();

  return 0;
}
