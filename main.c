/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/******************************************************************************
 * MSP432 Empty Project
 *
 * Description: An empty project that uses DriverLib
 *
 *                MSP432P401
 *             ------------------
 *         /|\|                  |
 *          | |                  |
 *          --|RST               |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 *            |                  |
 * Author: 
*******************************************************************************/
/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "sound.h"
#include "serial.h"



soundNote_t tDo = { .frequency = 245};
soundNote_t tRe = { .frequency = 218};
soundNote_t tMi = { .frequency = 194};
soundNote_t tFa = { .frequency = 183};
soundNote_t tSol = { .frequency = 164};
soundNote_t tLa = { .frequency = 146};
soundNote_t tSi = { .frequency = 130};


static uint8_t ucPlay = 0;


static void SysTick_INT(void);

int main(void)
{
    /* Stop Watchdog  */
    WDT_A_holdTimer();

    /* TODO
     *  - Init GPIO 2.7
     *  - Init PWM on GPIO 2.7
     *  - Set PWM frequency at 440Hz
     */

    /* Setting DCO to 3MHz */


    //![Simple Timer_A Example]
    /* Setting MCLK to REFO at 128Khz for LF mode
     * Setting SMCLK to 64Khz */
    CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    CS_initClockSignal(CS_MCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_2);
//    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);
    //PCM_setPowerState(PCM_AM_LF_VCORE0);

    Serial_Init();

    SysTick_registerInterrupt(SysTick_INT);
    SysTick_setPeriod((CS_getDCOFrequency()/100));
    SysTick_enableInterrupt();
    SysTick_enableModule();


    /* Configuring GPIO2.7 as peripheral output for PWM  and P6.7 for button

     * interrupt */
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring Timer_A to have a period of approximately 500ms and
     * an initial duty cycle of 10% of that (3200 ticks)  */
    //Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
    //![Simple Timer_A Example]

    /* Activation des interptions */
    Interrupt_enableMaster();


    while(1)
    {
    }
}

uint32_t ulTemp = 0;
bool btemp = false;
static void SysTick_INT(void)
{

//    UART_transmitData(EUSCI_A0_BASE, 'A');

    if (SERIAL_bButtonPushed)
    {
        SERIAL_bButtonPushed = false;
//        switch (ucPlay)
//        {
//            case 0:
//                SOUND_Stop();
//                ucPlay = 0xFF;
//                break;
//            case 1:
//                SOUND_Play(tDo);
//                ucPlay = 0xFF;
//                break;
//            case 2:
//                SOUND_Play(tRe);
//                ucPlay = 0xFF;
//                break;
//            case 3:
//                SOUND_Play(tMi);
//                ucPlay = 0xFF;
//                break;
//            case 4:
//                SOUND_Play(tFa);
//                ucPlay = 0xFF;
//                break;
//            case 5:
//                SOUND_Play(tSol);
//                ucPlay = 0xFF;
//                break;
//            case 6:
//                SOUND_Play(tLa);
//                ucPlay = 0xFF;
//                break;
//            case 7:
//                SOUND_Play(tSi);
//                ucPlay = 0xFF;
//                break;
//            default:
//                break;
//        }
        SOUND_Play(tDo);
        btemp = true;
    }
    else
    {
        SOUND_Stop();
        btemp = false;
    }
    ulTemp++;
}


/* ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------- */

