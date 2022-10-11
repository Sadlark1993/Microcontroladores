
//****Interrupcao****
//#include <interrupt.h>

#include <16F877A.h>
#device ADC=10
#use delay(crystal=20000000)


int c=0; 

#INT_RTCC
void  RTCC_isr(void) 
{
   //entra a cada 13.1ms
   if(c++ == 77){ //executar a cada 1 s
      output_toggle(PIN_D2);
      c = 0;
   }
}

void main()
{

   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256|RTCC_8_BIT);      //13,1 ms overflow


   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      output_high(PIN_B4);


      //TODO: User Code
   }
}
