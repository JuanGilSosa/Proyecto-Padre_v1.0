#ifndef ROPA_H_INCLUDED
#define ROPA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "jugador.h"
#include "divisiones.h"

#define HB_IDBOX 200
typedef struct{
    int codigo; // le voy a a dar utilidad como si fuera un ID para la Ropa
    char nombreRopa[30];
    int stock; //este disminuye por si se rompe una remera
    int cant;  //esta es la cantidad de ropa cargada
    int tipo; //0-ropa viaje, 1-ropa entrenamiento, 2-ropa de juego, 3-otros
    char descripcion[500];
    char fecha[128];
}ropaNueva;

int BUFFER_LIMITE = 0; //este tendria el valor de la cantidad de ropa cuando se desea repartir

void seleccionarOpcionR(stDivisiones **ADL);
void ingresarRopaNueva();
void mostrarTipoRopa(int x, int y, int tipo);
void guardarRopaNueva(ropaNueva a);
void mostrarJugadoresConRopaEntr(stDivisiones **ADL);
void mostrarRopa(stDivisiones **ADL);
void mostrarConjuntoRopa(ropaNueva a,int y);
void verRopaSistemaJugador(stDivisiones **ADL,int view);
void bajarRopa();
//void mostrarTodaLaRopa();
int contarRegistrosRopa(char nArch[]);
void mostrarRopaEliminada(stDivisiones **ADL);
int ultimoCodigo();
void darRopaEntr(stDivisiones **ADL);
void darRopa(stDivisiones **ADL);
#endif // ROPA_H_INCLUDED
