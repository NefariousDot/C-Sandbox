/******************************************************************************
 * This program demonstrates different methods to shift values of varibales
 * Three methods are demonstrated in this code.
 * one with use of temp variable and others are without temp variables
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void method1(int a, int b){
    // using temp variable
    printf("\n***********BEFORE SHIFTING***********\n");
    printf("Varibale1 = %d & variable2 = %d\n",a,b);

    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("\n***********AFTER SHIFTING***********\n");
    printf("Varibale1 = %d & variable2 = %d\n",a,b);
}

void method2(int a, int b){
    // using addition operation
    printf("\n***********BEFORE SHIFTING***********\n");
    printf("Varibale1 = %d & variable2 = %d\n",a,b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\n***********AFTER SHIFTING***********\n");
    printf("Varibale1 = %d & variable2 = %d\n",a,b);
}

void method3(int a, int b){
    // using xor gate. 
    // Similar bits gives 0 and different bits give 1 as output.
    printf("\n***********BEFORE SHIFTING***********\n");
    printf("Varibale1 = %d & variable2 = %d\n",a,b);

    a = a ^ b ;
    b = a ^ b ;
    a = a ^ b ;

    printf("\n***********AFTER SHIFTING***********\n");
    printf("Varibale1 = %d & variable2 = %d\n",a,b);
}

int main(){
    int var1, var2, sel;

    printf("Enter two variables : \n");
    scanf("%d%d", &var1, &var2);

    printf("\n\n***********SELECTION***********\n");
    printf(" 1 --> Methos 1\n 2 --> Method 2\n 3 --> Method 3\nEnter your selection : ");
    scanf("%d",&sel);

    switch (sel)
    {
    case 1:
        method1(var1, var2);
        break;
    
    case 2:
        method2(var1, var2);
        break;
    
    case 3:
        method3(var1, var2);
        break;

    default:
        printf("### WRONG SELECTION ###\n");
        break;
    }

    return 0;
}

