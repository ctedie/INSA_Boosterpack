/*
 * song.c
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
#include <stdlib.h>

#include "song.h"
#include "notes.h"

/*--Macro-------------------------------------------------------------*/
/*--Types-------------------------------------------------------------*/
/*--Variables---------------------------------------------------------*/
double g_pdPapaNoel[] =
{
     DO_FREQUENCY_3   ,
     PAUSE            ,
     SOL_FREQUENCY_3  ,
     PAUSE            ,
     SOL_FREQUENCY_3  ,
     PAUSE            ,
     SOL_FREQUENCY_3  ,
     PAUSE            ,
     LA_FREQUENCY_3   ,
     PAUSE            ,
     SOL_FREQUENCY_3  ,
     NULL
};
/*--Prototype---------------------------------------------------------*/
/*--Exported functions------------------------------------------------*/
/*--Privaye functions-------------------------------------------------*/


