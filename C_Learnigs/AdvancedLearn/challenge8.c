/**************************************************
@file: Challenge5.c
@topic: MACROS
@description: test your understanding of macros
@conversion: A few challenges to understand macros very  well
CHALLENGE #1
C program to print values of the following predefined symbollic constants
    __LINE__
    __FILE__
    __DATE__
    __TIME__
    __STDC__
    __func__

CHALLENGE #2
C program that defines a macro that accepts 2 parameters and return the sum of given numbers
    MACRO NAME should be SUM
    2 parameters should pass to macro which is entered by the user
    MACRO BODY is the code for the actual logic

CHALLENGE #3
C program to find the square and cube of a number
    There should be 2 MACROS
        * a SQUARE MACRO
        * a CUBE MACRO  
    you need to figure out how many parametes there should be
    your program should have the user enter any number
    program should then display the square and cube of the given number

CHALLENGE #4
C program to check whether a character is uppercase or lowercase using macros
    Should create 2 macros that accepts a single argument (Character)
        * IS_LOWER
        * IS_UPPER
        * both macros should return a boolean
    Program should have the user to enter any character using getchar()
    program then display whether character is upper or lower

Example Output
    # Enter a character : C
      C is upper case
    
    # Enter a character : 8
      Entered character is not in the chbet
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void challenge1(void){
    printf("CURRENTLY EXECUTING FUNCTION : %s\n\n",__func__);
    printf("Current PC : IN FILE %s ON LINE %d\n",__FILE__,__LINE__);
    printf("Last modified : %s on %s\n",__TIME__,__DATE__);
    #if (__STDC__ == 1)
    printf("Implementation is ISO-Conformed\n");
    #else
    printf("Implementation is NOT ISO-Conformed\n");
    #endif
}
// CHALLENGE 2
#define SUM(x,y) (x+y) 

//CHALLENGE 3
#define SQUARE(a) (a*a)
#define CUBE(a) (a*a*a)

//CHALLENGE 4
#define IS_UPPER(al) (al>='A' && al<='Z')
#define IS_LOWER(al) (al>='a' && al<='z')

int main(){

    int a = 0;
    int b = 0;
    int ch = 65;

    printf("\n***************************************************\n");
    printf("CHALLENGE : 1 \n");
    printf("***************************************************\n");
    challenge1();

    printf("\n***************************************************\n");
    printf("CHALLENGE : 2 \n");
    printf("***************************************************\n");
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    printf("Sum of Numbers is : %d\n",SUM(a,b));

    printf("\n***************************************************\n");
    printf("CHALLENGE : 3 \n");
    printf("***************************************************\n");
    // printf("Enter a numbers : ");
    // scanf("%d",&c);

    printf("SQUARE of Numbers is : %d\n",SQUARE(a));
    printf("CUBE of Numbers is : %d\n",CUBE(a));

    printf("\n***************************************************\n");
    printf("CHALLENGE : 4 \n");
    printf("***************************************************\n");
    printf("Enter a character : ");
    scanf("%d",&ch);

    if(IS_LOWER(ch))
    printf("%c is lowe case\n",ch);
    else if(IS_UPPER(ch))
    printf("%c is upper case\n",ch);
    else
    printf("Entered character is not in the alphabet\n");


    return 1;
}