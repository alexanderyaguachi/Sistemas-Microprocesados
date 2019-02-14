//#include <Sleep_n0m1.h>

//LIBRERIAS
#include <TimerOne.h>
#include <EEPROM.h>
#include <Keypad.h>
#include <LiquidCrystal.h>//librerá de pantalla lcd
#include <MsTimer2.h>
#include <LowPower.h>
#include <avr/wdt.h> //Librería perro guardían


LiquidCrystal lcd(13,12,11,10,9,8); //pines de habilitacion RS,E,D4,D5,D6,D7
//----------------------------------------------------------
//VARIABLES SENSORES
int garage=7;
int entrada=6;
int servicio=5;
//----------------------------------------------------------
//VARIABLES RELOJ
int segundos;
int minutero;
int horero;

int tempo=0;

int alarma=4;
//----------------------------------------------------------
//VARIABLES LEDS
int dormitorio=14;
int sala=15;
int cocina=16;

long randNumber;

//----------------------------------------------------------
//EEPROM CONTRASENA
  char pass [3]={EEPROM.read(4),EEPROM.read(5),EEPROM.read(6)};
  char passre [3];

  char act [3]={EEPROM.read(10),EEPROM.read(11),EEPROM.read(12)};
  char actre [3];

  int i=0;

  int p;

  int j=10;

  int opcion;
//----------------------------------------------------------
//TECLADO
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {//datos de teclado
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {30, 28, 26 , 24 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = {40, 38, 36, 34}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
char customKeyCambiar = customKeypad.getKey();


void setup() {
//----------------------------------------------------------  
//SERIAL y LCD
  lcd.begin(16, 2); //inicializar lcd
  lcd.setCursor(0, 0);
  lcd.print("SISTEMA DOMOTICO");
  Serial.begin(9600);//inicio de comunicacion serial
//----------------------------------------------------------
//EEPROM RELOJ
  minutero = EEPROM.read(20);
  horero = EEPROM.read(21);

//----------------------------------------------------------
//EEPROM CONTRASENA

//Contrasena Master
  //EEPROM.update(4,4);
  //EEPROM.update(5,7);
  //EEPROM.update(6,2);
  Serial.println(EEPROM.read(4));
  Serial.println(EEPROM.read(5));
  Serial.println(EEPROM.read(6));
  
//Contrasena Activacion
  //EEPROM.update(10,1);
  //EEPROM.update(11,2);
  //EEPROM.update(12,3);
  Serial.println(EEPROM.read(10));
  Serial.println(EEPROM.read(11));
  Serial.println(EEPROM.read(12));

  Serial.println(EEPROM.read(7));
  Serial.println(EEPROM.read(8));
  Serial.println(EEPROM.read(9));

//----------------------------------------------------------
//TIMERS
  MsTimer2::set(1000, reloj);//inicializacion de interrupcion de tiempo
  MsTimer2::start();//inicio de reloj

  Timer1.initialize(1000000);//contador a 1 seg
  
//----------------------------------------------------------
//PINES
  pinMode(garage,INPUT);//PINES DE ENTRADA
  pinMode(entrada,INPUT);//PINES DE ENTRADA
  pinMode(servicio,INPUT);//PINES DE ENTRADA
  pinMode(dormitorio, OUTPUT);//PINES DE ENTRADA
  pinMode(sala, OUTPUT);//PINES DE ENTRADA
  pinMode(cocina, OUTPUT);//PINES DE ENTRADA
  pinMode(alarma, OUTPUT);//PINES DE ENTRADA
   
//----------------------------------------------------------

Serial.println("LA CONFIGURACION ALMACENADA ES:");
Serial.println(EEPROM.read(24));
}

void loop() {
 keyPress();
//Serial.print(p);
// attachInterrupt(0, wakeUp, LOW);
// LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
// LowPower.idle(SLEEP_8S, ADC_OFF, TIMER5_OFF, TIMER4_OFF, TIMER3_OFF, 
//       TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART3_OFF, 
//        USART2_OFF, USART1_OFF, USART0_OFF, TWI_OFF);
 detachInterrupt(0); 
    
 
if(EEPROM.read(24)==2){
  luces();
  }    
 if(EEPROM.read(24)==0){
  digitalWrite(4,LOW);
  }

 if(EEPROM.read(24)==1){
  if(digitalRead(7)==HIGH||
     digitalRead(6)==HIGH||
     digitalRead(5)==HIGH){
     
     digitalWrite(4,HIGH);
     }

     if(EEPROM.read(24)==3){
  wakeUp();
  }    
  
  } 
 }


//---------------------------------------------------------------
//CONTROL DE ACCESO Y ALARMA
void reloj () {
 lcd.clear();//limpiar LCD
  lcd.setCursor(0,0);//posicionar cursor
  lcd.print("Hora");//imprimir en LCD
  lcd.setCursor(8,0);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,0);//posicionar cursor
  lcd.print(":");//imprimir en LCD
  lcd.setCursor(6,0);//posicionar cursor
  //lcd.print("0");////imprimir en LCD
  //lcd.print(horero);
   lcd.setCursor(9,0);//posicionar cursor
  //lcd.print("0");////imprimir en LCD
  lcd.print(minutero);
   lcd.setCursor(12,0);//posicionar cursor
  //lcd.print("0");////imprimir en LCD
  lcd.print(segundos);
//-----------------------------------------------------------

//HORA NORMAL
/*
   if(segundos<59){
      segundos++;
    }
    else{
         if(minutero<59){
           minutero++;
           EEPROM.write(20,minutero);
           segundos=0;
          }
          else{
              if(horero<24){
                horero++;
                EEPROM.write(21,horero);
                minutero=0;
                }
                else{
                   horero=0;
                  }
            }
      }

 */
//----------------------------------------------------------
//HORA PROYECTO

if(segundos<59){
      segundos++;
    }
    else{
         if(minutero<3){
           minutero++;
           EEPROM.write(20,minutero);
           segundos=0;
          
          }else{
            
            minutero=0;
            segundos=0;
            }
      }


}

void keyPress(){

  char customKey = customKeypad.getKey();
  switch (customKey){
    case '0'...'9':
    Serial.println("");
    passre[i]=customKey;
    i++;
    
    EEPROM.update(7,passre[0]-48);
    EEPROM.update(8,passre[1]-48);
    EEPROM.update(9,passre[2]-48);

    Serial.print(customKey);

lcd.setCursor(10,1 );   
lcd.print(passre[0]-48);
delay(200); 
lcd.setCursor(11,1 );  
lcd.print(passre[1]-48);
delay(200); 
lcd.setCursor(12,1 );  
lcd.print(passre[2]-48);  
delay(200); 
  if(i>2){
    
    i=0;
    }
    break;
    case 'A': 
    Serial.println("Control de acceso");
    checkPassword();
    EEPROM.update(24,p);

    Serial.println("Para cambiar la contrasena siga los siguientes pasos");
    Serial.println("1. Ingrese la nueva contrasena");
    Serial.println("2. Oprima D para guardar como Master");
    Serial.println("3. Oprima * para guardar como Activacion");
    
    break;
    case 'B': 
    Serial.println("Sistema de Luces");
    p=2;
    EEPROM.update(24,p);
    break;

    case 'C': 
    Serial.println("Sistema de Carga");
    p=3;
    EEPROM.update(24,p);
    wakeUp();
    break;
    case 'D': 
    
    opcion=1;
    checkPassword();
    break;
    case '*': 
    opcion=2;
    checkPassword();
    break;

    case '#': 
    
    break;
     }
  }



void checkPassword(){

  if (EEPROM.read(4)==EEPROM.read(7)&&
      EEPROM.read(5)==EEPROM.read(8)&&
      EEPROM.read(6)==EEPROM.read(9)){
      Serial.println("Master Correcto"); 
      Serial.println("Alarma Desactivada"); 
      lcd.clear();
      lcd.setCursor(0,1);//posicionar cursor
      lcd.print("Alarma OFF");
       
  p=0;
    }
  if (EEPROM.read(10)==EEPROM.read(7)&&
        EEPROM.read(11)==EEPROM.read(8)&&
        EEPROM.read(12)==EEPROM.read(9)){
        Serial.println("Activacion Correcto");   
        Serial.println("Alarma se Activara en 10 segundos"); 
        Timer1.attachInterrupt(temporizador);

      lcd.clear();
      lcd.setCursor(0,1);//posicionar cursor
      lcd.print("Alarma 10s");
   p=1;
        }

   if(opcion==1&&p==0){

        EEPROM.update(4,EEPROM.read(7));
        EEPROM.update(5,EEPROM.read(8));
        EEPROM.update(6,EEPROM.read(9));
    }

     if(opcion==2&&p==0){

        EEPROM.update(10,EEPROM.read(7));
        EEPROM.update(11,EEPROM.read(8));
        EEPROM.update(12,EEPROM.read(9));
    
    
    
    }

  }

  void temporizador(){
    
    tempo++;
    //Serial.println(tempo);
    if(tempo==10){
      Serial.println("ALARMA ACTIVADA");
      lcd.clear();
      lcd.setCursor(0,1);//posicionar cursor
      lcd.print("Alarma ON");
    }

  }

//---------------------------------------------------------------
//SISTEMA AUTOMATICO DE LUCES
void luces(){
  
  if(minutero==1){
  randNumber = random(14,17);
  digitalWrite(randNumber,HIGH);
  delay(200);
  digitalWrite(randNumber,LOW);
  delay(200);
    }
  
  if(minutero==2){
    digitalWrite(14,LOW);
    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    }  
  
  }
  

//---------------------------------------------------------------
//SISTEMA DE CARGA
void wakeUp()
{ if(minutero==2 || minutero==3 ){
       for (int i = 0 ;  i  <  16 ; i++)
             LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
             if(i==32){
              wdt_enable(WDTO_1S);
             }
}         
}
