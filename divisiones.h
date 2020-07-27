#ifndef DIVISIONES_H_INCLUDED
#define DIVISIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "listasDobles.h"

            #define UP 72
            #define LEFT 75
            #define RIGHT 77
            #define DOWN 80
            #define ENTER 13
            #define ESC 27




typedef struct{
    int idDivision; //solamente tendria 4ta, 5ta y 6ta y R - tendria los numero 4 - 5 - 6 - 7
    Nodo *listaJugador;
}stDivisiones;

void seleccionarOpcion(stDivisiones **ADL);
void altaJugador(stDivisiones **ADL);
int buscarPosDivision(stDivisiones **ADL, int div);
//void mostrarDivision(int division, char a[]);
void consultarJugador(stDivisiones **ADL);
void fileplayertocelda(stDivisiones **ADL);
void delPlayer(stDivisiones **ADL);
int returnPosDivision(int pos);
void listadoJugadores(stDivisiones **ADL);
void agregarEnLista(stDivisiones **ADL, stPlayer a, int pos);
void delPlayer(stDivisiones **ADL);
void listadoJugadores(stDivisiones **ADL);
void modificarDatosJugador(stDivisiones **ADL);
void modificarCampos(stDivisiones **ADL, int posCamp, int posDiv,Nodo *aux);
int returnPosDivision(int div);
#endif // DIVISIONES_H_INCLUDED
