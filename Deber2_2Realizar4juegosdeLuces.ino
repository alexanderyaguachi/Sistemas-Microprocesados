//Universidad Tecnica del Norte
// Alexander Yaguchi
//DEBER Nº 2 :Realizar 4 juegos de luces con activación mediante switchs.
// Indicamos que pines del arduino estamos utilizando
int led_1=8;   
int led_2=9;
int led_3=10;
int led_4=11;
int led_5=12;
int led_6=13;
int sw_1=7;
int sw_2=6;
int pulsador=5;
int leds [6]={led_1,led_2,led_3,led_4,led_5,led_6};
int leds1 [3]={led_2,led_4,led_6};
int contador=0;
int cont=0;
int i=0;  
int dato=0;
int dato2=0;
int conta=1;

void setup() {
  // put your setup code here, to run once:
  //Declaramos los pines digitales del arduino uno
  
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(led_3,OUTPUT);
pinMode(led_4,OUTPUT);
pinMode(led_5,OUTPUT);
pinMode(led_6,OUTPUT);
pinMode(sw_1,INPUT);
pinMode(sw_2,INPUT);
pinMode(pulsador,INPUT);

}

void loop() {
//1) Si el switch_1 esta en "1" y el swith_2 esa en "0", se encienderán y apagarán los leds pares (2,4,6)en forma ascendentemente y descendentemente
if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==LOW){
  for(;conta<=5;conta=conta+2){
    digitalWrite(leds[conta],HIGH);
    delay(200);
    digitalWrite(leds[conta],LOW);
    delay(200);
}
for(;conta>=1;conta=conta-2){
  digitalWrite(leds[conta],HIGH);
    delay(200);
    digitalWrite(leds[conta],LOW);
    delay(200);
}
conta=1;
}

//2) Si tenemos el swith_1 en "0" y el swith_2 en "1"  se encenderan aleatoriamente los leds pares (2,4,6).

if(digitalRead(sw_1)==LOW&&digitalRead(sw_2)==HIGH){
  delay(200);
  for(;i<5;i=i+1){
  dato=random(5);
  digitalWrite(leds1[dato],HIGH);
  delay(400);
  digitalWrite(leds1[dato],LOW);
  delay(400);
  i=0;
}
}

//3) Si el switch_1 esta en "1" y el swith_2 esa en "1", se encienderán y apagarán los leds impares (1,3,5)en forma ascendentemente y descendente
if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==HIGH){

  for(;contador<6;contador=contador+2){
    digitalWrite(leds[contador],HIGH);
    delay(200);
    digitalWrite(leds[contador],LOW);
    delay(200);
}
for(;contador>=0;contador=contador-2){
  digitalWrite(leds[contador],HIGH);
    delay(200);
    digitalWrite(leds[contador],LOW);
    delay(200);
}
contador=0;
}

//4)Si el switch_1 esta en "0" y el swith_2 esa en "0", se enciende aleatoriamente dos leds a la vez (6,1)(5,2)(4,3).
if (digitalRead(sw_1)==LOW&&digitalRead(sw_2)==LOW){ 
   for(;i<8;i+1){                                          
   dato2=random(3,8);                                      
   { 
      if(dato2==3){                                        
      digitalWrite(led_1,HIGH);
      digitalWrite(led_6,HIGH);   
      delay(400);}                                         
      if(dato2==3){                                        
      digitalWrite(led_1,LOW);
      digitalWrite(led_6,LOW);   
      delay(400);}                                         
      if(dato2==4){                                        
      digitalWrite(led_2,HIGH);
      digitalWrite(led_5,HIGH);   
      delay(400);}                                         
      if (dato2==4){                                       
      digitalWrite(led_2,LOW);
      digitalWrite(led_5,LOW);  
      delay(400);}                                         
      if(dato2==5){                                        
      digitalWrite(led_3,HIGH);
      digitalWrite(led_4,HIGH);   
      delay(400);}                                         
      if(dato2==5){                                        
      digitalWrite(led_3,LOW);
      digitalWrite(led_4,LOW);     
      delay(400);}                                         
      }
      i=0;
   }
   delay (1000);                                         
 }
}
