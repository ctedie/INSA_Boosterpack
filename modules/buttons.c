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


bool BUTTONS_Init(void)
{


    GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN1);    //Button 1
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN5);    //Button 2



    return true;
}
