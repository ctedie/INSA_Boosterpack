/*
 * notes.h
 *
 *  Created on: 3 déc. 2020
 *      Author: CT
 */

#ifndef MODULES_SOUND_NOTES_H_
#define MODULES_SOUND_NOTES_H_

/*--Includes----------------------------------------------------------*/
#include "sound.h"

/*--Macro-------------------------------------------------------------*/
#define DO_FREQUENCY_3          ((double)261.63)
#define REb_FREQUENCY_3         ((double)277.18)
#define RE_FREQUENCY_3          ((double)293.66)
#define MIb_FREQUENCY_3         ((double)311.13)
#define MI_FREQUENCY_3          ((double)329.63)
#define FA_FREQUENCY_3          ((double)349.23)
#define SOLb_FREQUENCY_3        ((double)369.99)
#define SOL_FREQUENCY_3         ((double)392   )
#define LAb_FREQUENCY_3         ((double)415.3 )
#define LA_FREQUENCY_3          ((double)440   )
#define SIb_FREQUENCY_3         ((double)466.16)
#define SI_FREQUENCY_3          ((double)493.88)


#define DO_FREQUENCY_4          ((double)DO_FREQUENCY_3   * 2)
#define REb_FREQUENCY_4         ((double)REb_FREQUENCY_3  * 2)
#define RE_FREQUENCY_4          ((double)RE_FREQUENCY_3   * 2)
#define MIb_FREQUENCY_4         ((double)MIb_FREQUENCY_3   * 2)
#define MI_FREQUENCY_4          ((double)MI_FREQUENCY_3   * 2)
#define FA_FREQUENCY_4          ((double)FA_FREQUENCY_3   * 2)
#define SOLb_FREQUENCY_4        ((double)SOLb_FREQUENCY_3 * 2)
#define SOL_FREQUENCY_4         ((double)SOL_FREQUENCY_3  * 2)
#define LAb_FREQUENCY_4         ((double)LAb_FREQUENCY_3  * 2)
#define LA_FREQUENCY_4          ((double)LA_FREQUENCY_3   * 2)
#define SIb_FREQUENCY_4         ((double)SIb_FREQUENCY_3  * 2)
#define SI_FREQUENCY_4          ((double)SI_FREQUENCY_3   * 2)


#define DO_FREQUENCY_5          ((double)DO_FREQUENCY_4   * 2)
#define REb_FREQUENCY_5         ((double)REb_FREQUENCY_4  * 2)
#define RE_FREQUENCY_5          ((double)RE_FREQUENCY_4   * 2)
#define MIb_FREQUENCY_5         ((double)MIb_FREQUENCY_4   * 2)
#define MI_FREQUENCY_5          ((double)MI_FREQUENCY_4   * 2)
#define FA_FREQUENCY_5          ((double)FA_FREQUENCY_4   * 2)
#define SOLb_FREQUENCY_5        ((double)SOLb_FREQUENCY_4 * 2)
#define SOL_FREQUENCY_5         ((double)SOL_FREQUENCY_4  * 2)
#define LAb_FREQUENCY_5         ((double)LAb_FREQUENCY_4  * 2)
#define LA_FREQUENCY_5          ((double)LA_FREQUENCY_4   * 2)
#define SIb_FREQUENCY_5         ((double)SIb_FREQUENCY_4  * 2)
#define SI_FREQUENCY_5          ((double)SI_FREQUENCY_4   * 2)


#define DO_FREQUENCY_6          ((double)DO_FREQUENCY_5   * 2)
#define REb_FREQUENCY_6         ((double)REb_FREQUENCY_5  * 2)
#define RE_FREQUENCY_6          ((double)RE_FREQUENCY_5   * 2)
#define MIb_FREQUENCY_6         ((double)MIb_FREQUENCY_5   * 2)
#define MI_FREQUENCY_6          ((double)MI_FREQUENCY_5   * 2)
#define FA_FREQUENCY_6          ((double)FA_FREQUENCY_5   * 2)
#define SOLb_FREQUENCY_6        ((double)SOLb_FREQUENCY_5 * 2)
#define SOL_FREQUENCY_6         ((double)SOL_FREQUENCY_5  * 2)
#define LAb_FREQUENCY_6         ((double)LAb_FREQUENCY_5  * 2)
#define LA_FREQUENCY_6          ((double)LA_FREQUENCY_5   * 2)
#define SIb_FREQUENCY_6         ((double)SIb_FREQUENCY_5  * 2)
#define SI_FREQUENCY_6          ((double)SI_FREQUENCY_5   * 2)

#define PAUSE   1


/*--Types-------------------------------------------------------------*/
typedef enum
{
    STYLE_DOUBLE_CROCHE = 1,    //1/4 Temps
    STYLE_CROCHE        = 2,           //1/2 Temps
    STYLE_NOIRE         = 4,            //1 Temps
    STYLE_BLANCHE       = 8,          //2 Temps = 2 noires
    STYLE_RONDE         = 16,            //4 Temps = 4 noires
//    STYLE_TRIPLE_CROCHE,    //1/8 Temps
//    STYLE_QUADRUPLE_CROCHE, //1/16 Temps

}styleNote_t;

typedef struct
{
    uint16_t frequency;
    styleNote_t style;
    bool pointe;
}soundNote_t;

/*--Variables---------------------------------------------------------*/
/*--Prototype---------------------------------------------------------*/
/*--Exported functions------------------------------------------------*/


#endif /* MODULES_SOUND_NOTES_H_ */
