#include "uart.h"
#include "encoding.h"
#include "stdlib.h"
#include "platform.h"

void todo() {

    UC *ptr1 = (UC *) POINTER1;
    US *ptr2 = (US *) POINTER2;
    UI *ptr3 = (UI *) POINTER3;

    US errorValue=0;
    
    UC eight =0x2F;
    US sixteen = 0xAB4D;
    UI thirtytwo = 0x7E1A3F8C;

/*######################################################################
# Single value assign
 ######################################################################*/

    //8bit value loaded
    *ptr1 = eight;

    //16bit value loaded
    *ptr2 = sixteen;

    //32bit value loaded
    *ptr3 = thirtytwo;


/*######################################################################
# Array value assign
 ######################################################################*/

    //store 10 8bit 
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(UART_0,"Sstoring 10 8bit values\n\r");
    Transmit_uart(UART_0,"######################################\n\r");
    UC *charArrayPtr = (UC *)ADDRS1;
    for(UC i = 0; i < 10; i++){

    *(charArrayPtr+i) = eight + i;

    Transmit_uart(UART_0,"\n\r Addr:0x");
    disp_Rx_data(charArrayPtr+i);   
    Transmit_uart(UART_0,"\n\rData:0x");
    disp_Rx_data(*(charArrayPtr+i));    
    Transmit_uart(UART_0,"\n\r");
    }

    Transmit_uart(UART_0,"PRESS ANY KEY TO CONTINUE\n\r");
    Rx_uart(UART_0);

    //store 10 16bit 
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(UART_0,"storing 10 16bit values\n\r");
    Transmit_uart(UART_0,"######################################\n\r");

    US *shortArrayPtr = (US *)ADDRS2;
    for(UC i = 0; i < 10; i++){
        *(shortArrayPtr+i) = sixteen + i;
        Transmit_uart(UART_0,"\n\r Addr:0x");
        disp_Rx_data(shortArrayPtr+i);   
        Transmit_uart(UART_0,"\n\rData:0x");
        disp_Rx_data(*(shortArrayPtr+i));    
        Transmit_uart(UART_0,"\n\r");   
    }

    Transmit_uart(UART_0,"PRESS ANY KEY TO CONTINUE\n\r");
    Rx_uart(UART_0);

    //store 20 32bit values
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(UART_0,"storing 20 32bit values\n\r");
    Transmit_uart(UART_0,"######################################\n\r");
    
    UI *intArrayPtr = (UI *)ADDRS3;
    for(UC i = 0; i < 20; i++){
        *(intArrayPtr+i) = thirtytwo + i;
        Transmit_uart(UART_0,"\n\r Addr:0x");
        disp_Rx_data(intArrayPtr+i);   
        Transmit_uart(UART_0,"\n\rData:0x");
        disp_Rx_data(*(intArrayPtr+i));    
        Transmit_uart(UART_0,"\n\r"); 
    }

    Transmit_uart(UART_0,"PRESS ANY KEY TO CONTINUE\n\r");
    Rx_uart(UART_0);


/*######################################################################
# Array value copy
 ######################################################################*/

    //copy 10 8bit values
    UC *destnPtr = (UC *)ADDRC1;
    UC *srcPtr = (UC *)ADDRS1;
    for(int i = 0; i < 10; i++){
        *(destnPtr+i) = *(srcPtr+i);
    }

    //copy 10 16bit values
    US *destnPtr1 = (US *)ADDRC2;
    US *srcPtr1 = (US *)ADDRS2;
    for(int i = 0; i < 10; i++){
        *(destnPtr1+i) = *(srcPtr1+i);
    }

    //copy 20 32bit values
    UI *destnPtr2 = (UI *)ADDRC3;
    UI *srcPtr2 = (UI *)ADDRS3;
    for(int i = 0; i < 20; i++){
        *(destnPtr2+i) = *(srcPtr2+i);
    }


/*######################################################################
# Array value comparison
 ######################################################################*/

    // compare 10 8bit values
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(0,"\n\r8 bit value comparison test started\n\r");
    for (UI i = 0; i < 10; i++) {
        if(*(srcPtr+i) != *(destnPtr+i))
        errorValue++;
    }
    if(errorValue == 0)
        Transmit_uart(0,"\n\rValues are CORRECT in 8 bit transfer\n\r");
    else
        Transmit_uart(0,"\n\rValues are not same in 8 bit transfer\n\r");
    errorValue = 0;
    Transmit_uart(0,"\n\r8 bit value comparison test Completed\n\r");
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(0,"\n\r");

    
    // compare 10 16bit values
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(0,"\n\r16 bit value comparison test started\n\r");
    for (UI i = 0; i < 10; i++) {
        if(*(srcPtr1+i) != *(destnPtr1+i))
        errorValue++;
    }
    if(errorValue == 0)
        Transmit_uart(0,"\n\rValues are CORRECT in 16 bit transfer\n\r");
    else
        Transmit_uart(0,"\n\rValues are not same in 16 bit transfer\n\r");
    errorValue = 0;
    Transmit_uart(0,"\n\r16 bit value comparison test Completed\n\r");
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(0,"\n\r");


    // compare 20 32bit values
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(0,"\n\r32 bit value comparison test started\n\r");
    for (UI i = 0; i < 10; i++) {
        if(*(srcPtr2+i) != *(destnPtr2+i))
        errorValue++;
    }
    if(errorValue == 0)
        Transmit_uart(0,"\n\rValues are CORRECT in 32 bit transfer\n\r");
    else
        Transmit_uart(0,"\n\rValues are not same in 32 bit transfer\n\r");
    errorValue = 0;
    Transmit_uart(0,"\n\r32 bit value comparison test Completed\n\r");
    Transmit_uart(UART_0,"######################################\n\r"); 
    Transmit_uart(0,"\n\r");


    while(1);

}