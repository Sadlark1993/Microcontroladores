//#include <main.h>

#include <16F876A.h>
#device ADC=10
#use delay(crystal=20000000)

#define LED PIN_c4
#define LED2 PIN_c1
#define DELAY 1000

void main()
{
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   

   while(TRUE)
   {

      //Example blinking LED program
      output_low(LED);
      delay_ms(DELAY);
      output_high(LED);
      delay_ms(DELAY);
      output_low(LED2);
      delay_ms(DELAY);
      output_high(LED2);
      delay_ms(DELAY);

      //TODO: User Code
   }

}
