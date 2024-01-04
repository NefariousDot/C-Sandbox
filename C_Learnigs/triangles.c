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

void rightAsterisk(int row){
    int i,j;
    for(i=1;i<=row;i++){
        //printing spaces
        for(j=1;j<=(row-i);j++){
            printf("  ");
        }
        //printing asterisk
        for(j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
}

void downLeftAsterisk(int row){
    int i,j;
    for(i=0;i<row;i++){
        for(j=1;j<=row-i;j++){
            printf("* ");
        }
        printf("\n");
    }
}

void downRightAsterisk(int row){
    int i,j;
    for(i=0;i<row;i++){
        for(j=1;j<=i;j++){
            printf("  ");
        }
        for(j=1;j<=row-i;j++){
            printf("* ");
        }
        printf("\n");
    }
}

void floydTriangle(int row){
    int i,j;
    int count =1;
    for(i=1;i<=row;i++){
        for(j=1;j<=i;j++){
            printf("%d ", count);
            count ++;
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
    printf("\n\n");
    rightAsterisk(row);
    printf("\n\n");
    downLeftAsterisk(row);
    printf("\n\n");
    downRightAsterisk(row);
    printf("\n\n");
    floydTriangle(row);
    printf("\n\n");
    
    return 0;
}
