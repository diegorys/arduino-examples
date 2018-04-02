#include <Boton.h>

/****************************************/
/**************** PIANO *****************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** NOTAS MUSICALES **/
#define SILENCIO 0
#define NOTA_DO  32
#define NOTA_RE  37
#define NOTA_MI  41
#define NOTA_FA  44
#define NOTA_SOL 49

/** PARÁMETROS **/

//Establece el tiempo de separación entre notas para que no suenen seguidas.
#define DURACION_SEPARACION 10

/** DATOS DEL PROGRAMA **/

//PINES DE ENTRADA ANALÓGICOS
int ldr        = A2;
int potOctava  = A1;

//TECLAS DEL PIANO
Boton teclaDo(5);
Boton teclaRe(6);
Boton teclaMi(10);
Boton teclaFa(11);
Boton teclaSol(12);

//PINES DE SALIDA
int led       = 9;
int buzPiano  = 14;

//OTRAS VARIABLES
int octava = 1;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzPiano, OUTPUT);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  tocaNota();
  estableceOctava();
  compruebaLuz();
}

/**
 * Comprueba si hay suficiente luz y enciende
 * los leds proporcinalmente a la luz.
 */
void compruebaLuz(){
  int luz = analogRead(ldr);
  Serial.println(luz);
  if(luz > 255){
    analogWrite(led,  0);
  }else{
    analogWrite(led, 255-luz);
  }
}

/**
 * Establece la octava en función de
 * lo que marque el potenciómetro.
 */
 void estableceOctava(){
   int potencia = analogRead(potOctava);
   octava = map(potencia, 0, 1023, 1, 8);
 }
 
 /**
  * Si hay algún pulsador activo, toca
  * la nota que le corresponde.
  */
 void tocaNota(){
    if(teclaDo.leerBoton() == HIGH){
       tone(buzPiano, NOTA_DO*octava);
    }else if(teclaRe.leerBoton() == HIGH){
       tone(buzPiano, NOTA_RE*octava);
    }else if(teclaMi.leerBoton() == HIGH){
       tone(buzPiano, NOTA_MI*octava);
    }else if(teclaFa.leerBoton() == HIGH){
       tone(buzPiano, NOTA_FA*octava);
    }else if(teclaSol.leerBoton() == HIGH){
       tone(buzPiano, NOTA_SOL*octava);
    }else{
      noTone(buzPiano);
    }
 }
