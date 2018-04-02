/****************************************/
/************ ECO INFRARROJOS ***********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibTimer.h>

/** VARIABLES **/

//Emite por IR.
IRsend emisor;

//Recibe IR.
IRrecv receptor(8);

//Decodifica un valor recibido.
IRdecode decodificador;

//Último protocolo recibido.
IRTYPES protocolo = UNKNOWN;

//Último código recibido.
unsigned long codigo;

//Orden recibida por el puerto serial.
int orden = 0;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup()
{
  Serial.begin(9600) ;
  receptor.enableIRIn(); // Start the receiver
  Serial.println("Emisor y receptor IR.") ;
}

/**
 * Bucle infinito de ejecución.
 */
void loop()
{
  recibir();
  enviar();
  delay(300);
}

/**
 * Envía el último código mediante el último protocolo
 * que se ha recibido.
 */
void enviar(){
  if (Serial.available() > 0) {
    orden = Serial.parseInt();
    if(orden == 1){
      if(protocolo != UNKNOWN){
        Serial.println("ENVIANDO");
        mostrar();
        emisor.send(protocolo,codigo, 32);
        Serial.println("OK");
        receptor.enableIRIn(); // Start the receiver
      }else{
        Serial.println("Protocolo desconocido");
      }
    }
  }
}

/**
 * Comprueba si hay datos y, si es así, actualiza el último
 * protocolo y el último código.
 */
void recibir(){
  if (receptor.GetResults(&decodificador)) {	
    decodificador.decode();//decode the signal	
    if(decodificador.decode_type != UNKNOWN && decodificador.value != 0xFFFFFFFF){
      codigo = decodificador.value;
      protocolo = decodificador.decode_type;
      Serial.println("RECIBIDO");
      mostrar();
    }	
    receptor.resume(); //restart the receiver	
  }  
}

/**
 * Muestra los datos del último protocolo y el
 * último código que se han recibido.
 */
void mostrar(){
  Serial.print("Protocolo: ");
  Serial.println(Pnames(protocolo));
  Serial.print("Valor: ");
  Serial.println(codigo, HEX);
}
