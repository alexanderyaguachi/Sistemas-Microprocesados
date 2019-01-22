#include <MsTimer2.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Alexander Yaguachi
 * 
 */
 int pulA=6, pulB=5, pulC=4; //botones de contraseña
 int i=0;
 int on=0;
 int A=0,B=0,C=0;//creamos una varible de conteo
 int clave[5]={'A','C','A','B','B'}; //clave por defecto
 int comp[5];
 const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //pines del arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2); //Inicia LCD 16X2
  pinMode(pulA,INPUT);
  pinMode(pulB,INPUT);
  pinMode(pulC,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),master,RISING);
  EEPROM.write(0,clave[0]);
  EEPROM.write(1,clave[1]);
  EEPROM.write(2,clave[2]);
  EEPROM.write(3,clave[3]);
  EEPROM.write(4,clave[4]);
  for(int j=0;j<5;j++){
    Serial.print(EEPROM.read(j));
  }
    Serial.println(" ");
} 

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pulA)==HIGH){
    comp[i]='A';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('A');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
  if(digitalRead(pulB)==HIGH){
    comp[i]='B';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('B');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
   if(digitalRead(pulC)==HIGH){
    comp[i]='C';//Valor en el primer estado
    i++;//incremento de contador
    Serial.print('C');//Enviamos mensaje mediante CX
    delay(500);//delay antirebotes
  }
  if(i==5){
    //verificamos la contrasena ingresada 
    if((comp[0]=='A')||(comp[1]=='A')||(comp[2]=='A')||(comp[3]=='A')||(comp[4]=='A')){      
      A++;
      Serial.println(A);
     }
     if((comp[0]=='B')||(comp[1]=='B')||(comp[2]=='B')||(comp[3]=='B')||(comp[4]=='B')){      
      B++;
      Serial.println(B);
      }  
      if((comp[0]=='C')||(comp[1]=='C')||(comp[2]=='C')||(comp[3]=='C')||(comp[4]=='C')){      
      C++;
      Serial.println(C);
      }
      if(A>=2&&B>=2&&C>=1){
      Serial.println("");//Enviamos mensaje mediante CX
      Serial.println("CLAVE CORRECTA");//Enviamos mensaje mediante CX
      Serial.println("ENCENDER CARRO");
      }else{
       Serial.println("");
       Serial.println("Tiene 2 Intentos");
      }
    } 
  
}
void master(){
  on=1-on;//asignamos la variable de cambio
  if(on==1){
  Serial.println("ChevyStart");//Enviamos mensaje mediante CX
  lcd.setCursor(0,0);
  lcd.print("ChevyStar");
  lcd.setCursor(0,1);
  lcd.print("Ingrese Contraseña");
  Serial.println("Ingrese Contrasena");//Enviamos mensaje mediante CX 
  if((EEPROM.read(0)==comp[0])&&(EEPROM.read(1)==comp[1])&&(EEPROM.read(2)==comp[2])&&(EEPROM.read(3)==comp[3])&&(EEPROM.read(4)==comp[4])){ 
  Serial.println("CONTRASEÑA CORRECTA");
  Serial.println("ENCIENDA CARRO");
  }else{
  Serial.println("CONTRASEÑA INCORRECTA");
  }
 }
}
