

/*   LED BLINK OF INBUILT LED PB7 ON STM32U575ZI-Q */

#include<stdint.h>

int main(void)
{
   uint32_t *pAHB2ENR1 =(uint32_t*) 0x46020c8c;  // ADDRESSS OF RCC_AHB2ENR1  TO GIVE CLOCK FOR GPIOS
   uint32_t *GPIOB_MODER =(uint32_t*)0x42020400;  //  ADDRESSS OF GPIOB_MODER
   uint32_t *GPIOB_ODR =(uint32_t*) 0x42020414;  //  ADDRESSS OF GPIOB_ODR

   *pAHB2ENR1 = *pAHB2ENR1 | (1<<1);  //enable 2 bit for gpiob
   *GPIOB_MODER &= ~(3<<14);  //Clear bit 15 and 14 to set O/P mode
   *GPIOB_MODER |= (1<<14);  // set 01 to bit 15 and 14 to set O/P mode
   while(1){
	   *GPIOB_ODR |= 1<<7;  // set 1 to bit-7 of port b
	   for( volatile int i=0;i<100000;i++); // delay
	   *GPIOB_ODR &=  ~(1<<7); //clear 1
	   for(volatile int i=0;i<100000;i++);
   }

}


