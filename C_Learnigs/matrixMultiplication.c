/**************************************************
 * MATRIX MULTIPLICATION 
 * 
 * #of col of a == #of row of b
 * result matrix = row of a X coln of b
 * (A row_ax0 * B 0xcoln_b)+(A01*B10)+(A02*B20)...(A 0xrow_b * B row_bx0)
 * this becomes first element of product matrix
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
 * Function name	: arrayMul()
 * Calculating ROW SUM 
 **************************************************/
/*void arrayMul(int arry1[][10], int arry2[][10],int row,int row1, int coln){
    int i,j,k,sum=0;
    int matrixC[row][coln];
    for(i=0;i<row;i++){
        for(j=0;j<coln;j++){
            for(k=0;k<row1;k++){
                sum+=arry1[i][k]*arry2[k][j];
                printf("Sum of %dx%dx%d is : %d\n",i,j,k,sum);
            }
            matrixC[i][j]=sum;
            sum=0;            
        }
    }

    printf("\n#########################\n");
    printf("MULTIPLIED MATRIX\n");
    dispArray(matrixC,row,coln);

}
*/

/**************************************************
 * Function name	: main()
 **************************************************/

int main(){
    /*int r1,c1,r2,c2;
    printf("Enter the number of rows and columns of FIRST MATRIX\n");
    printf("Row ?: ");
    scanf("%d",&r1);
    printf("Column ?: ");
    scanf("%d",&c1);

    printf("\nEnter the number of rows and columns of SECOND MATRIX\n");
    printf("Row ?: ");
    scanf("%d",&r2);
    printf("Column ?: ");
    scanf("%d",&c2);

    if(c1!=r2){
        printf("\nERROR : MULTIPLICATION CANNOT BE PERFORMED\n");
        printf("Column # of FIRST MATRIX should match with row # of SECOND MATRIX\n");
        return 0;
    } */

    //int matrixA[r1][c1],matrixB[r2][c2];

    int matrixA[2][3] = {{1,2,3},{1,2,1}};
    int matrixB[3][2]={{1,2},{1,2},{3,1}};
    
    //inputArray(matrixA,r1,c1);  
    //printf("\n");   
    //inputArray(matrixB,r2,c2); 
    
    //arrayMul(matrixA,matrixB,r1,r2,c1);

    int i,j,k,sum=0;
    int matrixC[2][2];
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<3;k++){
                printf("matrixA[%d][%d] = %d\n",i,k,matrixA[i][k]);
                printf("matrixB[%d][%d] = %d\n",k,j,matrixB[k][j]);
                sum+=matrixA[i][k]*matrixB[k][j];
                //printf("Sum of %dx%dx%d is : %d\n",i,j,k,sum);
            }
            matrixC[i][j]=sum;
            sum=0;            
        }
    }

    return 0;
}