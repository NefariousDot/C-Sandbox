/**
 * ListNodePtr createNode(char data) 
 * void insertAtBeginning(ListNodePtr *head, char data) #
 * void insertAtEnd(ListNodePtr *head, char data) #
 * void insertSorted(head, data) #
 * void deleteAtBeginning(ListNodePtr *head) #
 * void deleteAtEnd(ListNodePtr *head) #
 * void deleteByValue(ListNodePtr *head, char value) #
 * void printList(ListNodePtr head) #
 * int search(ListNodePtr head, char value)
 * void updateNode(ListNodePtr head, char oldValue, char newValue)
 * int countNodes(ListNodePtr head)
 * void reverseList(ListNodePtr *head)
 * void sortList(ListNodePtr *head)
 * void freeList(ListNodePtr *head)
 * 
 */

#include <stdio.h>
#include <stdlib.h>

//linked list creation
typedef struct node{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr; //(node_t *) = ListNodePtr

//protocol functions
void insertAtBeginning(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertSorted(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
void deleteAtEnd(ListNodePtr *head);
void deleteByValue(ListNodePtr *head, char value);
void printList(ListNodePtr head);
void isEmpty(ListNodePtr head);

void menuOptions(void){
    //This function print the option details for the use to choose
    printf("MENU OPTIONS \n\n"
    "1. INSERT DATA AT BEGINNING..\n"
    "2. INSERT AT THE END...\n"
    "3. INSERT IN SORTED ARRAY...\n"
    "4. DELETE AT BEGINNING...\n"
    "5. DELETE AT END...\n"
    "6. DELETE BY VALUE...\n"
    "7. CHECK WHETHER LIST IS EMPTY...\n"
    "8. END THE APPLICATION...\n");
}

int main(){
    ListNodePtr head = NULL;//initialized head 
    char val = '\0';
    int choice;

    menuOptions();
    printf("\nEnter your choice : ");
    scanf("%d",&choice);

    while(choice != 8){
        switch(choice){
            case 1: 
                printf("\nEnter the character to insert : ");
                scanf(" %c",&val);
                insertAtBeginning(&head, val);
                printList(head);
                //system("cls");
                break;

            case 2:
                printf("\nEnter the character to insert : ");
                scanf(" %c",&val);
                insertAtEnd(&head, val);
                printList(head);
                //system("cls");
                break;

            case 3:
                printf("\nEnter the character to insert : ");
                scanf(" %c",&val);
                insertSorted(&head, val);
                printList(head);
                //system("cls");
                break;

            case 4:
                printf("\nDeleting Node at the Beginning...\n");
                deleteAtBeginning(&head);
                printList(head);
                //system("cls");
                break;

            case 5:
                printf("\nDeleting Node at the End...\n");
                deleteAtEnd(&head);
                printList(head);
                //system("cls");
                break;

            case 6:
                printf("\nEnter the character to delete : ");
                scanf(" %c",&val);
                deleteByValue(&head, val);
                printList(head);
                ////system("cls");
                break;

            case 7:
                isEmpty(head);
                // printList(head);
                //system("cls");
                break;

            default:
                printf("INVALID SELECTION...\n");
                break;

        }
        printf("\nLets try another option \n");
        menuOptions();
        printf("\n??\n");
        scanf("%d",&choice);
    }

    printf("Closing Application...\n");
    return 0;

}

void insertAtBeginning(ListNodePtr *head, char value){
    ListNodePtr newNode = malloc(sizeof(node_t)); //created a new node
    newNode->data = value;
    newNode->nextPtr = *head; // new node points to the node available in head OR value NULL will be stored
    *head = newNode; // updating the head value with new node addr:
}

void insertAtEnd(ListNodePtr *head, char value){
    ListNodePtr currentPtr = *head;
    
    //checking whether list is empty
    if(currentPtr->nextPtr == NULL){
        ListNodePtr newNode = malloc(sizeof(node_t)); //if empty, create a new node and assign data
        newNode->data = value;
        newNode->nextPtr = NULL;
        *head = newNode;
    }

    else {
        //traverse all nodes
        while(currentPtr->nextPtr != NULL){
            currentPtr = currentPtr->nextPtr;
        }
        currentPtr->nextPtr = malloc(sizeof(node_t)); //create new node after identifying the NULL (end of list)
        currentPtr->nextPtr->data = value;
        currentPtr->nextPtr->nextPtr = NULL; //No need to change the header value as its already contains the correct addr:
    }
}

void insertSorted(ListNodePtr *head, char value){
    ListNodePtr newPtr, previousPtr, currentPtr;
    newPtr = malloc(sizeof(node_t));
    
    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        
        currentPtr = *head; //to check node after insertion
        previousPtr = NULL; //to check node before insertion

        //this while loop identifies where to put the new node
        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        //if check the previousPtr is still NULL. If so, means that value is the smallest element in the list
        if(previousPtr == NULL){
            newPtr->nextPtr = *head;
            *head = newPtr;
        }

        else { //identifies the location to put the new node
             previousPtr->nextPtr = newPtr;
             newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("\n%c not inserted. No Memory Available\n");
    }
}

void deleteAtBeginning(ListNodePtr *head){
    //delete the first node 
    ListNodePtr temp = NULL;
    if(*head == NULL){
        fprintf(stderr,"Error : List is empty\n");
        exit(EXIT_FAILURE);
    }
    else{
        temp = *head;
        *head = (*head)->nextPtr;
        free(temp);
    }
}

void deleteAtEnd(ListNodePtr *head){
    //removing the last node from list
    ListNodePtr currentPtr, PreviousPtr;
    if(*head == NULL){
        fprintf(stderr,"Error : List is empty\n");
        exit(EXIT_FAILURE);        
    }
    else {
        PreviousPtr = NULL;
        currentPtr = *head;

        while(currentPtr != NULL){
            PreviousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        free(currentPtr);
        PreviousPtr->nextPtr = NULL;

    }
}

void deleteByValue(ListNodePtr *head, char value){
    ListNodePtr currentPtr, previousPtr;

    if(*head == NULL){
        fprintf(stderr,"Error : List is empty\n");
        exit(EXIT_FAILURE);
    }

    else {
        currentPtr = *head;
        previousPtr = NULL;
        while(currentPtr->data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        previousPtr->nextPtr = currentPtr->nextPtr;
        free(currentPtr);
    }

}

void isEmpty(ListNodePtr head){
    if(head == NULL){
        printf("List is empty...\n");
    }
    else {
        printf("List is not empty\n");
    }
}

void printList(ListNodePtr head){
    if(head == NULL){
        fprintf(stderr,"\nError : List is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("\nThe List is :: \n");
        while(head != NULL){
            printf("%c --> ", head->data);
            head = head->nextPtr;
        }
        printf("NULL\n\n");
    }
}


