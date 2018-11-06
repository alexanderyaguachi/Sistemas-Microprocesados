//UNIVERSIDAD TECNICA DEL NORTE
//DEBER_3.2
//ALexander Ismael Yaguachi Morocho

int A=5;    // pines de salida del display
int B=4;    // pines de salida del display
int C=3;    // pines de salida del display
int D=2;    // pines de salida del display

int incrementa=6;   //pin activacion de pulsadores
int resta=7;        //pin activacion de pulsadores

int pulsador1;      // varriable para el antirebote
int pulsador2;      // varriable para el antirebote

int contador=0;     //variable de conteo

int dec=9;          // pin de acitivacion decedas del display
int uni=8;          // pin de acitivacion unidades del display

int decenas;        // Guarda un valor de decenas
int unidades;       // Guarda un valor de unidades


void setup() {
  
  pinMode(A, OUTPUT);     //Pines de salida digitales del display     
  pinMode(B, OUTPUT);     //Pines de salida digitales del display   
  pinMode(C, OUTPUT);     //Pines de salida digitales del display
  pinMode(D, OUTPUT);     //Pines de salida digitales del display
  pinMode(incrementa,INPUT);  //Pulsador aumentar como entrada digital
  pinMode(resta,INPUT);       //Pulsador resta como entrada digital
  pinMode(dec, OUTPUT);
  pinMode(uni, OUTPUT);
}

void loop() {
  if (digitalRead(incrementa) == LOW){
    //Variable antirrebote que cambia cuando se presiona el pulsador
    pulsador1 = 1;                      
   if(digitalRead(incrementa)==HIGH){
    if(contador>40){      // limite del conteo
      contador++;         //El contador se aumenta de uno en uno
      decenas=contador/10;    //valor de decenas
      unidades=contador-(decenas*10); //valor de unidades
    }else{    
      }
      contador = 0;
    }
  }
   if (digitalRead(resta) == LOW){
    //Variable antirrebote que cambia cuando se presiona el pulsador
    pulsador2=1;
   if(digitalRead(resta)==HIGH ){
   
    if(contador<40){
       contador--;        //El contador se resta o disminuye uno en uno
      
      }
      contador = 0;
  }
  digitalWrite(uni,HIGH);     // pin en alto de unidades 
  digitalWrite(dec,LOW);      // pin en bajo de decenas 
  delay(100);                 // tiempo de espera
  digitalWrite(uni,LOW);      // pin en bajo de unidades 
  digitalWrite(dec,HIGH);     // pin en alto de decenas 
  delay(100);                 // tiempo de espera
  } 

  // Envia los datos a los display de unidades y decenas
 switch(contador){

  //Muestar el numero 0
  case 0:    
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 1
  case 1: 
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 2
  case 2: 
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 3
  case 3: 
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 4
  case 4:
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 5
  case 5:
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 6
  case 6:
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 7
  case 7:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  break;
  //Muestar el numero 8
  case 8:
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  break;
  //Muestar el numero 9
  case 9:
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  break;
 }
}
