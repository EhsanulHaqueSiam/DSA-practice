# Linked List

A linked list is a list of items where one item of the list points to another item. A Node is used to represent a linked list. A Node is a user-defined data type that binds two or more variables together and makes a single unit of variable.

## Structures for Nodes

- **Node for Single Linked List**:
    ```c
    struct Node {
        int data;
        Node *nextNode;
    };
    ```

- **Node for Doubly Linked List**:
    ```c
    struct Node {
        int data;
        Node *nextNode;
        Node *backNode;
    };
    ```

### a. Creating a Single Linked List:

**Input and Initializations**: `int n, struct Node, Node *firstNode, Node *newNode, Node *currentNode`.

**Process**:
1. Create a Node (`newNode`).
2. Input the value of data for the `newNode`. The value of `nextNode` for the `newNode` will be null.
3. If the value of `firstNode` is null, go to (4). Else, go to (5).
4. The value of `firstNode` will be `newNode` and the value of `currentNode` will be `newNode`. Proceed to (6).
5. The value of `nextNode` for the `currentNode` will be `newNode`. The value of `currentNode` will be `newNode`. Proceed to (6).
6. Repeat (1), (2), (3), and (4)/(5) for `n` times to create a linked list with `n` nodes.

**Output**: The data of all the nodes.

### b. Printing a Single Linked List:

1. The value of `currentNode` will be `firstNode`.
2. Print the data of `currentNode`.
3. The value of `currentNode` will be the `nextNode` of `currentNode`.
4. Repeat (2), (3) while the `currentNode` is not null.

### c. Search an Element from a Single Linked List:

**Input and Initializations**: A linked list, `int element`, `bool flag = false`.

**Process**:
1. The value of `currentNode` will be `firstNode`.
2. If the value of data for `currentNode` is `element`, go to (3), else go to (4).
3. The value of `flag` will be true. Exit.
4. The value of `currentNode` will be the `nextNode` of `currentNode`.
5. While the `currentNode` is not NULL, repeat (2), (3), and (4).

**Output**: If the value of `flag` is true, print “Found”, else print “Not Found”.

### d. Find the Smallest Element from a Single Linked List:

**Input and Initializations**: A linked list, `int mini = 99999999`.

**Process**:
1. The value of `currentNode` will be `firstNode`.
2. If the value of data for `currentNode` is less than `mini`, go to (3), else go to (4).
3. The value of `mini` will be the value of data for `currentNode`.
4. The value of `currentNode` will be the `nextNode` of `currentNode`.
5. While the `currentNode` is not NULL, repeat (2), (3), and (4).

**Output**: The value of `mini`.

### e. Insert a Node at the First Position of a Single Linked List:

**Input and Initializations**: A Linked List.

**Process**:
1. Create a new Node (`newNode`).
2. Input the value of data for the `newNode`. The value of `nextNode` will be NULL.
3. The value of `nextNode` for the `newNode` will be `firstNode`.
4. The value of `firstNode` will be `newNode`.

**Output**: The data of all the nodes.

### f. Insert a Node at the Last Position of a Single Linked List:

**Process**:
1. Create a new Node (`newNode`).
2. Input the value of data for the `newNode`. The value of `nextNode` will be NULL.
3. The value of `currentNode` will be the `firstNode`.
4. If the value of `nextNode` for `currentNode` is not null, go to (5), else go to (7).
5. The value of `currentNode` will be `nextNode` of `currentNode`.
6. Repeat (4) and (5).
7. The value of `nextNode` for `currentNode` will be `newNode`.



### k. Creating a Doubly Linked List:

**Input and Initializations**: `int n, struct Node, Node *firstNode, Node *newNode, Node *currentNode`.

**Process**:
1. Create a Node (`newNode`).
2. Input the value of data for the `newNode`. The value of `nextNode` for the `newNode` will be null, the value of `backNode` for `newNode` will be null.
3. If the value of `firstNode` is null, go to (4). Else, go to (5).
4. The value of `firstNode` will be `newNode` and the value of `currentNode` will be `newNode`.
5. The value of `nextNode` for the `currentNode` will be `newNode`. The `backNode` for the `newNode` will be `currentNode`. The value of `currentNode` will be `newNode`.
6. Repeat (1), (2), (3), and (4)/(5) for `n` times.

**Output**: The data of all the nodes.

### l. Creating a Circular Linked List:

**Input and Initializations**: `int n, struct Node, Node *firstNode, Node *newNode, Node *currentNode`.

**Process**:
1. Create a Node (`newNode`).
2. Input the value of data for the `newNode`. The value of `nextNode` for the `newNode` will be null.
3. If the value of `firstNode` is null, go to (4). Else, go to (5).
4. The value of `firstNode` will be `newNode` and the value of `currentNode` will be `newNode`.
5. The value of `nextNode` for the `currentNode` will be `newNode`. The `nextNode` for the `newNode` will be `firstNode`. The value of `currentNode` will be `newNode`.
6. Repeat (1), (2), (3), and (4)/(5) for `n` times.

**Output**: The data of all the nodes.

