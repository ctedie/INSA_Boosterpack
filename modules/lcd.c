/*
 * lcd.c
 *
 *  Created on: 30 nov. 2020
 *      Author: CT
 */
/*--Includes---------------------------------------------------------*/
//* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "rgb_led.h"

/*--Macro-------------------------------------------------------------*/
#define LCD_RS  GPIO_PORT_P3, GPIO_PIN7
#define LCD_CS  GPIO_PORT_P5, GPIO_PIN0
/*--Types-------------------------------------------------------------*/
/*--Variables---------------------------------------------------------*/
/*--Prototype---------------------------------------------------------*/
/*Exported functions-------------------------------------------------*/
void LCD_Init(void)
{
    const eUSCI_SPI_MasterConfig spiMasterConfig =
    {
            EUSCI_B_SPI_CLOCKSOURCE_SMCLK,             // SMCLK Clock Source
            3000000,                                   // SMCLK = DCO = 3MHZ
            500000,                                    // SPICLK = 500khz
            EUSCI_B_SPI_MSB_FIRST,                     // MSB First
            EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,    // Phase
            EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH, // High polarity
            EUSCI_B_SPI_3PIN                           // 3Wire SPI Mode
    };


    GPIO_setAsOutputPin(LCD_RS);
    GPIO_setAsOutputPin(LCD_CS);

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring SPI in 3wire master mode */
    SPI_initMaster(EUSCI_B0_BASE, &spiMasterConfig);

    /* Enable SPI module */
    SPI_enableModule(EUSCI_B0_BASE);

    /* Enabling interrupts */
    SPI_enableInterrupt(EUSCI_B0_BASE, EUSCI_SPI_RECEIVE_INTERRUPT);
    Interrupt_enableInterrupt(INT_EUSCIB0);
    Interrupt_enableSleepOnIsrExit();
    //![Simple SPI Example]
    TXData = 0x01;

    /* Polling to see if the TX buffer is ready */
    while (!(SPI_getInterruptStatus(EUSCI_B0_BASE,EUSCI_SPI_TRANSMIT_INTERRUPT)));

    /* Transmitting data to slave */
    SPI_transmitData(EUSCI_B0_BASE, TXData);

    PCM_gotoLPM0();
    __no_operation();
}

}

/*--Privaye functions------------------------------------------------*/


