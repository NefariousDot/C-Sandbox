#include <stdio.h>
#include <limits.h>
int main()
{
    printf("size if int is %d bytes\n",sizeof(int));
    printf("size if char is %d bytes\n",sizeof(char));
    printf("size if float is %d bytes\n",sizeof(float));
    printf("size if double is %d bytes\n\n",sizeof(double));
    
    int v1=INT_MIN;
    int v2=INT_MAX;
    printf("Range of signed int is %d to %d\n\n",v1,v2);

    unsigned int v3=0;
    unsigned int v4=INT_MAX;
    printf("Range of unsigned int is %u to %u\n\n",v2,v4);

    short int v5=SHRT_MIN;
    short int v6=SHRT_MAX;
    printf("Range of signed short is %d to %d\n\n",v5,v6);

    short unsigned int v7=0;
    short unsigned int v8=USHRT_MAX;
    printf("Range of unsigned short is %u to %u\n\n",v7,v8);

    long int v9=LONG_MIN;
    long int v10=LONG_MAX;
    printf("Range of signed long is %ld to %ld\n\n",v9,v10);

    long unsigned int v11=0;
    long unsigned int v12=ULONG_MAX;
    printf("Range of unsigned long is %lu to %lu\n\n",v11,v12);

    return 0;

}
