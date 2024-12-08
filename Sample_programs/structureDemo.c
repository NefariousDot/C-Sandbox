/******************************************************************************
 * The program demonstrates the use of structures to organize related data and 
 * uses functions for reading and printing the item details.
 * 
 * This program allows users to enter details for multiple items such as item name, 
 * quantity, price, and calculates the total amount for each item
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

struct item {
    char itemName[100];
    int quantity;
    float price;
    float amount;
};


void readItem(struct item *item) {
    printf("\n");
    printf("Enter item name: ");
    scanf("%s", item->itemName);
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price: ");
    scanf("%f", &item->price);
    item->amount = item->quantity * item->price;
    printf("\n");
}

void printItem(struct item *item) {
    printf("\n");
    printf("Item name: %s\n", item->itemName);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
    printf("Amount: %.2f\n", item->amount);
    printf("\n");
}



// int lenghtString(const char *str) {
//     int i = 0;
//     while(*str) {
//         i++;
//         str++;
//     }

//     return i;
// }


int main() {

    // char *str = "hello, world\n";

    // char *strc = "good morning\n";



    // strcpy(strc, str);



    // printf("%s\n", strc);


    // char str1[]="I am Athmaram, Project Engineer in CDAC";
    // printf("Length of the string: %d\n", lenghtString(str));

    printf("Enter the total number of items: ");
    int n;
    scanf("%d", &n);
    struct item item[n];

    for (int i = 0; i < n; i++){
        readItem(&item[i]);
    }


    for (int i = 0; i < n; i++){
        printItem(&item[i]);
    }
    

    return 0;
}