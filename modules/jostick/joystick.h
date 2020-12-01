/*
 * joystick.h
 *
 *  Created on: 24 nov. 2020
 *      Author: CT
 */

#ifndef MODULES_JOYSTICK_H_
#define MODULES_JOYSTICK_H_

uint16_t m_usADCResult;
uint16_t m_usADCResult_filt;

void JOYSTICK_init(void);

#endif /* MODULES_JOYSTICK_H_ */
