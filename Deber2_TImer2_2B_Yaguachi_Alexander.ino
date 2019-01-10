/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 * Programa que muestre el segundero,minutero y horero visto en una lcd.
 * 
 */
#include <MsTimer2.h>       //Libreria timer2
#include <LiquidCrystal.h>  //Libreria lcd

const int rs = 12, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6; //pines del arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int horas=0;      //contador horas
int minutos=0;    //contador minutos
int segundos=0;   //contador segundo

String minutero;  //variable para la cx serial
String horero;    //variable para la cx

int minuto;     //variable para la conversion de string a int
int hora;       //variable para la conversion de String a int

int buzzer=5;  // pin de sonido de alarma

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // iniciamos la comunicacion serial.
  lcd.begin(16,2);    // iniciamos la lcd
  MsTimer2::set(1000, reloj);//1 segundo
  MsTimer2::start();
}
void loop() {
  // put your main code here, to run repeatedly:
 alarma();
}
void reloj(){
  segundos++;       //contador aumenta los segundos
  if(segundos>=60){
    segundos=0;     //se reseta los minutos
    minutos++;      //contador aumenta los minutos
    }
  if(minutos>=60){
    minutos=0;      // se resetea los minutos
    horas++;        //contador aumenta las horas
    }
  if(horas>=24){    
    horas=0;        //se resetea las horas
     }
 graficar();        //llama al metodo para graficar en la LCD
}
void graficar(){
   
   lcd.clear();  
   lcd.setCursor(0,1);        //indica en que posicion se impreme
   lcd.print("Hora: ");
    lcd.setCursor(6,1);       //indica en que posicion se impreme
   lcd.print(horas);          //imprime el valor de hora
   lcd.setCursor(8,1);        //indica en que posicion se impreme
   lcd.print(": ");           //imprime el valor de minuto
   lcd.setCursor(9,2);        //indica en que posicion se impreme
   lcd.print(minutos);
   lcd.setCursor(11,2);
   lcd.print(": ");
   lcd.setCursor(12,2);
   lcd.print(segundos);  
}
void alarma() {
  if (Serial.available() > 0) {//ver si hay algo en la comunicacion serial
  
    lcd.clear();
    lcd.setCursor(0,0);             //indica en que posicion se impreme
    lcd.print("Alarma:");           //muestra el valor en a lcd
    Serial.print("Hora: ");         //imprime el valor en comunicaion serial
    horero = Serial.readString();   //lee el string
    hora = String(horero).toInt();  //convierte el string a int 
    lcd.setCursor(5,0);             //indica en que posicion se impreme
    lcd.print(hora);                //imprime el valor en la lcd
    delay(300);
    Serial.print(": ");             //imprime el valor en comunicaion serial
    minutero = Serial.readString(); //lee el string
    minuto = String(minutero).toInt();//convierte de string a int
    lcd.setCursor(7,0);             //indica en que posicion se impreme
    lcd.print(minuto);              //imprime el valor en la lcd
    delay(300);    
  }
}
