#include <iostream>
#include <list>

class CircularQueue {
 private:
  std::list<int> lst;  // STL list to store queue elements
  int size_;  // Maximum size of the queue
  int count_;  // Current count of elements in the queue

 public:
  // Constructor to initialize queue
  CircularQueue(int size) : size_(size), count_(0) {}

  // Function to insert a new element into the queue
  void Enqueue(int value) {
    // Check if the queue is full
    if (count_ == size_) {
      std::cout << "Queue is full\n";
      return;
    }

    // Insert the new element into the queue and increase the count
    lst.push_back(value);
    count_++;
  }

  // Function to remove an element from the queue
  void Dequeue() {
    // Check if the queue is empty
    if (count_ == 0) {
      std::cout << "Queue is empty\n";
      return;
    }

    // Remove the element from the front of the queue and decrease the count
    lst.pop_front();
    count_--;
  }

  // Function to display the elements in the queue
  void Display() {
    // Check if the queue is empty
    if (count_ == 0) {
      std::cout << "Queue is empty\n";
      return;
    }

    // Print the elements in the queue
    for (const int &i : lst) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
};

int main() {
  // Create a queue with maximum size 3
  CircularQueue queue(3);

  // Add elements to the queue
  queue.Enqueue(10);
  queue.Enqueue(20);
  queue.Enqueue(30);

  // Display the queue
  queue.Display();  // Prints: 10 20 30

  // Remove an element from the queue
  queue.Dequeue();

  // Display the queue again
  queue.Display();  // Prints: 20 30

  return 0;
}
