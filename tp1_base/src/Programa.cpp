#include "Programa.h"

// Inicialmente no hay ninguna rutina.
Programa::Programa() {

}

// Agrega una instrucción a la rutina indicada.
// Si la rutina indicada no existe, crea una nueva rutina
// con dicho nombre.
void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion){
    if(esRutinaExistente(idRutina)) {
        rutinas[posRutina].instruccionesRutina.push_back(instruccion);
    }else {//si no existe
        rutinas[longitud(idRutina)].instruccionesRutina.push_back(instruccion);
    }
}

// Devuelve True si idRutina representa una rutina existente.
bool Programa::esRutinaExistente(Id idRutina) const{
    return (getPosRutina(idRutina)>=0);
}

// Devuelve la longitud (cantidad de instrucciones) de la rutina
// indicada.
//
// Precondición: esRutinaExistente(idRutina)
int Programa::longitud(Id idRutina) const {
    int i = 0;
    while (i < rutinas.size() && rutinas[i].nombreRutina != idRutina) {
        i++;
    }
    return (rutinas.size() > 0 &&(rutinas[i].nombreRutina == idRutina))? rutinas[i].instruccionesRutina.size() : 0;
}

// Devuelve la i-ésima instrucción de la rutina indicada.
//
// Precondición:
//   esRutinaExistente(idRutina) && 0 <= i && i < longitud(idRutina)
Instruccion Programa::instruccion(Id idRutina, int i) const {
    Instruccion inst;
    if(esRutinaExistente(idRutina) && i >= 0 && i < rutinas[posRutina].instruccionesRutina.size()) {
        inst = rutinas[posRutina].instruccionesRutina[i];
    }
    return inst;
}

int Programa::getPosRutina(Id rutina) {
    int i = 0;
    while (i < rutinas.size() && rutinas[i].nombreRutina != idRutina) {
        i++;
    }
    posRutina = (i<= rutinas.size())? i : -1;
    return posRutina;
}