/**************************************************
@file: stringToNumber.c
@topic: stdlib.h miscellaneous functions
@description: C program that performs string to number conversion
@conversion: 
    atoi()      ==> int atoi(const char *str);
    atol()      ==> long int atol(const char *str);
    atoll()     ==> long long int atoll(const char *str);
    atof()      ==> double atof(const char *str);
    strtof      ==> float strtof(const char *str, char **endptr);
    strtol()    ==> long int strtol(const char *str, char **endptr, int base);
    strtoll()   ==> long long int strtol(const char *str, char **endptr, int base);
    sscanf()    ==> int sscanf(const char *str, const char *format, ...);

 **************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Input strings
    char intStr[] = "12345";
    char longStr[] = "1234567890";
    char floatStr[] = "456.789";
    char hexStr[] = "0x1A3F";
    char mixedStr[] = "789abc";
    char remainingStr[] = "54321rest";

    // Using atoi
    int num = atoi(intStr);
    printf("atoi: %d\n", num);

    // Using atol
    long longNum = atol(longStr);
    printf("atol: %ld\n", longNum);

    // Using atoll
    long long longLongNum = atoll(longStr);
    printf("atoll: %lld\n", longLongNum);

    // Using strtol for decimal
    char *endPtr;
    long strtolNum = strtol(intStr, &endPtr, 10);
    printf("strtol (decimal): %ld\n", strtolNum);

    // Using strtol for hexadecimal
    strtolNum = strtol(hexStr, &endPtr, 16);
    printf("strtol (hexadecimal): %ld\n", strtolNum);

    // Using strtoll
    long long strtollNum = strtoll(longStr, &endPtr, 10);
    printf("strtoll: %lld\n", strtollNum);

    // Using strtod
    double doubleNum = strtod(floatStr, &endPtr);
    printf("strtod: %f\n", doubleNum);

    // Handling strings with numbers and characters
    strtolNum = strtol(mixedStr, &endPtr, 10);
    printf("strtol (mixed): %ld, Remaining: %s\n", strtolNum, endPtr);

    // Using sscanf for multiple formats
    char input[] = "42 3.14159 Hello";
    int extractedInt;
    float extractedFloat;
    char extractedString[20];
    sscanf(input, "%d %f %s", &extractedInt, &extractedFloat, extractedString);
    printf("sscanf: Integer: %d, Float: %f, String: %s\n", extractedInt, extractedFloat, extractedString);

    return 0;
}
