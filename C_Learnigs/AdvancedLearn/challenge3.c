/**************************************************
@file: Challenge3.c
@topic: Bit Masking
@description: C program that performs some calculations on bit masking
@conversion: input a number from the user
* check wherther the n-th bit of given number is set or not
* if not set, mark it as set
 **************************************************/

#include <stdio.h>

void decimalToBinary(int n) {
    // Array to store binary number
    int binaryNum[32];

    // Counter for binary array
    int i = 0;
    while (n > 0) {
        // Store the remainder in the binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main(){
    int num,bitSet,mask=1;

    printf("Enter a number : ");
    scanf("%d",&num);

    printf("Which bit you want to set ? (Starting from BIT0) : ");
    scanf("%d",&bitSet);

    mask <<= bitSet;

    printf("\n***************************************************\n");
    printf("NUMBER BEFORE MANIPULAION\n");
    decimalToBinary(num);
    printf("\n***************************************************\n");

    if((num & mask)== mask){
        perror("\nALREADY SET");
        return 0;
    }

    else{
        num |=mask;
        printf("\n***************************************************\n");
        printf("NUMBER AFTER MANIPULAION\n");
        decimalToBinary(num);
        printf("\n***************************************************\n");
    }

    return 0;
}
