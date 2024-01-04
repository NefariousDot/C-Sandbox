#include <stdio.h>
int main()
{
    for (int i=0;i<20;i++)
    {
        switch(i)
        {
            case 0: i+=5;
            case 1: i+=2;
            case 5: i+=5;
            default : i+=4;
        }
/*
Since break is not added in the switch case, 
all the statements after a successfull pass will execute.

That is ; for the first iteration i=0,
all the case below case 0 will execute.
*/

        printf("%d ",i);
    }
}