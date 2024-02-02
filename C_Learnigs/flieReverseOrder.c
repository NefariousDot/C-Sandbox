/**************************************************
@file: flieReverseOrder.c
@description: C program, to print the content of a text file in reverse order
@conversion: use fseek() to get to the end of the file
use ftell to get the position which will be the total length of file
use loop to count down to 0
@function: fgetc(), fputc(), fopen(), fclose(), fseek(), ftell()

 **************************************************/

#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fp;
    FILE *rev;
    char ch;
    int pos=0;
    int i = 1;
    fp = fopen("/home/athmaram/cdac/file.txt", "r");
    if (fp == NULL){
        printf("Error while opening the file.\n");
        return 0;
    }
    rev = fopen("/home/athmaram/cdac/reverse.txt", "w");
    if (rev == NULL){
        printf("Error while opening the file.\n");
        return 0;
    }

    fseek(fp,0,SEEK_END);
    pos = ftell(fp);
    

    while(i<pos){
        i++;
        fseek(fp,-i,SEEK_END);
        ch=fgetc(fp);
        printf("%c",ch);
        fputc(ch,rev);
    }
    printf("\n");

    fclose(fp);
    fclose(rev);
    //  remove("/home/athmaram/cdac/file.txt");
    //  rename("/home/athmaram/cdac/temp.txt","/home/athmaram/cdac/file.txt");
     return 0;

    
}