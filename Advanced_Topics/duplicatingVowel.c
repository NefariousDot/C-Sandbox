/**************************************************
@file: duplicatingVowels.c
@topic: Return the modified string where all the vowels are repeated twice
@description: Two Pointer Approach
@conversion: This approach uses two pointers: one to read characters from the input string, and the other 
    to write characters to the output string. 
    For each character in the input, check if it’s a vowel, and if so, write it twice using the write pointer. 
    This avoids the need for a temporary result string.

 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_vowel(char c) {
    char lower = tolower(c);
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'); //return TRUE/1 if of these vowels are available
}

void modify_string(char *str) {
    // int lower;
    int ln = strlen(str);
    char *read_ptr = str;
    
    //Allocating enough memory to contain the duplicated vowels
    // ln * 2 + 1 ==> one extra byte added to accomadate '\0' character.
    char *write_ptr = (char *) malloc (ln * 2 + 1 ,  sizeof(char));
    if(write_ptr == NULL){
        printf("Error in allocationg the memory\n");
        exit(1);
    }
    
    //keep track of the strat of the allocated memory
    char * modify_start = write_ptr;
    
    while (*read_ptr != '\0') {
        *write_ptr++ = *read_ptr;

        if (is_vowel(*read_ptr)) {
            *write_ptr++ = *read_ptr; // Add vowel again if it's a vowel
        }
        read_ptr++;
    }

    
    *write_ptr = '\0'; // Null-terminate the string
    
    printf("Modified String: %s\n", modify_start);
    free(modify_start); //free allocated memory , using the starting addrress
}

int main() {
    char input[128];
    printf("Enter a string: ");
    
    fgets(input, 128, stdin); // Read input string
    input[strcspn(input, "\n")] = '\0'; // To remove trailing '\n':

    modify_string(input);
    
    return 0;
}
