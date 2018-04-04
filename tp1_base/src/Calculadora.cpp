#include "Calculadora.h"

Calculadora::Calculadora(Programa programa) : _programa(programa){
    //var[0].nombre = "x";
    //var[1].nombre = "y";

    //no entiendo si solo puede haber 2 variables; y si ya deben estar inicializadas  desde antes o que
}


void Calculadora::asignarVariable(Id idVariable, int valor) {
    //establece el valor de la variable
    //indicada en la memoria de la calculadora.

    int posVar = existeVariable(idVariable);

    if(posVar != -1){
        var[posVar].valor = valor;
    }

    //si no existe la var, entonces la guardamos junto a su valor
    else {
        var.push_back({idVariable,valor});
    }

}

void Calculadora::ejecutar(Id idRutina) {

    /*
     * ejecuta el programa hasta alcanzar alguna de las
     * condiciones de finalización. La ejecución comienza en la primera instrucción de la rutina especificada por el
     * parámetro idRutina. Observar que si idRutina no es una rutina existente en el programa, la ejecución
     * finaliza de manera inmediata.
     */

    /*
    if(_programa.esRutinaExistente(idRutina)) {
        int recInstRutinas = 0;

        while(recInstRutinas < _programa.longitud(idRutina)) {
            gestorDeOperaciones(_programa.instruccion(idRutina,recInstRutinas));
            recInstRutinas++;
        }
    }
    */

    //Con este ciclo se deberia poder cambiar de rutina en tiempo real por medio de jumps
    //Suponemos que una vez que se hace un jump NO se vuelve atrás

    //SETEAMOS LA PRIMER RUTINA, PUEDE CAMBIAR LUEGO
    _rutinaActual = idRutina;
    _indiceDeEjecucion = 0;

    while(_programa.esRutinaExistente(_rutinaActual) && _indiceDeEjecucion < _programa.longitud(_rutinaActual)){
        gestorDeOperaciones(_programa.instruccion(_rutinaActual, _indiceDeEjecucion));

        //*/

        printf("\nPILA EN INSTRUCCION %d:\n", _indiceDeEjecucion);

        for(int i = 0; i < pila.size(); i++){
            printf("VALOR %d: %d\n", i, pila[i]);
        }
        //*/

        _indiceDeEjecucion++;
    }

    //*/

    printf("\nPILA AL FINAL:\n");

    for(int i = 0; i < pila.size(); i++){
        printf("VALOR %d: %d\n", i, pila[i]);
    }

    printf("------------------------------\n");

    //*/
}

/*
 *
 *
1. La rutina actual no existe en el programa. Por ejemplo, si se ejecuta jump(XYZZY) y la rutina XYZZY
no está definida, la calculadora finaliza la ejecución del programa.
2. La rutina actual existe en el programa, pero el índice de la instrucción actual está fuera del rango de las
instrucciones de dicha rutina. Por ejemplo, si se ejecuta la instrucción add y esa es la última instrucción
de la rutina actual, la calculadora finaliza la ejecución del programa.
 * */

void Calculadora::gestorDeOperaciones(Instruccion inst) {
    if(inst.operacion() == PUSH) {
        pila.push_back(inst.valor());
    }

    if(inst.operacion() == ADD) {
        if(pila.size() > 1) {
            int guardoValorSuma = pila[pila.size()-1] + pila[pila.size()-2];

            pila.pop_back();
            pila.pop_back();
            pila.push_back(guardoValorSuma);
        }

        else if(pila.size() == 0){
            pila.push_back(0);
        }
    }

    if(inst.operacion() == SUB) {
        if(pila.size() > 1) {
            int guardoValorResta = pila[pila.size()-1] - pila[pila.size()-2];

            pila.pop_back();
            pila.pop_back();
            pila.push_back(guardoValorResta);
        }

        else if(pila.size() == 0){
            pila.push_back(0);
        }
    }

    if(inst.operacion() == MUL) {
        if(pila.size() > 1) {
            int guardoValorMult = pila[pila.size()-1] * pila[pila.size()-2];

            pila.pop_back();
            pila.pop_back();
            pila.push_back(guardoValorMult);
        }

        else if(pila.size() == 0){
            pila.push_back(0);
        }
    }

    if(inst.operacion() == WRITE) {
        if(pila.size() > 0) {
            asignarVariable(inst.nombre(), pila[pila.size()-1]);
            pila.pop_back();
        }

        else {
            asignarVariable(inst.nombre(), 0);
        }
    }

    if(inst.operacion() == READ) {
        pila.push_back(valorVariable(inst.nombre()));

        //*/
        std::cout << "LEIDO EL VALOR DE la variable " << inst.nombre() << " IGUAL A " << valorVariable(inst.nombre()) << std::endl;
        //*/
    }

    if(inst.operacion() == JUMP) {
        operacionJUMP(inst.nombre());
    }

    if(inst.operacion() == JUMPZ) {

        if(pila.size() == 0 || (pila.size() != 0) && (pila[pila.size()-1] == 0) ) {
            pila.pop_back();
            operacionJUMP(inst.nombre());
        }

        else{
            pila.pop_back();
        }
    }

}

void Calculadora::operacionJUMP(Id rutina) {
    _rutinaActual = rutina;
    _indiceDeEjecucion = 0;
}

int Calculadora::valorVariable(Id idVariable) const{
    int posVar = existeVariable(idVariable);
    return (posVar!=-1)? var[posVar].valor : 0;
}
/*devuelve que tiene la variable indicada
            en la memoria de la calculadora. Si nunca se le dio valor a dicha variable, se asume que su valor
            por defecto es 0.*/

int Calculadora::existeVariable(Id nombre) const{
    int i = 0;
    while(i < var.size() && var[i].nombre!=nombre) {
        i++;
    }
    return (var.size() == 0 && i == 0)? -1 : i;
}
