#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include <iostream>
#include <vector>
#include <string>
typedef int memoria;

#include "Instruccion.h"

// La clase Programa sirve para representar una secuencia de instrucciones.
//
//     Programa programa;
//
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 10));
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 20));
//     programa.agregarInstruccion("A", Instruccion(OP_ADD));
//     programa.agregarInstruccion("A", Instruccion(OP_JUMP, "A"));
//
//     programa.agregarInstruccion("B", Instruccion(OP_PUSH, 30));
//     programa.agregarInstruccion("B", Instruccion(OP_WRITE, "x"));
//
// Corresponde a las siguientes rutinas:
//
//     --- A ---
//       push(10)
//       push(20)
//       add
//       jump(A)
//
//     --- B ---
//       push(30)
//       write(x)

class Programa {
public:
	// Inicialmente no hay ninguna rutina.
	Programa();

	void agregarInstruccion(Id idRutina, Instruccion instruccion);

	bool esRutinaExistente(Id idRutina) const;

	int longitud(Id idRutina) const;

	Instruccion instruccion(Id idRutina, int i) const;

private:
	// COMPLETAR
	struct rutina {
		Id nombreRutina;
		vector<Instruccion> instruccionesRutina;
	};
	vector<rutina> rutinas;
	int getPosRutina(Id rutina)const;

};

#endif /*__PROGRAMA_H__*/

