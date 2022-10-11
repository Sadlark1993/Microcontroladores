//#include <main.h>
#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

/*

#INT_RB
void  RB_isr(void) 
{
   //clear_interrupt(INT_RB);
   output_toggle(PIN_C5);
}
*/

void main()
{
   //setting all of B ports to input
   set_tris_b(0xFF);//its 1 byte. bit 1 means input, bit 0 means output.
   /*
   output_c(0);
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
*/
   while(TRUE){
      if(input(PIN_B5)){
         output_high(PIN_C4);
      }else{
         output_low(PIN_C4);
      }
   }

}
