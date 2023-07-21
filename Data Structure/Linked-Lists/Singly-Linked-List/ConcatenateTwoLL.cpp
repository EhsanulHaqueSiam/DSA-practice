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

  // function to insert at the end of the linked list
  void InsertAtEnd(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr) {
      head = new_node;
      return;
    }

    Node *last_node = head;
    while (last_node->next != nullptr) {
      last_node = last_node->next;
    }

    last_node->next = new_node;
  }

  // function to concatenate another linked list to this linked list
  void Concatenate(LinkedList other) {
    if (head == nullptr) { // if the first list is empty
      head = other.head; // just assign the head of the second list to the head
                         // of the first list
    } else {
      Node *last_node = head;
      while (last_node->next !=
             nullptr) { // find the last node of the first list
        last_node = last_node->next;
      }

      last_node->next = other.head; // link the last node of the first list with
                                    // the head of the second list
    }
  }
};

int main() {
  LinkedList ll1, ll2;

  // create the first linked list
  ll1.InsertAtEnd(1);
  ll1.InsertAtEnd(2);
  ll1.InsertAtEnd(3);

  // create the second linked list
  ll2.InsertAtEnd(4);
  ll2.InsertAtEnd(5);
  ll2.InsertAtEnd(6);

  ll1.Concatenate(
      ll2); // concatenate the second linked list to the first linked list

  return 0;
}
