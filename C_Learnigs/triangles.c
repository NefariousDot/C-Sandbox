#include <stdio.h>
#include <string.h>


void leftAsterix(int row){
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    int row;
    printf("Enter the number of rows : ");
    scanf("%d",&row);

    leftAsterix(row);
    
    return 0;
}