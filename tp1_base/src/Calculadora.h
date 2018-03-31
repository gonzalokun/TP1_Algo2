#ifndef SOLUCION_CALCULADORA_H
#define SOLUCION_CALCULADORA_H
#include <iostream>
#include <vector>
#include <string>
#include "Programa.h"

class Calculadora {

public:

    Calculadora(Programa programa);
    void asignarVariable(Id idVariable, int valor);
    void ejecutar(Id idRutina);
    int valorVariable(Id idVariable) const;
private:

    int existeVariable(Id nombre) const;

    Programa _programa;

    struct variables{
        Id nombre;
        int valor;
    };
    vector<variables> var;

    void gestorDeOperaciones(Instruccion inst);
    vector<memoria> pila; //si queremos ejecutar varios programas con la misma calculadora no tendriamos memoria
        //quiza seria mejor generar un struct de memoria, que almacene la pila y ademas el nombre del programa al q pertenece
    void operacionJUMP(Id rutina);

};


#endif //SOLUCION_CALCULADORA_H
