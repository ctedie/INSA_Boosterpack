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

#include "notes.h"

typedef struct
{
    double Frequency;
    uint16_t durattion;
}soundPlayedNoteSong_t;



soundNote_t tDo;
soundNote_t tRe;
soundNote_t tMi;
soundNote_t tFa;
soundNote_t tSol;
soundNote_t tLa;
soundNote_t tSi;

void Sound_Init(void);
bool SOUND_Play(soundNote_t tNote);
void SOUND_PlayNote(uint16_t frequency);
void SOUND_PlayNoteFromPartition(soundNote_t note);
bool SOUND_Stop(void);
void SOUND_ChangeFrequency(soundNote_t *tNote, uint8_t ratio);
void SOUND_Demo(uint32_t ulTick);

#endif /* SOUND_H_ */
