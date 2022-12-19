/**
 * 
 * @file CircularLinkedList.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Circular Linked List Implementation in C language
 * @version 0.1
 * @date 2022-12-19
 * @copyright Copyright (c) 2022
 * 
 */

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
CircularLinkedList* createNewCircularLinkedList()
{
    CircularLinkedList *list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * @brief Create a new Node object
 * 
 * @param data 
 * @return Node* 
 */
Node* createNewNode(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtEnd(CircularLinkedList *list, int data)
{
    Node *node = createNewNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        node->next = list->head;
    }
    else {
        list->tail->next = node;
        list->tail = node;
        node->next = list->head;
    }
    list->size++;
}

/**
 * @brief Insert a new node at the beginning of the list
 * 
 * @param list 
 * @param data 
 */
void insertAtBeginning(CircularLinkedList *list, int data)
{
    Node *node = createNewNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        node->next = list->head;
    }
    else {
        node->next = list->head;
        list->head = node;
        list->tail->next = list->head;
    }
    list->size++;
}

/**
 * @brief Insert a new node at the given position
 * 
 * @param list 
 * @param data 
 * @param position 
 */
void insertAtPosition(CircularLinkedList *list, int data, int position)
{
    if (position < 0 || position > list->size) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(list, data);
    }
    else if (position == list->size) {
        insertAtEnd(list, data);
    }
    else {
        Node *node = createNewNode(data);
        Node *temp = list->head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        list->size++;
    }
}

/**
 * @brief Delete the first node of the list
 * 
 * @param list 
 */
void deleteFirstNode(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    list->tail->next = list->head;
    free(temp);
    list->size--;
}

/**
 * @brief Delete the last node of the list
 * 
 * @param list 
 */
void deleteLastNode(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    while (temp->next != list->tail) {
        temp = temp->next;
    }
    temp->next = list->head;
    free(list->tail);
    list->tail = temp;
    list->size--;
}

/**
 * @brief Delete the node at the given position
 * 
 * @param list 
 * @param position 
 */
void deleteNodeAtPosition(CircularLinkedList *list, int position)
{
    if (position < 0 || position >= list->size) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 0) {
        deleteFirstNode(list);
    }
    else if (position == list->size - 1) {
        deleteLastNode(list);
    }
    else {
        Node *temp = list->head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        list->size--;
    }
}

/**
 * @brief Search for a node in the list
 * 
 * @param list 
 * @param data 
 * @return true 
 * @return false 
 */
bool search(CircularLinkedList *list, int data)
{
    Node *temp = list->head;
    do {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    } while (temp != list->head);
    return false;
}

/**
 * @brief Print the list
 * 
 * @param list 
 */
void printList(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

/**
 * @brief Print the list in reverse order
 * 
 * @param list 
 */
void printListReverse(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->tail;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->tail);
    printf("\n");
}

/**
 * @brief Reverse the list
 * 
 * @param list 
 */
void reverseList(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *current = list->head;
    Node *prev = NULL;
    Node *next = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != list->head);
    list->tail = list->head;
    list->head = prev;
    list->tail->next = list->head;
}

/**
 * @brief Reverse the list recursively
 * 
 * @param node
 */
void reverseListRecursive(Node *node)
{
    if (node->next == NULL) {
        return;
    }
    reverseListRecursive(node->next);
    node->next->next = node;
    node->next = NULL;
}

/**
 * @brief Delete the list
 * 
 * @param list 
 */
void deleteList(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = list->head;
    do {
        Node *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    } while (temp != list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * @brief Free the list
 * 
 * @param list 
 */
void freeList(CircularLinkedList *list)
{
    deleteList(list);
    free(list);
}

/**
 * @brief Main entry point
 * 
 * @param argc 
 * @param argv 
 * @return * int 
 */
int main(int argc, char** argv)
{
    return 0;
}
