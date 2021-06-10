#include "GPIO.h"
#include "NVIC.h"
#include "EXIT.h"
#define RCC_AHB1ENR				(*((uint32*)0x40023830))

volatile uint8 flag=0;
void SystemInit(){}
	
int main(void){
	RCC_AHB1ENR |=(1u<<6);
	vGPIO_PinSetMode(GPIOG,PIN13,Mode_output);
	vGPIO_PinSetMode(GPIOG,PIN14,Mode_output);
	
	vGPIO_PinSetOutType(GPIOG,PIN13,Mode_Output_pushpull);
	vGPIO_PinSetOutType(GPIOG,PIN14,Mode_Output_pushpull);

	vGPIO_PinSetOutSpeed(GPIOG,PIN13,Speed_output_low);
	vGPIO_PinSetOutSpeed(GPIOG,PIN14,Speed_output_low);
	//////////////////////////////////////////////////////////////
	// NVIC
	vNVIC_SetEnable(6);
	//EXIT0 where PA0 is where the switch is connected
	vEXIT_EnableLINE(0);
	vEXIT_EVENT_Type(0,RISING_EVENT);
	vEXIT_setPort(0,GPIOA);
	
	while(1){
		int i;
			if(flag==1){
		vGPIO_PinWrite(GPIOG,PIN13,HIGH);
		vGPIO_PinWrite(GPIOG,PIN14,HIGH);
		for(i=0;i<50000;i++);
		vGPIO_PinWrite(GPIOG,PIN13,LOW);
		vGPIO_PinWrite(GPIOG,PIN14,LOW);
		for(i=0;i<50000;i++);
		flag=0;
	}
}
}


void EXIT0_IQRHandler(void)
{
	flag=1;
}