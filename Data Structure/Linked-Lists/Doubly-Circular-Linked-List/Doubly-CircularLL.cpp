#include <iostream>

class Node {
public:
  int data;
  Node* next;
  Node* prev;

  Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class DoubleCircularLinkedList {
public:
  Node* head;

  DoubleCircularLinkedList() { 
    head = nullptr; 
  }

  // Function to create list with array elements
  void CreateList(int arr[], int size) {
    Node *temp, *new_node;
    int i;

    if (size == 0) return;

    // Create head node separately
    head = new Node(arr[0]);
    head->next = head;
    head->prev = head;

    // Create the rest of the list
    temp = head;
    for (i = 1; i < size; i++) {
      new_node = new Node(arr[i]);
      new_node->next = temp->next;
      new_node->prev = temp;
      temp->next->prev = new_node;
      temp->next = new_node;
      temp = temp->next;
    }
  }

  // Function to get length of the list
  int Length() {
    Node* temp = head;
    int length = 0;

    if (head != nullptr) {
      do {
        length++;
        temp = temp->next;
      } while (temp != head);
    }

    return length;
  }

  // Function to insert node at a given position
  void Insert(int data, int position) {
    Node* temp = new Node(data);
    Node* ptr = head;
    int i;

    if (position < 0 || position > Length()) {
      return;
    }

    if (position == 0) {
      temp->next = head;
      temp->prev = head->prev;
      head->prev->next = temp;
      head->prev = temp;
      head = temp;
    } else {
      for (i = 0; i < position - 1; i++) {
        ptr = ptr->next;
      }
      temp->next = ptr->next;
      temp->prev = ptr;
      ptr->next->prev = temp;
      ptr->next = temp;
    }
  }

  // Function to delete node at a given position
  void Delete(int position) {
    Node* temp;
    int i;

    if (position < 0 || position >= Length()) {
      return;
    }

    if (position == 0) {
      temp = head;
      head->prev->next = head->next;
      head->next->prev = head->prev;
      head = head->next;
    } else {
      temp = head;
      for (i = 0; i < position; i++) {
        temp = temp->next;
      }
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
    delete temp;
  }

  // Function to display list iteratively
  void DisplayIteratively() {
    Node* temp = head;

    if (head != nullptr) {
      do {
        std::cout << temp->data << " ";
        temp = temp->next;
      } while (temp != head);
    }

    std::cout << "\n";
  }

  // Helper function to display list recursively
  void DisplayRecursivelyHelper(Node* start, Node* node) {
    if (node == start && node != head) {
      return;
    }
    std::cout << node->data << " ";
    DisplayRecursivelyHelper(start, node->next);
  }

  // Function to display list recursively
  void DisplayRecursively() {
    if (head != nullptr) {
      DisplayRecursivelyHelper(head, head);
    }
    std::cout << "\n";
  }
};

int main() {
  DoubleCircularLinkedList list;
  int arr[] = {10, 20, 30, 40, 50};
  list.CreateList(arr, 5);

  std::cout << "Original List: ";
  list.DisplayIteratively();

  list.Insert(25, 3);
  std::cout << "List after inserting 25 at position 3: ";
  list.DisplayIteratively();

  list.Delete(1);
  std::cout << "List after deleting node at position 1: ";
  list.DisplayIteratively();

  std::cout << "List displayed recursively: ";
  list.DisplayRecursively();

  return 0;
}
