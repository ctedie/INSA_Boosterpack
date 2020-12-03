/*
 * sound.h
 *
 *  Created on: 22 nov. 2020
 *      Author: CT
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint16_t frequency;

}soundNote_t;

typedef struct
{
    soundNote_t* note;
    uint16_t durattion;
    uint16_t pause;
}soundSong_t;



soundNote_t tDo;
soundNote_t tRe;
soundNote_t tMi;
soundNote_t tFa;
soundNote_t tSol;
soundNote_t tLa;
soundNote_t tSi;

void Sound_Init(void);
bool SOUND_Play(soundNote_t tNote);
bool SOUND_Stop(void);
void SOUND_ChangeFrequency(soundNote_t *tNote, uint8_t ratio);
void SOUND_Demo(uint32_t ulTick);

#endif /* SOUND_H_ */
