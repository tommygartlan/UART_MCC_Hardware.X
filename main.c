/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F46K22
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

void delay_1s(void);


void send_string(const char *x)
{
    while(*x)
    {
        EUSART1_Write(*x++);
    }    
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    unsigned char rx_data;

    unsigned char byte_value = 24;
    int number = -1025;
    
    LATB = 0x00;
    delay_1s();
    delay_1s();
    LATB = 0xFF;
    delay_1s();
    delay_1s();
    LATB = 0x00;
    
    
    //EUSART1_Write('>');
    send_string("Hello\n\r");
    delay_1s();
    printf("printf can be used if a putch function has been defined \n\r");
    printf("Byte Value is %d",byte_value);  //printf is useful since you can print numbers
    printf("\n\r");  //Newline, Return to beginning of line
    printf("Signed integer Value is %d \n\r",number); //can also print negative numbers
    printf ("Please enter a character and this will be echoed \n\n\r");
    while (1)
    {
        
        rx_data = EUSART1_Read();
        //scanf("%c",&rx_data);
        printf ("The character typed is %c \n\r", rx_data);
        printf ("The ascii code for this character is %x \n\r", rx_data);
        
    }
}
/**
 End of File
*/

void delay_1s(void)
{
    unsigned char i;
    for (i=0;i<25;i++)
            __delay_ms(40);  //max value is 40 since this depends on the _delay() function which has a max number of cycles
    
}