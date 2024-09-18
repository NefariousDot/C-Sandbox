/******************************************************************************
 * This program checks whether a given number is a Strong number or not.
 * A Strong number is a number for which the sum of the factorials of its digits equals the number itself.
 * 
 * For example, 145 is a Strong number because 1! + 4! + 5! = 1 + 24 + 120 = 145.
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int factorial (int num){
    int mul = 1;
    while (num != 0)
    {
        mul = mul *num;
        num--;
    }
    return mul;    
}

bool isStrongNumber(int num){
    int temp = num;
    int sum = 0;
    while (temp != 0)
    {
        sum += factorial(temp % 10);
        temp = temp / 10;
    }
    if(sum == num)
    return true;
    else
    return false;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isStrongNumber(num))
    printf("%d is a Strong number.\n", num);
    else
    printf("%d is not a Strong number.\n", num);
}