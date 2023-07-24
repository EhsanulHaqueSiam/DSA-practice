#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

class Node {
 public:
  int data;
  Node* next;
};

// Initialize head pointers for two lists
Node* head1 = new Node;
Node* head2 = new Node;

// Function to create a linked list from an array
void CreateList(Node* &head, int A[], int n) {
  Node* temp;
  Node* tail;

  head->data = A[0];
  head->next = nullptr;
  tail = head;

  // Iterating through the array and adding elements to the list
  for (int i = 1; i < n; i++) {
    temp = new Node;
    temp->data = A[i];
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
  }
}

// Function to create a second linked list which intersects the first one
void CreateIntersectedList(Node* &head, int A[], int n, Node* intersect_at) {
  Node* temp;
  Node* tail;

  head->data = A[0];
  head->next = nullptr;
  tail = head;

  // Adding elements to the list
  for (int i = 1; i < n; i++) {
    temp = new Node;
    temp->data = A[i];
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
  }

  // Connecting last node of the second list to the first list
  tail->next = intersect_at;
}

// Function to find the intersection point of two lists
void FindIntersection(Node* head1, Node* head2) {
  // Stacks to store the nodes of the lists
  stack<Node*> stack1, stack2;

  // Adding nodes of first list to the stack
  while (head1 != nullptr) {
    stack1.push(head1);
    head1 = head1->next;
  }

  // Adding nodes of second list to the stack
  while (head2 != nullptr) {
    stack2.push(head2);
    head2 = head2->next;
  }

  Node* intersection_point = nullptr;

  // Finding the intersection point by comparing the nodes
  while (!stack1.empty() && !stack2.empty() && stack1.top() == stack2.top()) {
    intersection_point = stack1.top();
    stack1.pop();
    stack2.pop();
  }

  cout << "Intersection point: " << intersection_point->data << endl;
}

int main() {
  // Creating the first linked list
  int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  CreateList(head1, A, sizeof(A) / sizeof(A[0]));

  // Finding the node where we want to intersect the second list
  Node* temp = head1;
  for (int i = 0; i < 5; i++) {
    temp = temp->next;
  }

  // Creating the second list which intersects the first one
  int B[] = {2, 4, 6, 8, 10};
  CreateIntersectedList(head2, B, sizeof(B) / sizeof(B[0]), temp);

  // Finding the intersection point of two lists
  FindIntersection(head1, head2);

  return 0;
}
