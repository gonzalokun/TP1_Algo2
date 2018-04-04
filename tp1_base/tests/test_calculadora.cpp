#include "gtest/gtest.h"

#include "../src/Calculadora.h"



TEST(test_calculadora, ejecutar_suma_sin_elem) {
    Programa p;

    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.asignarVariable("x", 38);
    EXPECT_EQ(c.valorVariable("x"),38);

    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"),40);

    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"),42);
}

TEST(test_calculadora, rutina_con_jump_sin_sentido){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "METODO_QUE_NO_EXISTE"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 160);
}

//*
TEST(test_calculadora, rutina_con_jump){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));

    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(PUSH, 80));
    p.agregarInstruccion("B", Instruccion(SUB));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 0);
}

//*/

//*

TEST(test_calculadora, testeo_con_jumps){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 40));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));

    p.agregarInstruccion("B", Instruccion(PUSH, 80));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(SUB));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 40);
}

//*/

TEST(test_calculadora, testeo_parametros){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 40));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 40);
}
