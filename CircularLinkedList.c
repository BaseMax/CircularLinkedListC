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

#include "CircularLinkedList.h"

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
void reverseListRecursive(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    reverseListRecursiveHelper(list->head);
    Node *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
    list->tail->next = list->head;
}

void reverseListRecursiveHelper(Node *node)
{
    if (node->next == NULL) {
        return;
    }
    reverseListRecursiveHelper(node->next);
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
 * @brief Find the middle node of the list
 * 
 * @param list
 * @return Node* 
 */
Node* findMiddleNode(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    Node *slow = list->head;
    Node *fast = list->head;
    while (fast->next != list->head && fast->next->next != list->head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * @brief Find the maximum node of the list
 * 
 * @param list
 * @return Node* 
 */
Node* findMaximumNode(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    Node *max = list->head;
    Node *temp = list->head->next;
    do {
        if (temp->data > max->data) {
            max = temp;
        }
        temp = temp->next;
    } while (temp != list->head);
    return max;
}

/**
 * @brief Find the minimum node of the list
 * 
 * @param list
 * @return Node* 
 */
Node* findMinimumNode(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    Node *min = list->head;
    Node *temp = list->head->next;
    do {
        if (temp->data < min->data) {
            min = temp;
        }
        temp = temp->next;
    } while (temp != list->head);
    return min;
}

/**
 * @brief Merge two linked-lists
 * 
 * @param list1
 * @param list2
 * @return CircularLinkedList
 * 
 */
CircularLinkedList* mergeTwoLists(CircularLinkedList *list1, CircularLinkedList *list2)
{
    if (list1->head == NULL) {
        return list2;
    }
    if (list2->head == NULL) {
        return list1;
    }
    list1->tail->next = list2->head;
    list2->tail->next = list1->head;
    list1->tail = list2->tail;
    list1->size += list2->size;
    return list1;
}

/**
 * @brief Sort the linked list
 * 
 * @param list
 */
void sortLinkedList(CircularLinkedList *list)
{
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

/**
 * @brief Merge two sorted lists
 * 
 * @param list1
 * @param list2
 * @return CircularLinkedList* 
 */
CircularLinkedList* mergeTwoSortedLists(CircularLinkedList *list1, CircularLinkedList *list2)
{
    if (list1->head == NULL) {
        return list2;
    }
    if (list2->head == NULL) {
        return list1;
    }
    Node *temp1 = list1->head;
    Node *temp2 = list2->head;
    CircularLinkedList *mergedList = createNewCircularLinkedList();
    while (temp1 != list1->tail && temp2 != list2->tail) {
        if (temp1->data < temp2->data) {
            insertAtEnd(mergedList, temp1->data);
            temp1 = temp1->next;
        } else {
            insertAtEnd(mergedList, temp2->data);
            temp2 = temp2->next;
        }
    }
    while (temp1 != list1->tail) {
        insertAtEnd(mergedList, temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != list2->tail) {
        insertAtEnd(mergedList, temp2->data);
        temp2 = temp2->next;
    }
    return mergedList;
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
