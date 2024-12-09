/**************************************************
@file: registeringLog.c
@topic: atexit() function 
@description: C program that illustrate atexit() by registering a log
@conversion: atexit() allows to register a function to be called when exit() executes
    Here the program will generate a log file upon returns from main from
    Because, the exit() will implicitly called whenever main function returns
 **************************************************/

#include <stdio.h>
#include <stdlib.h>

void log_exit() {
    FILE *log = fopen("program.log", "w+");
    if (log) {
        fprintf(log, "Program exited successfully.\n");
        fclose(log);
    }
}

int main() {
    atexit(log_exit);
    printf("This program will log its termination.\n");
    return 0;
}
