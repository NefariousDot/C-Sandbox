/******************************************************************************
 * This program checks whether a given year is a leap year or not. 
 * A leap year is a year that is evenly divisible by 4, but if it's also divisible by 100, 
 * it must be divisible by 400 to be considered a leap year.
 ******************************************************************************/

#include <stdio.h>
int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("%d is a leap year\n", year);
    }
    else
    {
        printf("%d is not a leap year\n", year);
    }
    return 0;
}