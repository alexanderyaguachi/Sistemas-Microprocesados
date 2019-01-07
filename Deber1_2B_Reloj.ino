/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 * Programa que muestre el segundero,minutero y horero visto en una lcd.
 * 
 */
#include <MsTimer2.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int horas=0;
int minutos=0;
int segundos=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(1000, reloj);
  MsTimer2::start();
}
void loop() {
  // put your main code here, to run repeatedly:
 
}
void graficar(){
   lcd.setCursor(7,0);
   lcd.print("Reloj");
   lcd.clear();
   lcd.setCursor(5,0);
   lcd.print("Reloj");
   lcd.setCursor(0,1);
   lcd.print("Hora: ");
    lcd.setCursor(6,1);
   lcd.print(horas);
   lcd.setCursor(8,1);
   lcd.print(": ");
   lcd.setCursor(9,2);
   lcd.print(minutos);
   lcd.setCursor(11,2);
   lcd.print(": ");
   lcd.setCursor(12,2);
   lcd.print(segundos); 
}
void reloj(){
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
