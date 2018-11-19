/////////////////////////LABORATORIO/////////////////////////////
//UNIVERSIDAD TECNICA DEL NORTE
//INTEGRANTES:
//PICUASI EDISON
//YAGUACHI ALEXANDER
int pA=4, pB=5, pC=6, pD=7; //configuramos los pines para los pulsadores
int on=0;//creamos una variable de control para el encendido
int i=0;//creamos una varible de conteo
int A=0,B=0,C=0,D=0;//creamos una varible de conteo
int ledv=8, ledr=9; //configuramos los pines
int ctrl=2;//configuramos el pin para el control del sistema
int clave[6]={'A','C','A','B','D','D'}; //creamos la clave
int comp[6];//creamos la variable a comparar

void setup() {
Serial.begin(9600);//inicializamos la CX
pinMode(ledv,OUTPUT);//inicializamos las variables
pinMode(ledr,OUTPUT);//inicializamos las variables
pinMode(pA,INPUT);//inicializamos las variables
pinMode(pB,INPUT);//inicializamos las variables
pinMode(pC,INPUT);//inicializamos las variables
pinMode(pD,INPUT);//inicializamos las variables
attachInterrupt(digitalPinToInterrupt(2),sistema,FALLING);//inicializamos las interrupcion

}

void loop() {
 if(on==1){
    validar();

  }

}
void sistema(){
  on=1-on;//asignamos la variable de cambio
  if(on==1){
  Serial.println("SISTEM ON");//Enviamos mensaje mediante CX
  Serial.println("Ingrese Contrasena");//Enviamos mensaje mediante CX
  digitalWrite(ledv,HIGH);
  digitalWrite(ledr,LOW); 
  }else{
  Serial.println("SISTEM OFF");//Enviamos mensaje mediante CX
    digitalWrite(ledr,HIGH);
    digitalWrite(ledv,LOW);
  }
  return;
  }

void validar(){

if(digitalRead(pA)==HIGH){
    comp[i]='A';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('A');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
  if(digitalRead(pB)==HIGH){
    comp[i]='B';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('B');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
   if(digitalRead(pC)==HIGH){
    comp[i]='C';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('C');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
  if(digitalRead(pD)==HIGH){
    comp[i]='D';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('D');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
  if(i==6){
    //verificamos la contrasena ingresada
    
    //if((comp[0]==clave[0])&&(comp[1]==clave[1])&&(comp[2]==clave[2])&&(comp[3]==clave[3])&&(comp[4]==clave[4])&&(comp[5]==clave[5])){

    if((comp[0]=='A')||(comp[1]=='A')||(comp[2]=='A')||(comp[3]=='A')||(comp[4]=='A')||(comp[5]=='A')){      
      A++;
      Serial.println(A);
     } 
      //delay(600);

     if((comp[0]=='B')||(comp[1]=='B')||(comp[2]=='B')||(comp[3]=='B')||(comp[4]=='B')||(comp[5]=='B')){      
      B++;
      Serial.println(B);
      }  
      //delay(600);

      if((comp[0]=='C')||(comp[1]=='C')||(comp[2]=='C')||(comp[3]=='C')||(comp[4]=='C')||(comp[5]=='C')){      
      C++;
      Serial.println(C);
      }
      //delay(600);

      if((comp[0]=='D')||(comp[1]=='D')||(comp[2]=='D')||(comp[3]=='D')||(comp[4]=='D')||(comp[5]=='D')){      
      D++;
      Serial.println(D);
      } 
      //delay(600);



      if(A>=2&&B>=1&&C>=1&&D>=0){
      Serial.println("");//Enviamos mensaje mediante CX
      Serial.println("CLAVE CORRECTA");//Enviamos mensaje mediante CX
      
      digitalWrite(ledv,HIGH);//Encedemos led
      digitalWrite(ledv,LOW);//Encedemos led
       }
       else {
      Serial.println("");//Enviamos mensaje mediante CX
      Serial.println("CLAVE INCORRECTA");//Enviamos mensaje mediante CX      
      digitalWrite(ledr,HIGH);//encendemos leds
      digitalWrite(ledr,LOW);//Encedemos led
    }
      }
     
  }
