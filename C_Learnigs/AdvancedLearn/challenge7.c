/**************************************************
@file: Challenge5.c
@topic: Recursion
@description: C program that calculate the sum of numbers from 1 to n. Also
a program which will find the GCD(Greatest Common Denominator) of 2 numbers using recursion
@conversion: 
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int seriesSum(int range){
    if(range == 1)  return 1;

    return range + seriesSum(range - 1);
}

int gcdNum(int num1,int num2){
    if(num2 == 0)   return num1;

    return gcdNum(num2, num1 % num2);
}

int main(){

    int range,gcd1,gcd2;

    printf("**************************************************\n");
    printf("Enter a range to calculate the sum :");
    scanf("%d",&range);

    printf("\nSum of numbers ranging from 1 to %d is %d\n",range, seriesSum(range));

    printf("**************************************************\n");
    printf("\nEnter the two numbres to calculate GCD :");
    scanf("%d %d",&gcd1,&gcd2);

    printf("GCD of the two numbers %d and %d is %d\n",gcd1,gcd2,gcdNum(gcd1,gcd2));
    printf("**************************************************\n");

    return 0;
}