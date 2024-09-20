/**************************************************
@file: Challenge5.c
@topic: Recursion
@description: C program for factorial using recursion method
@conversion: THIS IS THE MOST SIMPLEST EXAMPLE PROGRAM TO ILLUSTRATE RECURSION
 **************************************************/

#include <stdio.h>
#include <stdlib.h>

int factorialRecursion(int limit){

    if(limit == 0)  return 1;

    return limit * factorialRecursion(limit -1);
}

int main(){
    int numLimit;
    printf("Enter a limit for factorial calculation :");
    scanf("%d",&numLimit);

    for(int i=0;i<=numLimit;i++){
        printf("%d!   =  %d\n",i,factorialRecursion(i));

    }

    return 0;

}