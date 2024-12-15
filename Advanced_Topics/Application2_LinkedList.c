/******************************************************************************************************
 * @file: Application2_LinkedList.c
 * @topic: Dynamic Memory Management and Linked List Manipulation
 * @description: This program implements a singly linked list with a variety of operations such as 
 * initialization, insertion, deletion, traversal, searching, counting, reversal, sorting, and cleanup.
 * It demonstrates the use of dynamic memory allocation and efficient list management in C. The program
 * is modularized to allow each function to perform a specific task, making the code reusable and easy to understand.
 * 
 * 
 * The structure used for the linked list nodes:
 * struct node {
 *      char data;                // Data stored in the node (character).
 *      struct node *nextPtr;     // Pointer to the next node in the list.
 * };
 * 
 * Key operations:
 * createNode()       ==> Dynamically allocates a new node with given data.
 * initializeList()   ==> Initializes the head pointer to signify an empty list.
 * insertAtBeginning() ==> Adds a new node at the start of the list.
 * insertAtEnd()      ==> Appends a new node to the end of the list.
 * deleteAtBeginning() ==> Removes the first node in the list.
 * deleteAtEnd()      ==> Removes the last node in the list.
 * deleteByValue()    ==> Deletes the first occurrence of a specified value.
 * printList()        ==> Traverses and prints the list in a user-friendly format.
 * search()           ==> Searches for a specific value in the list.
 * countNodes()       ==> Counts the total number of nodes in the list.
 * reverseList()      ==> Reverses the linked list.
 * sortList()         ==> Sorts the list in ascending order.
 * freeList()         ==> Frees all allocated memory to avoid memory leaks.
 * 
 * Highlights:
 * - Demonstrates efficient memory allocation using malloc() and freeing using free().
 * - Implements robust error handling, ensuring NULL pointers are managed appropriately.
 * - Supports operations that enhance the versatility of the linked list for various use cases.
 * - Modular design simplifies code readability and maintenance.
 * 
 ******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    char data;
    struct node *nextPtr;
} node_t, *ListNodePtr;

// Function to create a new node
ListNodePtr createNode(char data) {
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(node_t));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->nextPtr = NULL;
    }
    return newNode;
}

// Function to initialize the list (head set to NULL)
void initializeList(ListNodePtr *head) {
    *head = NULL;
}

// Add a new node at the beginning of the list
void insertAtBeginning(ListNodePtr *head, char data) {
    ListNodePtr newNode = createNode(data);
    if (newNode != NULL) {
        newNode->nextPtr = *head;
        *head = newNode;
    }
}

// Add a new node at the end of the list
void insertAtEnd(ListNodePtr *head, char data) {
    ListNodePtr newNode = createNode(data);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNodePtr current = *head;
        while (current->nextPtr != NULL) {
            current = current->nextPtr;
        }
        current->nextPtr = newNode;
    }
}

// Remove the first node in the list
void deleteAtBeginning(ListNodePtr *head) {
    if (*head == NULL) return;

    ListNodePtr temp = *head;
    *head = (*head)->nextPtr;
    free(temp);
}

// Remove the last node in the list
void deleteAtEnd(ListNodePtr *head) {
    if (*head == NULL) return;

    if ((*head)->nextPtr == NULL) {
        free(*head);
        *head = NULL;
    } else {
        ListNodePtr current = *head;
        while (current->nextPtr->nextPtr != NULL) {
            current = current->nextPtr;
        }
        free(current->nextPtr);
        current->nextPtr = NULL;
    }
}

// Delete the first node with the specified value
void deleteByValue(ListNodePtr *head, char value) {
    if (*head == NULL) return;

    if ((*head)->data == value) {
        ListNodePtr temp = *head;
        *head = (*head)->nextPtr;
        free(temp);
        return;
    }

    ListNodePtr current = *head;
    while (current->nextPtr != NULL && current->nextPtr->data != value) {
        current = current->nextPtr;
    }

    if (current->nextPtr != NULL) {
        ListNodePtr temp = current->nextPtr;
        current->nextPtr = current->nextPtr->nextPtr;
        free(temp);
    }
}

// Print the list
void printList(ListNodePtr head) {
    while (head != NULL) {
        printf("%c -> ", head->data);
        head = head->nextPtr;
    }
    printf("NULL\n");
}

// Search for a value in the list
int search(ListNodePtr head, char value) {
    while (head != NULL) {
        if (head->data == value) return 1; // Found
        head = head->nextPtr;
    }
    return 0; // Not found
}

// Count the number of nodes in the list
int countNodes(ListNodePtr head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->nextPtr;
    }
    return count;
}

// Reverse the linked list
void reverseList(ListNodePtr *head) {
    ListNodePtr prev = NULL, current = *head, next = NULL;
    while (current != NULL) {
        next = current->nextPtr;
        current->nextPtr = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Sort the linked list
void sortList(ListNodePtr *head) {
    if (*head == NULL) return;

    ListNodePtr current, index;
    char temp;
    for (current = *head; current->nextPtr != NULL; current = current->nextPtr) {
        for (index = current->nextPtr; index != NULL; index = index->nextPtr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

// Free all nodes in the list
void freeList(ListNodePtr *head) {
    ListNodePtr temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->nextPtr;
        free(temp);
    }
}

// Main function to demonstrate the functionality
int main() {
    ListNodePtr head;
    initializeList(&head);

    // Test operations
    insertAtBeginning(&head, 'C');
    insertAtEnd(&head, 'D');
    insertAtBeginning(&head, 'B');
    insertAtBeginning(&head, 'A');
    printf("Initial list: ");
    printList(head);

    printf("\nDeleting 'B'...\n");
    deleteByValue(&head, 'B');
    printList(head);

    printf("\nReversing the list...\n");
    reverseList(&head);
    printList(head);

    printf("\nSorted list: ");
    sortList(&head);
    printList(head);

    printf("\nFreeing the list...\n");
    freeList(&head);
    printList(head);

    return 0;
}
