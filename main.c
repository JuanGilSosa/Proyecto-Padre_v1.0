/*
*       ANOTACIONES: en listas dobles, acomodar la funcion de mostrarJugador que tiene los parametros de x & y como 0, 0 y hacerlo iterativo
*       - Fijarse en la busqueda y eliminacion de un nodo, que se buscan por nombre, capas que quiere otra cosa (TERMINADO)
*       - Acomodar los menus, para que se accesible para el usuario
*       gotoxy(50,12);
*
*
*/

//EL LIMITE ES 36 EN Y


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

#include "divisiones.h"
#include "gotoxy.h"

typedef struct{char v[50];}v_dato;

///PROTOTIPADOS
void iniciarPrograma(stDivisiones **ADL);
int confirmarCredencial(int x, int y);
void borrarTexto (int x, int y, int cantidadEspacios);
void keyevent(int x, int y);
int cint(char a);
bool validstart(char a[], v_dato b);

bool isKeyDown(int vkey) ;
///
int main()
{
    //startprogram();
    system("mode con: cols=127 lines=38");

    //srand(time(NULL));
    recuadro();//si pongo aca esto, no titila la pantalla

    //ADL [0] esta 4ta - ADL [1] esta 5ta - ADL [2] esta 6ta - ADL [3] esta reserva
    stDivisiones *ADL = (stDivisiones *)malloc(sizeof(stDivisiones)*4);
    int validos = 4;
    iniciarPrograma(&ADL);
    fileplayertocelda(&ADL);
    menuPrincipal(&ADL);
    return 0;
}

void getFecha(char fecha[128]){
    clock_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    //char fecha[128];
    strftime(fecha,128,"%d/%m/%y",tlocal);
}


void barraCarga(int x, int y){
    int segundos = 1;
    for(int i = 0; i <= 50; i++){
        Sleep(segundos*20);
        gotoxy(x + i,y);
        printf("%c", 220);
        gotoxy(x+24,y+2);

        printf("%d %c", i*2, 37);
    }

}

void resetstring(char a[]){
    memset(a,0,sizeof(char));
}

void upperstring(char a[]){
    for(int i = 0; a[i] != '\0' ;i++){
        a[i]  = toupper(a[i]);
    }
}

void iniciarPrograma(stDivisiones **ADL){
    int d = 4;
    for(int i = 0;i < 4;i++){
        (*ADL)[i].listaJugador = inicLista();
        (*ADL)[i].idDivision = d;
        d+=1;
    }
}

int cint(char a){
    int n = a - '0';
    return n;
}
void systemreset(stDivisiones **ADL){

}
int confirmarCredencial(int x, int y)
{
    hidecursor(1);
    gotoxy(x+4,y);
    printf("%cGuadar Datos Ingresados?",168);
    gotoxy(x+6,y+1);
    printf("[ESC] NO | [ENTER] SI");
    char op = _getch();
    return (op==27 ? 0 : 1); /**con el ternario, si apreta escape, retorna 0, osea cancelo la operacion, sino
    retorna 1 para confirmar el registro*/
}

void borrarTexto (int x, int y, int cantidadEspacios){
        int cont=0;
        while (cont<=cantidadEspacios){
            gotoxy(x,y);
            printf("%c", 0);
            x++;
            cont++;
    }
    gotoxy(x-cantidadEspacios-1,y);
}

void keyevent(int x, int y){//x & y son los parametros de posicion para mostrar el mensaje
    char a[]= "> Presione una tecla para continuar <";
    int num=0;
    hidecursor(1);
    /*while(num==0){
        gotoxy(x,y);
        color(78);
        puts(a);
        Sleep(1000);
        clearcolor(a,x,y);
        Sleep(1000);
        fflush(stdin);
    }*/
    color(13);
    gotoxy(x,y);
    puts(a);
    fflush(stdin);
    getch();
    borrarTexto(x,y,40);
}

//hasta que encuentra id del player
void modifyfile(stPlayer a){
    FILE *pArchivo = fopen("jugadores.dat","r+b");
    stPlayer aux;
    int flag = 0;
    if(pArchivo){
        rewind(pArchivo);
        while(flag == 0 && fread(&aux,sizeof(stPlayer),1,pArchivo)>0){
            if(aux.idPlayer == a.idPlayer){
                fseek(pArchivo,sizeof(stPlayer)*(-1),SEEK_CUR);
                fwrite(&a,sizeof(stPlayer),1,pArchivo);
                flag = 1;
            }
        }
        fclose(pArchivo);
    }
}

void modifymemory(stDivisiones **ADL, Nodo *nNodo, int pos){// posicion de la division que quiero modificar
    (*ADL)[pos].listaJugador = modificarLista((*ADL)[pos].listaJugador,nNodo);
}

void startprogram(){
    system("title UTILERIA ALDOSIVI");
    v_dato a;
    FILE *pArchi = fopen("C:\\Windows\\System32\\v_dird43j5jel.dat","rb");
    if(pArchi){
        fread(&a,sizeof(v_dato),1,pArchi);
        fclose(pArchi);
    }
    char v[40];
    FILE *pArchivo = fopen(a.v,"rb");
    if(pArchivo){

        resetstring(a.v);
        resetstring(v);

        fread(&a,sizeof(v_dato),1,pArchivo);
        strcpy(v,a.v);
        fclose(pArchivo);
    }
    if(!validstart(v,a)){
        msgsoftware();
        getch();
        exit(EXIT_FAILURE);
    }
}

bool validstart(char a[], v_dato b){
    return (strcmp(a,b.v)==0) ? true : false;
}

void msgsoftware(){
    printf("\t\t\t\t***********************");
    printf("\n\t\t\t\***********************");
    printf("\n\n >> Por favor verifique que tenga la version adecuada \n\n");
    printf("| Tu version de windows: ");
    system("ver");
    printf("\nComuniquese ct*PROGRAMA INCOMPATIBLE*\n");
    printf("\t\t\t\ton el desarrollador.\n\n - e-mail : juanmanuels499%cgmail.com\n\n\n\n\n",64);
}

void clearscreen_2(int _max){ //max seria la cantidad maxima de hasta donde tiene que bajar para borrar
    int min_x = 44;

    int x = min_x;

    borrarTexto(x,3,80);
    borrarTexto(x,4,80);
    borrarTexto(x,5,80);
    borrarTexto(x,6,80);
    for(int i = 0;i<_max;i++){
        borrarTexto(x,i+6,80);
    }
}

void clearscreen_3(int _max){

//        gotoxy(2,27);

    int min_x = 3;
    int x = min_x;

    for(int i = 0;i<_max;i++){
        borrarTexto(x,i+27,39);
    }
}

void limpiartabla(){
    borrarTexto(44,1,80);//borra el viewbox
}
