#include "jugador.h"
///FUNCIONES QUE TENGAN INTERACCION CON EL JUGADOR


stPlayer cargarJugador(int division){           //cargo un jugador en una buffer, y lo retorno
    stPlayer a;
    char div[8];
    hidecursor(1);
    asignarDivision_string(division,div);
    color(14);
    gotoxy(62,3);
    printf("-----------------------------------------------");
    gotoxy(62,4);
    printf("|  Presione [ENTER] cuando complete un campo  |");
    gotoxy(62,5);
    printf("-----------------------------------------------");

    color(11);
    gotoxy(75,1);
    printf("CARGANDO JUGADOR DE >%s<",div);


    formularioCargaJugador();
    color(10);
    gotoxy(60,7);
    fflush(stdin);
    gets(a.nombre_p);
    gotoxy(101,7);
    fflush(stdin);
    gets(a.apellido);
    gotoxy(60,8);
    fflush(stdin);
    scanf("%ld",&a.DNI);
    gotoxy(101,8);
    fflush(stdin);
    scanf("%d",&a.numeroCanasto);
    a.idPlayer = ultimoIdPlayer()+1;
    a.estado = 0;

    //se guarda una division en la estructura int division;
    if(strcmp(div,"Reserva")!=0){
        //se guarda, 4,5 o 6
        a.division = cint(div[0]);
    }else if(strcmp(div,"Reserva")==0){
        //sino se guarda un 7 que significaria la reserva
        a.division = 7;
    }

    a.entr = setInicE();
    a.ropV.entregado = 0;
    a.ropV.bolso = setInicV();
    return a;
}

void mostrarJugador(stPlayer a, int x, int y){
    color(10);
    cartelJugador(62,3);
    gotoxy(x,y);
    color(14);
    printf("|NOMBRE.....: %s",a.nombre_p);
    y+=2;
    gotoxy(x,y);
    printf("|APELLIDO...: %s",a.apellido);
    y+=2;
    gotoxy(x,y);
    printf("|D.N.I......: %ld",a.DNI);
    y+=2;
    gotoxy(x,y);
    printf("|N%cCANASTO..: %d",167,a.numeroCanasto);
}


void mostrarJugadorL(stPlayer a, int y){
    char d[10];
    gotoxy(44,y);
    printf("|");

    gotoxy(47,y);
    printf("%d",a.numeroCanasto);
    gotoxy(56,y);

    asignarDivision_string(returnPosDivision(a.division),d);
    puts(d);
    gotoxy(68,y);
    puts(a.apellido);
    gotoxy(91,y);
    puts(a.nombre_p);
    gotoxy(113,y);
    printf("%ld",a.DNI);

    gotoxy(124,y);
    printf("|");
}
void playertofile(stPlayer a){
    FILE *pArchivo = fopen("jugadores.dat","ab");
    if(pArchivo){
        fwrite(&a,sizeof(stPlayer),1,pArchivo);
        fclose(pArchivo);
    }
}

int ultimoIdPlayer(){
    int id=0;
    stPlayer a;
    FILE *pArchivo = fopen("jugadores.dat","rb");

    if(pArchivo){
        fseek(pArchivo,sizeof(stPlayer)*(-1),SEEK_END);
        if(fread(&a,sizeof(stPlayer),1,pArchivo)>0){
            id = a.idPlayer;
        }
        fclose(pArchivo);
    }
    return id;
}

char *verEstado(int estado){
    return (estado == 1) ? "Suspendido" : "Activo";
}

void asignarDivision_string(int pos, char a[]){
    if(pos == 0){
        strcpy(a,"4ta");
    }else if(pos == 1){
        strcpy(a,"5ta");
    }else if (pos == 2){
        strcpy(a,"6ta");
    }else if(pos == 3){
        strcpy(a,"Reserva");
    }
}



