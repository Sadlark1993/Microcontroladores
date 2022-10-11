//Autor: Claudio Zimmermann Junior
/*
   Faca a leitura analogica do pino A0 configurado em 8 bits.
O dispositivo deve apresentar 7 niveis de alerta atraves do dispositivo de
3 segmentos. Tabela:

Nivel    intervalo     valor no dispositivo
N1:      127<=x<143     1
N2:      143<=x<159     6
N3:      159<=x<175     2
N4:      175<=x<191     5
N5:      191<=x<207     3
N6:      207<=x<223     4
N7:      223<=X<239     7

pinos:a = PIN_B2;
      b = PIN_B1;
      c = PIN_B0;
*/
//#include <mini-disp3.h>

#include <16F877A.h>
#device ADC=8
#use delay(crystal=20000000)

void main()
{
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_64);
   
   unsigned int valorAn;
   set_adc_channel(0);
   delay_ms(1);
   output_low(PIN_A5); //Desligar display 7 seg.
   output_b(0); //Iniciar com todos os leds B desligados.

   while(TRUE)
   {
      valorAn = read_adc();
      output_d(valorAn); //imprime o valor lido na porta D
      /*
      a = PIN_B2;
      b = PIN_B1;
      c = PIN_B0;
      */
      if(valorAn>= 127 && valorAn < 239){
         if(valorAn<143) output_b(1);
         else if(valorAn<159) output_b(6);
         else if(valorAn<175) output_b(2);
         else if(valorAn<191) output_b(5);
         else if(valorAn<207) output_b(3);
         else if(valorAn<223) output_b(4);
         else output_b(7);       
      }else{
         output_b(0);
      }
   }

}
