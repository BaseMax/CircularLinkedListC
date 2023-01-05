# Circular Linked-List C

This is a simple implementation of a circular linked-list in C. Circular linked-lists are a type of linked-list where the last node points to the first node. This is useful for implementing queues and stacks. This implementation is a doubly linked-list, meaning that each node has a pointer to the next node and a pointer to the previous node.

## Usage

```c
// Create a new list
CircularLinkedList *list = createNewCircularLinkedList();

// Insert some nodes
insertAtBeginning(list, 1);
insertAtBeginning(list, 2);
insertAtBeginning(list, 3);
insertAtBeginning(list, 4);
insertAtBeginning(list, 5);

// Print the list
printList(list);

// Insert a node at the end
insertAtEnd(list, 6);

// Print the list
printList(list);

// Insert a node at the given position
insertAtPosition(list, 7, 3);

// Print the list
printList(list);

// Reverse the list
reverseList(list);

// Print the list
printList(list);

// Reverse the list recursively
// reverseListRecursive(list);

// Print the list
printList(list);

// Delete the first node
deleteFirstNode(list);

// Print the list
printList(list);

// Delete the last node
deleteLastNode(list);

// Print the list
printList(list);

// Delete the node at the given position
deleteNodeAtPosition(list, 3);

// Print the list
printList(list);

// Search for a node
printf("Search for 3: %s\n", search(list, 3) ? "true" : "false");

// Print the list in reverse order
printListReverse(list);

// Delete the list
deleteList(list);

// Print the list
printList(list);

// Free the list
freeList(list);
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2022, Max Base
