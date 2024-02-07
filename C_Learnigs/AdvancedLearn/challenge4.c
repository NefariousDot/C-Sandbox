/**************************************************
@file: Challenge4.c
@topic: Bit Fields
@description: C program that contains the following bit fields in a structure.
@conversion: This structure is going to represent an on-screen box.
*Structure contains
    the box can be opaque or transparent (USE SINGLE BIT TO REPRESENT)
    a fill color os selected from the following palette of colors
        black, red, green, yellow, blue, magenta, cyan or white.(8 POSSIBILITY; 3BITS)
    a boarder can be shown or hidden (USE SINGLE BIT TO REPRESENT)
    a boarder color is selected from the same palette used for the fill color
    a boarder can use one of the 3 line styles :- solid, dotted, or dashed (2BITS)
* Use padding to place the fill-related information in one byte
* The boarder related information in another byte

* FIRST; create a variable of the structure type and initialize the bitfiled with
some default vale and print those values

* SECOND;modify the structure content by accessing each bitfield and changing the
default value to another value, then print the modified value 
 **************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

/*LINE STYLES*/
#define SOLID   0
#define DOTTED  1
#define DASHED  2

/*PRIMARY COLORS*/
#define RED     1 
#define GREEN   2
#define BLUE    4

/*MIXED COLORS*/
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE )

const UC * color[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

typedef struct onScreenBox{
    UI :4;
    US lucid:1;
    UI fill_color:3;
    UI :2;
    US boarder_type:1;
    UI boarder_color:3;
    US boarder_style:2;
}screenBox;

void showBox(screenBox *ptr){
    printf("The box is %s\n",(ptr->lucid == 1)? "transparent" : "opaque");
    printf("Fill color is %s\n",color[ptr->fill_color]);
    printf("Boarder Type is %s\n",(ptr->boarder_type ? "hidden" : "shown"));
    printf("Boarder Color : %s\n", color[ptr->boarder_color]);
    printf("Boarder style is ");
    switch (ptr->boarder_style)
    {
    case SOLID : printf("solid\n");
        break;
    
    case DOTTED : printf("dotted\n");
        break;

    case DASHED : printf("dashed\n");
        break;
    
    default: printf("Unknown");
        break;
    }
     
}


int main(){
    screenBox box = {0, MAGENTA, 1, GREEN, DOTTED};

    printf("\n***************************************************\n");
    printf("INITIAL BOX DETAILS \n");
    printf("***************************************************\n");
    showBox(&box);
    printf("\n");

    return 0;
}

