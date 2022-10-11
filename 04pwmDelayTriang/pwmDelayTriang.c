
//****Onda Triangular PMW****
//#include <pwmDelayTriang.h>

#include <16F877A.h>
#device ADC=10
#use delay(crystal=20000000)


void main()
{
   unsigned int16 timer=0, duty=0, period=1000;

   while(TRUE)
   {
      /*
      //PWM 40%
      output_high(PIN_D1);
      delay_us(400);
      output_low(PIN_D1);
      delay_us(600);
      */
      
      //pwm onda triangular
      for(duty = 0; duty<=1000; duty++){
         for(timer=0; timer<=10; timer++){
            output_high(PIN_D1);
            delay_us(duty);
            output_low(PIN_D1);
            delay_us(period-duty);
         }
      
      }
      for(duty = 999; duty>=0; duty--){
         for(timer=0; timer<=10; timer++){
            output_high(PIN_D1);
            delay_us(duty);
            output_low(PIN_D1);
            delay_us(period-duty);
         }
      
      }
      


      //TODO: User Code
   }

}
