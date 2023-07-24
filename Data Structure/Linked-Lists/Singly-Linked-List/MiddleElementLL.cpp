#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

// Declare a class for each node in the linked list.
class Node {
 public:
  int data;
  Node* next;
};

// The head of the list.
Node* head = new Node;

// Function to create a linked list from an array of integers.
void create(int A[], int n) {
  Node* temp;
  Node* tail;

  // Initialize head node.
  head->data = A[0];
  head->next = nullptr;
  tail = head;

  // Loop over array to add elements into linked list.
  for (int i = 1; i < n; i++) {
    temp = new Node;
    temp->data = A[i];
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
  }
}

// Method 1: Traverse the list to find its length, then locate the middle node.
void middleNode1(Node* p) {
  int length = 0;

  // Compute the length of linked list.
  while (p) {
    length++;
    p = p->next;
  }

  // Compute the index of middle element.
  int index = static_cast<int>(ceil(length / 2.0));

  // Traverse to the middle element.
  Node* q = head;
  for (int i = 0; i < index - 1; i++) {
    q = q->next;
  }
  cout << "Middle Element (Method-I): " << q->data << endl;
}

// Method 2: Two-pointer technique to find the middle node in one pass.
void middleNode2(Node* p) {
  Node* q = p;
  while (q) {
    q = q->next;
    if (q) {
      q = q->next;
    }
    if (q) {
      p = p->next;
    }
  }
  cout << "Middle Element (Method-II): " << p->data << endl;
}

// Method 3: Use a stack to find the middle node.
void middleNode3(Node* p) {
  stack<Node*> s;
  
  // Push all nodes to the stack.
  while (p) {
    s.push(p);
    p = p->next;
  }

  int length = s.size();

  // Calculate how many elements to pop to reach the middle.
  int popLength = static_cast<int>(floor(length / 2.0));

  // Pop elements until the middle is reached.
  while (popLength) {
    s.pop();
    popLength--;
  }
  cout << "Middle Element (Method-III): " << s.top()->data << endl;
}

int main() {
  // Create linked list from array.
  int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
  create(A, sizeof(A) / sizeof(A[0]));

  cout << endl;
  
  // Call all three methods to find the middle element.
  middleNode1(head);
  middleNode2(head);
  middleNode3(head);

  return 0;
}

/* 
1. `middleNode1`: This method computes the length of the list, then traverses to the middle node. This involves traversing the list twice, so the time complexity is O(2N), which simplifies to O(N), where N is the length of the list.

2. `middleNode2`: This method uses the two-pointer technique to find the middle node in one pass. One pointer (p) moves one step at a time, and the other pointer (q) moves two steps at a time. By the time the fast pointer reaches the end of the list, the slow pointer will be at the middle. This method has a time complexity of O(N).

3. `middleNode3`: This method uses a stack to store all nodes, then pops nodes from the stack until it reaches the middle node. This method also has a time complexity of O(N), but it uses additional space to store the nodes in the stack. */