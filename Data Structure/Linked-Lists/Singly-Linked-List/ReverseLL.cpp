#include <iostream>
using namespace std;

class Node {
public:
  int data;   // data to be stored in the node
  Node *next; // pointer to the next node
};

class LinkedList {
public:
  Node *head = nullptr; // pointer to the head node

  // function to insert at the end of the linked list
  void InsertAtEnd(int data) {
    Node *new_node = new Node; // create a new node
    new_node->data = data;     // assign data to the new node
    new_node->next = nullptr;  // new node does not point to anything initially

    if (head == nullptr) { // if the list is empty
      head = new_node;     // make new node as the head
      return;
    }

    Node *last_node = head;              // start from the head
    while (last_node->next != nullptr) { // find the last node
      last_node = last_node->next;
    }

    last_node->next = new_node; // link the last node with the new node
  }

  // function to reverse the linked list without using recursion
  void ReverseIteratively() {
    Node *prev = nullptr; // previous node
    Node *current = head; // current node
    Node *next = nullptr; // next node

    while (current != nullptr) { // traverse the list
      next = current->next;      // save the next node
      current->next = prev;      // reverse the link
      prev = current;            // update prev
      current = next;            // update current
    }

    head = prev; // update head to the last node
  }

  // function to reverse the linked list using recursion
  Node *ReverseRecursively(Node *node) {
    if (node == nullptr || node->next == nullptr) { // if node is the last node
      head = node;                                  // update head to node
      return node;
    }

    Node *reversed_rest = ReverseRecursively(
        node->next);            // recursively reverse the rest of the list
    reversed_rest->next = node; // reverse the link between the last node of the
                                // reversed rest and node
    node->next = nullptr;       // remove the old link

    return node; // node becomes the last node of the reversed list
  }

  // helper function to call ReverseRecursively(Node* node) function
  void ReverseRecursively() {
    if (head != nullptr) {      // if the list is not empty
      ReverseRecursively(head); // call the function with the head node
    }
  }
};

int main() {
  LinkedList ll;
  ll.InsertAtEnd(1);
  ll.InsertAtEnd(2);
  ll.InsertAtEnd(3);
  ll.InsertAtEnd(4);
  ll.InsertAtEnd(5);

  ll.ReverseIteratively(); // reverse the linked list iteratively

  ll.ReverseRecursively(); // reverse the linked list recursively

  return 0;
}
