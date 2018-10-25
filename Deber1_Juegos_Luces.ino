UNIVERSIDAD TECNICA DEL NORTE
Alexander Yaguachi
Deber 1 Juego de Luces


int t=400;                         //Declaramos el tiempo de prendido
int leds[6]={6,7,8,9,10,11};       //Declaramos un vector de 6 posiciones
int rdm;
void setup() {
      
     for(int i=0;i<6;i++){
        pinMode(leds[i],OUTPUT);
      }
}
void loop() {
  
    //Juego 1
    for(int i=0;i<6;i=i+2){       //Indica la secuencia de pines en alto "1,3,5"
    digitalWrite(leds[i],HIGH);
    delay(t);                     //Reliza una pausa durante un tiempo
    digitalWrite(leds[i],LOW);
    delay(t);                     //Reliza una pausa durante un tiempo
    }
    //Juego 2
    for(int i=1;i<6;i=i+2){      //Indica la secuencia de pines en alto "2,4,6"
    digitalWrite(leds[i],HIGH);
    delay(t);                   //Reliza una pausa durante un tiempo
    digitalWrite(leds[i],LOW);
    delay(t);
    }
    rdm=random(8);              //Imprime un led aleatorio dentro del vector de 6 posiciones
    digitalWrite(leds[rdm],HIGH);
    delay(t);
    digitalWrite(leds[rdm],LOW);
    delay(t);
}
