/*
 * buttons.c
 *
 *  Created on: 23 nov. 2020
 *      Author: CT
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "buttons.h"
#include "sound.h"
//#include "joystick.h"



bool BUTTONS_Init(void)
{


    GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN1);    //Button 1
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN5);    //Button 2
    GPIO_setAsInputPin(GPIO_PORT_P4, GPIO_PIN1);    //Button Joystick

    //GPIO_interruptEdgeSelect(GPIO_PORT_P5, GPIO_PIN1, GPIO_HIGH_TO_LOW_TRANSITION);

    GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN1);
    GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN5);
    GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN1);

    GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN1);
    GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN5);
    GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN1);

    Interrupt_enableInterrupt(INT_PORT5);
    Interrupt_enableInterrupt(INT_PORT3);
    Interrupt_enableInterrupt(INT_PORT4);


    return true;
}

void PORT3_IRQHandler(void)
{
    SOUND_songs_t song = BEAU_SAPIN;
    GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN5);

    if(!SOUND_Playing())
        SOUND_StartNewSong(song);

}

void PORT4_IRQHandler(void)
{
    GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN1);


}

void PORT5_IRQHandler(void)
{
    SOUND_songs_t song = PAPA_NOEL;
    GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN1);

    if(!SOUND_Playing())
        SOUND_StartNewSong(song);


}
