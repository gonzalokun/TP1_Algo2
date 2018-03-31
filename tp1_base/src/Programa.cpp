#include "Programa.h"

// Inicialmente no hay ninguna rutina.
Programa::Programa() {

}

void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion){
    int posRutina = getPosRutina(idRutina);
    if(posRutina != -1) {
        rutinas[posRutina].instruccionesRutina.push_back(instruccion);
    }else {//si no existe
        rutinas.push_back({idRutina,{instruccion}});
    }
}

bool Programa::esRutinaExistente(Id idRutina) const{
    return (getPosRutina(idRutina)>=0);
}

int Programa::longitud(Id idRutina) const {
    int i = 0;
    while (i < rutinas.size() && rutinas[i].nombreRutina != idRutina) {
        i++;
    }
    return (rutinas.size() > 0 && i < rutinas.size() &&(rutinas[i].nombreRutina == idRutina))? rutinas[i].instruccionesRutina.size() : 0;
}

//aca pide que i pertenezca al rango de las instrucciones. que pasa si no? que devolvemos? no existen las instrucciones vacias, si o si hay que darle parametros
Instruccion Programa::instruccion(Id idRutina, int i) const {
    //Instruccion inst;
    int posRutina = getPosRutina(idRutina);
    if(esRutinaExistente(idRutina) && i >= 0 && i < rutinas[posRutina].instruccionesRutina.size()) {
        return Instruccion(rutinas[posRutina].instruccionesRutina[i]);
    }
}//mejorar la forma de retorno aca (en base a entender que hacer con la precondicion)

int Programa::getPosRutina(Id rutina) const{
    int i = 0;
    while (i < rutinas.size() && rutinas[i].nombreRutina != rutina) {
        i++;
    }
    return (rutinas.size() != 0 && i< rutinas.size())? i : -1;
}