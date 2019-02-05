/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Nombre: Alexander Yaguachi
 * Deber: Realizar un programa que permita poner al sistema 19 segundos 
 * en modo sleep, se despierte, realice un lectura del conversor análogo 
 * digital, lo imprimapor comunicación serial y vuelva a dormir 19 segundos.
 */
#include <MsTimer2.h>   // libreria control de tiempos
#include<avr/sleep.h>
#include<avr/power.h>
#include <LowPower.h>   //libreria para apagar y encender el sistema de arduino
int cont=0;
void setup() {
  Serial.begin(9600);
  MsTimer2::set(500,conteo);// Se inicia el timer 
  MsTimer2::start();        // Se inicia el timer
}
void loop() {
  
}
void conteo(){
  for(;cont<20;cont++){ // condicion para que el sistema se duerma 19 segundos
    //cont++;
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); 
    }
    else
    {
    Serial.println(analogRead(A0));  // imprime el conversor analogico
   Serial.printl("Sistema encendido");
    delay(400);   // 
    cont=0;       //reiniciamos el sistema    
  }
}
