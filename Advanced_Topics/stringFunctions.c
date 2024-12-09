/**************************************************
@file: stringFunctions.c
@topic: Various String Functions
@description: Included examples of string functions such as strrchr(), strstr(), strtok()
@conversion: 
    char *strrchr(const char * string, int character) ===> To find the last occurance of character in string
    char *strstr(const char *s1, const char *s2)      ===> To find the first occurance of S2 in S1
    char *strtok(char *s1, const char *s2)            ===> Breaks the string S1 into tokens based on delimiter in S2

 **************************************************/

#include <stdio.h>
#include <string.h>

int main(){

    char str[] = "hey,Athma,Ram";

    // strrchr()
    printf("STRRCHR() DEMO\n");
    char *result = strrchr(str,'a');
    if(result)
    printf("Last Occurance of 'a' : %s\n",result);
    else
    printf("NOT FIND ANY OCCCURANCE\n");

    // strstr()
    result = NULL;
    printf("\nSTRSTR() DEMO\n");
    const char *substr = "ma";
    result = strstr(str,substr);
    if(result)
    printf("Occurance of '%s'  : %s\n",substr,result);
    else
    printf("NOT FIND ANY OCCCURANCE\n");

    // strtok()
    result = NULL;
    printf("\nSTRTOK() DEMO\n");
    const char *delim = ",";
    result = strtok(str,delim);
    while(result){
        printf("TOKEN  : %s\n",result);
        result = strtok(NULL,delim);
    }

    return 0;
    

}