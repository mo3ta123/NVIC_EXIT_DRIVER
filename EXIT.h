#ifndef EXIT_H
#define EXIT_H

#include"STD_TYPES.h"
#include"EXIT_Priv.h"

typedef enum{
	RISING_EVENT=0,
	FALLING_EVENT
}EXIT_EVENT;	




void vEXIT_EnableLINE(uint8 lineNum);		//not masked
void vEXIT_DisableLINE(uint8 lineNum);	//masked

void vEXIT_EVENT_Type(uint8 lineNum,EXIT_EVENT EVENT);

void vEXIT_Software_Trigger(uint8 lineNum);

void vEXIT_setPort(uint8 lineNum,uint8);

#endif