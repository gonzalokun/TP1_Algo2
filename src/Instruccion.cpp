#include "Instruccion.h"

Instruccion::Instruccion(Operacion operacion, int valor){
    valorInstruccion = valor;
    operacionInstruccion = operacion;
}

Instruccion::Instruccion(Operacion operacion){
    operacionInstruccion = operacion;
}

// Precondición: la operación es READ, WRITE, JUMP o JUMPZ
Instruccion::Instruccion(Operacion operacion, Id nombre){
    operacionInstruccion = operacion;
    rutinaInstruccion = nombre;
}

Operacion Instruccion::operacion() const{
    return operacionInstruccion;
}

// Precondición: la operación es PUSH
int Instruccion::valor() const{
    return valorInstruccion;
}

// Precondición: la operación es READ, WRITE, JUMP o JUMPZ
Id Instruccion::nombre() const{
    return rutinaInstruccion;
}