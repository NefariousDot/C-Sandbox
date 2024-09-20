/**************************************************
 * ARRAY OF POINTERS
 * 
 * Storing a array of string in a most efficint way 
 * lesser wastage of memory 
 **************************************************/

#include<stdio.h>
#include<string.h>

int main(){
    char *fruits[]={"2 Oranges","2 Apples","2 Bananas","1 Pineapple"};

    for(int i=0;i<4;i++){
        printf("fruits[%d] = %s \n",i,fruits[i]);
    }

/**************************************************
 * Comparing Strings
 **************************************************/
    if(strcmp(fruits[1],fruits[2])<0)
    printf("\n%s is less than %s\n",fruits[1],fruits[2]);
    else
    printf("%s is not less than %s\n",fruits[1],fruits[2]);

    return 0;
}

