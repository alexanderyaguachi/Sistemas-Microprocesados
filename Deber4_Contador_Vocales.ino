/*UNIVERSIDAD TECNICA DEL NORTE
 * Alexander Yaguachi Morocho
 * 
 * Deber 4_1
 * Realizar un sistema que permite determinar el número
   de vocales dentro de una palabra. Este dato es ingresado por comunicación 
   serial y la respuesta del mismo de igual manera. Subir su link de github. 
   Ejemplo 1: Ingreso: CIERCOM Retorna: 3 Ejemplo 2. Ingreso: DATOS Retorna: 2
*/
String palabra;     //variable de ingreso para ingreso de datos
int dato=0;
int i=0;  // contador 
int j=0;  // contador para vocales
void setup()
{
  Serial.begin(9600);  //configuracion del puerto serial de 9600bps
  Serial.println("Ingrese Palabra");//Para ingresar una palabra 
  } 
void loop(){
  delay(1500);  //Asignar un tiempo de espera para escribir la palabra
  if(Serial.available()>0){ //valida si hay datos de entrada en la comunicacion serial
    Serial.println();   //Realiza un salto de linea
    palabra=Serial.readString();  // lee la cadenade texto
    Serial.println();   //Realiza un salto de linea
    Serial.println("Total de Vocales:");
    dato=palabra.length();
    
    for(;i<dato;i++){   // condicion de conteo de la palabra escrita
      if(palabra.charAt(i)=='a'   //para vocales minúsculas
      || palabra.charAt(i)=='e'   //para vocales minusculas
      || palabra.charAt(i)=='i'   //para vocales minusculas
      || palabra.charAt(i)=='o'   //para vocales minusculas
      || palabra.charAt(i)=='u')  //para vocales minusculas
      {
      j=j+1;    //el contador de vocales aunmenta uno cuando encuentra una vocal
      }else if(palabra.charAt(i)=='A'  //para vocales mayúsculas
      || palabra.charAt(i)=='E'        //para vocales mayúsculas
      || palabra.charAt(i)=='I'        //para vocales mayúsculas
      || palabra.charAt(i)=='O'        //para vocales mayúsculas
      || palabra.charAt(i)=='U')       //para vocales mayúsculas
      { 
       j=j+1;   //el contador de vocales aunmenta uno cuando encuentra una vocal
       }
     }
    Serial.println(j);    //imprime el numero de vocales que conto
    i=0;  
    j=0;
    }
}
