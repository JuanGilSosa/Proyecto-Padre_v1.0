#ifndef BOLSO_H_INCLUDED
#define BOLSO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct{
    int ID_BOLSO;
    int rem1;
    int rem2;
    int buzo;
    int campera;
    int pantalonLargo;
    int bermuda;
}Bolso;

Bolso inicBolso(int idBolso);

#endif // BOLSO_H_INCLUDED
