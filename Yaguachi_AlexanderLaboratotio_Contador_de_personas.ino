/////////////////////////LABORATORIO/////////////////////////////

//INTEGRANTES:
//PICUASI EDISON
//YAGUACHI ALEXANDER

int A=5,B=4,C=3,D=2; // pines de salida para display
int sensor1,sensor2; // pines de entrada para sensor 1 y sensor 2
int led1=6,led2=7; // pines de acitivacion led 1 y led 2
int boton=10; // pin de acitivacion boton
int valor=0;  // variable almacenamiento dato boton
int i=0;  // variable de conteo
int dec=9; // pin de acitivacion decenas
int uni=8;  // pin de activacion unidades
int decenas; // variable de almacenamiento de decenas
int unidades; // variable de almacenamiento de unidades

void setup(){
  Serial.begin(9600);
 pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin
 pinMode(led1,OUTPUT); // configuracion de pin
 pinMode(led2,OUTPUT); // configuracion de pin
pinMode(dec,OUTPUT); // configuracion de pin
pinMode(uni,OUTPUT); // configuracion de pin
pinMode(boton,INPUT); // configuracion de pin

}

void loop(){
/////////////////////////////////////////////////////////////////
//CONFIGURACION DE ENTRADAS ANALOGICAS

sensor1 = analogRead(A0)/100; // configuracion del sensor
sensor2 = analogRead(A1)/100; // configuracion del sensor
/////////////////////////////////////////////////////////////////
//SENSOR 1

if(sensor1==8){  // condicion de activacion
   delay(600);   // delay antirebotes
   if(i<10){     // limite de conteo
     i++;       // aumento de variable
     decenas=i/10;  // valor de decenas
     unidades= i-(decenas*10); // valor unidades
     digitalWrite(led1,HIGH); //  activar led
     delay(200);
     digitalWrite(led1,LOW); //  desactivar led
    }
 }

//////////////////////////////////////////////////////////
//SENSOR 2

if(sensor2==8){  // condicion de activacion
   delay(600);   // delay antirebotes
   if(i<=10){     // limite de conteo
     i--;       // aumento de variable
     decenas=i/10;  // valor de decenas
     unidades= i-(decenas*10); // valor unidades
     digitalWrite(led2,HIGH); //  activar led
     delay(200);
     digitalWrite(led2,LOW); //  desactivar led
    }
    
    if(i<0){  //  condicion de retorno cuando es menor a cero
      i=0;  //reset
      decenas=0;  //reset
      unidades=0; //reset
      }
 }
 
 /*
 Serial.println("sensor1");
 Serial.println(sensor1);
 Serial.println("sensor2");
 Serial.println(sensor2);*/
/////////////////////////////////////////////////////////////////
//MULTIPLEXACION DE DISPLAY

 digitalWrite(uni,HIGH); // activacion de pin de unidades
 digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 contador(unidades);    // llamo metodo de visualizacion
 delay(10);  // espero
digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,HIGH);  // activacion de pin de decenas
 contador(decenas);  // llamo metodo de visualizacion
 delay(10); // espero

/////////////////////////////////////////////////////////////////
//BOTON DE RESETEO

valor=digitalRead(boton);// lectura de dato 
//Serial.println(valor);
if(valor==0){  //comparar el valor del dato
  i=0;  //reset
  unidades=0; //reset
  decenas=0;  //reset
  }
}

//necesita valor de entrada

void contador (int j){
switch(j){
  //0
  case 0:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//1
 case 1:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//2
case 2:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//3
case 3:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//4
case 4:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//5
case 5:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//6
case 6:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//7
case 7:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//8
case 8:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//9
case 9:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
}
