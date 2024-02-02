/**************************************************
@file: fileChallenge.c
@description: C program, to find the total number of lines in a text file

 **************************************************/

#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int count = 0;

    fp = fopen("/home/athmaram/cdac/file.txt", "r");
    if (fp == NULL)
    {
        printf("Error while opening the file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            count++;
    }
    fclose(fp);
    printf("Total number of lines: %d\n", count);
    return 0;   
}