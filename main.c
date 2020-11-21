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

//![Simple Timer_A Config]
/* Timer_A PWM Configuration Parameter */
Timer_A_PWMConfig pwmConfig =
{
        .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
        .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
        .timerPeriod = 145, //440Hz
        .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4,
        .compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET,
        .dutyCycle = 72 // 0.5 de dutycycle
};
//![Simple Timer_A Config]

int main(void)
{
    /* Stop Watchdog  */
    WDT_A_holdTimer();

    /* TODO
     *  - Init GPIO 2.7
     *  - Init PWM on GPIO 2.7
     *  - Set PWM frequency at 440Hz
     */


    //![Simple Timer_A Example]
    /* Setting MCLK to REFO at 128Khz for LF mode
     * Setting SMCLK to 64Khz */
    CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    CS_initClockSignal(CS_MCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_2);
    //PCM_setPowerState(PCM_AM_LF_VCORE0);

    /* Configuring GPIO2.7 as peripheral output for PWM  and P6.7 for button
     * interrupt */
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring Timer_A to have a period of approximately 500ms and
     * an initial duty cycle of 10% of that (3200 ticks)  */
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
    //![Simple Timer_A Example]


    while(1)
    {
        
    }
}



/* ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------- */

