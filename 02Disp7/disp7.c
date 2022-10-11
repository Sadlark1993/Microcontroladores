/*
   O algoritmo abaixo exibe numeros nosdisplays de 7 segmentos incrementando 
do dado valor inicial ate o dado valor final. Depois ele faz o inverso,
decrementando ate o valor final. E assim sucessivamente.
*/

//#include <disp7.h>

#include <16F877A.h>
#device ADC=8
#use delay(crystal=20000000)

//constantes
#define DELAY 5
#define INICIO 9
#define FINAL 92
#define DISP4 PIN_A5
#define DISP3 PIN_A4
#define DISP2 PIN_A3
#define DISP1 PIN_A2
#define TEMPO 30

void main()
{
   unsigned int n[10];
   
   n[0] = 0b00111111; //0
   n[1] = 0b00000110; //1
   n[2] = 0b01011011; //2
   n[3] = 0b01001111; //3
   n[4] = 0b01100110; //4
   n[5] = 0b01101101; //5
   n[6] = 0b01111101; //6
   n[7] = 0b00000111; //7
   n[8] = 0b01111111; //8
   n[9] = 0b01101111; //9
   
   output_high(DISP4);
   output_high(DISP3);
   output_low(DISP2);
   output_low(DISP1);

   unsigned int u;
   unsigned int d;
   
   while(TRUE)
   {
      //incrementando...
      for(unsigned int i = INICIO;i <= FINAL;i++){
         //definindo dezenas e unidades
         d = i/10;
         u = i%10;
         
         for(unsigned int t=0; t<= TEMPO; t++){//tempo de exibicao por numero
            output_low(DISP3);
            output_d(n[u]);
            output_high(DISP4);
            delay_ms(DELAY);
            
            output_low(DISP4);
            output_d(n[d]);
            output_high(DISP3);
            delay_ms(DELAY);
         }
         
      }
      
      //decrementando...
      for(unsigned int i = FINAL;i >= INICIO;i--){
         //definindo dezenas e unidades
         d = i/10;
         u = i%10;
         //tempo em que o numero ficarah mostrando no disp.
         for(unsigned int t=0; t<= TEMPO; t++){
            output_low(DISP3);
            output_d(n[u]);
            output_high(DISP4);
            delay_ms(DELAY);
            
            output_low(DISP4);
            output_d(n[d]);
            output_high(DISP3);
            delay_ms(DELAY);
         }
         
      }
      
      
      //TODO: User Code
   }

}
