
//****PISCA LED****
//#include <Pisca.h>

#include <16F877A.h>
#device ADC=10
#use delay(crystal=20000000)

#define LED PIN_C4
#define DELAY 500

void main()
{
   output_high(PIN_C3);
   //output_high(PIN_B1);
   //output_low(PIN_B3);
   while(TRUE)
   {
      output_high(PIN_C3);
      //Example blinking LED program
      output_low(LED);
      delay_ms(DELAY);
      output_high(LED);
      delay_ms(DELAY);

      //TODO: User Code
   }

}
