#include "ropa.h"

void seleccionarOpcionR(stDivisiones **ADL){
    char i;

    do{
        i = menuIndumentaria();
        switch(i){
            case 0:
                ingresarRopaNueva();
                break;
            case 1:
                verRopaSistemaJugador(ADL,eleccionVerRopa());
                break;
            case 2:
                darRopa(ADL);
                break;
            case 3:
                sacarRopa(ADL);
                break;
            case 4:
                eliminarRopaIngresada();
                //bajarRopa();
                break;
            case 5:
                restaurarRopaBajada();
                break;
            case 6:
                menuPrincipal(ADL);
                break;
        }
    }while(1);
}

void ingresarRopaNueva(){
    ropaNueva a;
    int tipo = -1;
    tipo = tipoRopa();
    if(tipo==4){
        menuIndumentaria();
    }else{
        a.codigo = ultimoCodigo();
        a.codigo+=1;

        a.tipo = tipo;
        hidecursor(1);
        mostrarTipoRopa(71,4,a.tipo);

        formularioCargarRopa();

        color(14);
        gotoxy(60,7);
        fflush(stdin);
        gets(a.nombreRopa);

        gotoxy(111,7);
        fflush(stdin);
        scanf("%d",&a.cant);
        a.stock = a.cant;

        gotoxy(62,8);
        fflush(stdin);
        gets(a.descripcion);

        getFecha(a.fecha);

        upperstring(a.nombreRopa); //ponemos en mayuscula el nombre y la descripcion
        upperstring(a.descripcion);

        if(confirmarCredencial(66,10) == 1){
            guardarRopaNueva(a);
            gotoxy(72,13);
            color(15);
            printf("Guardado con exito!");
        }else{
            gotoxy(72,13);
            color(15);
            printf("Cancelado con exito!");
        }
        keyevent(65,14);
    }
    clearscreen_2(8);
}

void mostrarTipoRopa(int x, int y, int tipo){
    if(tipo == 0){
        gotoxy(x,y);
        printf("| ROPA DE VIAJE |");
    }
    if(tipo == 1){
        gotoxy(x,y);
        printf("| ROPA DE ENTRENAMIENTO |");
    }
    if(tipo == 2){
        gotoxy(x,y);
        printf("| ROPA DE JUEGO |");
    }
}

void guardarRopaNueva(ropaNueva a){
    FILE *pArchivo = fopen("ropaNueva.dat","ab");

    if(pArchivo){
        fwrite(&a,sizeof(ropaNueva),1,pArchivo);
        fclose(pArchivo);
    }
}

void mostrarJugadoresConRopaEntr(stDivisiones **ADL){
    int pos;
    while(1 && pos != 4){
        pos = eleccionDivision();
        if(pos != 4){
            Nodo *seg = (*ADL)[pos].listaJugador;
            int y=3;
        //si esto, es porque no hay jugadores en esa pocision del arreglo de lista
            if(seg==NULL){
                visualizarListadoRopaEntr();
                gotoxy(52,6);
                printf("----");
                gotoxy(66,6);
                printf("----");
                gotoxy(74,6);
                printf("----");
                gotoxy(82,6);
                printf("----");
                gotoxy(91,6);
                printf("----");
                gotoxy(104,6);
                printf("----");
                gotoxy(117,6);
                printf("----");
            }
            while(seg!=NULL){
                mostrarUnJugadorConRopaEntr(seg->dato.entr,seg->dato.apellido,y);
                y+=1;
                seg = seg->sig;
            }

            keyevent(62,30);
            limpiartabla();
            clearscreen_2(contarNodos((*ADL)[pos].listaJugador));
        }
        if(pos == 4){
            borrarTexto(3,12,25);
            verRopaSistemaJugador(ADL,0);
        }
    }
}

void mostrarJugadoresConRopaViaje(stDivisiones **ADL){
    int y = 3;
    int pos;
    while(1 && pos != 4){
        pos = eleccionDivision();
        if(pos != 4){
            Nodo *seg = (*ADL)[pos].listaJugador;
            while(seg!=NULL){
                //tiene que motrar otra cosa
                y+=1;
                seg = seg->sig;
            }
            keyevent(62,30);
            borrarTexto(74,1,30);
            clearscreen_2(contarNodos((*ADL)[pos].listaJugador)+3);
        }
        if(pos == 4){
            verRopaSistemaJugador(ADL,eleccionVerRopa());
        }
    }
}

void mostrarRopa(stDivisiones **ADL){
    int tipo;
    int cantTipo=0;
    int y = 6;
    while(1 && tipo != 4){
        tipo = tipoRopa();
        y=6;
        if(tipo != 4){
            visualizarRopaEnSistem();
            FILE *pArchivo = fopen("ropaNueva.dat","rb");
            ropaNueva a;
            if(pArchivo){
                while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
                    if(a.tipo == tipo){
                        cantTipo+=1;
                        mostrarConjuntoRopa(a,y);
                        y+=1;
                    }
                }
                fclose(pArchivo);
            }else{
                gotoxy(46,y);
                printf("---");
                gotoxy(58,y);
                printf("---");
                gotoxy(71,y);
                printf("---");
                gotoxy(95,y);
                printf("---");
            }
            keyevent(67,35);
            clearscreen_2(cantTipo);
        }
        if(tipo == 4){
            tipo = eleccionVerRopa();
            if(tipo == 3){
                seleccionarOpcionR(ADL);
            }else{
                verRopaSistemaJugador(ADL,tipo);
            }
        }
    }
}

void mostrarConjuntoRopa(ropaNueva a,int y){
    gotoxy(44,y);
    printf("|%s",a.fecha);
    gotoxy(53,y);
    printf("|%s",a.nombreRopa);
    gotoxy(68,y);
    printf("|%d/%d",a.stock,a.cant);
    gotoxy(76,y);
    printf("|%s",a.descripcion);
}


void verRopaSistemaJugador(stDivisiones **ADL,int view){
    int op = -1;
    if(view == 0){
        op = menuFormaVerRopa();
        if(op == 0){
            op = menuVerRopaEV();
            consultaVerRopa(ADL,op);
        }
        if(op == 1){
            op = -1;
            //le cambio el funcionamiento a la variable op para esa funcion menuVerRopaEV()
            op = menuVerRopaEV();
            if(op == 0){
                mostrarJugadoresConRopaEntr(ADL);
            }
            if(op == 1){
                mostrarEntregaBolso(ADL);
                //mostrarJugadoresConRopaViaje(ADL);
                //mostrar la ropa de viaje
                //tiene que ser una forma de mostrar la ropa de Entrenamiento y la de los bolsos
            }
            if(op == 2){
                verRopaSistemaJugador(ADL,0);
            }
        }
        if(op == 2){
            verRopaSistemaJugador(ADL,eleccionVerRopa());
        }
    }
    if(view == 1){
        mostrarRopa(ADL);
    }
    if(view == 2){
        mostrarRopaEliminada(ADL);
    }
    if(view == 3){
        seleccionarOpcionR(ADL);
    }
}

void bajarRopa(){
    FILE *pArchivo = fopen("ropaNueva.dat","rb");
    FILE *pArchivo_ = fopen("ropaBajada.dat","ab");
    ropaNueva a;

    hidecursor(1);
    int tipo = tipoRopa();
    char op;
    char ropA[30];
    if(tipo != 4){
        gotoxy(3,29);
        printf("Ingrese el nombre del atuendo..: ");
        fflush(stdin);
        gotoxy(3,30);
        printf("|->");
        gets(ropA);
        if(pArchivo_){
            if(pArchivo){
                while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
                    if((a.tipo == tipo) && (strcmp(a.nombreRopa,ropA)==0)){
                        gotoxy(60,4);
                        printf("Dar de baja?");
                        gotoxy(60,5);
                        printf("[ENTER]SI - [ESC]NO");
                        mostrarConjuntoRopa(a,7);
                        op = getch();
                        if(op==ENTER){
                            resetstring(ropA);
                            gotoxy(60,10);
                            a.stock = 1;
                            printf("Escribe el motivo..: ");
                            fflush(stdin);
                            gets(ropA);
                            strcpy(a.descripcion,ropA);
                            fwrite(&a,sizeof(ropaNueva),1,pArchivo_);
                        }
                    }
                }
                fclose(pArchivo);
            }
            fclose(pArchivo_);
            clearscreen_2(5);
        }
    }
}

void mostrarTodaLaRopa(){
    visualizarRopaEnSistem();
    int y=6;
    FILE *pArchivo = fopen("ropaNueva.dat","rb");
    ropaNueva a;
    if(pArchivo){
        while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
            mostrarConjuntoRopa(a,y);
            y+=1;
        }
        fclose(pArchivo);
    }
}


int contarRegistrosRopa(char nArch[]){
    int cont=0;
    FILE *pArchivo = fopen(nArch,"rb");
    ropaNueva a;
    if(pArchivo){
        while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
            cont+=1;
        }
        fclose(pArchivo);
    }
    return cont;
}

void mostrarRopaEliminada(stDivisiones **ADL){
        visualizarRopaBaja();
        int r = contarRegistrosRopa("ropaBajada.dat");
        int y = 6;
        FILE *pArchivo = fopen ("ropaBajada.dat","rb");
        ropaNueva a;

        if(pArchivo){
            while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
                mostrarNombreDescrRopa(a,y);
                y+=1;
            }
            fclose(pArchivo);
        }else if(r<=0){
                gotoxy(48,6);
                printf("- VACIO -");
                gotoxy(84,6);
                printf("- VACIO -");
        }
    getch();
    clearscreen_2(r);
    verRopaSistemaJugador(ADL,eleccionVerRopa());
}

void mostrarNombreDescrRopa(ropaNueva a, int y){
    gotoxy(44,y);
    printf("| %s",a.nombreRopa);
    gotoxy(64,y);
    printf("| %s",a.descripcion);
}


int ultimoCodigo(){
    int i=0;
    FILE *pArchivo = fopen("ropaNueva.dat","rb");
    ropaNueva a;
    if(pArchivo){
        fseek(pArchivo,sizeof(ropaNueva)*-1,SEEK_END);
        if(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
            i = a.codigo;
        }
    }
    return i;
}


/*
void sacarRopaEliminada(int tipo){
    FILE *pArchivo = fopen("ropaBajada.dat","rb");
    FILE *pArchivo_ = fopen("backup.dat","wb");

    ropaNueva a;
    if(pArchivo){
        if(pArchivo_){
            while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){

            }
        }
    }
}
*/

void darRopa(stDivisiones **ADL){
    int op = 0;
    while(op!=3){
        op = menuDarRopa();
        if(op == 0){
            darRopaEntr(ADL);
        }
        if(op == 1){
            darBolsoViaje(ADL);
        }
    }
}

void darRopaEntr(stDivisiones **ADL){
    ropaE r;
    int asign = -1;
    int pos = eleccionDivision();
    char ape[30];
    Nodo *aux;
    int idR = 4;
    int idRemera = 4;
    if(pos != 4){
        while(idR == IDRETRY){
            gotoxy(3,27);
            printf("Ingrese el apellido del jugador");
            fflush(stdin);
            gotoxy(3,28);
            hidecursor(1);
            printf("|- ");
            gets(ape);
            upperstring(ape);
            aux = buscarNodo((*ADL)[pos].listaJugador,ape);
            clearscreen_3(2);
            if(aux){
                mostrarUnJugadorConRopaEntr(aux->dato.entr,ape,3);
                while(asign != 6){
                    gotoxy(5,1);
                    printf("PRESIONE [ENTER] PARA ASIGNARLE ROPA");
                    asign = asignarRopaEntrenamiento();
                    //eso significa que presiono ENTER y no quiere salir
                    while(idRemera == IDRETRY && asign == 0){
                        hidecursor(1);
                        gotoxy(60,15);
                        printf("----------------------------------------");
                        gotoxy(60,16);
                        printf("|Ingrese el numero de la remera.:      |");
                        gotoxy(60,17);
                        printf("----------------------------------------");
                        gotoxy(94,16);
                        fflush(stdin);
                        scanf("%d",&r.remera);
                        //esto borra el "Ingrese el numero de la remera.:" con todo su respectivo marco
                        borrarTexto(60,15,45);
                        borrarTexto(60,16,45);
                        borrarTexto(60,17,45);
                        if(r.remera != aux->dato.entr.remera){
                            if(MessageBox(NULL,"¿Guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                                idRemera = -1;
                                borrarTexto(72,3,3);
                                aux->dato.entr.remera = r.remera;
                                gotoxy(72,3);
                                printf("|%d",aux->dato.entr.remera);
                            }
                        }else if(r.remera == aux->dato.entr.remera){
                            idRemera = MessageBox(NULL,"Ya tiene ese numero","Atencion",MB_RETRYCANCEL+MB_DEFAULT_DESKTOP_ONLY);
                            borrarTexto(94,16,3);
                        }
                    }
                    /**
                        Todo esto verifica lo elejido antes y si tiene cero (0), porque si tiene 1, no le da la opcion
                        de cambiar lo mismo a 1. Por si se genera un error en memoria
                    */
                    if(asign == 1 && aux->dato.entr.shor == 0){
                        if(MessageBox(NULL,"¿Guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            r.shor = setAnyRopaE();
                            aux->dato.entr.shor = r.shor;
                            gotoxy(81,3);
                            printf("|%s",verRopa(aux->dato.entr.shor));
                        }
                    }
                    if(asign == 2 && aux->dato.entr.buzo == 0){
                        if(MessageBox(NULL,"¿Guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            r.buzo = setAnyRopaE();
                            aux->dato.entr.buzo = r.buzo;
                            gotoxy(65,3);
                            printf("|%s",verRopa(aux->dato.entr.shor));
                        }
                    }
                    if(asign == 3 && aux->dato.entr.termico == 0){
                        if(MessageBox(NULL,"¿Guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            r.termico = setAnyRopaE();
                            aux->dato.entr.termico = r.termico;
                            gotoxy(89,3);
                            printf("|%s",verRopa(aux->dato.entr.termico));
                        }
                    }
                    if(asign == 4 && aux->dato.entr.mediasLargas == 0){
                        if(MessageBox(NULL,"¿Guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            r.mediasLargas = setAnyRopaE();
                            aux->dato.entr.mediasLargas = r.mediasLargas;
                            gotoxy(99,3);
                            printf("|%s",verRopa(aux->dato.entr.mediasLargas));
                        }
                    }
                    if(asign == 5 && aux->dato.entr.zoquetes == 0){
                        if(MessageBox(NULL,"¿Guardar datos?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            r.zoquetes = setAnyRopaE();
                            aux->dato.entr.zoquetes = r.zoquetes;
                            gotoxy(115,3);
                            printf("|%s",verRopa(aux->dato.entr.zoquetes));
                        }
                    }
                    //entonces si quiere volver cambiamos idR para que corte con el while
                    if(asign == 6){
                        idR = -1;
                    }
                    modifyfile(aux->dato);
                }
            }else{
                if(aux==NULL){
                    idR = MessageBox(HWND_DESKTOP,"Jugador no encontrado","Atencion",MB_RETRYCANCEL+MB_ICONEXCLAMATION+MB_DEFAULT_DESKTOP_ONLY);
                }
            }
        }
        clearscreen_2(4);
        //borrarTexto(75,1,30);
        limpiartabla();
        borrarTexto(3,1,37);

    }
}

void darBolsoViaje(stDivisiones **ADL){
    int idR = 4;
    Bolso bolso;
    Nodo *aux;
    char ape[30];
    int pos = eleccionDivision(),asign=0;
    if(pos != 4){
        while(idR == IDRETRY){
            gotoxy(3,27);
            hidecursor(1);
            printf("Ingrese el apellido del jugador.: ");
            gotoxy(3,28);
            printf("|- ");
            fflush(stdin);
            gets(ape);
            upperstring(ape);
            aux = buscarNodo((*ADL)[pos].listaJugador,ape);
            clearscreen_3(2);
            //si hay nodo aux es prque encontro el jugador
            if((aux!=NULL) && (aux->dato.ropV.entregado == 0)){
                visualizarListado();
                mostrarJugadorL(aux->dato,3);
                if(idR=MessageBox(HWND_DESKTOP,"¿Entregar Bolso?","ATENCION",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                    asign = 0;
                    gotoxy(60,15);
                    printf("----------------------------------------");
                    gotoxy(60,16);
                    printf("|Ingrese el numero del Bolso.:         |");
                    gotoxy(60,17);
                    printf("----------------------------------------");
                    gotoxy(91,16);
                    fflush(stdin);
                    scanf("%d",&asign);
                    aux->dato.ropV.entregado = 1; //entregamos el bolso
                    aux->dato.ropV.bolso.ID_BOLSO = asign;
                    modifyfile(aux->dato);
                    clearscreen_2(1);
                    borrarTexto(60,15,45);
                    borrarTexto(60,16,45);
                    borrarTexto(60,17,45);
                }
            }else if(aux!=NULL && aux->dato.ropV.entregado == 1){
                MessageBox(HWND_DESKTOP,"Bolso ya Entregado","ATENCION",MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
                idR = -1;
            }else if(aux == NULL){
                idR = MessageBox(HWND_DESKTOP,"Jugador no Encontrado","ATENCION",MB_RETRYCANCEL+MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
            }
            clearscreen_3(3);
        }
    }
    clearscreen_2(1);
}

//es un listado con la entrega de bolso de una division en particular elejida
void mostrarEntregaBolso(stDivisiones **ADL){
    int y;
    int posDiv = -1;
    char pDiv[10];
    while(posDiv!=4){
        y=3;
        posDiv = eleccionDivision();
        if(posDiv != 4){
            asignarDivision_string(posDiv,pDiv);
            visualizarEntregaBolso();
            Nodo *listaPos = (*ADL)[posDiv].listaJugador;
            while(listaPos != NULL){
                mostrarUnaEntregaBolso(listaPos,pDiv,y);
                y+=1;
                listaPos = listaPos -> sig;
            }
            keyevent(67,35);
            limpiartabla();
            clearscreen_2(contarNodos((*ADL)[posDiv].listaJugador));
        }
    }
    if(posDiv == 4){
        borrarTexto(3,12,25);
        verRopaSistemaJugador(ADL,0);
    }
}

void mostrarUnaEntregaBolso(Nodo *a,char div[],int y){
    gotoxy(44,y);//division
    printf("|%s",div);
    gotoxy(55,y);//jugador
    printf("|%s",a->dato.apellido);
    gotoxy(79,y);//numero de bolso
    printf("|%d",a->dato.ropV.bolso.ID_BOLSO);
    gotoxy(99,y);//entregado
    printf("|%s",verRopa(a->dato.ropV.entregado));
}

//puede sacar ropa de entrenamiento o un bolso, o ropa del mismo bolso
void sacarRopa(stDivisiones **ADL){
    int op = -1;;
    int op2;
    while(op != 2){
        op = menuSacarRopa();
        if(op == 0){
            sacarRopaEntr(ADL);
        }
        while(op == 1){
            op2 = menuSacarBolso();
            if(op2 == 0){
                sacarBolso(ADL);
            }
            if(op2 == 1){
                sacarTodosBolso(ADL);
            }
            if(op2 == 2){
                op = -1;//esto lo hago para que rompa con el while(op==1){}
            }
        }
    }
}
void sacarTodosBolso(stDivisiones **ADL){
    if(MessageBox(NULL,"¿Sacar a todos el bolso?"," ",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
        for(int i = 0;i<4;i++){
            (*ADL)[i].listaJugador = sacarBolsoLista((*ADL)[i].listaJugador);
        }
        MessageBox(NULL,"Bolsos sacados correctamente!"," ",MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
    }
}
void sacarBolso(stDivisiones **ADL){
    int idR = 4;
    Nodo *aux;
    int pos = eleccionDivision();
    char posDiv[10];
    asignarDivision_string(pos,posDiv);
    char ape[30];
    if(pos != 4){
        while(idR == IDRETRY){
            hidecursor(1);
            gotoxy(3,27);
            printf("Ingrese el apellido del jugador");
            gotoxy(3,28);
            printf("|- ");
            fflush(stdin);
            gets(ape);
            upperstring(ape);
            aux = buscarNodo((*ADL)[pos].listaJugador,ape);
            clearscreen_3(2);
            if(aux){
                if(aux->dato.ropV.entregado == 1){
                    visualizarEntregaBolso();
                    mostrarUnaEntregaBolso(aux,posDiv,6);//como muestro a un jugador nomas, pongo como 3er parametro el 6
                    if(MessageBox(NULL,"¿Sacar Bolso?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                        idR = 2;
                        aux->dato.ropV.entregado = 0;
                        aux->dato.ropV.bolso.ID_BOLSO = 0;
                        modifyfile(aux->dato);
                    }else{
                        idR = 2;
                    }
                }else if(aux->dato.ropV.entregado == 0){
                    idR = MessageBox(NULL,"Este jugador no tiene bolso","Atencion",MB_RETRYCANCEL+MB_ICONASTERISK+MB_DEFAULT_DESKTOP_ONLY);
                }
            }else if(aux==NULL){
                idR = MessageBox(NULL,"Jugador no Encontrado","Atencion",MB_RETRYCANCEL+MB_ICONWARNING+MB_DEFAULT_DESKTOP_ONLY);
            }
            clearscreen_2(4);
        }
        if(idR == 2){
            sacarRopa(ADL);
        }
    }
    /*if(pos == 4){
        sacarRopa(ADL);
    }*/
}

void sacarRopaEntr(stDivisiones **ADL){
    int opAsign;
    int idR = 4;
    Nodo *aux;
    char ape[30];
    int pos = eleccionDivision();
    if(pos != 4){
        while(idR == IDRETRY){
            hidecursor(1);
            gotoxy(3,27);
            printf("Ingrese el apellido del jugador");
            gotoxy(3,28);
            printf("|- ");
            fflush(stdin);
            gets(ape);
            upperstring(ape);
            aux = buscarNodo((*ADL)[pos].listaJugador,ape);
            clearscreen_3(2);
            if(aux){
                mostrarUnJugadorConRopaEntr(aux->dato.entr,ape,3);
                while(opAsign != 6){
                    gotoxy(5,1);
                    printf("PRESIONE [ENTER] PARA SACAR ROPA");
                    opAsign = asignarRopaEntrenamiento();
                    //borrarTexto(5,1,37);
                    if(opAsign == 0){
                        if(MessageBox(NULL,"¿Sacar Remera?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            aux->dato.entr.remera = 0;
                            borrarTexto(72,3,3);
                            printf("|%s",verRopa(aux->dato.entr.remera));
                        }
                    }
                    if(opAsign == 1 && aux->dato.entr.shor == 1){
                        if(MessageBox(NULL,"¿Sacar Short?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            aux->dato.entr.shor = 0;
                            gotoxy(81,3);
                            printf("|%s",verRopa(aux->dato.entr.shor));
                        }
                    }
                    if(opAsign == 2 && aux->dato.entr.buzo){
                        if(MessageBox(NULL,"¿Sacar Buzo?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            aux->dato.entr.buzo = 0;
                            gotoxy(65,3);
                            printf("|%s",verRopa(aux->dato.entr.buzo));
                        }
                    }
                    if(opAsign == 3 && aux->dato.entr.termico == 1){
                        if(MessageBox(NULL,"¿Sacar Termico?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            aux->dato.entr.termico = 0;
                            gotoxy(89,3);
                            printf("|%s",verRopa(aux->dato.entr.termico));
                        }
                    }
                    if(opAsign == 4 && aux->dato.entr.mediasLargas == 1){
                        if(MessageBox(NULL,"¿Sacar Medias Largas?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            aux->dato.entr.mediasLargas = 0;
                            gotoxy(99,3);
                            printf("|%s",verRopa(aux->dato.entr.mediasLargas));
                        }
                    }
                    if(opAsign == 5 && aux->dato.entr.zoquetes == 1){
                        if(MessageBox(NULL,"¿Sacar Zoquetes?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            aux->dato.entr.zoquetes = 0;
                            gotoxy(115,3);
                            printf("|%s",verRopa(aux->dato.entr.zoquetes));
                        }
                    }
                    if(opAsign == 6){
                        idR = -1;
                    }
                    modifyfile(aux->dato);
                }
            }else if(aux == NULL){
                idR = MessageBox(HWND_DESKTOP,"Jugador no Encontrado","Atencion",MB_RETRYCANCEL+MB_ICONEXCLAMATION+MB_DEFAULT_DESKTOP_ONLY);
            }
        }
    }
    //borrarTexto(75,1,23);
    limpiartabla();
    clearscreen_2(1);
    if(opAsign == 6 || idR == 2){
        sacarRopa(ADL);
    }
}

void eliminarRopaIngresada(){
    char mot[100];
    int flag = 0;
    int cant = contarRegistrosRopa("ropaNueva.dat");
    char menuR[cant][50];
    int i=0;
    if(cant!=0){
    //mostrar toda la ropa cargada y apartir de ahi y usar menu
        mostrarTodaLaRopa();
        FILE *pArchivo = fopen("ropaNueva.dat","rb");
        ropaNueva a;
        if(pArchivo){
            while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
                strcpy(menuR[i],a.nombreRopa);
                i+=1;
            }
            fclose(pArchivo);
        }
        i=-1;//reseteamos i para usarlo a lahora de leer en el archivo
        i = movearrowsUPDOWNROPA(menuR,cant);
        int lim=0;
        pArchivo = NULL;
        pArchivo = fopen("ropaNueva.dat","rb");
        if(pArchivo){
            while((flag==0) && (fread(&a,sizeof(ropaNueva),1,pArchivo)>0)){
                if(i == lim){ // esto esta para encontrar el dato en el archivo ropaNueva.dat
                    FILE *pArchivo_ = fopen("ropaBajada.dat","ab");
                    if(pArchivo_){
                        hidecursor(1);
                        gotoxy(50,cant+7);
                        printf("|Ingrese el motivo..: ");
                        fflush(stdin);
                        gets(mot);
                        a.stock--;
                        modifyfile_r(a); // lo hago antes de strcpy para que no me modifique la descripcion

                        strcpy(a.descripcion,mot);

                        fwrite(&a,sizeof(ropaNueva),1,pArchivo_);

                        fclose(pArchivo_);
                    }
                    flag=1;
                }
                lim+=1;
            }
            fclose(pArchivo);
            clearscreen_2(cant+2);
        }
    }
}


void consultaVerRopa(stDivisiones **ADL,int forma){
    int i=0;
    char posDiv[10];
    int retrycancel=4;
    while(forma != 2){
        int pos = eleccionDivision();
        asignarDivision_string(pos,posDiv);
        char ape[30];
        Nodo *aux;
        if(pos!=4){
            while(retrycancel == IDRETRY){
                hidecursor(1);
                gotoxy(3,27);
                printf("Ingrese el apellido del jugador");
                gotoxy(3,28);
                printf("|- ");
                fflush(stdin);
                gets(ape);
                upperstring(ape);
                aux = buscarNodo((*ADL)[pos].listaJugador,ape);
                clearscreen_3(2);
                if(aux){
                    if(forma == 0){
                        mostrarUnJugadorConRopaEntr(aux->dato.entr,ape,3);
                        keyevent(62,30);
                        clearscreen_2(1);
                        limpiartabla();
                        retrycancel = IDCANCEL;
                    }
                    if(forma == 1){
                        visualizarEntregaBolso();
                        mostrarUnaEntregaBolso(aux,posDiv,3);
                        keyevent(62,30);
                        clearscreen_2(1);
                        limpiartabla();
                        retrycancel = IDCANCEL;
                    }
                }else{
                    retrycancel = MessageBox(NULL,"Jugador no Encontrado","Atencion",MB_ICONASTERISK+MB_RETRYCANCEL+MB_DEFAULT_DESKTOP_ONLY);
                }
            }
        }
        if(pos == 4 || retrycancel == IDCANCEL){
            //MessageBox(HWND_DESKTOP,"SALI a POS==4 y retrycancel==IDCANCEL","",MB_ICONASTERISK);
            borrarTexto(3,12,20);
            retrycancel = IDRETRY;
            forma = menuVerRopaEV();
        }
    }
    if(forma == 2){
        verRopaSistemaJugador(ADL,0);
    }
}

void modifyfile_r(ropaNueva a){
    FILE *pArchivo = fopen("ropaNueva.dat","r+b");
    ropaNueva aux;
    int flag = 0;
    if(pArchivo){
        rewind(pArchivo);
        while(flag == 0 && fread(&aux,sizeof(ropaNueva),1,pArchivo)>0){
            if(aux.codigo == a.codigo){
                fseek(pArchivo,sizeof(ropaNueva)*(-1),SEEK_CUR);
                fwrite(&a,sizeof(ropaNueva),1,pArchivo);
                flag = 1;
            }
        }
        fclose(pArchivo);
    }
}

void restaurarRopaBajada(stDivisiones **ADL){
    int flag = 0;
    int cant = contarRegistrosRopa("ropaBajada.dat");
    char menuR[cant][50];
    int i=0;
    if(cant!=0){
    //mostrar toda la ropa cargada y apartir de ahi y usar menu
        mostrarRopaEliminada(ADL);
        FILE *pArchivo = fopen("ropaBajada.dat","rb");
        ropaNueva a;
        if(pArchivo){
            while(fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
                strcpy(menuR[i],a.nombreRopa);
                i+=1;
            }
            fclose(pArchivo);
        }
        i=-1;//reseteamos i para usarlo a lahora de leer en el archivo
        i = movearrowsUPDOWNROPA(menuR,cant);
        int lim = 0;
        pArchivo = fopen("ropaBajada.dat","rb");
        if(pArchivo){
            while((flag==0)&&fread(&a,sizeof(ropaNueva),1,pArchivo)>0){
                if(i == lim){
                    FILE *pArchivo_ = fopen("ropaNueva.dat","ab");
                    if(pArchivo_){
                        if(MessageBox(HWND_DESKTOP,"¿Restaurar Atuendo?","Atencion",MB_YESNO+MB_ICONQUESTION+MB_DEFAULT_DESKTOP_ONLY) == IDYES){
                            a.stock++; /*hago esto porque lo que se pone de stock en el archivo ropaBajada es la misma
                            estructura de datos que hay en el archivo ropaNueva*/
                            modifyfile_r(a);
                            eliminarFile(a,"ropaBajada.dat");
                        }
                    }
                }
            }
        }
    }
}

void eliminarFile(ropaNueva a,char nArch[]){
    int flag=0;
    ropaNueva aux;
    FILE *pArchivo = fopen(nArch,"r+b");
    FILE *pArchivo_ = fopen("backupRopa.dat","w+b");
    if(pArchivo){
        if(pArchivo_){
            while(fread(&aux,sizeof(ropaNueva),1,pArchivo)>0){
                if(a.codigo != aux.codigo){
                    fwrite(&aux,sizeof(ropaNueva),1,pArchivo_);
                }
            }
            rewind(pArchivo_);
            fclose(pArchivo);
            pArchivo = fopen(nArch,"wb");
            while(fread(&aux,sizeof(ropaNueva),1,pArchivo_)>0){
                fwrite(&aux,sizeof(ropaNueva),1,pArchivo);
            }
            fclose(pArchivo_);
        }
        fclose(pArchivo);
    }
}
