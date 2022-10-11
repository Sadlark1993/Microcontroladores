
//****Conversor AD****
//#include <ADConv.h>

#include <16F877A.h>
#device ADC=8
#use delay(crystal=20000000)

#include <math.h>

void main()
{
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_DIV_64);
   
   //char a[] = "aaa";//testando string
   //boolean v = true;
   
   unsigned int valorAn;
   set_adc_channel(0);
   delay_ms(1);

   while(TRUE)
   {
      valorAn = read_adc();
      valorAn = (int)((valorAn/32.0)+0.5f);
      valorAn = pow(2,valorAn);
      output_d(valorAn-1);
      //TODO: User Code
   }

}
