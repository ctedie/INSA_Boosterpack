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

soundNote_t test[] =
{
 {DO_FREQUENCY_3, STYLE_CROCHE},
 {RE_FREQUENCY_3, STYLE_NOIRE},
 {MI_FREQUENCY_3, STYLE_BLANCHE},
};
/*--Prototype---------------------------------------------------------*/
/*--Exported functions------------------------------------------------*/
/*--Privaye functions-------------------------------------------------*/


