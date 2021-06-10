#ifndef NVIC_H
#define NVIC_H
#include"STD_TYPES.h"
#include"NVIC_Priv.h"
void vNVIC_SetEnable(uint8 u8Intrupt_NUM);
void vNVIC_clearEnable(uint8 u8Intrupt_NUM);

void vNVIC_setPending(uint8 u8Intrupt_NUM);
void vNVIC_clearPending(uint8 u8Intrupt_NUM);

uint8 u8NVIC_ReadActive(uint8 u8Intrupt_NUM);

void vNVIC_setIBR(uint8 u8Intrupt_NUM ,uint8 Group_Pri,uint8 SubGroup_Pri ,PRI_CONFIG CONFIG);





#endif