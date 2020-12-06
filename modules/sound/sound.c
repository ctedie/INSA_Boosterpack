/*
 * sound.c
 *
 *  Created on: 22 nov. 2020
 *      Author: CT
 */
/*--Includes---------------------------------------------------------*/
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sound.h"
#include "notes.h"
#include "song.h"

/*--Macro-------------------------------------------------------------*/

/*--Types-------------------------------------------------------------*/
typedef enum
{
    IN,
    PROCESS,
    OUT
}stateProcess_t;


/*--Variables---------------------------------------------------------*/

static bool m_bIsPlaying = true;
static soundNote_t* m_tSongToPlay;
static uint8_t m_ucIndexNote = 0;
soundNote_t m_tCurrentPlayingNote;

stateProcess_t state = IN;
//stateProcess_t nextState = IN;
static uint8_t remaining;

static bool m_bEndDemo = false;

/*--Prototype---------------------------------------------------------*/
void StateChart(void);

/*--Exported functions------------------------------------------------*/
void Sound_Init(void)
{
    tDo.frequency = 45866;  //261.63Hz
    tRe.frequency = 40863;    //293.66
    tMi.frequency = 36404;    //329.63Hz
    tFa.frequency = 34361;    //349.23Hz
    tSol.frequency = 30612;   //392.00Hz
    tLa.frequency = 27273;    //440.00Hz
    tSi.frequency = 24297;    //493.88

    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION);

}

bool SOUND_Play(soundNote_t tNote)
{
    Timer_A_PWMConfig pwmConfig =
    {
            .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = tNote.frequency,
            .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4,
            .compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET,
            .dutyCycle = (tNote.frequency >> 1) // 0.5 de dutycycle
    };

    if(tNote.frequency != m_tCurrentPlayingNote.frequency)
    {
        if(tNote.frequency != 1)
        {
            Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
            m_tCurrentPlayingNote.frequency = tNote.frequency;
        }
        else
        {
            SOUND_Stop();
        }
    }
    else
    {
        return false;
    }

    return true;
}

void SOUND_PlayNoteFromPartition(soundNote_t note)
{
    Timer_A_PWMConfig pwmConfig =
    {
            .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = (uint16_t)(12000000.0 / note.frequency),
            .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4,
            .compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET,
            .dutyCycle = ((uint16_t)(12000000.0 / note.frequency) >> 1) // 0.5 de dutycycle
    };

    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);

}

bool SOUND_Stop(void)
{
    Timer_A_stopTimer(TIMER_A0_BASE);
    m_tCurrentPlayingNote.frequency = 0;

    return true;
}

void SOUND_ChangeFrequency(soundNote_t *tNote, uint8_t ratio)
{
   tNote->frequency =  tNote->frequency * ratio;
}


void StateChart(void)
{
    switch (state)
    {
        case IN:    //Lecture de la note
            m_bIsPlaying = true;
            if(m_tSongToPlay[m_ucIndexNote].frequency == NULL)
            {
                state = OUT;
                break;
            }

            remaining = (uint8_t)m_tSongToPlay[m_ucIndexNote].style;
            if(g_ptPapaNoel[m_ucIndexNote].pointe)
            {
                remaining += ((uint8_t)m_tSongToPlay[m_ucIndexNote].style) / 2;
            }
            SOUND_PlayNoteFromPartition(m_tSongToPlay[m_ucIndexNote]);
            remaining--;
            state = PROCESS;
            break;
        case PROCESS:   // On continue en fonction de la longeur de  la note
            if(remaining == 0)
            {
                //Note suivante
                state = IN;
                m_ucIndexNote++;
            }
            else
            {
                remaining--;
            }
            break;
        case OUT: // Note suivante ou fin
            SOUND_Stop();
            m_bIsPlaying = false;
            break;
        default:
            break;
    }

}
void SOUND_StartNewSong(SOUND_songs_t song)
{
    switch (song)
    {
        case PAPA_NOEL:
            m_tSongToPlay = g_ptPapaNoel;
            state = IN;
            break;
        case BEAU_SAPIN:
            m_tSongToPlay = g_ptMonBeauSapin;
            state = IN;
            break;
        default:
            state = OUT;
            break;
    }
    m_ucIndexNote = 0;
}

bool SOUND_Playing(void)
{
    return m_bIsPlaying;
}

void SOUND_Demo(uint32_t ulTick)
{
    if(!m_bEndDemo)
    {
//        if(((ulTick % 16) == 0))  //Toute les 160ms pour une double croche à 90BPM
        if(((ulTick % 16) == 0))  //Toute les 160ms pour une double croche à 90BPM
        {
            StateChart();
        }

}
}

/*--Privaye functions-------------------------------------------------*/
void TA0_N_IRQHandler(void)
{
//    Timer_A_clearCaptureCompareInterrupt
}
