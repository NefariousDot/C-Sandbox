/******************************************************************************
 * In this program, you're trying to add an unsigned integer (i) and 
 * a signed integer (j), and print the result as an unsigned integer
 ******************************************************************************/

#include <stdio.h>
int main()
{
    unsigned i= 1;
    signed int j= -4;
    printf("%u\n",i+j);
    return 0;

    /* 

    ANSWER IS 4294967293

    Integer value depends from machine to machine

    Actual value will be -3, take the 2's compliment and add 1
    MAX VALUE IS 11111111111111111111111111111111 (4294967295)
    Here value after 2's complement is 11111111111111111111111111111101 (4294967293)
    
    */
}