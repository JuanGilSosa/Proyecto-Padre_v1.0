#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Bolso.h"
typedef struct{
    Bolso bolso;
    int entregado;//indica 1 si se entrego o 0 si no se entrego
}RopaV;

Bolso setInicV();
void mostrarUnJugadorConRopaViaje(Bolso a,int y);
int setAnyRopaV();
Bolso inicBolso(int idBolso);
#endif // VIAJE_H_INCLUDED
