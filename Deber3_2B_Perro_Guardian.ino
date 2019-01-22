//UNIVERSIDAD TECNICA DEL NORTE
/*
 * ALEXANDER YAGUACHI
 *       WDTO_15MS
          WDTO_30MS
          WDTO_60MS
          WDTO_120MS
          WDTO_250MS
          WDTO_500MS
          WDTO_1S
          WDTO_2S
          WDTO_4S
          WDTO_8S
 */
#include <avr/wdt.h> //Librería perro guardían
#include <LiquidCrystal.h> //Librería LCD
#include <MsTimer2.h> //Librería timer2
#include <EEPROM.h>

const int rs = 12, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6; //pines del arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int cont = 0;
float pot;
float poten;
void setup() { 
  lcd.begin(16, 2); //Inicia LCD 16X2
  lcd.setCursor(0, 0); //Posición inicial
  lcd.print("TIEMPO DE CONFIGURACION"); //Impmrime mensaje inicial de configuracion
  MsTimer2::set(1000, conteo); //timer esta en segundo
  attachInterrupt(0,stado, RISING); //Interrupción
}

void loop() {
  // put your main code here, to run repeatedly:
 poten=analogRead(0);
 
  pot = (poten* 5.00) / 1023.0; //conversión CAD
  if (pot >= 1.0 && pot <= 2.0) { //verifica cuando el cont esta 10s
    lcd.setCursor(0, 1); //posicion donde se impreme el CAD
    lcd.print(cont); 
    cont = 10;
  } else if (pot > 2.00 && pot <= 3.00) { //verifica cuando el cont esta 20s
    lcd.setCursor(0, 1); //posicion donde se impreme el CAD
    lcd.print(cont);
    cont = 20;
  } else if (pot > 3.00 && pot <= 4.00) { //verifica cuando el cont esta 30s
    cont = 30;
    lcd.setCursor(0, 1); //posicion donde se impreme el CAD
    lcd.print(cont);
    cont = 30;
  } else if (pot > 4.00 && pot <= 5.00) { //verifica cuando el cont esta 40s
    lcd.setCursor(0, 1); //posicion donde se impreme el CAD
    lcd.print(cont); 
    cont = 40;
  }
}

void stado(){
 switch(cont){
  case 10:
  MsTimer2::start();
  lcd.setCursor(0, 0);
  lcd.print("PERRO.G :10S");//impresion en LCD
  cont = 10; 
  break;
  case 20:
  MsTimer2::start();
  lcd.setCursor(0, 0);
  lcd.print("PERRO.G :20S");//impresion en lcd
  cont = 20; 
  break;
  case 30:
  MsTimer2::start();
  lcd.setCursor(0, 0);
  lcd.print("PERRO.G :30S");//impresion en lcd
  cont = 30; 
  break;
  case 40:
  MsTimer2::start();
  lcd.setCursor(0, 0);
  lcd.print("PERRO.G :40S");//impresion en lcd
  cont = 40; 
  break;
 }
}
void conteo(){
  cont--;
  if (cont == 1) { //Activa el Perro Guardiam
    wdt_enable(WDTO_1S); //Activa Perro Guardian en 1S
  }
}
