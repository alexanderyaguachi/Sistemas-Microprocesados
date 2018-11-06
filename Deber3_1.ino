//UNIVERSIDAD TECNICA DEL NORTE
//DEBER_3.1
//ALexander Ismael Yaguachi Morocho

int A = 5;  // pines de salida del display
int B = 4;  // pines de salida del display
int C = 3;  // pines de salida del display
int D = 2;  // pines de salida del display

int contador = 0;  //variable de conteo
int unidades = 8;  // pin de activacion unidades del display
int decenas = 9;   // pin de acitivacion decedas del display
int centenas= 10;  // pin de acitivacion centenas del display
int cont_decena=0; // Guarda un valor de decenas
int cont_unidad=0; // Guarda un valor de unidades
int cont_centenas=0; // Guarda un valor de centenas
int cont_obj=0;

void setup() {
  
  pinMode (A, OUTPUT);  //Pines de salida digitales del display 
  pinMode (B, OUTPUT);  //Pines de salida digitales del display
  pinMode (C, OUTPUT);  //Pines de salida digitales del display
  pinMode (D, OUTPUT);  //Pines de salida digitales del display
  
  pinMode (unidades, OUTPUT);
  pinMode (decenas, OUTPUT);
  pinMode (centenas, OUTPUT);
}

void loop() {

  if (contador < 200) {                        
    contador++;       //incrementa el contador mas 1
      cont_centenas= contador/100;    //valor de centenas      
      digitalWrite(unidades,LOW);     // pin en bajo de unidades       
      digitalWrite(decenas, LOW);     // pin en bajo de decenas
      digitalWrite(centenas, HIGH);   // pin en alto de centenas
      dis(cont_centenas);                       
      delay(100);                     // tiempo de espera          
      cont_decena=((contador - (cont_centenas * 100))/10);   //valor de decenas
      digitalWrite(unidades,LOW);     // pin en bajo de unidades        
      digitalWrite(decenas,HIGH);     // pin en alto de decenas
      digitalWrite(centenas,LOW);     // pin en bajo de centenas
      dis(cont_decena);                    
      delay(100);                      // tiempo de espera      
      cont_obj = ((contador - (cont_centenas * 100))/10);  
      cont_unidad=((contador - (cont_centenas * 100))-cont_obj*10); //valor de unidades
      digitalWrite(unidades,HIGH);      // pin en alto de unidades    
      digitalWrite(decenas,LOW);        // pin en bajo de decenas
      digitalWrite(centenas,LOW);       // pin en bajo de centenas
      dis(cont_unidad);                      
      delay(100);                       // tiempo de espera        
    }   
    else
  {
    contador = 0;                            
  }
}
// visualizacion de los numeros del display
void dis (int numero) {    //necesita valor de entrada                  
  switch (numero) {
    case 0:                                   
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    case 5:

      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;


    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;

    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;

  }
}
