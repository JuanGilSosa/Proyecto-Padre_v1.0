#include "Viaje.h"

int setAnyRopaV(){
    return 1;
}

Bolso setInicV(){
    Bolso a;
    a.bermuda = 0;
    a.buzo = 0;
    a.campera = 0;
    a.pantalonLargo = 0;
    a.rem1 = 0;
    a.rem2 = 0;
    a.ID_BOLSO = 0;
    return a;
}
//muestra el contenido del bolso
void mostrarBolso(Bolso a,int y){
    visualizarBolso();
    gotoxy(44,y);
    printf("|%d",a.ID_BOLSO);
    gotoxy(54,y);
    printf("|%s",verRopa(a.rem1));
    gotoxy(65,y);
    printf("|%s",verRopa(a.rem2));
    gotoxy(76,y);
    printf("|%s",verRopa(a.buzo));
    gotoxy(85,y);
    printf("|%s",verRopa(a.campera));
    gotoxy(95,y);
    printf("|%s",verRopa(a.pantalonLargo));
    gotoxy(114,y);
    printf("|%s",verRopa(a.bermuda));
}


