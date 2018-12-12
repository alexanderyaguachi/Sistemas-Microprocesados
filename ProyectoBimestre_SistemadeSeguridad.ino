/*
* UNIVERSIDAD TECNICA DEL NORTE
*Integrantes: Alexander Yaguachi
              Edison Picuasi
*/

#include <Keypad.h>
#include <Password.h>
#include <LiquidCrystal.h>

const byte FILAS=4; //cuatro filas
const byte COLS=4; //cuatro columnas
int numero=0;

const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

Password clave1 = Password("12A12");//trabajador 1
Password clave2 = Password("12B34");//trabajafor 2
Password clave3 = Password("12C56");//trabajador 3
Password clave4 = Password("12D78");//trabajador 4
Password alarma = Password("12346");//clave serial
Password master = Password("12121");//Administrador
byte currentLength = 0;

char teclado[FILAS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinfilas[FILAS]={41,43,45,47};
byte pincolumnas[COLS]={31,33,35,37};

Keypad keypad = Keypad(makeKeymap(teclado),pinfilas,pincolumnas, FILAS, COLS);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int on=0;
int pinon=51;
int pinoff=50;
int bot=2;
int verde=13;
int rojo=12;

int pinzumbador = 11;    // pin del zumbador
int frecuencia = 220; 


int P1=29; // pin de salida para display
int P2=28; // pin de salida para display
int P3=27; // pin de salida para display
int P4=26; // pin de salida para display
int i=0;  // variable de conteo
int dec=14; // pin de acitivacion decenas
int uni=11;  // pin de activacion unidades
int decenas; // variable de almacenamiento de decenas
int unidades;

void setup() {
  
  // put your setup code here, to run once:
  pinMode(P1,OUTPUT); // configuracion de pin
 pinMode(P2,OUTPUT); // configuracion de pin
 pinMode(P3,OUTPUT); // configuracion de pin
 pinMode(P4,OUTPUT); // configuracion de pin 
 pinMode(dec,OUTPUT); // configuracion de pin
 pinMode(uni,OUTPUT); // configuracion de pin
  Serial.begin(9600);
  Serial.println("SISTEMA DE SEGURIDAD");
  Serial.println("Reinciar->! Evaluar la contraseña->?");
  Serial.print("Enter password: ");
  lcd.setCursor(0,0);
  lcd.print("Clave:");
  keypad.addEventListener(keypadEvent);
  attachInterrupt(digitalPinToInterrupt(bot),sistema,RISING);
  attachInterrupt(digitalPinToInterrupt(3),Masterpass,RISING);
  pinMode(pinon,OUTPUT);
  pinMode(pinoff,OUTPUT);
  pinMode(bot,INPUT);

  pinMode(verde,OUTPUT);
  pinMode(rojo,OUTPUT);

  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("S.DE.SEGURIDAD");
  lcd.setCursor(0,1);
  lcd.print("Ingrese Codigo:");
  delay(1000);
  lcd.clear();


  
  
}
void loop() {
  // put your main code here, to run repeatedly:
  
  if(on==1){
    dis();
  keypad.getKey();
  if (Serial.available()){
    char input = Serial.read();
    lcd.write(Serial.read());
    switch (input){
     
      case '!': //reset password
        alarma.reset();
        currentLength = 0;
        Serial.println("Restablecer la Contraseña");
      break;
      case '?': //Evaluando el codigo
        if (alarma.evaluate()){
          Serial.println();
          lcd.setCursor(0,1);
          lcd.print("Clave Correcta  ");
          Serial.println("Contraseña Correcta");
          digitalWrite(verde,HIGH);
          digitalWrite(rojo,LOW);
          tone(pinzumbador,frecuencia);    // inicia el zumbido
          delay(2000);                    
          noTone(pinzumbador);               // lo detiene a los dos segundos
          delay(1000);
          
        }else{
          Serial.println();
          lcd.setCursor(0,1);
          lcd.print("Clave correcto");
          Serial.println("Contraseña Incorrecta");
          digitalWrite(verde,LOW);
          digitalWrite(rojo,HIGH);
        }
      break;
      default: 
        alarma << input;
        currentLength++;
        
        for (byte i=0; i<currentLength; i++){
          //Serial.print('*');
        }
     }
  }
  }
}
void sistema(){
  on=1-on;
  if(on==1){
    digitalWrite(pinon,HIGH);
    digitalWrite(pinoff,LOW);
  }else{
    digitalWrite(pinoff,HIGH);
    digitalWrite(pinon,LOW);
  }
}

void keypadEvent(KeypadEvent eKey){
  if(on==1){
  switch (keypad.getState()){
    case PRESSED:
  lcd.print(eKey);
  switch (eKey){
    case '*': checkPassword(); break;
    break;
    case '#':
    clave1.reset();break;
    clave2.reset();break;
    clave3.reset();break;
    clave4.reset();break;
    
    default: 
    clave1.append(eKey);
    clave2.append(eKey);
    clave3.append(eKey);
    clave4.append(eKey);
    
     }
  }
 }
}
void checkPassword(){
    if(on==1){
    if(clave1.evaluate()||clave2.evaluate()||clave3.evaluate()||clave4.evaluate()){
     lcd.clear();
     lcd.setCursor(0,1);
     lcd.print("CLAVE CORRECTA");
     digitalWrite(verde,HIGH);
     digitalWrite(rojo,LOW);
     reset_password();
     numero++;
     Serial.println(numero);
     delay(1000);    
     }else{
      lcd.clear();
     lcd.setCursor(0,1);
     lcd.print("CLAVE INCORRECTA");
     reset_password();
     digitalWrite(rojo,HIGH);
     digitalWrite(verde,LOW);


     }
     delay(1000);
    lcd.clear();
 }
}
void reset_password(){
  if(on==1){
    clave1.reset(); // resetea password despues de entrada correcta    
    clave2.reset(); // resetea password despues de entrada correcta
    clave3.reset(); // resetea password despues de entrada correcta    
    clave4.reset(); // resetea password despues de entrada correcta
  }
}
void reset_clave(){
  if(on==1){
//pregunte q user quiere cambiar
//lees el # de ususaro
  lcd.setCursor(0,0);
  lcd.print("Sleccionar U.C");
  switch (keypad.getState()){
  case '1':
  clave1.set("11111");//trabajador 1
  //clave cambiada imprimir 
  lcd.setCursor(0,0);
  lcd.print("");
  lcd.setCursor(0,1);
  lcd.print("Clave Cambiada");
  break;
  case '2':
  clave2.set("22222");//trabajador 2
  lcd.print("Clave Cambiada"); 
  break;
  case '3':
  clave3.set("33333");//trabajador 3
  lcd.print("Clave Cambiada");
  break;
  case '4':
  clave4.set("44444");//trabajador 4
  lcd.print("Clave Cambiada");
  break;
  }
 }
}

void Masterpass(){
  Serial.print("");
 
  if(master.evaluate()){
   reset_clave();
   Serial.print("Clave cambiada");

  }
  }
void contador (int j){
switch(numero){
  //0
  case 0:
digitalWrite(P1,LOW);
digitalWrite(P2,LOW);
digitalWrite(P3,LOW);
digitalWrite(P4,LOW);
break;
//1
 case 1:
digitalWrite(P1,HIGH);
digitalWrite(P2,LOW);
digitalWrite(P3,LOW);
digitalWrite(P4,LOW);
break;
//2
case 2:
digitalWrite(P1,LOW);
digitalWrite(P2,HIGH);
digitalWrite(P3,LOW);
digitalWrite(P4,LOW);
break;
//3
case 3:
digitalWrite(P1,HIGH);
digitalWrite(P2,HIGH);
digitalWrite(P3,LOW);
digitalWrite(P4,LOW);
break;
//4
case 4:
digitalWrite(P1,LOW);
digitalWrite(P2,LOW);
digitalWrite(P3,HIGH);
digitalWrite(P4,LOW);
break;
//5
case 5:
digitalWrite(P1,HIGH);
digitalWrite(P2,LOW);
digitalWrite(P3,HIGH);
digitalWrite(P4,LOW);
break;
//6
case 6:
digitalWrite(P1,LOW);
digitalWrite(P2,HIGH);
digitalWrite(P3,HIGH);
digitalWrite(P4,LOW);
break;
//7
case 7:
digitalWrite(P1,HIGH);
digitalWrite(P2,HIGH);
digitalWrite(P3,HIGH);
digitalWrite(P4,LOW);
break;
//8
case 8:
digitalWrite(P1,LOW);
digitalWrite(P2,LOW);
digitalWrite(P3,LOW);
digitalWrite(P4,HIGH);
break;
//9
case 9:
digitalWrite(P1,HIGH);
digitalWrite(P2,LOW);
digitalWrite(P3,LOW);
digitalWrite(P4,HIGH);
break;
}
}

void dis(){
  // delay antirebotes
   if(i<40){     // limite de conteo
     i++;       // aumento de variable
     decenas=i/10;  // valor de decenas
     unidades= i-(decenas*10); // valor unidades
    }
   else{
    i=0; // reset conteo
    unidades=0; // reset unidades
    decenas=0;  // reset decenas
   }
 
   if(i<=40){     // limite de conteo
     i--;       // aumento de variable
     decenas=i/10;  // valor de decenas
     unidades= i-(decenas*10); // valor unidades
    }
 
 digitalWrite(uni,HIGH); // activacion de pin de unidades
 digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 contador(unidades);    // llamo metodo de visualizacion
 delay(400);  // espero
digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,HIGH);  // activacion de pin de decenas
 contador(decenas);  // llamo metodo de visualizacion
 delay(400); // espero
}
