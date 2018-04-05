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

TEST(test_calculadora, test_dieg) {
    Programa p;

    p.agregarInstruccion("MAINDIEG", Instruccion(READ, "x"));
    p.agregarInstruccion("MAINDIEG", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAINDIEG", Instruccion(WRITE, "y"));
    p.agregarInstruccion("MAINDIEG", Instruccion(ADD));
    p.agregarInstruccion("MAINDIEG", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("MAINDIEG");

    EXPECT_EQ(c.valorVariable("y"), 2);
    EXPECT_EQ(c.valorVariable("x"), 0);
}

//*/

TEST(test_calculadora, mult_con_un_solo_parametro){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 888));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(MUL));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 0);
}

//*/

TEST(test_calculadora, rutina_con_jump_sin_sentido){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "METODO_QUE_NO_EXISTE"));
    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 160);
}

//*/

TEST(test_calculadora, rutina_con_jump){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 45));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));

    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(PUSH, 45));
    p.agregarInstruccion("B", Instruccion(SUB));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 0);
}

//*/

TEST(test_calculadora, multiples_read){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 32));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));

    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 32*6);
}

//*

TEST(test_calculadora, rutina_con_jump2){
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

//*/

TEST(test_calculadora, rutina_con_write){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 40));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 40);
}

//*/

//*/

TEST(test_calculadora, rutina_write_read){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 80));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(READ, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 80);
}

//*/

//*/
TEST(test_calculadora, rutina_con_jumpz){
    Programa p;

    p.agregarInstruccion("A", Instruccion(PUSH, 40));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "B"));

    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));

    Calculadora c(p);

    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 80);
}

TEST(test_calculadora, test_hasta_0){
    Programa p;

    p.agregarInstruccion("RUTINA0", Instruccion(READ, "n"));
    p.agregarInstruccion("RUTINA0", Instruccion(PUSH, 1));
    p.agregarInstruccion("RUTINA0", Instruccion(SUB));
    p.agregarInstruccion("RUTINA0", Instruccion(WRITE, "n"));
    p.agregarInstruccion("RUTINA0", Instruccion(READ, "n"));
    p.agregarInstruccion("RUTINA0", Instruccion(JUMPZ, "FIN"));
    p.agregarInstruccion("RUTINA0", Instruccion(JUMP, "RUTINA0"));

    Calculadora c(p);

    c.asignarVariable("n", 10);
    c.ejecutar("RUTINA0");

    EXPECT_EQ(c.valorVariable("n"), 0);
}
//*/
