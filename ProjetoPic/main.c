//Projeto de PIC

//#include <main.h>
#include <16F877A.h>
#device ADC=8

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

/*
   Esquema dos pinos do teclado:
   
   R1 = RD0
   R2 = RD1
   R3 = RD2
   R4 = RD3
   C1 = RB1
   C2 = RB2
   C3 = RB3
   C4 = RB4
*/

#include <mod_lcd.c>
#include "kbd_ext_board2.c"

unsigned char tmp;

#INT_RB
void  RB_isr(void) 
{
   clear_interrupt(INT_RB);
   disable_interrupts(INT_RB);
   tmp = tc_tecla(1500);
   output_toggle(PIN_C4);
   enable_interrupts(INT_RB);
}

void main()
{
   //setando portas b
   set_tris_b(0xF0);
   port_b_pullups(true);
   
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   
   delay_ms(100);
   lcd_ini();
   delay_ms(100);
   
   printf(lcd_escreve, "\fIFMT 2022");
   delay_ms(1000);
   printf(lcd_escreve, "\f     TECLADO     ");
   delay_ms(2000);
   
   while(TRUE)
   {
      if(tmp != 255){
         printf(lcd_escreve, "\fButton %c", tmp);
      }else{
         printf(lcd_escreve, "\f     TECLADO L    ");
      }
   }
}
