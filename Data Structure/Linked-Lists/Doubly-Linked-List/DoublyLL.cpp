#include <iostream>

// Doubly linked list node
class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  // Node constructor
  Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
 public:
  Node* head;

  // Constructor creates an empty list
  DoublyLinkedList() { head = nullptr; }

  // Creates a doubly linked list with elements from an array
  void CreateWithArrayElements(const int arr[], int size) {
    Node* last = nullptr;
    Node* temp = nullptr;

    head = new Node(arr[0]);
    last = head;

    for (int i = 1; i < size; ++i) {
      temp = new Node(arr[i]);
      temp->prev = last;
      last->next = temp;
      last = temp;
    }
  }

  // Inserts a node at a given position
  void Insert(int data, int position) {
    Node* temp = new Node(data);
    Node* ptr = head;

    // Special case for head end
    if (position == 0) {
      temp->next = head;
      if (head != nullptr) head->prev = temp;
      head = temp;
      return;
    }

    // Locate the node before the point of insertion
    for (int i = 0; ptr != nullptr && i < position - 1; i++) {
      ptr = ptr->next;
    }

    // Check if node is not null
    if (ptr == nullptr) {
      std::cout << "Position is greater than the length of the list\n";
      return;
    }

    // Insert node
    temp->next = ptr->next;
    temp->prev = ptr;

    if (ptr->next != nullptr) {
      ptr->next->prev = temp;
    }
    ptr->next = temp;
  }

  // Display list iteratively
  void DisplayIteratively() {
    Node* temp = head;

    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }

  // Recursive function to display list
  void DisplayRecursively(Node* node) {
    if (!node) {
      std::cout << std::endl;
      return;
    }
    std::cout << node->data << " ";
    DisplayRecursively(node->next);
  }

  // Length of list
  int Length() {
    Node* temp = head;
    int length = 0;

    while (temp) {
      length++;
      temp = temp->next;
    }
    return length;
  }
};

int main() {
  DoublyLinkedList list;

  int arr[] = {10, 20, 30, 40, 50};
  list.CreateWithArrayElements(arr, 5);

  std::cout << "Display list iteratively: ";
  list.DisplayIteratively();

  std::cout << "Display list recursively: ";
  list.DisplayRecursively(list.head);

  std::cout << "Length of list: " << list.Length() << std::endl;

  list.Insert(25, 2);

  std::cout << "After insertion: ";
  list.DisplayIteratively();

  return 0;
}
