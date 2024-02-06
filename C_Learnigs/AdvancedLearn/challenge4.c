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