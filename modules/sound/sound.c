/*
 * sound.c
 *
 *  Created on: 22 nov. 2020
 *      Author: CT
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sound.h"
#include "notes.h"
#include "song.h"


bool m_bPlaying = false;
//soundPlayedNoteSong_t m_ptPN[] =
//{
// //TODO
// {},
//};



double m_pdNotes[] =
{
     DO_FREQUENCY_3   ,
//     REb_FREQUENCY_3  ,
     RE_FREQUENCY_3   ,
//     MIb_FREQUENCY_3  ,
     MI_FREQUENCY_3   ,
     FA_FREQUENCY_3   ,
//     SOLb_FREQUENCY_3 ,
     SOL_FREQUENCY_3  ,
     //LAb_FREQUENCY_3  ,
     LA_FREQUENCY_3   ,
     //SIb_FREQUENCY_3  ,
     SI_FREQUENCY_3   ,
     DO_FREQUENCY_4   ,
     NULL
};

uint8_t m_ucIndexNote = 0;

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

soundNote_t m_tCurrentPlayingNote;
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
            m_bPlaying = true;
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


void SOUND_PlayNote(uint16_t frequency)
{
    Timer_A_PWMConfig pwmConfig =
    {
            .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = frequency,
            .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4,
            .compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET,
            .dutyCycle = (frequency >> 1) // 0.5 de dutycycle
    };

    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
}

bool SOUND_Stop(void)
{
    Timer_A_stopTimer(TIMER_A0_BASE);
    m_tCurrentPlayingNote.frequency = 0;
    m_bPlaying = false;

    return true;
}

void SOUND_ChangeFrequency(soundNote_t *tNote, uint8_t ratio)
{
   tNote->frequency =  tNote->frequency * ratio;
}

static bool m_bEndDemo = false;
static uint8_t remaining = 1;
static bool newNote = true;
void SOUND_Demo(uint32_t ulTick)
{
    if(!m_bEndDemo)
    {
        if(((ulTick % 33) == 0))  //Toute les 330ms pour une croche à 90BPM
        {
            if(newNote == true)
            {
               remaining = (uint8_t)test[m_ucIndexNote].style;
               newNote = false;
               SOUND_PlayNoteFromPartition(test[m_ucIndexNote]);
            }
            else // ||  && (remaining == 0)
            {
                remaining--;
            }

//                m_ucIndexNote++;
        }
        else if (remaining == 0)
        {

            //Prochaine note
            newNote = true;
            m_ucIndexNote++;
        }
        else if(m_ucIndexNote > 2)
        {
            SOUND_Stop();

        }
    }

}


void TA0_N_IRQHandler(void)
{
//    Timer_A_clearCaptureCompareInterrupt
}
