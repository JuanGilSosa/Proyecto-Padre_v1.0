#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "divisiones.h"

int movearrowsUPDOWN(char a[][50], int lenMenu);
int movearrowsLEFTRIGHT(char a[][50], int lenMenu);
int eleccionDivision();
void menuPrincipal(stDivisiones **ADL);
int menuJugador(stDivisiones **ADL);
void formularioCargaJugador();
void recuadro();
void clearcolor(char a[], int x, int y);
void mostrarMenuUPDOWN(char a[][50], int lenMenu);
void mostrarMenuLEFTRIGHT(char a[][50], int lenMenu);
int menuIndumentaria();
int tipoRopa();
int eleccionVerRopa();
void visualizarListado();
void formularioCargaJugador();
void cartelJugador(int x, int y);
void formularioCargarRopa();
void visualizarListadoRopaEntr();
void visualizarRopaEnSistem();
void visualizarRopaBaja();
int menuDarRopa();
void visualizarRopaViaje();
void visualizarEntregaBolso();
#endif // MENUS_H_INCLUDED
