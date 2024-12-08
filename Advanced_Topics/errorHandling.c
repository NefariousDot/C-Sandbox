/**************************************************
@file: duplicatingVowels.c
@topic: setjmp and longjmp
@description: The setjmp and longjmp functions in C allow for non-local jumps, meaning you can jump between different functions 
            or parts of a program bypassing the normal flow of execution. These functions are primarily used for error handling 
            and unwinding complex control structures.
@conversion: This is a practical example of division by zero handling

 **************************************************/

#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void safe_divide(int a, int b) {
    if (b == 0) {
        longjmp(env, 1); // Jump to error handler
    }
    printf("Result: %d\n", a / b);
}

int main() {
    if (setjmp(env) == 0) {
        safe_divide(10, 0); // Triggers error
        safe_divide(10, 2); // This won't execute
    } else {
        printf("Error: Division by zero!\n");
    }
    return 0;
}
