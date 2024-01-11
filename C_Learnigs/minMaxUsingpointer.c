#include <stdio.h>
void minMax(int arr[],int len,int *min, int *max){
    *min = *max = arr[0];
    int i;
    for(i=1;i<len;i++){
        if(arr[i]>*max)
        *max=arr[i];
        if(arr[i]<*min)
        *min=arr[i];
    }
}

int main(){
    int a[]={23,4,21,98,987,45,32,123,10};
    int min,max;
    int len=sizeof(a)/sizeof(a[0]);
    minMax(a,len,&min,&max);
    printf("Maximum value of array : %d\n",max);
    printf("Minimum value of array : %d\n",min);

    return 0;
}