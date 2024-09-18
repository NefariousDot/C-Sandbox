/******************************************************************************
 * An Armstrong number (or narcissistic number) is a number that is equal to 
 * the sum of its own digits each raised to the power of the number of digits. 
 * For example, 153 is an Armstrong number because 
 * 153 = 1^3 + 5^3 + 3^3.
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

// function calculates the number of digits in the input number
int countArmstrong (int num){
    int count = 0;
    while (num != 0)
    {
        num = num / 10;
        count++;
    }
    return count;    
}
/**
 * function iterates through each digit of the number, 
 * raising it to the power of the total digit count, and summing these values.
 */
bool isArmstrong (int num){    
    int temp = num;
    int sum = 0;
    while (temp != 0)
    {
        int mul = 1;
        int rem = temp % 10;
        int count = countArmstrong(num);
        while (count > 0)
        {
            mul = mul * rem;
            count--;
        }
        sum+=mul;        
        temp = temp / 10;
    }

    if (sum == num)
    return true;
    else
    return false;  
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
    printf("%d is an Armstrong number.\n", num);
    else
    printf("%d is not an Armstrong number.\n", num);
}