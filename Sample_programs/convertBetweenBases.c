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

int binaryToDecimal(int binNumber){
    int i=1,rem, decimalValue=0;
    while(binNumber){
        rem = binNumber % 10;
        decimalValue += rem * i  ;
        binNumber /= 10;
        i *= 2;
    }
    return decimalValue;
}

int octalToDecimal(int octaNumber){
    int i=1,rem, decimalValue=0;
    while(octaNumber){
        rem = octaNumber % 10;
        decimalValue += rem * i  ;
        octaNumber /= 10;
        i *= 8;
    }
    return decimalValue;
}

int hexaToDecimal(int hexaNumber){
    // make sure while getting the value for hexaNumber,
    // USE "%X" as FORMATE SPECIFIER 
    int i=1,rem, decimalValue=0;
    while(hexaNumber){
        rem = hexaNumber % 16; // Correcting to get hex digits (0-15)
        decimalValue += rem * i  ;
        hexaNumber /= 16;
        i *= 16;
    }
    return decimalValue;
}


int main(){
    int decimalNumber;
    printf("Enter a Decimal Number : ");
    scanf("%d",&decimalNumber);
    
    decimalToBinary(decimalNumber);
    decimalToOctal(decimalNumber);
    decimalToHexa(decimalNumber);
    /**
     * binaryToDecimal(); COMPLETED
     * octalToDecimal(); COMPLETED
     * hexaToDecimal(); COMPLETED
     * 
     * REMAINING TO BE COMPLETED
     *  binary to octal
     *  binary to hexa
     *  octal to binary
     *  octal to hexa
     *  hexa to binary
     *  hexa to octal
     */
    
}
