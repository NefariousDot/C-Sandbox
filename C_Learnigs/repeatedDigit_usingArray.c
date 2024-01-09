#include <stdio.h>

void isRepeated(int num){
    int count=0;
    int rem, rep[10]={0};

    while(num){
        rem=num%10;
        if(rep[rem]!=0){
            printf("Number %d is repeated %d Times\n",rem,rep[rem]+1);
            count++;
        }
        rep[rem]+=1;
        num/=10;
    }
    if(count==0)
    printf("No digit has been repeated\n");

}

int main(){
    int value;
    printf("Enter a +ve digit to check : ");
    scanf("%d",&value);

    isRepeated(value);

    return 0;
}