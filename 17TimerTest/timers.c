//Testando Timer1

//#include <timers.h>
#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

unsigned int aux;

#INT_TIMER1
void  TIMER1_isr(void) 
{
   aux++;
   if(aux==10){
      aux=0;
      output_toggle(PIN_D1); //esse pino muda o estado a cada 1 segundo
   }
}

void main()
{
   aux = 0;
   output_low(PIN_D1);
   output_low(PIN_D0);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);      //104 ms overflow


   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      output_toggle(PIN_D0); //esse pino muda o estado 4x por segundo
      delay_ms(250);
   }

}
