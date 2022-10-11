//Interrupcao Externa No B0

//#include <main.h>

#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

   unsigned char tmp;

#INT_EXT
void  EXT_isr(void) 
{
   clear_interrupt(INT_EXT);
   output_toggle(PIN_C4);
}

void main()
{
   set_tris_b(0x01);
   //set_tris_d(0x00);
   //set_tris_C(0xFF);
   output_low(PIN_D1);
   output_low(PIN_D2);
   
   ext_int_edge(H_TO_L);
   clear_interrupt(INT_EXT);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      //TODO: User Code
   }

}
