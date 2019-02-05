/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Alexander Ismael
 * 
 */
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <LowPower.h> //librería LowPower
#include <avr/power.h> //librerias sleep
#include <avr/sleep.h> 

const int rs = 12, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6; // pines lcd16x2
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int horas=0;    //variable hotas
int minutos=0;  //varaible minutos
int segundos=0; // variable segundos

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //inicia comunicaion serial
  lcd.begin(16,2);    //iniciar lcd
  MsTimer2::set(1000, reloj);//tiempo
  MsTimer2::start();
  attachInterrupt(0,levantar,FALLING); //interrup cion para levantar el sistema
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
  sleep_enable();
  
  
}
void loop() {
  // put your main code here, to run repeatedly:
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);   //dormir el sistema
   sleep_enable();
}
void graficar(){
   lcd.setCursor(7,0);
   lcd.print("Reloj");
   lcd.clear();
   lcd.setCursor(5,0);
   lcd.print("Reloj");
   lcd.setCursor(0,1);
   lcd.print("Hora: ");
    lcd.setCursor(6,1); //posiscion donde se imprime
   lcd.print(horas);    //Imprimer la hora
   lcd.setCursor(8,1);  //posiscion donde se imprime
   lcd.print(": ");
   lcd.setCursor(9,2);  //posiscion donde se imprime
   lcd.print(minutos);  //Imprimer los minutos
   lcd.setCursor(11,2);
   lcd.print(": ");     //posiscion donde se imprime
   lcd.setCursor(12,2); //posiscion donde se imprime
   lcd.print(segundos); //Imprimer los segundos
    
}
void reloj(){
  LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF); // modo sleep para ahorrar energia
  power_all_enable();  // apaga los perifericos
  segundos++;
  if(segundos>=60){
    segundos=0;
    minutos++;
    }
  if(minutos>=60){
    minutos=0;
    horas++;
    }
  if(horas>=24){
    horas=0;
     }
 graficar(); 
 }
 void levantar (){ 
    power_adc_enable(); 
  }else{
    power_adc_disable();
    }
  }
 
