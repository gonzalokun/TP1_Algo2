#ifndef SOLUCION_CALCULADORA_H
#define SOLUCION_CALCULADORA_H
#include <iostream>
#include <vector>
#include <string>
typedef int memoria;
class Calculadora {

public:

    Calculadora::Calculadora(Programa programa);/* construye una calculadora que tiene cargado
            el programa indicado.*/
    void Calculadora::asignarVariable(Id idVariable, int valor);/* establece el valor de la
    variable indicada en la memoria de la calculadora.*/
    void Calculadora::ejecutar(Id idRutina);/* ejecuta el programa hasta alcanzar alguna de las
            condiciones de finalización. La ejecución comienza en la primera instrucción de la rutina especificada por el
            parámetro idRutina. Observar que si idRutina no es una rutina existente en el programa, la ejecución
            finaliza de manera inmediata.*/
    int Calculadora::valorVariable(Id idVariable) const; /*devuelve que tiene la variable indicada
            en la memoria de la calculadora. Si nunca se le dio valor a dicha variable, se asume que su valor
            por defecto es 0.*/
private:

    int existeVariable(Id nombre);
    Programa _programa;
    vector<memoria> pila;
    struct variables{
        Id nombre;
        int valor;
    };
    vector<variables> var;
    int posVar;


};


#endif //SOLUCION_CALCULADORA_H
