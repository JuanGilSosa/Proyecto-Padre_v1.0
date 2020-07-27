#include "MENUS.h"

void recuadro(){
    color(15);
    int x=2;
    int y=0;
    //punta ╔
    gotoxy(x-1,y);
    printf("%c",201);

    //linea horizontal ARRIBA
    while(x<125){
        gotoxy(x,y);
        printf("%c",205);
        if(x==43){
            gotoxy(x,y);
            printf("%c",203);// ╦
        }
        x++;
    }
    //punta ╗
    printf("%c",187);

    //linea vertical IZQUIERDA
    while(y<37){
        gotoxy(1,y+1);
        printf("%c",186);
        y++;
    }
    //punta ╚
    gotoxy(1,y);
    printf("%c",200);

    //linea horizontal ABAJO
    x=2;
    while(x<125){
        gotoxy(x,y);
        printf("%c",205);
        x++;
    }
    //punta ╝
    gotoxy(x,y);
    printf("%c",188);

    //linea vertical DERECHA
    y=0;
    while(y<36){
        gotoxy(x,y+1);
        printf("%c",186);
        y++;
    }

    //linea para titulos
    x=2;
    y=2;
    gotoxy(x-1,y);
    printf("%c",204);// ╠
    while(x<125){
        gotoxy(x,y);
        printf("%c",205);
        x++;
    }
    gotoxy(x,y);
    printf("%c",185); // ╣

    //linea que divide
    x=43;
    gotoxy(x,y-1);
    printf("%c",186);
    gotoxy(x,y);
    printf("%c",206);
    while(y<36){
        gotoxy(x,y+1);
        printf("%c",186);
        y++;
    }
    gotoxy(x,y+1);
    printf("%c",202);

    //ventana para ingresar datos
    x = 1;
    gotoxy(x,26);
    printf("%c",204);
    while(x<43){
        x+=1;
        gotoxy(x,26);
        printf("%c",205);
    }
    gotoxy(x,26);
    printf("%c",185);
}



/*
*   movearrows sirve para seleccionar una opcion con las flechas direccionales
*/

int movearrowsUPDOWN(char a[][50], int lenMenu){
    char op;
    int i = 0;
    int subY = 4; // variable de posicion de gotoxy

    color(10);
    hidecursor(0);
    mostrarMenuUPDOWN(a,lenMenu);

    gotoxy(3,subY);
    color(11);
    puts(a[i]);

    while(op != 13){
        fflush(stdin);
        op = _getch();

        if(i>0 && op==UP){
            clearcolor(a[i],3,subY);
            i--;
            //pinto la palabra en la posicion de - i -
            subY-=2;
            color(11);
            gotoxy(3,subY);
            puts(a[i]);
        }
        if(i<lenMenu-1 && op==DOWN){
            clearcolor(a[i],3,subY);
            i++;
            subY+=2;
            //pinto la palabra en la posicion de - i -
            color(11);
            gotoxy(3,subY);
            puts(a[i]);
        }
    }
    return i;
}

int movearrowsLEFTRIGHT(char a[][50], int lenMenu){
    char op;
    int i = 0;

    int subX = 66;

    color(14);
    mostrarMenuLEFTRIGHT(a,lenMenu);

    color(14);
    gotoxy(subX,13);
    puts(a[i]);

    while(op!=13){
        fflush(stdin);
        op = _getch();
        if(i > 0 && op == LEFT){
            clearcolor(a[i],subX,13);
            i--;
            subX-=(int)strlen(a[i]); //casteamos por las dudas de que reste a subX cualquier cosa
            color(14);
            gotoxy(subX,13);
            puts(a[i]);
        }
        if(i < lenMenu-1 && op == RIGHT){
            clearcolor(a[i],subX,13);
            i++;
            subX+=(int)strlen(a[i]);
            color(14);
            gotoxy(subX,13);
            puts(a[i]);
        }
    }
}

//desptina una palabra en la consola, trabajando de un color que en este caso es verde(10)
void clearcolor(char a[], int x, int y){
    color(10);
    gotoxy(x,y);
    puts(a);
}


int movearrowsUPDOWNROPA(char a[][50], int lenMenu){
    char op;
    int i = 0;
    int subY = 6; // variable de posicion de gotoxy

    color(10);
    hidecursor(0);
    mostrarMenuUPDOWNROPA(a,lenMenu);

    gotoxy(52,subY);
    color(11);
    puts(a[i]);

    while(op != 13){
        fflush(stdin);
        op = _getch();

        if(i>0 && op==UP){
            clearcolor(a[i],52,subY);
            i--;
            //pinto la palabra en la posicion de - i -
            subY-=1;
            color(11);
            gotoxy(52,subY);
            puts(a[i]);
        }
        if(i<lenMenu-1 && op==DOWN){
            clearcolor(a[i],52,subY);
            i++;
            subY+=1;
            //pinto la palabra en la posicion de - i -
            color(11);
            gotoxy(52,subY);
            puts(a[i]);
        }
    }
    return i;
}

void mostrarMenuUPDOWNROPA(char a[][50], int lenMenu){
    char subI=6;
    int i;
    for(i = 0;i < lenMenu;i++){
        gotoxy(52,subI);
        subI+=1;
        puts(a[i]);
    }
}


/*
*   Muestra el menu cargado en una matriz de tipo char
*/
void mostrarMenuUPDOWN(char a[][50], int lenMenu){
    borrarTexto(3,3,20);
    borrarTexto(3,5,20);
    borrarTexto(3,7,20);
    borrarTexto(3,9,20);
    borrarTexto(3,11,20);
    borrarTexto(3,13,24);
    borrarTexto(3,15,20);
    char subI=3;
    int i;
    for(i = 0;i < lenMenu;i++){
        gotoxy(3,subI+1);
        subI+=2;
        puts(a[i]);
    }
}

void mostrarMenuLEFTRIGHT(char a[][50], int lenMenu){
    char subX = 66;
    int i;
    for(i = 0; i<lenMenu;i++){
        gotoxy(subX,13);
        subX+=(int)strlen(a[i])+1;
        puts(a[i]);
    }
}



//hacemos que retorne una posicion en el arreglo en base a la divion que se eligio
int eleccionDivision(){

    char op;

    borrarTexto(2,1,40);
    borrarTexto(3,4,30);
    borrarTexto(3,6,30);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    gotoxy(14,1);
    color(15);
    printf("ELEJI UNA DIVISION");

    char menuD[][50] = {
        "  [1] - 4ta     ",
        "  [2] - 5ta     ",
        "  [3] - 6ta     ",
        "  [4] - RESERVA ",
        "  [5] - VOLVER  "
    };
    op = movearrowsUPDOWN(menuD,5);
    return op;
}

int menuJugador(stDivisiones **ADL){
    int op;

    char menuJ[][50] = {
        "[1] - CARGAR JUGADOR                ",
        "[2] - CONSULTAR JUGADOR             ",
        "[3] - ELIMNAR JUGADOR               ",
        "[4] - LISTADO DE JUGADORES          ",
        "[5] - MODIFICAR DATOS DE UN JUGADOR ",
        "[6] - VOLVER                        "
    };

    borrarTexto(3,4,30);
    borrarTexto(3,6,33);
    borrarTexto(3,8,30);
    borrarTexto(16,1,15);
    borrarTexto(5,1,30);

    gotoxy(11,1);
    color(15);
    printf("ADMINISTRACION JUGADORES");
    op = movearrowsUPDOWN(menuJ,6);
    return op;
}

int menuIndumentaria(){
    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);


    char op;

    char menuR[][50] = {
        "[1] - CARGAR ROPA",
        "[2] - VER ROPA",
        "[3] - DAR ROPA", //da la ropa a  un jugador o profesor
        "[4] - SACAR ROPA",
        "[5] - DAR DE BAJA A ROPA",
        "[6] - RESTAURAR ROPA", //restaura las indumentarias que estan rotas y tengo que subir el stock
        "[7] - VOLVER"
    };

    gotoxy(8,1);
    color(15);
    printf("ADMINISTRACION INDUMENTARIAS");
    op = movearrowsUPDOWN(menuR,7);
    return op;
}

int tipoRopa(){

    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    int tipo;
    char tipoR[][50] = {
        "[1] - ROPA DE VIAJE",
        "[2] - ROPA DE ENTRENAMIENTO",
        "[3] - ROPA DE JUEGO",
        "[4] - OTROS",
        "[5] - VOLVER"
    };
    tipo = movearrowsUPDOWN(tipoR,5); //siendo que me retorna una posicion en el arreglo
    return tipo;
}

/*
    Te hace elejir entre ver ropa que tiene un jugador, o la ropa que se tiene cargada en un archivo(no se carga
                                                                                                     en memoria)
*/
int eleccionVerRopa(){
    int op;

    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    char menuR[][50] = {
        "[1] - JUGADOR",
        "[2] - CARGADA EN SISTEMA",
        "[3] - ELIMINADA",
        "[4] - VOLVER"
    };
    op = movearrowsUPDOWN(menuR,4);
    return op;
}

int asignarRopaEntrenamiento(){
    int op;
    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    char menuR[][50] = {
        "[1] - REMERA",
        "[2] - SHORT",
        "[3] - BUZO",
        "[4] - TERMICO",
        "[5] - MEDIAS LARGAS",
        "[6] - ZOQUETES",
        "[7] - VOLVER"
    };
    op = movearrowsUPDOWN(menuR,7);
    return op;
}
/*
int asignarRopaViaje(){
    int op;
    gotoxy(5,1);
    printf("PRESIONE [ENTER] PARA ASIGNARLE ROPA");
    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    char menuR[][50] = {
        "[1] - REMERA 1",
        "[2] - REMERA 2",
        "[3] - BUZO",
        "[4] - CAMPERA",
        "[5] - PANTALON LARGO",
        "[6] - BERMUDA",
        "[7] - VOLVER"
    };
    op = movearrowsUPDOWN(menuR,7);
    return op;
}
*/
int menuDarRopa(){

    borrarTexto(3,1,32);
    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    gotoxy(14,1);
    color(15);
    printf("ELIJA UNA OPCION");

    int op;
    char menuR[][50] = {
        "[1] - ENTRENAMIENTO",
        "[2] - VIAJE",
        "[3] - OTRO",
        "[4] - VOLVER"
    };
    op = movearrowsUPDOWN(menuR,4);
    return op;
}

int menuSacarRopa(){
    int op;

    borrarTexto(3,1,34);
    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
    borrarTexto(3,16,30);

    gotoxy(14,1);
    color(15);
    printf("SACAR ROPA");

    char menuR[][50] = {
        "[1] - ENTRENAMIENTO",
        "[2] - BOLSO",
        "[3] - VOLVER"
    };

    op = movearrowsUPDOWN(menuR,3);

    return op;
}

int menuSacarBolso(){
    borrarTexto(3,4,30);

    char menuR[][50] = {
        "[1] - UN JUGADOR",
        "[2] - TODOS LOS JUGADORES",
        "[3] - VOLVER"
    };
    int op = movearrowsUPDOWN(menuR,3);
    return op;
}

//ve la ropa de entrenamiento y de viaje, siendo lo que tiene el jugador
int menuVerRopaEV(){
    borrarTexto(3,4,30);
    borrarTexto(3,6,34);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    int op;
    char menuR[][50] = {
        "[1] - ROPA DE ENTRENAMIENTO",
        "[2] - ROPA DE VIAJE",
        "[3] - VOLVER"
    };

    op = movearrowsUPDOWN(menuR,3);
    return op;
}

int menuFormaVerRopa(){
    borrarTexto(3,4,30);
    borrarTexto(3,6,30);
    borrarTexto(3,8,30);
    borrarTexto(3,10,30);
    int op;
    char menuR[][50] = {
        "[1] - CONSULTA",
        "[2] - LISTADO",
        "[3] - VOLVER"
    };
    op = movearrowsUPDOWN(menuR,3);
    return op;
}

int menuOpciones(){
    borrarTexto(3,4,38);
    borrarTexto(3,6,38);
    borrarTexto(3,8,38);
    borrarTexto(3,10,38);
    char menuO[][50] = {
        "[1] - REINICIAR SISTEMA",
        "[2] - ACERCA DE",
        "[3] - VOLVER"
    };
    int op = movearrowsUPDOWN(menuO,3);
    return op;
}

void menuPrincipal(stDivisiones **ADL){
    borrarTexto(5,1,30);
    borrarTexto(3,8,20);
    borrarTexto(3,10,35);
    borrarTexto(3,12,34);
    borrarTexto(3,14,20);
    borrarTexto(3,16,24);
    borrarTexto(3,18,20);
    borrarTexto(3,20,20);

    gotoxy(16,1);
    color(15);
    printf("MENU PRINCIPAL   ");
    char menuP[][50] = {
        "[1] - ADMINISTRACION JUGADORES     ",
        "[2] - ADMINISTRACION INDUMENTARIAS ",
        "[3] - OPCIONES                     ",
        "[4] - SALIR                        "
    };

    char op = movearrowsUPDOWN(menuP,4);
    do{
        switch(op){
            case 0:
                seleccionarOpcion(ADL);
                //administracion jugadores
                break;
            case 1:
                seleccionarOpcionR(ADL);
                //administracion ropa
                break;
            case 2:
                seleccionarOpcionO(ADL);
                //opciones
                break;
            case 3:
                system("cls");
                exit(1);
                break;
        }
    }while(1);
}

void visualizarListado(){
    /*
    gotoxy(74,1);
    printf(" | LISTADO DE JUGADORES | ");
    */
    //gotoxy(44,3);
    //printf("---------------------------------------------------------------------------------");
    gotoxy(44,1);
    printf("|Canasto| | Division | |      Apellido      | |      Nombre     | |     DNI     |");
    //gotoxy(44,5);
    //printf("---------------------------------------------------------------------------------");
}

void formularioCargaJugador(){
    gotoxy(46,6);
    printf("===========================================================================");
    gotoxy(46,7);
    printf("| NOMBRE....:                            APELLIDO....:                    |");
    gotoxy(46,8);
    printf("| D.N.I.....:                            N%cCANASTO...:                    |",167);
    gotoxy(46,9);
    printf("===========================================================================");
}

void cartelJugador(int x, int y){
    gotoxy(x,y);
    printf("###############################################");
    y++;
    gotoxy(x,y);
    printf("#      JUGADOR CON LOS SIGUIENTES DATOS      #");
    y++;
    gotoxy(x,y);
    printf("###############################################");
}

void formularioCargarRopa(){
    gotoxy(46,6);
    printf("===========================================================================");
    gotoxy(46,7);
    printf("| PRENDA....:                             CANTIDAD RECIBIDA....:          |");
    gotoxy(46,8);
    printf("| DESCRIPCION.:                                                           |");
    gotoxy(46,9);
    printf("===========================================================================");
}

void visualizarListadoRopaEntr(){
    /*
    gotoxy(74,1);
    printf(" | JUGADORES CON ROPA | ");
    gotoxy(44,3);
    printf("---------------------------------------------------------------------------------");
    */
    gotoxy(44,1);
    printf("|      Jugador     | |Buzo| |Remera| |Short| |Termico| |Medias Largas| |Zoquetes|");
    /*
    gotoxy(44,5);
    printf("---------------------------------------------------------------------------------");
    */
}

void visualizarRopaEnSistem(){
    gotoxy(44,3);
    printf("+-------------------------------------------------------------------------------+");
    gotoxy(44,4);
    printf("| FECHA  |NOMBRE ATUENDO| STOCK |              DESCRIPCION                     |");
    gotoxy(44,5);
    printf("+-------------------------------------------------------------------------------+");
}

void visualizarRopaBaja(){
    gotoxy(44,3);
    printf("+-------------------------------------------------------------------------------+");
    gotoxy(44,4);
    printf("| NOMBRE DE ATUENDO |               ESTADO EN EL QUE SE ENCUENTRA               |");
    gotoxy(44,5);
    printf("+-------------------------------------------------------------------------------+");
}

void visualizarBolso(){
    gotoxy(44,3);
    printf("+-------------------------------------------------------------------------------+");
    gotoxy(44,4);
    printf("|  BOLSO  | REMERA 1 | REMERA 2 |  BUZO  | CAMPERA |  PANTALON LARGO  | BERMUDA |");
    gotoxy(44,5);
    printf("+-------------------------------------------------------------------------------+");
}

void visualizarEntregaBolso(){
    //gotoxy(44,3);
    //printf("+-------------------------------------------------------------------------------+");
    gotoxy(44,1);
    printf("| Division |        Jugador        |  Numero de Bolso  |  ENTREGADO  |");
    //gotoxy(44,5);
    //printf("+-------------------------------------------------------------------------------+");
}

void mostrarDivEleccion(){
    gotoxy(46,9);
    printf("                           ESCRIBA LA OPCION                               ");
    gotoxy(46,10);
    printf("===========================================================================");
    gotoxy(46,11);
    printf("| 4. Para 4ta                            5. Para 5ta                      |");
    gotoxy(46,12);
    printf("| 6. Para 6ta                            7. Para Reserva                  |",167);
    gotoxy(46,13);
    printf("===========================================================================");
}
