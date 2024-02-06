/**************************************************
@file: Challenge2.c
@topic: complex number
@description: C program that performs some calculations on complex numbers
@conversion: create a double complex number with imaginary number squred 
using the multiplication operator (I*I)
*display the imaginary number and real number
*create a double complex number with imaginary number squred 
using the power function from math.h (pow(I,2))
*display the imaginary number and real number
 **************************************************/

#include <stdio.h>
#include <math.h>
#include <complex.h>

int readComplexNumber(double complex *num){
    double real,imaginary;
    printf("***************************************************\n");
    printf("Enter the complex number\n");
    printf("***************************************************\n");
    printf("Enter the real part : ");
    scanf("%lf",&real);
    printf("Enter the imaginary part : ");
    scanf("%lf",&imaginary);
    *num = real + imaginary*I;
    return 0;

} 

void displayComplexNumber(double complex num){
    printf("\n\n***************************************************\n");
    printf("Display complex number\n");
    printf("***************************************************\n");
    printf("Real part : %.2f\n",creal(num));
    printf("Imaginary part : %.2fi\n",cimag(num));
    printf("COMPLEx NUMBER : %.2f + %.2fi\n",creal(num),cimag(num));
}

int main(){

    double complex num1; 
    double complex *ptr = &num1;

    readComplexNumber(ptr);

    displayComplexNumber(num1);

    return 0;

}