#include"NVIC.h"

void vNVIC_SetEnable(uint8 u8Intrupt_NUM){
	
	if(u8Intrupt_NUM <=31)										//from 0 to 31
		NVIC_ISER0=(1u<<u8Intrupt_NUM);
	else if(u8Intrupt_NUM <=63){							//from 32 to 63
		NVIC_ISER1=(1u<<(u8Intrupt_NUM%32));
	}
	else if(u8Intrupt_NUM <=90){							//from 64 to 90
		NVIC_ISER2=(1u<<(u8Intrupt_NUM%64));
	}
}

void vNVIC_clearEnable(uint8 u8Intrupt_NUM){
	if(u8Intrupt_NUM <=31)										//from 0 to 31
		NVIC_ICER0=(1u<<u8Intrupt_NUM);
	else if(u8Intrupt_NUM <=63){							//from 32 to 63
		NVIC_ICER1=(1u<<(u8Intrupt_NUM%32));
	}
	else if(u8Intrupt_NUM <=90){							//from 64 to 90
		NVIC_ICER2=(1u<<(u8Intrupt_NUM%64));
	}
}


void vNVIC_setPending(uint8 u8Intrupt_NUM){
	if(u8Intrupt_NUM <=31)										//from 0 to 31
		NVIC_ISPR0=(1u<<u8Intrupt_NUM);
	else if(u8Intrupt_NUM <=63){							//from 32 to 63
		NVIC_ISPR1=(1u<<(u8Intrupt_NUM%32));
	}
	else if(u8Intrupt_NUM <=90){							//from 64 to 90
		NVIC_ISPR2=(1u<<(u8Intrupt_NUM%64));
	}
}

void vNVIC_clearPending(uint8 u8Intrupt_NUM){
	if(u8Intrupt_NUM <=31)										//from 0 to 31
		NVIC_ICPR0=(1u<<u8Intrupt_NUM);
	else if(u8Intrupt_NUM <=63){							//from 32 to 63
		NVIC_ICPR1=(1u<<(u8Intrupt_NUM%32));
	}
	else if(u8Intrupt_NUM <=90){							//from 64 to 90
		NVIC_ICPR2=(1u<<(u8Intrupt_NUM%64));
	}
}


uint8 u8NVIC_ReadActive(uint8 u8Intrupt_NUM){
	uint8 activeState =0;
	if(u8Intrupt_NUM <=31){										//from 0 to 31
		activeState= checkBit(NVIC_IABR0,u8Intrupt_NUM);
	}
	else if(u8Intrupt_NUM <=63){							//from 32 to 63
		activeState= checkBit(NVIC_IABR1,(u8Intrupt_NUM%32));
	}
	else if(u8Intrupt_NUM <=90){							//from 64 to 90
		activeState= checkBit(NVIC_IABR2,(u8Intrupt_NUM%64));
	}
	return activeState;
}



void vNVIC_setIBR(uint8 u8Intrupt_NUM ,uint8 Group_Pri,uint8 SubGroup_Pri ,PRI_CONFIG CONFIG){
	SCB_AIRCR =0x05FA0000;
	switch(CONFIG){
		//case 0b0xx grop [7:4]  	subgroup none
		case PRIGROUP_CONFIG0:
			SCB_AIRCR =0x05FA0300;
			//NVIC_IPR[u8Intrupt_NUM]=(Group_Pri<<4u);
			break;
		
		//case 0b100 grop [7:5]  	subgroup [4]
		case PRIGROUP_CONFIG1:
			SCB_AIRCR =0x05FA0400;
			//NVIC_IPR[u8Intrupt_NUM]=((Group_Pri<<5u)|(SubGroup_Pri<<4u));
			break;
		
		//case 0b101 grop [7:6] 	subgroup [5:4]
		case PRIGROUP_CONFIG2:
			SCB_AIRCR =0x05FA0500;
			//NVIC_IPR[u8Intrupt_NUM]=((Group_Pri<<6u)|(SubGroup_Pri<<4u));
			break;
		
		//case 0b110 grop [7]  		subgroup [6:4]
		case PRIGROUP_CONFIG3:
			SCB_AIRCR =0x05FA0600;
			//NVIC_IPR[u8Intrupt_NUM]=((Group_Pri<<7u)|(SubGroup_Pri<<4u));
			break;
		
		//case 0b111 grop None  	subgroup [7:4]
		case PRIGROUP_CONFIG4:
			SCB_AIRCR =0x05FA0700;
			//NVIC_IPR[u8Intrupt_NUM]=(SubGroup_Pri<<4u);
		break;
		}
		NVIC_IPR[u8Intrupt_NUM]=(Group_Pri<<(4u+CONFIG))|(SubGroup_Pri<<4u);
}
