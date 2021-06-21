/****************************************/
/************ RECEPTOR INFRARROJOS ***********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibTimer.h>

/** VARIABLES **/

//Recibe IR.
IRrecv receptor(8);

//Decodifica un valor recibido.
IRdecode decodificador;

//�ltimo protocolo recibido.
IRTYPES protocolo = UNKNOWN;

//�ltimo c�digo recibido.
unsigned long codigo;


/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup()
{
  Serial.begin(9600) ;
  receptor.enableIRIn(); // Start the receiver
  Serial.println("Receptor IR.") ;
}

/**
 * Bucle infinito de ejecuci�n.
 */
void loop()
{
  if (receptor.GetResults(&decodificador)) {	
    decodificador.decode();//decode the signal	
    if(decodificador.decode_type != UNKNOWN && decodificador.value != 0xFFFFFFFF){
      codigo = decodificador.value;
      protocolo = decodificador.decode_type;
      Serial.println("RECIBIDO");
  		Serial.print("Protocolo: ");
  		Serial.println(Pnames(protocolo));
  		Serial.print("Valor: ");
  		Serial.println(codigo, HEX);
    }	
    receptor.resume(); //restart the receiver	
  }
	delay(300);
}
