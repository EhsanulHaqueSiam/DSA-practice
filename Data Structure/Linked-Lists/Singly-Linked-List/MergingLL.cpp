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

  // Function to insert a node at the end of the linked list
  void InsertAtEnd(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr) {
      head = new_node;
    } else {
      Node *last_node = head;
      while (last_node->next != nullptr) {
        last_node = last_node->next;
      }
      last_node->next = new_node;
    }
  }

  // Function to merge the current linked list with another linked list
  // The two linked lists must be sorted in non-decreasing order
  void Merge(LinkedList other) {
    Node *first = this->head;
    Node *second = other.head;

    // Creating a dummy node to store the result
    Node *dummy_node = new Node;

    // last stores the last node
    Node *last = dummy_node;

    // Compare and merge nodes from the two linked lists to the result linked
    // list
    while (true) {
      // If any list is empty
      if (first == nullptr) {
        // If both lists are empty
        if (second == nullptr) {
          break;
        }
        // If only the first list is empty, attach all nodes of second list to
        // the result list
        last->next = second;
        break;
      } else if (second == nullptr) {
        // If only the second list is empty, attach all nodes of first list to
        // the result list
        last->next = first;
        break;
      }

      // Compare data of the nodes in the two lists and add the node with
      // smaller data to the result list
      if (first->data <= second->data) {
        last->next = first;
        first = first->next;
      } else {
        last->next = second;
        second = second->next;
      }

      // Update the last node
      last = last->next;
    }

    // The merged linked list is stored in the next of the dummy node
    this->head = dummy_node->next;
  }

  // Function to display the linked list
  void Display() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList ll1, ll2;

  // Create the first sorted linked list: 1 -> 3 -> 5
  ll1.InsertAtEnd(1);
  ll1.InsertAtEnd(3);
  ll1.InsertAtEnd(5);

  // Create the second sorted linked list: 2 -> 4 -> 6
  ll2.InsertAtEnd(2);
  ll2.InsertAtEnd(4);
  ll2.InsertAtEnd(6);

  // Merge the two sorted linked lists: 1 -> 2 -> 3 -> 4 -> 5 -> 6
  ll1.Merge(ll2);

  // Display the merged sorted linked list
  ll1.Display();

  return 0;
}
