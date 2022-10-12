//#include <charTab.h>
#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

//Esquema dos pinos do LCD
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

void main()
{
   delay_ms(100);
   lcd_ini();
   delay_ms(100);
   
   printf(lcd_escreve, "\fIFMT 2022");
   delay_ms(1500);
   unsigned char c = '5';
   unsigned int i = c-48;

   while(TRUE)
   {
   /*
      c = '0';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '1';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '2';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '3';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '4';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '5';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '6';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '7';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '8';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      
      c = '9';
      printf(lcd_escreve, "\f%c: %u", c, c);
      delay_ms(2000);
      //48 - 57.
      */
      printf(lcd_escreve, "\f5: %u", i);
      delay_ms(2000);
      
   }

}
