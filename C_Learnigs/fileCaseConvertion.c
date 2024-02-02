/**************************************************
@file: fileCaseConvertion.c
@description: C program, to convert all the characters of a text file to uppercase.
write the results out to a temporary file.
then remove the temporary file name to the original file and rename the temporary filename.
@conversion: islower() to check the lower case
and substract 32 from the ascii value
@function: fgetc() and fputc()
@function: fopen() and fclose()
@function: rename() and remove()

 **************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    FILE *tmp;
    char ch;
    fp = fopen("/home/athmaram/cdac/file.txt", "r");
    if (fp == NULL){
        printf("Error while opening the file.\n");
        return 0;
    }
    tmp = fopen("/home/athmaram/cdac/temp.txt", "w");
    if (tmp == NULL){
        printf("Error while opening the file.\n");
        return 0;
    }
     while((ch=fgetc(fp))!=EOF){
        if(islower(ch)){
            ch=ch-32;
        }
        putc(ch,tmp);
        printf("%c",ch);
     }

    fclose(fp);
    fclose(tmp);
    //  remove("/home/athmaram/cdac/file.txt");
    //  rename("/home/athmaram/cdac/temp.txt","/home/athmaram/cdac/file.txt");
     return 0;

}