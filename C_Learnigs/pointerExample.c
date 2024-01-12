#include<stdio.h>

void swap(int *x, int *y){
    static int *temp;
    temp=x;
    x=y;
    y=temp;
}

void printab(){
    static int i,a=-3,b=-6;
    i=0;
    while(i<=4){
        printf("i(%d) MOD 2 value is %d\n",i,i%2);
        if((i++)%2==1)
        continue;
        a+=i;
        b+=i;
    }
    swap(&a,&b);
    printf("a = %d , b = %d\n",a,b);
}

void main(){
    printab();
    printab();
}