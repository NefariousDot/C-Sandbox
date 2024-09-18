/**************************************************
@file: decimalToBinary.c
@description: C program to convert decimal to binary
@conversion: 
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
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    decimalToBinary(n);

    return 0;
}