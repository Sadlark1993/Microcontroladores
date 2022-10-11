/*
SDA = PIN_C4;
SCL = PIN_C3;
*/

//#include <mainRTC.h>
#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)

//comunicacao pelo protocolo I2C
#use I2C(MASTER, I2C1, SLOW = 100000, STREAM = DS3231_STREAM)

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
#include "DS3231.c"

RTC_Time *myTime;

void main()
{  
   delay_ms(100);
   lcd_ini();
   delay_ms(100);
   printf(lcd_escreve, "\fIniciando...");
   delay_ms(1000);  // wait a second
   /*
   myTime = RTC_Get();
   printf(lcd_escreve,"\fvai comecar");
   printf(lcd_escreve, "\fTIME: %02u:%02u:%02u\n", myTime->hours, myTime->minutes, myTime->seconds);
   printf(lcd_escreve,"atualizando...");
   delay_ms(3000);
   
   //set RTC time to 21:08:47 (hh:mm:ss) and date to 03-01-19 (dd-mm-yy)
   myTime->hours = 3;
   printf(lcd_escreve,"\fhours");
   myTime->minutes = 47;
   printf(lcd_escreve,"\fminutes");
   myTime->seconds = 47;
   myTime->dow     = TUESDAY;
   myTime->day     = 11;
   myTime->month   = AUGUST;
   myTime->year    = 22;
   // write time and date to the RTC chip
   RTC_Set(myTime);

   //printf(lcd_escreve,"\fPassou");
   delay_ms(100);
   printf(lcd_escreve, "\fTIME: %02u:%02u:%02u", myTime->hours, myTime->minutes, myTime->seconds);
   */
   IntSqw_Set(OUT_1Hz);
   while(TRUE)
   {
   myTime = RTC_Get();
   printf(lcd_escreve, "\fTIME: %02u:%02u:%02u", myTime->hours, myTime->minutes, myTime->seconds);
   delay_ms(300);
   }
}
