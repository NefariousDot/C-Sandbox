#include <stdio.h>

//Using macro name as function
#define add(x,y) x+y

//Multiple lines using macro
#define great(a,b) if(a>b)\
{\
    printf("%d is greater\n",a);\
}\
else\
{\
    printf("%d is greater\n",b);\
}

int main()
{
    printf("Using macro name as function :- %d\n",add(1,2));
    great(5,6);

    return 0;
}