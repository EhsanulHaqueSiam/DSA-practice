#include <iostream>

using std::cout;
using std::endl;

class Node {
 public:
  Node* prev;
  int data;
  Node* next;
};

class DoublyLinkedList {
 private:
  Node* head;

 public:
  // Default constructor
  DoublyLinkedList();

  // Constructor creating list from array
  DoublyLinkedList(int A[], int n);

  // Destructor to clean up memory
  ~DoublyLinkedList();

  // Display the list
  void Display();

  // Calculate the length of the list
  int Length();

  // Insert data at a specific index in the list
  void Insert(int index, int x);

  // Delete node at specific index from the list
  int Delete(int index);

  // Reverse the list
  void Reverse();
};

DoublyLinkedList::DoublyLinkedList() {
  head = new Node;
  head->prev = nullptr;
  head->data = 0;
  head->next = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int *A, int n) {
  head = new Node;
  head->prev = nullptr;
  head->data = A[0];
  head->next = nullptr;

  Node* tail = head;

  // Iterating through the array and adding elements to the list
  for (int i = 1; i < n; i++){
    Node* t = new Node;
    t->prev = tail;
    t->data = A[i];
    t->next = tail->next; // tail->next is pointing to NULL
    tail->next = t;
    tail = t;
  }
}

void DoublyLinkedList::Display() {
  Node* p = head;
  // Iterate through the list and print elements
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int DoublyLinkedList::Length() {
  Node* p = head;
  int length = 0;

  // Iterate through the list to count nodes
  while (p != nullptr) {
    length++;
    p = p->next;
  }
  return length;
}

void DoublyLinkedList::Insert(int index, int x) {
  Node* p = head;

  // Checking for valid index
  if (index < 0 || index > Length()) {
    return;
  }

  Node* t = new Node;
  t->data = x;

  // Inserting at the start of the list
  if (index == 0) {
    t->prev = nullptr;
    t->next = head;
    head->prev = t;
    head = t;
  } else {
    // Iterate to the index where we need to insert
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    t->prev = p;
    t->next = p->next;

    // Adjusting previous node of the next node if it exists
    if (p->next) {
      p->next->prev = t;
    }
    p->next = t;
  }
}

int DoublyLinkedList::Delete(int index) {
  Node* p = head;
  int x = -1;

  // Checking for valid index
  if (index <= 0 || index > Length()) {
    return x;
  }

  // Deleting the first node
  if (index == 1) {
    head = head->next;
    if (head) {
      head->prev = nullptr;
    }
    x = p->data;
    delete p;
  } else {
    // Iterate to the index of node to be deleted
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    p->prev->next = p->next;
    if (p->next) {
      p->next->prev = p->prev;
    }
    x = p->data;
    delete p;
  }
  return x;
}

void DoublyLinkedList::Reverse() {
  Node* p = head;
  Node* temp;

  // Swapping previous and next for all nodes of doubly linked list
  while (p != nullptr) {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;

    // Moving to next node which is stored in temp
    p = p->prev;

    // Change head if we are at end of the list
    if (p != nullptr && p->next == nullptr) {
      head = p;
    }
  }
}

DoublyLinkedList::~DoublyLinkedList() {
  Node* p = head;

  // Deleting all nodes one by one from the start
  while (head) {
    head = head->next;
    delete p;
    p = head;
  }
}

int main() {
  int A[] = {1, 3, 5, 7, 9};

  DoublyLinkedList dll(A, sizeof(A) / sizeof(A[0]));

  dll.Display();
  dll.Insert(0, 11);
  dll.Insert(6, 13);
  dll.Display();

  dll.Delete(1);
  dll.Delete(6);
  dll.Display();

  dll.Reverse();
  dll.Display();

  return 0;
}
