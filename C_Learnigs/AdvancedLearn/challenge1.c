/**************************************************
@file: fileChallenge.c
@topic: Flexible Array Members
@description: C program that uses Flexible Array Members inside a structure
@conversion: create a structure named myArray that has lenght and 
flexible array member named array
*read information form the user ,the size of the array at runtime
*allocate memory for the structure
*set the length member and fill the array with some dummy data
*display the array

 **************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct S{
    int length;
    int array[];
}myArray;

int main(){
    int len;
    printf("Enter the length of the array : ");
    scanf("%d",&len);

    myArray *ptr;
    ptr = malloc(sizeof(myArray));

    ptr->length = len;

    //set array[]
    for(int i=0;i<len;i++){
        ptr->array[i] = i+1;
    }

    //display array
    for(int i=0;i<len;i++){
        printf("%d ",ptr->array[i]);
    }

    printf("\n");
    
    return 0;
}

