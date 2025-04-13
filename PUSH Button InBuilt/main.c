#include<stdint.h>

int main(void)
{
   uint32_t *pAHB2ENR1 =(uint32_t*) 0x46020c8c;  // ADDRESSS OF RCC_AHB2ENR1  TO GIVE CLOCK FOR GPIOS
   uint32_t *GPIOB_MODER =(uint32_t*)0x42020400;  //  ADDRESSS OF GPIOB_MODER
   uint32_t *GPIOB_ODR =(uint32_t*) 0x42020414;  //  ADDRESSS OF GPIOB_ODR
   uint32_t *GPIOC_MODER =(uint32_t*)0x42020800;
   uint32_t *GPIOC_IDR =(uint32_t*)0x42020810;

   *pAHB2ENR1 |= 3<<1;

   *GPIOB_MODER &= ~(3<<14);
   *GPIOB_MODER |=1<<14;

   *GPIOC_MODER &= ~(3<<26);
while(1){
   if((*GPIOC_IDR)&&(1<<13)){
	   *GPIOB_ODR |= 1<<7;  // set 1 to bit-7 of port b
	   for( volatile int i=0;i<100000;i++); // delay
	   *GPIOB_ODR &=  ~(1<<7); //clear 1
	   for(volatile int i=0;i<100000;i++);
   }

}
}
