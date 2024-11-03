/******************************************************************************
 * Array sorting using qsort()
 * 
 * qsort() is a std library function stdlib.h
 * syntax
 * void qsort(void *base, size_t num, size_t size, int compare(const void *, 
 * const void *) );
 * 
 * base => pointer to the array which need to be sorted
 * num => Total number of elements
 * size => Size of each elements in byte
 * compare => pointer to a function
 * 
 * compare() has 3 outcomes
 * 1. <0 ; if first value is less than second value
 * 2.  0 ; if both are equal
 * 3. >0 ; if first value is greater than second value
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b){
    return * (int *)a - * (int *)b;
}

int compare_des(const void *a, const void *b){
    return * (int *)b - * (int *)a;
}

int main(){
    int array[] = {5,3,8,6,6,2,7};
    size_t arraySize = sizeof(array)/sizeof(array[0]);
    size_t elem = sizeof(int);

    printf("ORIGINAL ARRAY\n");
    for(int i=0; i<arraySize; i++)
    printf("%d ", array[i]);

    qsort(array, arraySize, elem, compare_asc);

    printf("\n\nSORTED ARRAY IN ASCEDING ORDER\n");
    for(int i=0; i<arraySize; i++)
    printf("%d ", array[i]);
    printf("\n");

    qsort(array, arraySize, elem, compare_des);

    printf("\n\nSORTED ARRAY IN DESCENDING ORDER\n");
    for(int i=0; i<arraySize; i++)
    printf("%d ", array[i]);
    printf("\n");

    return 0;

}