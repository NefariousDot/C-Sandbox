// INPUT : python programming language 
// OUTPUT: nohtyp gnimmargorp egaugnal 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reves(char str[], int end, int start){
    // reverse string
    // printf("\nSTART : %d END : %d\n", start, end);
    for(int i = end; i>=start; i--)
    printf("%c",str[i]);
    printf(" ");

}

int main(){
    char string[] = "Python Programming Language";

    int length = strlen(string);
    printf("LENGTH : %d\n", length);
    int st =0;

    for(int i=0; i<=length; i++){
        if(string[i]==' ' || string[i]== '\0'){
            reves(string, i-1, st );
            st = i+1;
        }    
    }

    return 0;


}