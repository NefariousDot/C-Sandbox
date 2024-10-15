#include <stdio.h>
#include <stdint.h>

int remArray[250];

void displayConversion(int length){
    for(int j=length-1; j>=0; j--){
        if(remArray[j]>=10)
        printf("%X",remArray[j]);
        else
        printf("%d",remArray[j]);
    }
    printf("\n");
}

void decimalToBinary(int deci){
    int i =0;
    while(deci){
        remArray[i] = deci%2;
        i++;
        deci /=2;
    }
    printf("DECIMAL TO BINARY CONVERTED VALUE : ");
    displayConversion(i);
}

void decimalToOctal(int deci){
    int i =0;
    while(deci){
        remArray[i] = deci%8;
        i++;
        deci /=8;
    }
    printf("DECIMAL TO OCTAL CONVERTED VALUE : ");
    displayConversion(i);
}

void decimalToHexa(int deci){
    int i =0;
    while(deci){
        remArray[i] = deci%16;
        i++;
        deci /=16;
    }
    printf("DECIMAL TO HEXA CONVERTED VALUE : ");
    displayConversion(i);
}



int main(){
    int decimalNumber;
    printf("Enter a Decimal Number : ");
    scanf("%d",&decimalNumber);
    
    decimalToBinary(decimalNumber);
    decimalToOctal(decimalNumber);
    decimalToHexa(decimalNumber);
    
}