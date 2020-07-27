#include "opciones.h"

void seleccionarOpcionO(stDivisiones **ADL){

    int op;
    do{
        op = menuOpciones();
        switch(op){
            case 0:
                system("cls");
                resetmemory(ADL);
                delfiles();
                system("cls");
                recuadro();
                break;
            case 1:
                datospersonales();
                break;
            case 2:
                menuPrincipal(ADL);
                break;
        }
    }while(1);
}

void datospersonales(){
    MessageBox(
        HWND_DESKTOP,
        "Version 1.0\n\nAnte algun problema comuniquese a:\njuanmanuels499@gmail.com\n\nCopyright © 2020 Todos los derechos reservados\n\nEste programa esta protegido para el uso puro y exclusivo dentro de este dispositivo, en el caso del intento de uso externo comuniquese con el desarrollador.",
        "Acerca de",
        MB_USERICON+MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
}

void resetmemory(stDivisiones **ADL){
    int i; //posiciones del arreglo
    for (i = 0; i<4;i++){
        (*ADL)[i].listaJugador = refreshlist((*ADL)[i].listaJugador);
    }
}

void delfiles(){
    system("del jugadores.dat");system("del ropaNueva.dat");
    system("del ropaBajada.dat");system("del eliminado.dat");
    MessageBox(HWND_DESKTOP,"SISTEMA REINICIADO","System",MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
}

