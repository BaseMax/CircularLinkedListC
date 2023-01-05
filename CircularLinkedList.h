#ifndef _CIRCULAR_LINKEDLIST_H_
#define _CIRCULAR_LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CircularLinkedList {
    Node *head;
    Node *tail;
    int size;
} CircularLinkedList;

/**
 * @brief Create a new Circular Linked List object
 * 
 * @return CircularLinkedList* 
 */
CircularLinkedList* createNewCircularLinkedList();

/**
 * @brief Create a new Node object
 * 
 * @param data 
 * @return Node* 
 */
Node* createNewNode(int data);

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtEnd(CircularLinkedList *list, int data);

/**
 * @brief Insert a new node at the beginning of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtBeginning(CircularLinkedList *list, int data);

/**
 * @brief Insert a new node at the given position
 * 
 * @param list 
 * @param data 
 * @param position 
 */
void insertAtPosition(CircularLinkedList *list, int data, int position);

/**
 * @brief Delete the first node of the list
 * 
 * @param list 
 */
void deleteFirstNode(CircularLinkedList *list);

/**
 * @brief Delete the last node of the list
 * 
 * @param list 
 */
void deleteLastNode(CircularLinkedList *list);

/**
 * @brief Delete the node at the given position
 * 
 * @param list 
 * @param position 
 */
void deleteNodeAtPosition(CircularLinkedList *list, int position);

/**
 * @brief Search for a node in the list
 * 
 * @param list 
 * @param data 
 * @return true 
 * @return false 
 */
bool search(CircularLinkedList *list, int data);

/**
 * @brief Print the list
 * 
 * @param list 
 */
void printList(CircularLinkedList *list);

/**
 * @brief Print the list in reverse order
 * 
 * @param list 
 */
void printListReverse(CircularLinkedList *list);

/**
 * @brief Reverse the list
 * 
 * @param list 
 */
void reverseList(CircularLinkedList *list);

/**
 * @brief Reverse the list recursively
 * 
 * @param node
 */
void reverseListRecursive(Node *node);

/**
 * @brief Delete the list
 * 
 * @param list 
 */
void deleteList(CircularLinkedList *list);

/**
 * @brief Find the middle node of the list
 * 
 * @param list
 * @return Node* 
 */
Node* findMiddleNode(CircularLinkedList *list);

/**
 * @brief Find the maximum node of the list
 * 
 * @param list
 * @return Node* 
 */
Node* findMaximumNode(CircularLinkedList *list);

/**
 * @brief Find the minimum node of the list
 * 
 * @param list
 * @return Node* 
 */
Node* findMinimumNode(CircularLinkedList *list);

/**
 * @brief Merge two linked-lists
 * 
 * @param list1
 * @param list2
 * @return CircularLinkedList
 * 
 */
CircularLinkedList* mergeTwoLists(CircularLinkedList *list1, CircularLinkedList *list2);

/**
 * @brief Sort the linked list
 * 
 * @param list
 */
void sortLinkedList(CircularLinkedList *list);

/**
 * @brief Merge two sorted lists
 * 
 * @param list1
 * @param list2
 * @return CircularLinkedList* 
 */
CircularLinkedList* mergeTwoSortedLists(CircularLinkedList *list1, CircularLinkedList *list2);

/**
 * @brief Free the list
 * 
 * @param list 
 */
void freeList(CircularLinkedList *list);

#endif
