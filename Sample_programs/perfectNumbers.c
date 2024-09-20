/******************************************************************************
 * This program determines if a given integer is a perfect number. 
 * A perfect number is a positive integer that is equal to the sum of its proper divisors (excluding itself).
 ******************************************************************************/

#include <stdio.h>

int main()
{
    int num, i, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        printf("%d is a perfect number.\n", num);
    }
    else
    {
        printf("%d is not a perfect number.\n", num);
    }
}