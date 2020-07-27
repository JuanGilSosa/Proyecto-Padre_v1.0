#include "divisiones.h"
///GUARDO TODAS LAS FUNCIONES QUE TENGAN EL TIPO DE DATO stDivisiones


void seleccionarOpcion(stDivisiones **ADL){
    char op;
    do{
        borrarTexto(3,27,30); //borra lo que hay en la ventana de ingresar datos
        borrarTexto(3,28,30);
        borrarTexto(3,29,36);
        borrarTexto(3,30,30);
        op = menuJugador(ADL);
        switch (op){
            case 0:
                altaJugador(ADL);
                break;
            case 1:
                consultarJugador(ADL);
                break;
            case 2:
                delPlayer(ADL);
                break;
            case 3:
                listadoJugadores(ADL);
                break;
            case 4:
                modificarDatosJugador(ADL);
                break;
            case 5:
                menuPrincipal(ADL);
                break;
        }
    }while(1);
}


void altaJugador(stDivisiones **ADL){
    int division;
    char op;
    int i;
    stPlayer a;
    do{
        i=0;
        division = eleccionDivision();
        if(division == 0){///4ta
            a = cargarJugador(division);
            i = buscarPosDivision(ADL,a.division);
        }
        if(division == 1){///5ta
            a = cargarJugador(division);
            i = buscarPosDivision(ADL,a.division);
        }
        if(division == 2){///6ta
            a = cargarJugador(division);
            i = buscarPosDivision(ADL,a.division);
        }
        if(division == 3){///RESERVA
            a = cargarJugador(division);
            i = buscarPosDivision(ADL,a.division);
        }
        if(division == 4){//salgo nomas
            seleccionarOpcion(ADL);
        }
        clearscreen_2(10);
        mostrarJugador(a,62,8);
        color(10);
        if(MessageBox(HWND_DESKTOP,"¿Guardar Jugador?","Atencion",MB_ICONQUESTION+MB_YESNO+MB_DEFAULT_DESKTOP_ONLY)==IDYES){//sino sale, preguntamos si quiere cargar los datos
            //(*ADL)[i].listaJugador = agregarFinal((*ADL)[i].listaJugador, crearNodo(a));
            upperstring(a.apellido);
            upperstring(a.nombre_p); //ponemos en mayuscula el nombre y apellido del jugador

            agregarEnLista(ADL,a,i);
            playertofile(a);//si pasa, agregamos en el archivo
            MessageBox(HWND_DESKTOP,"Jugador Cargado!"," ",MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
            /*
            gotoxy(68,16);
            printf("***************************");
            gotoxy(68,17);
            printf("*JUGADOR CARGADO CON EXITO*");
            gotoxy(68,18);
            printf("***************************");
            keyevent(63,20);
            */
        }
        //BORRAMOS TODA LA PANTALLA SECUNDARIA
        borrarTexto(74,1,30);//Cargando Jugador
        clearscreen_2(13);
    }while(1);
}

int buscarPosDivision(stDivisiones **ADL, int div){
    int pos = -1;
    int i;
    while(pos == -1){
        i=0;
        if((*ADL)[i].idDivision == div){//pos 0, estaria 4
            pos = i;
        }
        i+=1;
        if((*ADL)[i].idDivision == div){//pos 1, estaria 5
            pos = i;
        }
        i+=1;
        if((*ADL)[i].idDivision == div){//pos 2 estaria 6
            pos = i;
        }
        i+=1;
        if((*ADL)[i].idDivision == div){// pos 3 estaria Reserva(7)
            pos = i;
        }
    }
    return pos;
}

void fileplayertocelda(stDivisiones **ADL){
    stPlayer a;
    int i = 0;
    FILE *pArchivo = fopen("jugadores.dat","rb");

    if(pArchivo){
        while(fread(&a,sizeof(stPlayer),1,pArchivo)>0){
            if(a.estado==0){
                i = buscarPosDivision(ADL,a.division);
                agregarEnLista(ADL,a,i);
            }
        }
        fclose(pArchivo);
    }
}
                                                //tendria la funcion de buscarPos
void agregarEnLista(stDivisiones **ADL, stPlayer a, int pos){
    (*ADL)[pos].listaJugador = agregarEnOrden((*ADL)[pos].listaJugador, crearNodo(a));
}

void consultarJugador(stDivisiones **ADL){
    char ape[30];
    int i=-1;
    int div=0;
    borrarTexto(3,12,35);
    borrarTexto(3,14,35);
    div = eleccionDivision();
    if(div != 4){
        asignarDivision_string(div,ape);
        gotoxy(3,27);
        printf(" - BUSCAR JUGADOR DE %s",ape);
        resetstring(ape);
        gotoxy(3,29);
        printf("| Ingrese el apellido del jugador");
        fflush(stdin);
        gotoxy(3,30);
        hidecursor(1);
        printf("| - ");
        gets(ape);
        upperstring(ape);
    }
    if(div != 4){
        Nodo *aux = buscarNodo((*ADL)[div].listaJugador,ape);//busca en una posicion determinada
        if(aux){
            visualizarListado();
            mostrarJugadorL(aux->dato,3);
            keyevent(66,11);
            limpiartabla();
            clearscreen_2(1);

            //mostrar un njugador con su determinada indumentaria
        }else{
            gotoxy(75,7);
            printf("***********************");
            gotoxy(75,8);
            printf("*Jugador no encontrado*");
            gotoxy(75,9);
            printf("***********************");
            keyevent(66,11);
            borrarTexto(75,7,25);
            borrarTexto(75,8,25);
            borrarTexto(75,9,25);
        }
    }
    seleccionarOpcion(ADL);

}

void delPlayer(stDivisiones **ADL){
/*
    borrarTexto(3,12,34);
    borrarTexto(3,14,34);
*/
    Nodo *aux;
    char ape[30];
    int d = eleccionDivision();
    int pos;
    char op;
/*
    borrarTexto(3,4,30);
    borrarTexto(3,6,30);
    borrarTexto(3,8,30);
    borrarTexto(3,10,34);
    borrarTexto(3,12,30);
*/
    //si eligio una opcion distina a la de volver
    //entramos a eliminar un jugador, sino mas bien cambiarle el estado a 1(eliminado)
    if(d != 4){
        pos = d;
        asignarDivision_string(pos,ape);
        gotoxy(3,27);
        printf("BORRAR JUGADOR DE %s",ape);
        gotoxy(3,29);
        resetstring(ape);
        printf("| Ingrese el apellido del jugador...: ");
        gotoxy(3,30);
        printf("| - ");
        fflush(stdin);
        gets(ape);
        upperstring(ape);
        aux = buscarNodo((*ADL)[pos].listaJugador,ape);
        //si encuentra un jugador, osea que aux quedaria distinto de NULL
        if(aux){
            visualizarListado();
            /*
            gotoxy(74,1);
            printf("    | BORRAR JUGADOR |   ");
            */
            mostrarJugadorL(aux->dato,3);
            gotoxy(73,12);
            color(10);
            printf("%cDesea dar de baja este jugador?",168);
            gotoxy(79,13);
            printf("[ENTER] SI | [ESC] NO");
            fflush(stdin);
            op = getch();
            if(op == ENTER){
                aux->dato.estado = 1;/*se supone que como tiene una direccion de
                memoria se modifica la posicion en la memoria RAM  - SE MODIFICARIA
                TAMBIEN EN EL VECTOR >ADL< */
                modifyfile(aux->dato);
                gotoxy(73,15);
                color(14);
                printf("Jugador borrado con exito");
                (*ADL)[pos].listaJugador = borrarNodo((*ADL)[pos].listaJugador,ape);
                keyevent(71,17);
                clearscreen_2(0);
            }else if(op == ESC){
                gotoxy(73,15);
                color(14);
                printf("Operacion cancelada con exito!");
                keyevent(71,17);
                clearscreen_2(0);
            }
        }else{
            gotoxy(75,7);
            printf("***********************");
            gotoxy(75,8);
            printf("*Jugador no encontrado*");
            gotoxy(75,9);
            printf("***********************");
            keyevent(66,11);
            borrarTexto(75,7,25);
            borrarTexto(75,8,25);
            borrarTexto(75,9,25);
        }
    }


    limpiartabla();
    borrarTexto(3,27,35);//ingrese el apellido del jugador
    borrarTexto(73,12,31);
    borrarTexto(79,13,30);
    borrarTexto(73,15,30);
    borrarTexto(75,16,30);
}


void listadoJugadores(stDivisiones **ADL){

    int pos = eleccionDivision();
    if(pos != 4){
        if((*ADL)[pos].listaJugador){
            visualizarListado();
            mostrarLista((*ADL)[pos].listaJugador,0,3);
            getch();
        }else {
            visualizarListado();
            gotoxy(46,3);
            printf("----");
            gotoxy(57,3);
            printf("----");
            gotoxy(74,3);
            printf("----");
            gotoxy(96,3);
            printf("----");
            gotoxy(115,3);
            printf("----");
            getch();
        }
        hidecursor(0);
        limpiartabla();
        clearscreen_2(contarNodos((*ADL)[pos].listaJugador));
    }
}

void modificarDatosJugador(stDivisiones **ADL){
    int posD = eleccionDivision();
    char ape[40];
    int idR = 4;
    if(posD!=4){
        while(idR == IDRETRY){
            char op;
            gotoxy(3,27);
            resetstring(ape);
            asignarDivision_string(posD,ape);
            printf("MODIFCAR JUGADOR DE %s",ape);//utilizamos el string {ape} siendo que despues lo resetamos para otro uso
            gotoxy(3,29);
            printf("| Ingrese el apellido del jugador: ");
            resetstring(ape);
            gotoxy(3,30);
            printf("| - ");
            hidecursor(1);
            fflush(stdin);
            gets(ape);
            upperstring(ape);
            Nodo *aux;
            aux = buscarNodo((*ADL)[posD].listaJugador,ape);

            borrarTexto(3,27,35);
            borrarTexto(3,29,35);
            borrarTexto(3,30,20);

            if(aux){
                visualizarListado();
                mostrarJugadorL(aux->dato,3);
                /*color(14);
                gotoxy(68,9);
                printf("%cDesea modificar los datos de %s?",168,aux->dato.nombre_p);
                gotoxy(76,10);
                printf("[ENTER] SI | [ESC] NO");
                fflush(stdin);
                op = getch();
                borrarTexto(68,9,50);
                borrarTexto(76,10,25);*/
                if(MessageBox(HWND_DESKTOP,"¿Modificar datos del jugador?"," ",MB_ICONQUESTION+MB_YESNO+MB_DEFAULT_DESKTOP_ONLY)==IDYES){
                    char campos[][50] = {
                        "[1] - NOMBRE",
                        "[2] - APELLIDO",
                        "[3] - D.N.I",
                        "[4] - DIVISION ",
                        "[5] - N.CANASTO",
                        "[6] - VOLVER"
                    };
                    int posCamp;
                    while(posCamp!=5){
                        posCamp = movearrowsUPDOWN(campos,6); //obtengo la posicion de la matriz
                        modificarCampos(ADL,posCamp,posD,aux);
                        idR = IDCANCEL;
                    }
                }else{
                    gotoxy(73,12);
                    printf("Operacion Cancelada con exito!");
                    hidecursor(1);
                    getch();
                    idR = IDCANCEL;
                    borrarTexto(73,12,32);
                }
            }else{
                idR = MessageBox(NULL,"Jugador no Encontrado","Atencion",MB_RETRYCANCEL+MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
            }
        }
    }
    limpiartabla();
    clearscreen_2(1);
}

void modificarCampos(stDivisiones **ADL, int posCamp, int posDiv,Nodo *aux){
    if(posCamp == 0){ // Modifica Nombre
        char n[40];
        hidecursor(1);
        borrarTexto(89,3,18);
        gotoxy(92,3);
        fflush(stdin);
        gets(n);
        upperstring(n);
       // aux = buscarNodo((*ADL)[posDiv].listaJugador,ape);
        if(MessageBox(NULL,"¿Desea guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
            strcpy(aux->dato.nombre_p,n); // se supone que esto andaria, porque estoy modificando una direccion de memoria
            modifyfile(aux->dato);
        }
        //clearscreen_2(1);
    }
    if(posCamp == 1){ // Modifica Apellido
        char ap[40];
        borrarTexto(68,3,19);
        hidecursor(1);
        gotoxy(68,3);
        fflush(stdin);
        gets(ap);
        upperstring(ap);
       // aux = buscarNodo((*ADL)[posDiv].listaJugador,ape);
        if(MessageBox(NULL,"¿Desea guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
            strcpy(aux->dato.apellido,ap);
            modifyfile(aux->dato);
        }
        //clearscreen_2(1);
    }
    if(posCamp == 2){  //Modifica El DNI
        long int dni = 0;
        borrarTexto(113,3,10);
        gotoxy(113,3);
        fflush(stdin);
        scanf("%ld",&dni);
        //aux = buscarNodo((*ADL)[posDiv].listaJugador,ape);
        if(MessageBox(NULL,"¿Desea guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
            aux->dato.DNI = dni;
            modifyfile(aux->dato);
        }
        //clearscreen_2(1);
    }
    if(posCamp == 3){ //Modifica la division, cambiar a un jugador de division y que se cargue en la posicion correcta en el arreglo
        mostrarDivEleccion();
        char div[10];
        int d = 0;
        borrarTexto(56,3,5);
        hidecursor(1);
        fflush(stdin);
        scanf("%d",&d);
        asignarDivision_string(returnPosDivision(d),div);
        gotoxy(56,3);
        puts(div);
       // aux = buscarNodo((*ADL)[posDiv].listaJugador,ape);
        if(d == 4 || d == 5 || d == 6 || d == 7){
            if(MessageBox(NULL,"¿Desea guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){//si cambia la division, borro el nodo en la posicion del jugador,y dsp lo agrego en la nueva posicion del arreglo
                aux->dato.division = d;
                agregarEnLista(ADL,aux->dato,returnPosDivision(d));
                modifyfile(aux->dato);
                (*ADL)[posDiv].listaJugador = borrarNodo((*ADL)[posDiv].listaJugador,aux->dato.apellido);
            }
        }
        //clearscreen_2(8);
    }
    if(posCamp == 4){ //Modifica el Numero de canasto
        int nC = 0;
        borrarTexto(45,3,5);
        gotoxy(46,3);
        fflush(stdin);
        scanf("%d",&nC);
        //aux = buscarNodo((*ADL)[posDiv].listaJugador,ape);
        if(MessageBox(NULL,"¿Desea guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
            aux->dato.numeroCanasto = nC;
            modifyfile(aux->dato);
        }
        //clearscreen_2(1);
    }
    if(posCamp == 5){ // Vuelve
        //borrarTexto(74,1,27); //el | LISTADO DE JUGADORES |
        limpiartabla();
        clearscreen_2(1);
        //menuJugador(ADL);
    }

}
/*
    mandas la posicion del arreglo, y verificando que posicion tiene es lo que retorna
    como division

*/
int returnPosDivision(int div){
    int pos = -1;

    if(div == 4){
        pos = 0;
    }
    if(div == 5){
        pos = 1;
    }
    if(div == 6){
        pos = 2;
    }
    if(div == 7){
        pos = 3;
    }
    return pos;
}
