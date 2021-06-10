#include"EXIT.h"


void vEXIT_EnableLINE(uint8 lineNum){
	setBit(EXTI_IMR,lineNum);
}

void vEXIT_DisableLINE(uint8 lineNum){
	resetBit(EXTI_IMR,lineNum);
}

void vEXIT_EVENT_Type(uint8 lineNum,EXIT_EVENT EVENT){
	switch(EVENT){
		case RISING_EVENT:
			setBit(EXTI_RTSR,lineNum);
			resetBit(EXTI_FTSR,lineNum);
			break;
		case FALLING_EVENT:
			setBit(EXTI_FTSR,lineNum);
			resetBit(EXTI_RTSR,lineNum);
			break;
	}
}


void vEXIT_Software_Trigger(uint8 lineNum){
	setBit(EXTI_SWIER,lineNum);
}

void vEXIT_setPort(uint8 lineNum,uint8 PortName){
	if(lineNum<=3){
		SYSCFG_EXTICR->SYSCFG_EXTICR1 &=~(0xF<<((lineNum%4)*4));
		SYSCFG_EXTICR->SYSCFG_EXTICR1 |=(PortName<<((lineNum%4)*4));
	}
	else if(lineNum<=7){
		SYSCFG_EXTICR->SYSCFG_EXTICR2 &=~(0xF<<((lineNum%4)*4));
		SYSCFG_EXTICR->SYSCFG_EXTICR2 |=(PortName<<((lineNum%4)*4));
	}
	else if(lineNum<=11){
		SYSCFG_EXTICR->SYSCFG_EXTICR3 &=~(0xF<<((lineNum%4)*4));
		SYSCFG_EXTICR->SYSCFG_EXTICR3 |=(PortName<<((lineNum%4)*4));
	}
	else if(lineNum<=15){
		SYSCFG_EXTICR->SYSCFG_EXTICR4 &=~(0xF<<((lineNum%4)*4));
		SYSCFG_EXTICR->SYSCFG_EXTICR4 |=(PortName<<((lineNum%4)*4));
	}
}