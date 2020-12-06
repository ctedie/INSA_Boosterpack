/*
 * sound.h
 *
 *  Created on: 22 nov. 2020
 *      Author: CT
 */

#ifndef SOUND_H_
#define SOUND_H_

/*--Includes----------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "notes.h"

/*--Macro-------------------------------------------------------------*/
/*--Types-------------------------------------------------------------*/
typedef struct
{
    double Frequency;
    uint16_t durattion;
}soundPlayedNoteSong_t;

typedef enum
{
    PAPA_NOEL,
    BEAU_SAPIN
}SOUND_songs_t;


/*--Variables---------------------------------------------------------*/
soundNote_t tDo;
soundNote_t tRe;
soundNote_t tMi;
soundNote_t tFa;
soundNote_t tSol;
soundNote_t tLa;
soundNote_t tSi;

/*--Exported functions------------------------------------------------*/
void Sound_Init(void);
bool SOUND_Play(soundNote_t tNote);
void SOUND_PlayNoteFromPartition(soundNote_t note);
bool SOUND_Stop(void);
void SOUND_StartNewSong(SOUND_songs_t song);
bool SOUND_Playing(void);
void SOUND_ChangeFrequency(soundNote_t *tNote, uint8_t ratio);
void SOUND_Demo(uint32_t ulTick);

#endif /* SOUND_H_ */
