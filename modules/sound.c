/*
 * sound.c
 *
 *  Created on: 22 nov. 2020
 *      Author: CT
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "sound.h"

bool m_bPlaying = false;

void Sound_Init(void)
{
    tDo.frequency = 245;
    tRe.frequency = 218;
    tMi.frequency = 194;
    tFa.frequency = 183;
    tSol.frequency = 164;
    tLa.frequency = 146;
    tSi.frequency = 130;

//    Timer_A_clearInterruptFlag(TIMER_A0_BASE);
//    Timer_A_enableCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_4);
//
//    Interrupt_enableInterrupt(INT_TA0_N;)

}
bool SOUND_Play(soundNote_t tNote)
{
    Timer_A_PWMConfig pwmConfig =
    {
            .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = tNote.frequency, //440Hz
            .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4,
            .compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET,
            .dutyCycle = (tNote.frequency >> 1) // 0.5 de dutycycle
    };

    if(m_bPlaying == false)
    {
        Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
        m_bPlaying = true;
    }
    else
    {
        return false;
    }

    return true;
}

bool SOUND_Stop(void)
{
    Timer_A_stopTimer(TIMER_A0_BASE);
    m_bPlaying = false;

    return true;
}

void SOUND_ChangeFrequency(soundNote_t *tNote, uint8_t ratio)
{
   tNote->frequency =  tNote->frequency * ratio;
}

void TA0_N_IRQHandler(void)
{
    Timer_A_clearCaptureCompareInterrupt
}
