/******************************************************************************
 * This program generates a pattern of characters based on the user-specified number of rows. 
 * The number of rows is restricted to a maximum of 18. 
 * If the user inputs a number outside this range, it is automatically adjusted to 18. 
 * The program prints rows where each row contains a sequence of characters from an array, 
 * prefixed by the row number.
 ******************************************************************************/

#include <stdio.h>
int main()
{
    int row,i,j;
    char a[]= {'A','B','C','D','E','F','G','H'};
    printf("Enter the number of Rows : ");
    scanf("%d",&row);

    printf("\n\n**********************************\n");
    printf("Rows Limited to 18\n");
    printf("if selected row is zero or greater than 18\nsystem will comnsider it as 18\n");
    printf("System will automatically change row to 18\n");
    printf("**********************************\n");

    if((row>18) || (row==0))
    row = 18;
    
    printf("\nPrinting the sequence\n");
    for (i=0;i<=row;i++)
    {
        for (j=0;j<=8;j++)
        {
            printf("%d%c ",i,a[j]);
        }
        printf("\n*************************\n");
    }

    return 0;
}
