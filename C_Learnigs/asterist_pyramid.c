#include <stdio.h>

int main() {
    int rows, i, j, space;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    space = rows;

    for (i = 1; i <= rows; i++) {
        //Entering Space before printing "*"
        for (j = 1; j < space; j++) {
            printf(" ");
        }
        space--;

        //printing "*" ; no need to worry about the other spaces after this.
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}