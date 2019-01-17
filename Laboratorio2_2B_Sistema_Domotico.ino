/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Realizar el sistema domótico que tenga 3 sensores 
 * ubicados en puertas y ventana. Debe guardar la hora 
 * en la memoria EEPROM cuando suceda algún 
 * inconveniente después que la casa sea asegurada. 
 * Para ello, debe ingresar una contrasena de 5 digitos 
 * (guardados en la EEPROM)que dará 25 segundos para 
 * salir de la casa y que los sensores se activen. 
 * Si la alarma se enciende, obligatoriamente debe 
 * digitar la contraseña para apagarla. Además, debe 
 * tener una función de poder cambiarla en caso de 
 * necesitarlo. El ingreso de la misma puede ser 
 * por teclado matricial o comunicación serial. 
 * Toda la información del estado de la alarma se lo 
    debe visualizar en una lcd.
 */
      
#include <TimerOne.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
#include <Keypad.h>

LiquidCrystal lcd (13,12,11,10,9,8);//configurar pines LCD
const byte FILAS=4; //cuatro filas
const byte COLS=4; //cuatro columnas

char pass [5]={EEPROM.read(4),EEPROM.read(5),EEPROM.read(6),EEPROM.read(7),EEPROM.read(8)};
char passre [5];
char passca [5];
char teclado[FILAS][COLS]={
  {'7','2','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','+'}
};
byte pinfilas[FILAS]={41,43,45,47};
byte pincolumnas[COLS]={31,33,35,37};

Keypad customKeypad = Keypad(makeKeymap(teclado),pinfilas,pincolumnas, FILAS, COLS);

Keypad customKeypad2 = Keypad(makeKeymap(teclado),pinfilas,pincolumnas, FILAS, COLS);
int segundos = 1; 
int minutero=0;
int horero=0;
int contador=0;
int guar=0;
int p1;
int p2;
int vent;
int i=0;
int j=0;
int pres=0;
int buzzer=7;//pin buzzer

void setup() {
 //EEPROM.write(0,0);
 //EEPROM.write(1,1);

 //EEPROM.update(4,contra);
 Serial.begin (9600);
 lcd.begin(16,2);
  Timer1.initialize(1000000);
  minutero = EEPROM.read (0);
  horero = EEPROM.read (1);
  MsTimer2 :: set (400, reloj); // 1 segundo
  MsTimer2 :: start ();
pinMode(buzzer,OUTPUT);//configuracion pin buzzer
/*
EEPROM.update(4,1);
EEPROM.update(5,2);
EEPROM.update(6,3);
EEPROM.update(7,4);
EEPROM.update(8,6);
 */
 
Serial.println(EEPROM.read(4));
Serial.println(EEPROM.read(5));
Serial.println(EEPROM.read(6));
Serial.println(EEPROM.read(7));
Serial.println(EEPROM.read(8));

 
}

void loop() {
keyPress();
if(contador>5){
 p1=analogRead(A0)/1023;
 p2=analogRead(A1)/1023;
 vent=analogRead(A2)/1023;
  
  /*Serial.println(p1);
  Serial.println(p2);
  Serial.println(vent);
  */
  delay(500);

 if(p1==1||p2==1||vent==1){
  guar++;
  if(guar==2){
    delay(40);
    EEPROM.update(2,minutero);
    
    delay(40);
    EEPROM.update(3,horero);
    Serial.print("hora:");
    Serial.print(EEPROM.read(3));
    Serial.print("Minuto");
    Serial.println(EEPROM.read(2));
    }
    digitalWrite(buzzer,HIGH);//encender buzzer
    }
  }
}

void reloj (){
 lcd.clear();//limpiar LCD
  lcd.setCursor(0,0);//posicionar cursor
  lcd.print("Hora");//imprimir en LCD
  lcd.setCursor(8,0);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,0);//posicionar cursor
  lcd.print(":");//imprimir en LCD
  lcd.setCursor(6,0);//posicionar cursor
  //lcd.print("0");////imprimir en LCD
  lcd.print(horero);
   lcd.setCursor(9,0);//posicionar cursor
  //lcd.print("0");////imprimir en LCD
  lcd.print(minutero);
   lcd.setCursor(12,0);//posicionar cursor
  //lcd.print("0");////imprimir en LCD
  lcd.print(segundos);
  
   if(segundos<59){
      segundos++;
    }
    else{
         if(minutero<59){
           minutero++;
           EEPROM.write(0,minutero);
           segundos=0;
          }
          else{
              if(horero<24){
                horero++;
                EEPROM.write(1,horero);
                minutero=0;
                }
                else{
                   horero=0;
                  }
            }
      }

//Serial.print(horero);
//Serial.print(":");
//Serial.print(minutero);
//Serial.print(":");
//Serial.println(segundos);    
  }

void keyPress(){
  char customKey = customKeypad.getKey();
  switch (customKey){
    case '0'...'9':
    passre[i]=customKey;
    i++;
    
    EEPROM.update(10,passre[0]-48);
    EEPROM.update(11,passre[1]-48);
    EEPROM.update(12,passre[2]-48);
    EEPROM.update(13,passre[3]-48);
    EEPROM.update(14,passre[4]-48);
    
    Serial.print(customKey);
/*
    Serial.println(EEPROM.read(10));
    Serial.println(EEPROM.read(11));
    Serial.println(EEPROM.read(12));
    Serial.println(EEPROM.read(13));
    Serial.println(EEPROM.read(14));
    */
    pres=1;
    break;
    case '*': 
    Serial.println("Validar");
    checkPassword(); 
    break;
    case '#': 
    Serial.println("Apagar");
    Apagar();
    break;
    case '+': 
    Serial.println("Change");
    //keyPress2();
    break;
     }
  }

void checkPassword(){
  if(pres==1){
  if (EEPROM.read(4)==EEPROM.read(10)&&
      EEPROM.read(5)==EEPROM.read(11)&&
      EEPROM.read(6)==EEPROM.read(12)&&
      EEPROM.read(7)==EEPROM.read(13)&&
      EEPROM.read(8)==EEPROM.read(14)){
    Serial.println("Alarma Activado");    
    Timer1.attachInterrupt(conteo);
    }
  }
}
void Apagar(){
  Serial.println("Para Apagar digite contrasena");
  if(pres==1){
  if (EEPROM.read(4)==EEPROM.read(10)&&
      EEPROM.read(5)==EEPROM.read(11)&&
      EEPROM.read(6)==EEPROM.read(12)&&
      EEPROM.read(7)==EEPROM.read(13)&&
      EEPROM.read(8)==EEPROM.read(14)){
  Serial.println("Apagado");
  digitalWrite(buzzer,LOW);//apagar buzzer
  Timer1.stop();
  contador=0;
  
    }
    }
  }
void Change(){/*
    EEPROM.update(4,passca[0]-48);
    EEPROM.update(5,passca[1]-48);
    EEPROM.update(6,passca[2]-48);
    EEPROM.update(7,passca[3]-48);
    EEPROM.update(8,passca[4]-48);

    Serial.println(EEPROM.read(4));
    Serial.println(EEPROM.read(5));
    Serial.println(EEPROM.read(6));
    Serial.println(EEPROM.read(7));
    Serial.println(EEPROM.read(8));
  */
  }

  void conteo(){
    contador++;
    Serial.println(contador);
    }
