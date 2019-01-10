#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
LiquidCrystal lcd (12,10,9,8,7,6);//configurar pines LCD
int horero=0, minutero=0, segundero=0,horeroA=0, minuteroA=0;  //variables de conteo
int opcion=0;
int mod=0;
int buzzer   = 22;        //pin de la alarma
void setup() {
Serial.begin(9600);  // iniciamos la comunicaión serial   
lcd.begin(16,2);     // iniciamos la lcd
MsTimer2::set(1000,contador);  //1 segundo
MsTimer2::start();
pinMode(buzzer,OUTPUT);
attachInterrupt(digitalPinToInterrupt(19),bfuncion,FALLING);    //interrupciones de sistemas
attachInterrupt(digitalPinToInterrupt(20),modificar,FALLING);   //interrupciones de sistemas
attachInterrupt(digitalPinToInterrupt(21),aumentar,FALLING);    //interrupciones de sistemas
 horero=EEPROM.read(0);
 minutero=EEPROM.read(1);
 horeroA=EEPROM.read(2);
 minuteroA=EEPROM.read(3);
}
void loop() {
reloj();
Alarma();
}
void bfuncion(){
opcion=1-opcion;
 switch(opcion){   
    case 0:
    Serial.println("Modificar Hora");
    break;
    case 1:
    Serial.println("Crear Alarma"); 
    break;
  }
}
void modificar(){
mod=1-mod;
 switch(mod){
     
    case 0:
    Serial.println("Hora");
    break;
    case 1:
    Serial.println("Minuto");
    break;
   }
}
void aumentar(){

  if(opcion==0&&mod==0){
    hora();
    }
  if(opcion==0&&mod==1){
    minuto();
    }
    if(opcion==1&&mod==0){
    horaA();
    }
  if(opcion==1&&mod==1){
    minutoA();
    }
  }
void reloj(){

  lcd.clear();//limpiar LCD
  lcd.setCursor(0,0);//posicionar cursor
  lcd.print("Hora");//imprimir en LCD
  lcd.setCursor(8,0);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,0);//posicionar cursor
  lcd.print(":");//imprimir en LCD
  
  lcd.setCursor(0,1);//posicionar cursor
  lcd.print("Alarm");//imprimir en LCD
  lcd.setCursor(8,1);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,1);//posicionar cursor
  lcd.print(":");//imprimir en LCD
  
  if(horero<24){
    lcd.setCursor(6,0);//posicionar cursor
      if(horero<10)//condicion si el valor es menor a 10
        lcd.print("0");////imprimir en LCD
        lcd.print(horero);//imprimir en LCD
        EEPROM.write(1,horero);
        delay(40);
  }else{
    horero=0;//reiniciar variable
  }  
  if(minutero<60){
    lcd.setCursor(9,0);//posicionar cursor
      if(minutero<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(minutero);//imprimir en LCD
        EEPROM.write(0,minutero);
        delay(40);
  }else{
    horero++;//incremento de variable
    minutero=0;//reiniciar variable
  }
///////////////////////////////////////////
  if(horeroA<24){
    lcd.setCursor(6,1);//posicionar cursor
      if(horeroA<10)//condicion si el valor es menor a 10
        lcd.print("0");////imprimir en LCD
        lcd.print(horeroA);//imprimir en LCD
        EEPROM.write(3,horeroA);
        delay(40);
  }else{
    horeroA=0;//reiniciar variable
  }
 if(minuteroA<60){
    lcd.setCursor(9,1);//posicionar cursor
      if(minuteroA<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(minuteroA);//imprimir en LCD
        EEPROM.write(2,minuteroA);
        delay(40);
  }else{
    horeroA++;//incremento de variable
    minuteroA=0;//reiniciar variable
  }
  if(segundero<60){
    lcd.setCursor(12,0);//posicionar cursor
      if(segundero<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(segundero);//imprimir en LCD
  }else{
    minutero++;//incrementar variable
    segundero=0;//reiniciar variable
  }
  delay(50);   
}
void contador(){
  segundero++;//incrementar variable
}
void minuto(){
  if(minutero<60){
    minutero++;//incrementar variable
    EEPROM.update(0,minutero);
    delay(40);
  }else{
    minutero=0;//reiniciar variable
  } 
}
void minutoA(){
  if(minuteroA<60){
    minuteroA++;//incrementar variable
    
    EEPROM.update(2,minuteroA);
    delay(40);
  }else{
    minuteroA=0;//reiniciar variable
  }
}
void hora(){
  if(horero<24){
    horero++;//incrementar variable
    EEPROM.update(1,horero);
    delay(40);
  }else{
    horero=0;//reiniciar variable
  }
}
void horaA(){
  if(horeroA<24){
    horeroA++;//incrementar variable
    
    EEPROM.write(3,horeroA);
    delay(40);
  }else{
    horeroA=0;//reiniciar variable
  }
}
void Alarma(){
  if(EEPROM.read(0)==EEPROM.read(2)&&EEPROM.read(1)==EEPROM.read(3)){
    tono();
    Serial.println("DESPIERTA");
    }
  }
 void tono(){  
  digitalWrite(buzzer,HIGH);
  delay(100); 
 }
