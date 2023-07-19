#include <iostream>

using namespace std;

// CircularQueue represents a dynamic circular queue data structure.
class CircularQueue {
private:
    int size_;  // Size of the circular queue.
    int front_;  // Index of the front item in the queue.
    int rear_;  // Index of the rear item in the queue.
    int* queue_;  // Pointer to the dynamically allocated array representing the queue.

public:
    // The constructor initializes the queue with the provided size.
    CircularQueue(int size);

    // The destructor frees up the dynamically allocated memory.
    ~CircularQueue();

    // Checks if the queue is full. Returns true if full, false otherwise.
    bool IsFull();

    // Checks if the queue is empty. Returns true if empty, false otherwise.
    bool IsEmpty();

    // Adds an item to the rear of the queue.
    void Enqueue(int x);

    // Removes an item from the front of the queue and returns it.
    int Dequeue();

    // Displays all the items in the queue from front to rear.
    void Display();
};

CircularQueue::CircularQueue(int size) {
    this->size_ = size;
    front_ = 0;
    rear_ = 0;
    queue_ = new int [size];
}

CircularQueue::~CircularQueue() {
    delete [] queue_;
}

bool CircularQueue::IsEmpty() {
    // front_ equals rear_ in the case where the queue is empty.
    if (front_ == rear_){
        return true;
    }
    return false;
}

bool CircularQueue::IsFull() {
    // In a circular queue, the queue is full when the next slot pointed by `rear_`
    // (considering wrapping around to the beginning if it's at the end) is the `front_`.
    if ((rear_ + 1) % size_ == front_){
        return true;
    }
    return false;
}

// If the queue is not full, this method adds an item to the rear of the queue.
void CircularQueue::Enqueue(int x) {
    if (IsFull()){
        cout << "Queue Overflow" << endl;
    } else {
        // `rear_` is moved to the next slot (wrapping around to the beginning if necessary)
        // before adding the new item.
        rear_ = (rear_ + 1) % size_;
        queue_[rear_] = x;
    }
}

// If the queue is not empty, this method removes an item from the front of the queue and returns it.
int CircularQueue::Dequeue() {
    int x = -1;
    if (IsEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        // `front_` is moved to the next item (wrapping around to the beginning if necessary)
        // before removing the item.
        front_ = (front_ + 1) % size_;
        x = queue_[front_];
    }
    return x;
}

// This method prints all the elements in the queue from the front to the rear.
void CircularQueue::Display() {
    // Start at the slot after `front_` (wrapping around to the beginning if necessary)
    // and go up to `rear_`.
    int i = front_ + 1;
    do {
        cout << queue_[i] << flush;
        if (i < rear_) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size_;
    } while (i != (rear_ + 1) % size_);
}

// The main function demonstrates the functionality of the CircularQueue class.
int main() {
    // An array of test items to enqueue to the circular queue.
    int array_elements[] = {1, 3, 5, 7, 9};

    // Create a CircularQueue object.
    CircularQueue circular_queue(sizeof(array_elements)/sizeof(array_elements[0]) + 1);

    // Enqueue each element from the test array into the queue.
    for (int i = 0; i < sizeof(array_elements)/sizeof(array_elements[0]); i++){
        circular_queue.Enqueue(array_elements[i]);
    }

    // Display the queue after enqueuing items.
    circular_queue.Display();
    cout << endl;

    // Try to enqueue one more item. This should cause an overflow because the queue is already full.
    circular_queue.Enqueue(10);

    // Dequeue all items from the queue.
    for (int i = 0; i < sizeof(array_elements)/sizeof(array_elements[0]); i++){
        circular_queue.Dequeue();
    }

    // Try to dequeue one more item. This should cause an underflow because the queue is already empty.
    circular_queue.Dequeue();

    return 0;
}
