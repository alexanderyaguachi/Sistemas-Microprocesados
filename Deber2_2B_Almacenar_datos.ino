 #include <EEPROM.h>
/*
 * Universidada Tecnica del Norte
 * Realice un sistema que guarde en una 
 * posición de la memoria EEPROM solo 
 *  cuando su valor exceda a la anterior lectura.
 */

int cont = 0; // contador 
int v_alma = 0; //valor donde se almacenara el numero entero
String valor;

void setup() {
  
    Serial.begin(9600); //iniciar Cx Serial
    Serial.println("Ingrese dato:"); //Ingresa el valor almacenado sea mayor o menor
}

void loop() {
 
  if (Serial.available() > 0) { //verifica si hay valores almacenados
    valor = Serial.readString(); //valor que recive 
    v_alma = valor.toInt(); // convertir dato a entero
    EEPROM.read(cont);
    if (cont < 256) { //verfica si la memoria es llena
      if (v_alma > EEPROM.read(cont)) { //validar que sea mayor
        cont++; //incrementa una pocisión
        EEPROM.write(cont, v_alma); //guarda en una posicion el valor almacenado
        delay(100);
        Serial.print("Se almaceno: "); //Almacen la posicon  guardada y la imprime
        Serial.print(v_alma);
        Serial.print(" en la siguiente posicion: ");
        Serial.println(cont);
        } 
        else {
        Serial.println("Valor  menor es"); //Cuando el valor sea  menor o igual
      }
     } else {
      
      Serial.println("La memoria es llena"); //memoria llena
    }
  }
}
