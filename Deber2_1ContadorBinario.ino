//Universidad Tecnica del Norte
// Alexander Yaguchi
//DEBER Nº 2:Realizar un contador binario del 1 al 31

// Indicamos que pines del arduino estamos utilizando
int boton = 14;
int v_binario [5] = {17, 18, 19, 20, 21};   //Declaramos un vector de 5 posiciones para contador binario
int i = 0;
int j = 0;
void setup() {
  for ( ; i < 5 ; i++)
  {
    pinMode ( v_binario [i] , OUTPUT);
    pinMode ( boton , INPUT);
  }

}

void loop() {
  if ( digitalRead  (boton) == HIGH) {
    for ( i = 0 ; i < 31 ; i ++) {
      for ( j = 0 ; j < 5; j++) {
        if ((( i >> j) & 1 ) == 1) {
          digitalWrite ( v_binario [j] , HIGH );
         }
         else digitalWrite (v_binario [j] , LOW );

         delay (400);             //Reliza una pausa durante un tiempo
      }
    }
  }
  else
  {
    //digitalWrite(  v_binario [5] , LOW ) ;
    digitalWrite(  1 , LOW ) ;
    digitalWrite(  2, LOW ) ;
    digitalWrite(  3, LOW ) ;
    digitalWrite(  4 , LOW ) ;
    digitalWrite(  5 , LOW ) ;
    delay (400);
  }
}
