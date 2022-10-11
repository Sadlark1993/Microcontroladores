//autor: Claudio Zimmermann Jr.
/*
   Faca o circuito e o programa que liga um LED1 e desliga LED2 quando o botao
(BOT1) estiver apertado e desliga LED1 e liga o LED2 se o botao (BOT1) estiver
solto. Os LED 3, 4 e 5 devem ficar piscando com frequencias de 1.3, 2 e 3.5
vezes n Hz. Onde n eh igual a soma do ultimo e penultimo numero da sua 
matricula.

Pinos:
 LED1 = PIN_D0
 LED2 = PIN_D1
 LED3 = PIN_D2
 LED4 = PIN_D3
 LED5 = PIN_D4
 
 BOT1 = PIN_B3

*/

//#include <piscInterrupt.h>
#include <16F877A.h>
#device ADC=10
#use delay(crystal=20000000)

#define LED1 PIN_D0
#define LED2 PIN_D1
#define LED3 PIN_D2
#define LED4 PIN_D3
#define LED5 PIN_D4

unsigned long int c = 1;
unsigned long int b = 1;
unsigned long int a = 1;

#INT_RTCC
void  RTCC_isr(void) 
{
   if(c++ == 310){
      output_toggle(LED5);
      c = 1;
   }
   if(b++ == 543){
      output_toggle(LED4);
      b = 1;
   }
   if(a++ == 835){
      output_toggle(LED3);
      a = 1;
   }
   
   
}

void main()
{
   output_d(0);
   int1 i = 0;

   
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_BIT);      //51,2 us overflow


   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      //input pull up (valor 0 no pino quando aperta o botao).
      i = input_state(pin_B3);
      if(i){
         output_high(LED2);
         output_low(LED1);
      }else{
         output_high(LED1);
         output_low(LED2);
      }

      //TODO: User Code
   }

}
