#include <stdio.h>

void fibonacci(int fibonacciRange)
{
    int first=0;
    int second=1, next, i;

    printf("%d\n%d\n",first,second);

    for(i=0;i<fibonacciRange;i++)
    {
        next=first+second;
        first=second;
        second=next;
        printf("%d\n",next);
    }
}

int main()
{
    int fibonacciRange;
    printf("Enter the range: ");
    scanf("%d",&fibonacciRange);

    printf("Fibonacci Series: \n");
    fibonacci(fibonacciRange);

    return 0;
}