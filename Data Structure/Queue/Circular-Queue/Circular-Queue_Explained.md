# Circular Queue: An In-Depth Exploration

## Introduction
A circular queue, often referred to as a 'Ring Buffer', is an advanced version of the standard queue data structure. The defining characteristic of a circular queue is that it forms a circular link, with the last element pointing to the first element. This unique feature allows for efficient memory utilization, as it enables the insertion of an element in the first position when the last position is full and the first position is empty - a scenario that a standard queue cannot handle. Like a standard queue, a circular queue operates based on the FIFO (First In First Out) principle.

## Table of Contents
1. [Introduction](#introduction)
2. [The Concept of a Circular Queue](#the-concept-of-a-circular-queue)
3. [Operations on a Circular Queue](#operations-on-a-circular-queue)
4. [Understanding Circular Queue Operations through GIFs](#understanding-circular-queue-operations-through-gifs)
5. [Implementing a Circular Queue](#implementing-a-circular-queue)
6. [Pseudocode for Circular Queue Operations](#pseudocode-for-circular-queue-operations)
7. [Code Breakdown](#code-breakdown)
8. [Why is a Circular Queue Needed?](#why-is-a-circular-queue-needed)
9. [Optimizing Circular Queue](#optimizing-circular-queue)
10. [Related Data structures](#related-data-structures)
11. [Applications of Circular Queue](#applications-of-circular-queue)
12. [Useful Sites](#useful-sites)

## The Concept of a Circular Queue
In a circular queue, the addition (enqueue) and removal (dequeue) of elements occur at the rear (end) and front of the queue, respectively. The last element points to the first, giving the queue its circular structure. This circularity helps prevent the wastage of space that can occur in a regular queue implementation using arrays, particularly when elements are frequently added and removed.

## Operations on a Circular Queue
The operations performed on a circular queue include:

- **Front**: Retrieves the front item from the queue.
- **Rear**: Retrieves the last item from the queue.
- **Enqueue**: This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at the rear position. If the queue is full, it displays "Queue is full". If the queue is not full, it inserts an element at the end of the queue.
- **Dequeue**: This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from the front position. If the queue is empty, it displays "Queue is empty". If the queue is not empty, it retrieves the last element and removes it from the queue.

## Understanding Circular Queue Operations through GIFs
Visualizing the operations of a circular queue can be beneficial in understanding its functionality. The process of enqueuing and dequeing in a circular queue can be understood by visualizing the elements in the queue and how the front and rear pointers move in a circular motion. This visualization can help in understanding how the queue maintains its circular structure and how it manages memory more efficiently than a simple queue.

![Circular Queue](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)

The first GIF you provided is an animation of a circular buffer, also known as a circular queue or ring buffer. It's a data structure that uses a single, fixed-size buffer as if it were connected end-to-end. This structure is used in computer science to store multiple items of the same type.

In the animation, you can see that the buffer has a limited size, and when it's full, the oldest item is overwritten by the new one. The "head" of the queue is the point where new data is written, and the "tail" is where data is read. When the head reaches the end of the buffer, it wraps around to the beginning, hence the term "circular" buffer.

Let's move on to the next GIF.

![Circular Queue](https://i1.faceprep.in/Companies-1/circular-queue-implementation.gif)

The second GIF demonstrates the operations of a circular queue. The operations include:

Enqueue: This operation adds an element to the end of the queue. If the queue is full, it will display an error or overwrite the oldest data, depending on the implementation.

Dequeue: This operation removes an element from the front of the queue. If the queue is empty, it will display an error.

IsEmpty: This operation checks if the queue is empty.

IsFull: This operation checks if the queue is full.

Peek/Front: This operation gets the front item from queue.

Rear: This operation gets the last item from queue.

In the GIF, you can see the enqueue operation adding elements to the queue, and the dequeue operation removing them. When the end of the queue is reached, the enqueue operation starts adding elements from the beginning of the queue, hence making it a circular queue.

Let's proceed to the next GIF.

![Circular Queue](https://thealgoristsblob.blob.core.windows.net/thealgoristsimages/circular-buffer-ring-buffer-animation%20(1).gif)

The third GIF illustrates the concept of a circular buffer or ring buffer, which is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end. This structure lends itself easily to buffering data streams.

The GIF shows the following operations:

Write: This operation writes data into the buffer. If the buffer is full, it either overwrites the oldest data or returns an error, depending on the implementation.

Read: This operation reads data from the buffer. If the buffer is empty, it returns an error.

The GIF demonstrates how the write pointer moves around the buffer, writing data, and how the read pointer follows it, reading the data. When the write pointer reaches the end of the buffer, it wraps around to the beginning, hence making it a circular buffer.

Let's move on to the last GIF.

![Circular Queue](https://images.velog.io/images/llama/post/02da1f3c-fc3b-41d5-bc74-7c37da489b66/ezgif.com-gif-maker%20(5).gif)

The fourth GIF is another representation of a circular queue or circular buffer. It shows the following operations:

Enqueue (Push): This operation adds an element to the end of the queue. If the queue is full, it returns an error or overwrites the oldest data, depending on the implementation.

Dequeue (Pop): This operation removes an element from the front of the queue. If the queue is empty, it returns an error.

The GIF demonstrates how the enqueue and dequeue operations work in a circular queue. When the end of the queue is reached, the next element to be enqueued is placed at the beginning of the queue, making it circular. Similarly, the dequeue operation can remove elements from the front of the queue and when it reaches the end, it wraps around to the beginning.

In all these GIFs, the key concept is that a circular queue is a type of data structure where the end of the queue is connected to the beginning, making it appear as a circle. It is an efficient way of using a queue when the size is fixed, as it does not need to have any elements shifted, like in a normal queue or stack.

## Implementing a Circular Queue
A circular queue can be implemented using two data structures: an array or a linked list. The array implementation is simpler and more common. The array holds the elements of the queue, and two pointers, front and rear, point to the start and end of the queue. When we add an element, the rear pointer is incremented, and when we remove an element, the front pointer is incremented. If the pointers reach the end of the array, they will continue from the start of the array, hence the name "circular" queue.

## Pseudocode for Circular Queue Operations
Here's the pseudocode for the operations on a circular queue:

#### Enqueue Operation
```
function enqueue(data)
    if ((rear + 1) mod size == front) then
        return "Queue is Full"
    else if (queue is empty) then
        front <- rear <- 0
    else if (rear == size - 1 and front != 0) then
        rear <- 0
    else
        rear <- rear + 1
    end if
    queue[rear] <- data
end function
```

#### Dequeue Operation
```
function dequeue()
    if (front == -1) then
        return "Queue is Empty"
    else
        data <- queue[front]
        if (front == rear) then
            front <- rear <- -1
        else if (front == size - 1) then
            front <- 0
        else
            front <- front + 1
        end if
        return data
    end if
end function
```

#### IsEmpty Operation
```
function isEmpty()
    if (front == -1) then
        return true
    else
        return false
    end if
end function
```

#### IsFull Operation
```
function isFull()
    if ((rear + 1) mod size == front) then
        return true
    else
        return false
    end if
end function
```

#### Display Elements
```
function displayQueue()
    if (front == -1) then
        print "Queue is empty"
    else
        i <- front
        while (i != rear) do
            print queue[i]
            i <- (i + 1) mod size
        end while
        print queue[rear]
    end if
end function
```

## Code Breakdown

A circular queue is a linear data structure that follows the First In First Out (FIFO) principle. The difference between a standard queue and a circular queue is that the last element points to the first element making a circular link.

In this article, we're going to break down the provided C++ code that implements a circular queue.

### Class Definition

```cpp
class CircularQueue {
private:
    int size_;  // Size of the circular queue.
    int front_;  // Index of the front item in the queue.
    int rear_;  // Index of the rear item in the queue.
    int* queue_;  // Pointer to the dynamically allocated array representing the queue.
...
};
```

The `CircularQueue` class contains four private members: `size_`, `front_`, `rear_`, and `queue_`. `size_` keeps track of the size of the queue, `front_` and `rear_` hold the index of the front and rear items of the queue respectively, and `queue_` is a pointer to the dynamically allocated array representing the queue.

### Constructor and Destructor

```cpp
CircularQueue::CircularQueue(int size) {
    this->size_ = size;
    front_ = 0;
    rear_ = 0;
    queue_ = new int [size];
}

CircularQueue::~CircularQueue() {
    delete [] queue_;
}
```

The constructor `CircularQueue::CircularQueue(int size)` initializes the size of the queue and the indices of the front and rear items, and allocates memory for the queue. The destructor `CircularQueue::~CircularQueue()` releases the memory that was allocated for the queue when the object is destroyed, to prevent memory leaks.

### Queue Operations

The main operations available on the queue are `IsEmpty()`, `IsFull()`, `Enqueue(int x)`, `Dequeue()`, and `Display()`.

```cpp
bool CircularQueue::IsEmpty() {
    if (front_ == rear_){
        return true;
    }
    return false;
}
```

The `IsEmpty()` function checks if the queue is empty by comparing the front and rear indices. If they're equal, the queue is empty, and it returns true.

```cpp
bool CircularQueue::IsFull() {
    if ((rear_ + 1) % size_ == front_){
        return true;
    }
    return false;
}
```

`IsFull()` checks if the queue is full by adding one to the rear index (mod the size of the queue) and comparing it to the front index. If they're equal, the queue is full, and the function returns true.

```cpp
void CircularQueue::Enqueue(int x) {
    if (IsFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear_ = (rear_ + 1) % size_;
        queue_[rear_] = x;
    }
}

int CircularQueue::Dequeue() {
    int x = -1;
    if (IsEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front_ = (front_ + 1) % size_;
        x = queue_[front_];
    }
    return x;
}
```

`Enqueue(int x)` adds an item to the rear of the queue if it's not full, while `Dequeue()` removes an item from the front of the queue if it's not empty.

```cpp
void CircularQueue::Display() {
    int i = front_ + 1;
    do {
        cout << queue_[i] << flush;
        if (i < rear_) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size_;
    } while (i != (rear_ + 1) % size_);
}
```

The `Display()` function prints all the elements in the queue from the front to the rear.

### Main Function

```cpp
int main() {
    int array_elements[] = {1, 3, 5, 7, 9};
    CircularQueue circular_queue(sizeof(array_elements)/sizeof(array_elements[0]) + 1);
    ...
    return 0;
}
```

The `main()` function demonstrates the functionality of the `CircularQueue` class. It creates a `CircularQueue` object and uses it to enqueue and dequeue items. It also handles overflow and underflow conditions.

## Why is a Circular Queue Needed?
A circular queue is needed in scenarios where memory utilization is a priority. In a standard queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. However, in a circular queue, the last element points to the first element, allowing for efficient use of memory. This makes a circular queue particularly useful in systems where memory is a limited resource.

## Optimizing Circular Queue
The circular queue can be optimized by using a linked list instead of an array. This eliminates the need to pre-define the size of the queue and allows it to grow and shrink as required. This can be particularly useful in scenarios where the size of the queue can vary significantly, and pre-defining a size would either waste memory or limit the number of elements that can be added to the queue.

## Related Data structures
Queue, Stack, Priority Queue, and Deque (Double Ended Queue) are some data structures that are related to the circular queue. All these data structures allow insertion and removal of elements, but the order of insertion and removal is different. Understanding these related data structures can provide a more comprehensive understanding of data structures and their uses.

## Applications of Circular Queue
Circular queues are used in memory management, the undo mechanism in text editors, and CPU scheduling. They are also used in the implementation of buffers in MP3 media players and CD players. These applications highlight the versatility of the circular queue and its ability to efficiently manage memory in a variety of scenarios.

## Final Note
Understanding the circular queue data structure is essential for solving complex problems in computer science. It is a versatile data structure that efficiently manages the queue in a circular fashion

## Useful Sites

### Articles
1. [Introduction to Circular Queue](https://www.geeksforgeeks.org/introduction-to-circular-queue/)
2. [Circular Queue in Java](https://www.javatpoint.com/circular-queue)
3. [Circular Queue in Data Structure - Simplilearn](https://www.simplilearn.com/tutorials/data-structure-tutorial/circular-queue-in-data-structure)
4. [Circular Queue in Data Structure - Scaler](https://www.scaler.com/topics/data-structures/circular-queue-in-data-structure/)
5. [Circular Queue - BTechSmartClass](http://www.btechsmartclass.com/data_structures/circular-queue.html)
6. [CPP Circular Queue Data Structure](https://www.softwaretestinghelp.com/cpp-circular-queue-data-structure/)

