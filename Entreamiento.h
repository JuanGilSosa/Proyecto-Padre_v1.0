#ifndef ENTREAMIENTO_H_INCLUDED
#define ENTREAMIENTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/*
*   Si el valor que tiene dicha variable es 0, es porque no tiene ese atuendo
*   Si el valor que tiene es 1, es porque tiene ese atuendo
*/

typedef struct{
    int remera;
    int shor;
    int buzo;
    int termico;
    int mediasLargas;
    int zoquetes;
}ropaE;
/*
void entregarRemera(stDivisiones **ADL, int pos);
void entregarShor(stDivisiones **ADL, int pos);
void entregarBuzo(stDivisiones **ADL, int pos);
void entregarTermico(stDivisiones **ADL, int pos);
void entregarMediasL(stDivisiones **ADL, int pos);
void entregarZoquetes(stDivisiones **ADL, int pos);

void sacarRemera(stDivisiones **ADL, int pos);
void sacarShor(stDivisiones **ADL, int pos);
void sacarBuzo(stDivisiones **ADL, int pos);
void sacarTermico(stDivisiones **ADL, int pos);
void sacarMediasL(stDivisiones **ADL, int pos);
void sacarZoquetes(stDivisiones **ADL, int pos);
*/

ropaE cargaRopa();
char *verRopa(int a);
void mostrarUnJugadorConRopaEntr(ropaE a, char ape_jugador[],int y);
ropaE setInicE();

#endif // ENTREAMIENTO_H_INCLUDED
