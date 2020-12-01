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
//    Timer_A_clearCaptureCompareInterrupt
}
