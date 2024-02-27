/**************************************************
@file: Challenge5.c
@topic: variadic functions
@description: C program that ceates variadic function that will allow a pgm to add any amount of
numbers(integers) that they would like to be added together
@conversion: In order to know how many numbers are being passed to this veriodic function,
you can use the first argument as the number of arguments
@example: involking function with a variable number of arguments
addingNumber(2,10,20)
addingNumber(3,10,20,30)
addingNumber(4,10,20,30,40)

* OUTPUT
30
60
100
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int addingNumber(int num,...){
    int sum=0;    
    va_list ap;
    va_start(ap,num);

    while(num){
        sum += va_arg(ap,int);
        num--;
    }
    va_end(ap);

    return sum;
}


int averageNumber(int num,...){
    double avg=0;
    int temp,sum = 0;
    temp=num;
    va_list ap;
    va_start(ap,num);

    while(num){
        sum += va_arg(ap,int);
        num--;
    }
    va_end(ap);
    printf("FUNCTION averageNumber : sum = %d\n",sum);
    printf("FUNCTION averageNumber : num = %d\n",num);

    avg = (double)(sum/temp);
    printf("FUNCTION averageNumber : avg = %f\n",avg);

    return avg;

}

int main(){
    int sum=0;
    double average =0;

    sum = addingNumber(2,10,20);
    average = averageNumber(2,10,20);
    
    printf("Sum is %d\n",sum);
    printf("Average is %lf\n",average);

}