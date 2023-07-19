#include<iostream>

// Node structure for linked list
struct Node {
  int data;  // The integer value stored in this node
  Node* next;  // Pointer to the next node in the list, used to link nodes together
};

class CircularQueue {
 private:
  Node* front_;  // Pointer to the front of the queue, used to remove elements
  Node* rear_;  // Pointer to the rear of the queue, used to add elements

 public:
  // Constructor: Initializes an empty queue
  CircularQueue() : front_(nullptr), rear_(nullptr) {}

  // Destructor: Deallocates memory by deleting all nodes in the queue
  ~CircularQueue() {
    while (front_) {
      rear_ = front_->next;  // Temporarily save the next node
      delete front_;  // Delete the front node
      front_ = rear_;  // Move to the next node
    }
  }

  // Adds a new element to the end of the queue
  void Enqueue(int value) {
    Node* new_node = new Node;  // Allocate a new node on the heap
    if (new_node == nullptr) {
      std::cout << "Queue is full\n";
    } else {
      new_node->data = value;  // Assign the provided value to the new node
      new_node->next = nullptr;  // Initialize the next pointer to null
      if (front_ == nullptr) {
        // If the queue is empty, the new node is both the front and rear
        front_ = rear_ = new_node;
      } else {
        // Otherwise, add the new node to the end and update the rear pointer
        rear_->next = new_node;
        rear_ = new_node;
      }
      rear_->next = front_;  // To make the queue circular, point the rear to the front
    }
  }

  // Removes an element from the front of the queue
  void Dequeue() {
    if (front_ == nullptr) {
      std::cout << "Queue is empty\n";
    } else {
      Node* temp_node;  // Temporary pointer to the node being removed
      if (front_ == rear_) {
        // If the queue only has one element, delete it and reset pointers to null
        temp_node = front_;
        front_ = rear_ = nullptr;
        delete temp_node;
      } else {
        // Otherwise, save the front node, move the front pointer forward,
        // and delete the old front node
        temp_node = front_;
        front_ = front_->next;
        rear_->next = front_;  // Update rear's next to the new front
        delete temp_node;
      }
    }
  }

  // Prints all elements in the queue from front to rear
  void Display() {
    Node* temp_node = front_;  // Temporary node used for traversing the queue
    if (front_ == nullptr && rear_ == nullptr) {
      std::cout << "Queue is empty\n";
    } else {
      // Loop through the queue until we've returned to the front
      do {
        std::cout << temp_node->data << " ";  // Print the value at the current node
        temp_node = temp_node->next;  // Move to the next node
      } while (temp_node != front_);
    }
    std::cout << "\n";
  }
};

int main() {
  CircularQueue queue;  // Instantiate a new CircularQueue object
  queue.Enqueue(10);  // Add 10 to the queue
  queue.Enqueue(20);  // Add 20 to the queue
  queue.Enqueue(30);  // Add 30 to the queue
  queue.Display();  // Print the queue: should display "10 20 30"
  queue.Dequeue();  // Remove the front of the queue: 10
  queue.Display();  // Print the queue: should display "20 30"
  return 0;
}
