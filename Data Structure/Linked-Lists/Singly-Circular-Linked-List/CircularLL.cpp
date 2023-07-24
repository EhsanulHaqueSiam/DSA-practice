#include <iostream>

using std::cout;
using std::endl;
using std::flush;

// Node class
class Node {
 public:
  int data;
  Node* next;
};

// CircularLinkedList class
class CircularLinkedList {
 private:
  Node* head;

 public:
  // Constructor
  CircularLinkedList(int A[], int n);
  // Function to display the linked list
  void Display();
  // Function to display the linked list recursively
  void RecursiveDisplay(Node* p);
  // Getter for the head of the linked list
  Node* GetHead() { return head; }
  // Destructor
  ~CircularLinkedList();
};

// Constructor
// Creates a circular linked list from the array
CircularLinkedList::CircularLinkedList(int *A, int n) {
  Node* t;
  Node* tail;

  head = new Node;
  head->data = A[0];
  head->next = head;
  tail = head;

  // Iterate through the array and add each element to the list
  for (int i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = tail->next;
    tail->next = t;
    tail = t;
  }
}

// Display
// Iterates through the circular linked list and prints each element
void CircularLinkedList::Display() {
  Node* p = head;
  do {
    cout << p->data << " -> " << flush;
    p = p->next;
  } while (p != head);
  cout << endl;
}

// RecursiveDisplay
// Recursively traverses through the circular linked list and prints each element
void CircularLinkedList::RecursiveDisplay(Node *p) {
  static int flag = 0;
  if (p != head || flag == 0) {
    flag = 1;
    cout << p->data << " -> " << flush;
    RecursiveDisplay(p->next);
  }
  flag = 0;
}

// Destructor
// Deletes all the nodes in the circular linked list
CircularLinkedList::~CircularLinkedList() {
  Node* p = head;
  // Find the last node
  while (p->next != head){
    p = p->next;
  }

  // Start deleting the nodes from the beginning
  while (p != head) {
    p->next = head->next;
    delete head;
    head = p->next;
  }

  // Delete the last node
  if (p == head) {
    delete head;
    head = nullptr;
  }
}

int main() {
  int A[] = {1, 3, 5, 7, 9};

  CircularLinkedList cl(A, sizeof(A) / sizeof(A[0]));

  cl.Display();

  Node* h = cl.GetHead();
  cl.RecursiveDisplay(h);

  return 0;
}
