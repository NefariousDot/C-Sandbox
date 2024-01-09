/**************************************************
 2D array row sum and column sum
 **************************************************/

#include<stdio.h>

/**************************************************
 * Function name	: inputArray()
 * User input for the array elements 
 **************************************************/
void inputArray(int arry[][10],int row, int coln){
    int i,j;
    printf("\n\n***************************************************\n");
    printf("* CREATING ARRAY ELEMENTS\n");
    printf("***************************************************\n");
    for(i=0;i<row;i++){
        for(j=0;j<coln;j++){
            printf("Row-%d Column-%d : ",i,j);
            scanf("%d",&arry[i][j]);
        }
        printf("\n");
    }

}

/**************************************************
 * Function name	: dispArray()
 * User input for the array elements 
 **************************************************/
void dispArray(int arry[][10],int row, int coln){
    int i,j;
    printf("\n\n***************************************************\n");
    printf("* ARRAY ELEMENTS");
    printf("\n***************************************************\n");
    for(i=0;i<row;i++){
        for(j=0;j<coln;j++){
            printf("| %d ",arry[i][j]);
        }
        printf("|\n");
    }

}


/**************************************************
 * Function name	: rowSum()
 * Calculating ROW SUM 
 **************************************************/
void rowSum(int arry[][10],int row, int coln){
    int i,j,sum=0;
    printf("\n\n***************************************************\n");
    printf("* ROW VALUES SUM :  ");
    printf("\n***************************************************\n");
    for(i=0;i<row;i++){
        for(j=0;j<coln;j++){
            sum+=arry[i][j];
        }
        printf("ROW %d value sum : %d\n",i+1,sum);
    }
}

/**************************************************
 * Function name	: columnSum()
 * Calculating COLUMN SUM 
 **************************************************/
void columnSum(int arry[][10],int row, int coln){
    int i,j,sum=0;
    printf("\n\n***************************************************\n");
    printf("* COLUMN VALUES SUM :  ");
    printf("\n***************************************************\n");
    for(j=0;j<coln;j++){
        for(i=0;i<row;i++){
            sum+=arry[i][j];
        }
        printf("COLUMN %d value sum : %d\n",j+1,sum);
    }
}

/**************************************************
 * Function name	: main()
 **************************************************/

int main(){
    int r,c;
    printf("Enter the number of rows and columns\n");
    printf("Row ?: ");
    scanf("%d",&r);
    printf("Column ?: ");
    scanf("%d",&c);

    int matrix[r][c];

    
    inputArray(matrix,r,c);     
    dispArray(matrix,r,c);    
    rowSum(matrix,r,c);    
    columnSum(matrix,r,c);

    return 0;
}
