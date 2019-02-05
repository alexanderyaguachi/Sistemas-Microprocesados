/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Nombre: Alexander Yaguachi
 * Deber:Realizar un sistema que permita configurar por comunicación 
 * serial o por pulsadores el modo sleep cada 25 segundos.
 * Watchdog timer (WDT):
                  SLEEP_15MS
                  SLEEP_30MS
                  SLEEP_60MS
                  SLEEP_120MS
                  SLEEP_250MS
                  SLEEP_500MS
                  SLEEP_1S
                  SLEEP_2S
                  SLEEP_4S
                  SLEEP_8S
                  SLEEP_FOREVER
 
    
    LowPower.powerDown(WDT, modos);
 */
#include <MsTimer2.h>   // libreria control de tiempos
#include<avr/sleep.h>
#include<avr/power.h>
#include <LowPower.h>   //libreria para apagar y encender el sistema de arduino
int cont=0;

void setup() {
  Serial.begin(9600);
  //  MsTimer2::set(500,conteo);// Se inicia el timer 
  // MsTimer2::start();        // Se inicia el timer
  attachInterrupt(0,inte,LOW);
}
void loop() {
  
}
void inte(){
  for(;cont<25;cont++){ // condicion para que el sistema se duerma 19 segundos
    //cont++;
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); 
    }
    Serial.println(analogRead(A0));  // imprime el conversor analogico
    Serial.printl("Sistema encendido");
    delay(400);   // 
    cont=0;       //reiniciamos el sistema    
  }
}
