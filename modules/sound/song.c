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

// 90BPM
soundNote_t g_ptPapaNoel[] =
{
 {DO_FREQUENCY_3, STYLE_NOIRE, false},
 {FA_FREQUENCY_3, STYLE_NOIRE, false},
 {FA_FREQUENCY_3, STYLE_NOIRE, false},
 {FA_FREQUENCY_3, STYLE_NOIRE, false},
 {SOL_FREQUENCY_3, STYLE_NOIRE, false},
 {FA_FREQUENCY_3, STYLE_BLANCHE, true},
 {FA_FREQUENCY_3, STYLE_CROCHE, false},
 {SOL_FREQUENCY_3, STYLE_CROCHE, false},
 {LA_FREQUENCY_3, STYLE_NOIRE, false},
 {LA_FREQUENCY_3, STYLE_NOIRE, false},
 {LA_FREQUENCY_3, STYLE_NOIRE, false},
 {SIb_FREQUENCY_3, STYLE_NOIRE, false},
 {LA_FREQUENCY_3, STYLE_BLANCHE, false},

 {NULL, NULL, NULL}
};

//73BPM
soundNote_t g_ptMonBeauSapin[] =
{
 {DO_FREQUENCY_3, STYLE_NOIRE, false},

 {FA_FREQUENCY_3, STYLE_CROCHE, true},
 {FA_FREQUENCY_3, STYLE_DOUBLE_CROCHE, false},
 {FA_FREQUENCY_3, STYLE_NOIRE, false},
 {SOL_FREQUENCY_3, STYLE_NOIRE, false},

 {LA_FREQUENCY_3, STYLE_CROCHE, true},
 {LA_FREQUENCY_3, STYLE_DOUBLE_CROCHE, false},
 {LA_FREQUENCY_3, STYLE_NOIRE, true},
 {LA_FREQUENCY_3, STYLE_CROCHE, false},

 {SOL_FREQUENCY_3, STYLE_CROCHE, false},
 {LA_FREQUENCY_3, STYLE_CROCHE, false},
 {SIb_FREQUENCY_3, STYLE_NOIRE, false},
 {MI_FREQUENCY_3, STYLE_NOIRE, false},

 {SOL_FREQUENCY_3, STYLE_NOIRE, false},
 {FA_FREQUENCY_3, STYLE_NOIRE, false},

 {NULL, NULL, NULL}
};
/*--Prototype---------------------------------------------------------*/
/*--Exported functions------------------------------------------------*/
/*--Privaye functions-------------------------------------------------*/


