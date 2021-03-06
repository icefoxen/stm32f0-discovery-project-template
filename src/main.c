#include "stm32f0xx.h"

#define BSRR_VAL        0x0300


void delay(int a);

int main(void) {
	/*!< At this stage the microcontroller clock setting is already configured,
	     this is done through SystemInit() function which is called from startup
	     file (startup_stm32f0xx.s) before to branch to application main.
	     To reconfigure the default setting of SystemInit() function, refer to
	     system_stm32f0xx.c file
	   */

	/* GPIOC Periph clock enable */
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;


	GPIOC->MODER |= (GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0) ;
	/* Configure PC8 and PC9 in output  mode  */

	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_8 | ~GPIO_OTYPER_OT_9) ;
	// Ensure push pull mode selected--default

	GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8 | GPIO_OSPEEDER_OSPEEDR9);
	//Ensure maximum speed setting (even though it is unnecessary)

	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR8 | GPIO_PUPDR_PUPDR9);
	//Ensure all pull up pull down resistors are disabled


	volatile int i = 0;
	int increment = 10000;
	while(1) {
		/* Set PC8 and PC9 */
		GPIOC->BSRR = BSRR_VAL;
		delay(i);
		/* Reset PC8 and PC9 */
		GPIOC->BRR = BSRR_VAL;
		delay(i);
		//i += increment;
		i += increment;
		if(i > 1000000) {
			increment *= -1;
		}
		if(i <= 0) {
			increment *= -1;
		}
	}

	return 0;
}


void delay(int a) {
	volatile int i, j;

	for(i = 0 ; i < a ; i++) {
		j++;
	}

	return;
}

