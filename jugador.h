#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Entreamiento.h"
#include "Viaje.h"


typedef struct{
    int division;
    int idPlayer;
    char nombre_p[30];
    char apellido[30];
    long int DNI;
    int numeroCanasto;//capas que lo saco
    int estado;//1(suspendido-eliminado) | 0(activo)
    ropaE entr;
    RopaV ropV;
}stPlayer;

stPlayer cargarJugador(int division);
void mostrarJugador(stPlayer a, int x, int y);
void mostrarJugadorL(stPlayer a, int y);
void playertofile(stPlayer a);
int ultimoIdPlayer();
char *verEstado(int estado);
void asignarDivision_string(int pos, char a[]);
#endif // JUGADOR_H_INCLUDED
