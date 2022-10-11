/*
to the key pad, the signal is sended by the column pins, and collected by the
row pins.

keys meaning
A = right
B = left
C = up
D = down
# = exit
* = enter

keypad schematic
1 = C1+R1;
2 = C2+R1;
3 = C3+R1;
4 = C1+R2;
5 = C2+R2;
6 = C3+R2;
7 = C1+R3;
8 = C2+R3;
9 = C3+R3;
0 = C3+R4;
A(right) = C4+R1;
B(left) = C4+R2;
C(up) = C4+R3;
D(down) = C4+R4;
#(exit) = C3+R4;
*(enter) = C1+R4;

keypad pins connection
R1 PIN_B4
R2 PIN_B5
R3 PIN_B6
R4 PIN_B7
C1 PIN_B0
C2 PIN_B1
C3 PIN_B2
C4 PIN_B3
*/


//#include <projetoPIC.h>
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
#include "kbd_ext_board2.c"

unsigned char k;

#INT_RB
void  RB_isr(void) 
{
   clear_interrupt(INT_RB);
   output_toggle(PIN_D0);
   //disable_interrupts(INT_RB);
   if(!input(PIN_B4)||!input(PIN_B5)||!input(PIN_B6)||!input(PIN_B7)){
      //printf(lcd_escreve, "\fEntrando int");
      k = tc_tecla(15);
      output_low(PIN_B0);
      output_low(PIN_B1);
      output_low(PIN_B2);
      output_low(PIN_B3);
      //printf(lcd_escreve, "\fSaindo int");
   }
   //enable_interrupts(INT_RB);
}

//tabelas de dados dos solenoides
unsigned int s1[4][4] = {{13,0,14,30},
                         {17,30,19,0},
                         {0,0,2,20},
                         {0,0,0,0}};
                         
unsigned int s2[4][4] = {{0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0}};
                         
unsigned int s3[4][4] = {{0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0}};
                         
unsigned int s4[4][4] = {{0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0}};
                         


void sol1(){
   unsigned int i = 0;
   int1 f = 1;
   while(f){
      printf(lcd_escreve, "\fSol1 T%u\n%02u:%02u-%02u:%02u",(i+1), s1[i][0], s1[i][1], s1[i][2], s1[i][3]);
      if(k=='D'&&i<3){
         //printf(lcd_escreve, "\fEntrou D");
         i++; 
         k = 255;
      }else if(k=='C'&&i>0){
         //printf(lcd_escreve, "\fEntrou C");
         i--;
         k = 255; 
      }else k=255;
      delay_ms(150);
      output_toggle(PIN_D1);
   }
   
   
}

void main()
{
   //setando portas b
   set_tris_b(0xF0);
   port_b_pullups(true);
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
   
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   
   delay_ms(100);
   lcd_ini();
   delay_ms(100);
   printf(lcd_escreve, "\fIFMT 2022");
   
   sol1();

   while(TRUE)
   {
         output_toggle(PIN_D1);
         delay_ms(1000);
   }

}
