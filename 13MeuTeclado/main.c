//****LCD E TECLADO****
//pino da coluna: output
//pino da linha: input

//#include <teclado.h>

#include <16F877A.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

#ifndef lcd_enable
   #define lcd_enable pin_E1 // pino enable do LCD
   #define lcd_rs pin_E2 // pino rs do LCD
   //#define lcd_rw pin_e2 // pino rw do LCD
   #define lcd_d4 pin_d4 // pino de dados d4 do LCD
   #define lcd_d5 pin_d5 // pino de dados d5 do LCD
   #define lcd_d6 pin_d6 // pino de dados d6 do LCD
   #define lcd_d7 pin_d7 // pino de dados d7 do LCD
#endif


#include <mod_lcd.c>
#include "myKeypad.c"

void main()
{
   set_tris_b(0xF0);
   //output_b(0xF0);
   port_b_pullups(true);
   
   unsigned char tmp;
   delay_ms(100);
   lcd_ini();
   delay_ms(100);
   
   printf(lcd_escreve, "\fIFMT 2022");
   delay_ms(1000);
   printf(lcd_escreve, "\f     TECLADO     ");
   delay_ms(2000);
   
   output_high(PIN_C4);
 
   
   while(TRUE)
   {
      tmp = tc_tecla(20);
      
      if(tmp != 255){
         printf(lcd_escreve, "\fButton %c", tmp);
      }
      delay_ms(30);
   }
}
