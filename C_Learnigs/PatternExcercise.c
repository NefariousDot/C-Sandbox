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

    if((row>18) || (row=0))
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
