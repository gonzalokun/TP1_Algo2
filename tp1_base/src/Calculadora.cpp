#include "Calculadora.h"

Calculadora::Calculadora(Programa programa) (_programa(programa)){

}/* construye una calculadora que tiene cargado
            el programa indicado.*/


void Calculadora::asignarVariable(Id idVariable, int valor) {
    if(existeVariable(idVariable) != -1){
        var[posVar].valor = valor;
    } else {//si no existe la var, entonces la guardamos junto a su valor
        var.push_back({idVariable,valor});
    }
}/* establece el valor de la
    variable indicada en la memoria de la calculadora.*/


void Calculadora::ejecutar(Id idRutina) {

}/* ejecuta el programa hasta alcanzar alguna de las
            condiciones de finalización. La ejecución comienza en la primera instrucción de la rutina especificada por el
            parámetro idRutina. Observar que si idRutina no es una rutina existente en el programa, la ejecución
            finaliza de manera inmediata.*/


int Calculadora::valorVariable(Id idVariable) const{

} /*devuelve que tiene la variable indicada
            en la memoria de la calculadora. Si nunca se le dio valor a dicha variable, se asume que su valor
            por defecto es 0.*/

int Calculadora::existeVariable(Id nombre) {
    int i = 0;
    while(i < var.size() && var[i].nombre!=nombre) {
        i++;
    }
    posVar = (i <= var.size())? i : -1;
    return posVar;
}

//DUDA: CUANTAS VARIABLES PODRIA TENER UN MISMO PROGRAMA? ME FALTA TERMINAR LA FUNCION VALORVARIABLE