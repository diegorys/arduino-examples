/****************************************/
/************ ACTUADOR LUCES ************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

#ifndef _ACTUADOR_LUCES_H_

#define _ACTUADOR_LUCES_H_ 1

#include "Depuracion.h"

/** CLASE ACTUADOR LUCES **/

/**
 * Define la clase que maneja las luces del Coche Fantástico.
 */
class ActuadorLuces{
  
  public:

    /**
     * Constructor
     */     
    ActuadorLuces();
    
    /**
     * Inicializa los pines.
     */
    void iniciar(){};
    
    /**
     * Enciende la luz que corresponde a la posición de Kit.
     */
    void secuencia(){};
    
    /**
     * Desplaza el valor de kit al siguiente de la secuencia.
     */
    void desplazar();

  protected:
  
    //Posición de Kit, indica qué led se encenderá.
    unsigned char kit;
    
    //Utilizado para el sentido, ascendente o descendente.
    boolean sentido;
};

/** FIN DE CLASE ACTUADOR LUCES **/

/** CLASE ACTUADOR LUCES DIRECTO **/

/**
 * Define la clase que maneja las luces llamando directamente a los puertos
 * analógicos A0 - A7 de la ATMega (DDRF, PORTF).
 */
class ActuadorLucesDirecto : public ActuadorLuces{
    public:
    
     /**
      * Inicializa los pines.
      */
      void iniciar();
      
     /**
      * Enciende la luz que corresponde a la posición de Kit.
      */
      void secuencia();
      
    protected:
    
      /**
       * Controla la secuencia del led 1
       */
      int led1;
      
      /**
       * Controla la secuencia del led 2
       */
      int led2;
};

/** FIN DE CLASE ACTUADOR LUCES DIRECTO **/

/** CLASE ACTUADOR LUCES INDIRECTO **/

/**
 * Define la clase que maneja las luces llamando a la función digitalWrite().
 */
class ActuadorLucesIndirecto : public ActuadorLuces{
    public:
    
    /**
     * Constructor
     */
     ActuadorLucesIndirecto();
      
    /**
     * Inicializa los pines.
     */
     void iniciar();
     
    /**
     * Enciende la luz que corresponde a la posición de Kit.
     */
     void secuencia();
      
    protected:
    
      //Pines de kit.
      int pin[8];
};

/** FIN DE CLASE ACTUADOR LUCES INDIRECTO **/

#endif

