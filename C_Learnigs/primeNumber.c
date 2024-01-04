#include <stdio.h>

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
