#include "Entreamiento.h"

///////////////////////////////////////////////////////////////////
//Estas funciones solo cambian el valor de la estructura que se
//encuentra en memoria
///////////////////////////////////////////////////////////////////

/*
void entregarRemera(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.remera = 1;
}

void entregarShor(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.shor = 1;
}

void entregarBuzo(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.buzo = 1;
}

void entregarTermico(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.termico = 1;
}

void entregarMediasL(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.mediasLargas = 1;
}

void entregarZoquetes(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.zoquetes = 1;
}

void sacarRemera(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.remera = 0;
}

void sacarShor(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.shor = 0;
}

void sacarBuzo(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.buzo = 0;
}

void sacarTermico(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.termico = 0;
}

void sacarMediasL(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.mediasLargas = 0;
}

void sacarZoquetes(stDivisiones **ADL, int pos){
    (*ADL)[pos].listaJugador->dato.entr.zoquetes = 0;
}
*/

///////////////////////////////////////////////////////////////////

int setAnyRopaE(){
    return 1;
}

ropaE cargaRopa(){
    ropaE dato;

    gotoxy(62,11);
    printf("----------------------------------------------------------");
    gotoxy(62,12);
    printf("|Ingrese 1[TIENE] | 0[NO TIENE] la indumentaria resaltada|");
    gotoxy(62,13);
    printf("----------------------------------------------------------");

    gotoxy(62,15);
    printf(" | BUZO...........: ");
    gotoxy(62,16);
    printf(" | REMERA.........: ");
    gotoxy(62,17);
    printf(" | SHORT..........: ");
    gotoxy(62,18);
    printf(" | TERMICO........: ");
    gotoxy(62,19);
    printf(" | MEDIAS LARGAS..: ");
    gotoxy(62,20);
    printf(" | ZOQUETES.......: ");

    gotoxy(82,15);
    fflush(stdin);
    scanf("%d",&dato.buzo);
    gotoxy(82,16);
    fflush(stdin);
    scanf("%d",&dato.remera);
    gotoxy(82,17);
    fflush(stdin);
    scanf("%d",&dato.shor);
    gotoxy(82,18);
    fflush(stdin);
    scanf("%d",&dato.termico);
    gotoxy(82,19);
    fflush(stdin);
    scanf("%d",&dato.mediasLargas);
    gotoxy(82,20);
    fflush(stdin);
    scanf("%d",&dato.zoquetes);
    return dato;
}

ropaE setInicE(){
    ropaE a;
    a.buzo = 0;
    a.mediasLargas = 0;
    a.remera = 0;
    a.shor = 0;
    a.termico = 0;
    a.zoquetes = 0;
    return a;
}

//por ahora la uso para ver la ropa de entrenamiento
char *verRopa(int a){
    return (a==1) ? "SI" : "NO";
}

void estadoRemera(int a, int y){
    if(a!=0){ gotoxy(72,y);printf("|%d",a);}else{gotoxy(72,y);printf("|NO");}
}

void mostrarUnJugadorConRopaEntr(ropaE a, char ape_jugador[],int y){
    visualizarListadoRopaEntr();
    gotoxy(44,y);
    printf("|%s",ape_jugador);
    gotoxy(65,y);
    printf("|%s",verRopa(a.buzo));

    estadoRemera(a.remera,y);

    gotoxy(81,y);
    printf("|%s",verRopa(a.shor));
    gotoxy(89,y);
    printf("|%s",verRopa(a.termico));
    gotoxy(99,y);
    printf("|%s",verRopa(a.mediasLargas));
    gotoxy(115,y);
    printf("|%s",verRopa(a.zoquetes));
}

