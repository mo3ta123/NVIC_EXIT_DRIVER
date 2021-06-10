#ifndef EXIT_Priv_H
#define EXIT_Priv_H

#include"STD_TYPES.h"

#define EXIT_BASE_ADDRESSE 			0x40013C00

#define EXTI_IMR 								(*((volatile uint32 *)(EXIT_BASE_ADDRESSE+0x00)))
#define EXTI_RTSR 							(*((volatile uint32 *)(EXIT_BASE_ADDRESSE+0x08)))
#define EXTI_FTSR 							(*((volatile uint32 *)(EXIT_BASE_ADDRESSE+0x0C)))
#define EXTI_SWIER							(*((volatile uint32 *)(EXIT_BASE_ADDRESSE+0x10)))
#define EXTI_PR 								(*((volatile uint32 *)(EXIT_BASE_ADDRESSE+0x14)))

#define SYSCFG_BASE_ADDRESSE	 	0x40013800

#define SYSCFG_EXTICR 								((volatile SYSCFG_EXTICRx *)(SYSCFG_BASE_ADDRESSE+0x08))
	
typedef struct{
	uint32 SYSCFG_EXTICR1;
	uint32 SYSCFG_EXTICR2;
	uint32 SYSCFG_EXTICR3;
	uint32 SYSCFG_EXTICR4;
}SYSCFG_EXTICRx;

#endif