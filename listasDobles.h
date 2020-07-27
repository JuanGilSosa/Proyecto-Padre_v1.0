#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jugador.h"


typedef struct{
    stPlayer dato;
    //tengo que poner la indumentaria.
    struct Nodo *sig;
    struct Nodo *ante;
}Nodo;

Nodo *inicLista();
Nodo *crearNodo(stPlayer a);
Nodo *ultimoNodo(Nodo *lista);
Nodo *agregarFinal(Nodo *lista, Nodo *nNodo);
Nodo *borrarNodo(Nodo *lista, char ape[]);
Nodo *buscarNodo(Nodo *lista, char ape[]);
void mostrarLista(Nodo *lista, int x, int y);
int contarNodos(Nodo *lista);
Nodo *modificarLista(Nodo *lista, Nodo *nNodo);
Nodo *sacarBolsoLista(Nodo *lista);
#endif // LISTASDOBLES_H_INCLUDED
