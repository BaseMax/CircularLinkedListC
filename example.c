#include "CircularLinkedList.h"

/**
 * @brief Main entry point
 * 
 * @param argc 
 * @param argv 
 * @return * int 
 */
int main(int argc, char** argv)
{
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

    return 0;
}
