#include <iostream>

// Node class represents a node in a doubly circular linked list.
// It contains an integer data, and pointers to the previous and next nodes.
class Node {
 public:
  explicit Node(int val) 
      : data(val), next(nullptr), prev(nullptr) {}

  int data;
  Node* next;
  Node* prev;
};

// DoubleCircularLinkedList represents a doubly circular linked list.
// It mainly contains a pointer to the head node.
class DoubleCircularLinkedList {
 public:
  DoubleCircularLinkedList() : head(nullptr) {}

  // Creates a doubly circular linked list from the given array.
  void CreateList(const int arr[], int size);

  // Returns the length of the list.
  int Length() const;

  // Inserts a new node with given data at the given position.
  void Insert(int data, int position);

  // Deletes a node at the given position.
  void Delete(int position);

  // Displays the list iteratively.
  void DisplayIteratively() const;

  // Displays the list recursively.
  void DisplayRecursively() const;

 private:
  Node* head;

  // Recursive helper for the DisplayRecursively function.
  void DisplayRecursivelyHelper(Node* start, Node* node) const;
};

void DoubleCircularLinkedList::CreateList(const int arr[], int size) {
  if (size == 0) return;

  // Create head node separately.
  head = new Node(arr[0]);
  head->next = head;
  head->prev = head;

  // Create the rest of the list.
  Node* temp = head;
  for (int i = 1; i < size; ++i) {
    Node* new_node = new Node(arr[i]);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
    temp = temp->next;
  }
}

int DoubleCircularLinkedList::Length() const {
  Node* temp = head;
  int length = 0;

  if (head) {
    do {
      ++length;
      temp = temp->next;
    } while (temp != head);
  }

  return length;
}

void DoubleCircularLinkedList::Insert(int data, int position) {
  if (position < 0 || position > Length()) {
    return;
  }

  Node* temp = new Node(data);
  Node* ptr = head;

  if (position == 0) {
    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    head = temp;
  } else {
    for (int i = 0; i < position - 1; ++i) {
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp;
    ptr->next = temp;
  }
}

void DoubleCircularLinkedList::Delete(int position) {
  if (position < 0 || position >= Length()) {
    return;
  }

  Node* temp = head;
  if (position == 0) {
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
  } else {
    for (int i = 0; i < position; ++i) {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }
  delete temp;
}

void DoubleCircularLinkedList::DisplayIteratively() const {
  Node* temp = head;

  if (head) {
    do {
      std::cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
  }

  std::cout << "\n";
}

void DoubleCircularLinkedList::DisplayRecursively() const {
  if (head) {
    DisplayRecursivelyHelper(head, head);
  }
  std::cout << "\n";
}

void DoubleCircularLinkedList::DisplayRecursivelyHelper(Node* start, Node* node) const {
  if (node == start && node != head) {
    return;
  }
  std::cout << node->data << " ";
  DisplayRecursivelyHelper(start, node->next);
}

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
