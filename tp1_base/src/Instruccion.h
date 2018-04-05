#ifndef __INSTRUCCION_H__
#define __INSTRUCCION_H__

#include <iostream>
#include <vector>

#include "Utiles.h"

// Una instrucción está dada por un código de operación junto con una
// secuencia de parámetros de tipo entero.
//
// Actualmente todas las instrucciones de la máquina tienen a lo sumo
// un parámetro, y se espera que estén construidas de la siguiente manera:
//
//   PUSH     <numero>
//   ADD
//   SUB
//   MUL
//   READ     <nombre>
//   WRITE    <nombre>
//   JUMP     <nombre>
//   JUMPZ    <nombre>
//
class Instruccion { //no entiendo que tendriamos que hacer con las precondiciones: o sea, si restringimos con un if para que se cumpla la precondicion, que pasa cuando if da false?
                    //es decir, si para obtener una operacion de una rutina, indice de instruccion de la rutina debe ser valido.., pero que pasa si no cumple esto? porqu
public:
	// Precondición: la operación es PUSH
	Instruccion(Operacion operacion, int valor);

        // Precondición: la operación es ADD, SUB o MUL
	Instruccion(Operacion operacion);

        // Precondición: la operación es READ, WRITE, JUMP o JUMPZ
	Instruccion(Operacion operacion, Id nombre);

	Operacion operacion() const;

	// Precondición: la operación es PUSH
	int valor() const;

        // Precondición: la operación es READ, WRITE, JUMP o JUMPZ
	Id nombre() const;

private:
	Operacion operacionInstruccion;
	int valorInstruccion;
	Id rutinaInstruccion;

	// COMPLETAR
};

#endif /*__INSTRUCCION_H__*/
