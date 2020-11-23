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

bool SOUND_Play(soundNote_t tNote);
bool SOUND_Stop(void);

#endif /* SOUND_H_ */
