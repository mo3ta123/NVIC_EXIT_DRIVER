#ifndef NVIC_PRIV_H
#define NVIC_PRIV_H
#include"STD_TYPES.h"

#define NVIC_BASE_ADDRESSE 					0xE000E100

#define NVIC_ISER0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x100)))
#define NVIC_ISER1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x104)))
#define NVIC_ISER2									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x108)))
                                        
#define NVIC_ICER0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x180)))
#define NVIC_ICER1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x184)))
#define NVIC_ICER2									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x188)))
                                       
#define NVIC_ISPR0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x200)))
#define NVIC_ISPR1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x204)))
#define NVIC_ISPR2									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x208)))
                                         
#define NVIC_ICPR0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x280)))
#define NVIC_ICPR1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x284)))
#define NVIC_ICPR2									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x288)))
                                      
#define NVIC_IABR0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x300)))
#define NVIC_IABR1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x304)))
#define NVIC_IABR2									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x308)))

#define NVIC_IPR										((volatile uint8*)(NVIC_BASE_ADDRESSE+0x400))  //used as array or pointer not value  offeset by 8 bits 

#define SCB_BASE_ADDRESSE						0xE000ED00
#define SCB_AIRCR									(*(volatile uint32*) (SCB_BASE_ADDRESSE+0x0C))
	
typedef enum{
	PRIGROUP_CONFIG0=0,				//case 0b0xx grop [7:4]  	subgroup none 
	PRIGROUP_CONFIG1,					//case 0b100 grop [7:5]  	subgroup [4]
	PRIGROUP_CONFIG2,					//case 0b101 grop [7:6] 	subgroup [5:4]
	PRIGROUP_CONFIG3,					//case 0b110 grop [7]  		subgroup [6:4]
	PRIGROUP_CONFIG4					//case 0b111 grop None  	subgroup [7:4]
}PRI_CONFIG;

#endif