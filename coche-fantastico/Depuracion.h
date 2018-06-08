/****************************************/
/************** DEPURACIÓN **************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#ifndef _DEPURACION_H_

#define _DEPURACION_H_ 1

#include <Arduino.h>

/** DEFINICIONES **/

#define DEPURAR        false  //Activo mostrará por el puerto serial datos de depuración.
#define TEMPORIZADORES false  //Activo contará el tiempo de inicialización e iteraciones.
//Tiempo de delay para el bucle.
#define tiempoDelay 100

/** FUNCIONES **/

void startTemporizador();
void stopTemporizador();

#endif
