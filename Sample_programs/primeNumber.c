/******************************************************************************
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself. 
 * In other words, a prime number can only be divided evenly by 1 and the number itself.
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int num,i;
    printf("Enter a number: ");
    scanf("%d", &num);

    //IF LESS THAN 2, THEN NOT A PRIME NUMBER
    if(num<2)
    {
        printf("%d is not a prime number.\n", num);
        return 0;
    }

    /*
    Mathematically, you can represent this as;

    For i=2 to sqrt(num): 
    if n mod i=0, then n is not prime.
    */

   for(i=2; i*i<=num; i++)
   {
       if(num%i==0)
       printf("%d is not a prime number.\n", num);
       else
       printf("%d is a prime number.\n", num);
             
   }
   return 0;
}
