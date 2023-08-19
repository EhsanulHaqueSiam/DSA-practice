# **Linked List Operations**

## **Linear Linked List**

**Structure Node:**
```plaintext
value       //  data
next        // Pointer to the next node
```

**Structure LinkedList:**
```plaintext
head        // Pointer to the first node
```

**Functions:**

- **Initialize a Node**
    ```plaintext
    Function createNode(value):
        node = new Node
        node.value = value
        node.next = null
        return node
    ```

- **Initialize LinkedList**
    ```plaintext
    Function initializeLinkedList():
        list = new LinkedList
        list.head = null
        return list
    ```

- **Insert at Beginning**
    ```plaintext
    Function insertAtBeginning(list, value):
        newNode = createNode(value)
        newNode.next = list.head
        list.head = newNode
    ```

- **Insert at End**
    ```plaintext
    Function insertAtEnd(list, value):
        newNode = createNode(value)
        if (list.head == null):
            list.head = newNode
        else:
            currentNode = list.head
            while (currentNode.next != null):
                currentNode = currentNode.next
            currentNode.next = newNode
    ```

- **Insert at Specific Position**
    ```plaintext
    Function insertAtPosition(list, value, position):
        if position == 0:
            insertAtBeginning(list, value)
        else:
            newNode = createNode(value)
            currentNode = list.head
            currentPosition = 0
            while currentPosition < position - 1 and currentNode is not null:
                currentNode = currentNode.next
                currentPosition += 1
            if currentNode is null:
                print("Invalid position.")
            else:
                newNode.next = currentNode.next
                currentNode.next = newNode
    ```

- **Delete from Beginning**
    ```plaintext
    Function deleteFromBeginning(list):
        if list.head is not null:
            list.head = list.head.next
    ```

- **Delete from End**
    ```plaintext
    Function deleteFromEnd(list):
        if list.head is not null:
            if list.head.next is null:
                list.head = null
            else:
                currentNode = list.head
                while currentNode.next.next is not null:
                    currentNode = currentNode.next
                currentNode.next = null
    ```

- **Delete from Specific Position**
    ```plaintext
    Function deleteFromPosition(list, position):
        if list.head is not null:
            if position == 0:
                deleteFromBeginning(list)
            else:
                currentNode = list.head
                currentPosition = 0
                while currentPosition < position - 1 and currentNode.next is not null:
                    currentNode = currentNode.next
                    currentPosition += 1
                if currentNode.next is null:
                    print("Invalid position.")
                else:
                    currentNode.next = currentNode.next.next
    ```

## **Doubly Linked List**

**Structure Node:**
```plaintext
data        // The data
prev        // Pointer to the previous node
next        // Pointer to the next node
```

**Structure DoublyLinkedList:**
```plaintext
head        // Pointer to the first node
```

**Functions:**

- **Initialize a Node**
    ```plaintext
    Function createNode(value):
        node = new Node
        node.data = value
        node.prev = null
        node.next = null
        return node
    ```

- **Initialize DoublyLinkedList**
    ```plaintext
    Function initializeDoublyLinkedList():
        list = new DoublyLinkedList
        list.head = null
        return list
    ```

- **Insert at Beginning**
    ```plaintext
    Function insertAtBeginning(list, value):
        newNode = createNode(value)
        if list.head is not null:
            list.head.prev = newNode
        newNode.next = list.head
        list.head = newNode
    ```

- **Insert at End**
    ```plaintext
    Function insertAtEnd(list, value):
        newNode = createNode(value)
        if list.head is null:
            list.head = newNode
        else:
            currentNode = list.head
            while currentNode.next is not null:
                currentNode = currentNode.next
            currentNode.next = newNode
            newNode.prev = currentNode
    ```

- **Insert at Specific Position**
    ```plaintext
    Function insertAtPosition(list, value, position):
        if position == 0:
            insertAtBeginning(list, value)
        else:
            newNode = createNode(value)
            currentNode = list.head
            currentPosition = 0
            while currentPosition < position - 1 and currentNode is not null:
                currentNode = currentNode.next
                currentPosition += 1
            if currentNode is null:
                print("Invalid position.")
            else:
                newNode.prev = currentNode
                newNode.next = currentNode.next
                if currentNode.next is not null:
                    currentNode.next.prev = newNode
                currentNode.next = newNode
    ```

- **Delete from Beginning**
    ```plaintext
    Function deleteFromBeginning(list):
        if list.head is not null:
            list.head = list.head.next
            if list.head is not null:
                list.head.prev = null
    ```

- **Delete from End**
    ```plaintext
    Function deleteFromEnd(list):
        if list.head is not null:
            if list.head.next is null:
                list.head = null
            else:
                currentNode = list.head
                while currentNode.next is not null:
                    currentNode = currentNode.next
                currentNode.prev.next = null
    ```

- **Delete from Specific Position**
    ```plaintext
    Function deleteFromPosition(list, position):
        if list.head is not null:
            if position == 0:
                deleteFromBeginning(list)
            else:
                currentNode = list.head
                currentPosition = 0
                while currentPosition < position and currentNode is not null:
                    currentNode = currentNode.next
                    currentPosition += 1
                if currentNode is null:
                    print("Invalid position.")
                else:
                    currentNode.prev.next = currentNode.next
                    if currentNode.next is not null:
                        currentNode.next.prev = currentNode.prev
    ```

## **Circular Linked List**

**Structure Node:**
```plaintext
data // the value to store in the node
next // pointer to the next node in the list
```

**Structure CircularLinkedList:**
```plaintext
head // a reference to the first node in the circular linked list
```

**Functions:**

- **Insert at Beginning**
    ```plaintext
    Function insertAtBeginning(circularList, value):
        newNode = Node(value)
        if circularList.head == NULL:
            newNode.next = newNode
        else:
            newNode.next = circularList.head
            currentNode = circularList.head
            while currentNode.next != circularList.head:
                currentNode = currentNode.next
            currentNode.next = newNode
        circularList.head = newNode
    ```

- **Insert at End**
    ```plaintext
    Function insertAtEnd(circularList, value):
        newNode = Node(value)
        if circularList.head == NULL:
            newNode.next = newNode
            circularList.head = newNode
        else:
            newNode.next = circularList.head
            currentNode = circularList.head
            while currentNode.next != circularList.head:
                currentNode = currentNode.next
            currentNode.next = newNode
    ```

- **Insert at Specific Position**
    ```plaintext
    Function insertAtPosition(circularList, value, position):
        newNode = Node(value)
        if position == 1:
            insertAtBeginning(circularList, value)
            return
        currentNode = circularList.head
        count = 1
        while count < position - 1 and currentNode.next != circularList.head:
            currentNode = currentNode.next
            count += 1
        if count == position - 1:
            newNode.next = currentNode.next
            currentNode.next = newNode
        else:
            print("Invalid position.")
    ```

- **Delete from Beginning**
    ```plaintext
    Function deleteFromBeginning(circularList):
        if circularList.head == NULL:
            return  // Empty list
        currentNode = circularList.head
        while currentNode.next != circularList.head:
            currentNode = currentNode.next
        if circularList.head == currentNode: // Only one node in the list
            circularList.head = NULL
        else:
            circularList.head = circularList.head.next
            currentNode.next = circularList.head
    ```

- **Delete from End**
    ```plaintext
    Function deleteFromEnd(circularList):
        if circularList.head == NULL:
            return  // Empty list
        currentNode = circularList.head
        previousNode = NULL
        while currentNode.next != circularList.head:
            previousNode = currentNode
            currentNode = currentNode.next
        if previousNode == NULL:  // Only one node in the list
            circularList.head = NULL
        else:
            previousNode.next = circularList.head
    ```

- **Delete from Specific Position**
    ```plaintext
    Function deleteFromPosition(circularList, position):
        if circularList.head == NULL or position < 1:
            return  // Empty list or invalid position
        if position == 1:
            deleteFromBeginning(circularList)
            return
        currentNode = circularList.head
        previousNode = NULL
        count = 1
        while count < position and currentNode.next != circularList.head:
            previousNode = currentNode
            currentNode = currentNode.next
            count += 1
        if count == position:
            previousNode.next = currentNode.next
        else:
            print("Invalid position.")
    ```

