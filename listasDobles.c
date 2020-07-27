#include "listasDobles.h"

Nodo *inicLista(){
    return NULL;
}

Nodo *crearNodo(stPlayer a){
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = a;
    aux->sig = NULL;
    aux->ante = NULL;
    return aux;
}


Nodo *modificarLista(Nodo *lista, Nodo *nNodo){
    Nodo *aux = buscarNodo(lista, nNodo);
    if(aux){
        aux->dato = nNodo->dato;
    }
    return lista;
}

Nodo *agregarPrincipio(Nodo *lista, Nodo *nNodo){
    nNodo->sig = lista;
    if(lista){
        lista->ante = nNodo;

    }
    return nNodo;
}

Nodo *agregarFinal(Nodo *lista, Nodo *nNodo){

    if(lista==NULL){
        lista = nNodo;
    }else{
        Nodo *aux = ultimoNodo(lista);
        aux->sig = nNodo;
        nNodo->ante = aux;
    }
    return lista;
}

Nodo *agregarEnOrden(Nodo *lista, Nodo *nNodo){
    if(lista == NULL){
        lista = nNodo;
    }else if(lista->dato.numeroCanasto > nNodo->dato.numeroCanasto){
            lista = agregarPrincipio(lista,nNodo);
    }else{
        Nodo *ante = lista;
        Nodo *seg = lista->sig;
        while(seg!=NULL && seg->dato.numeroCanasto < nNodo->dato.numeroCanasto){
            ante = seg;
            seg = seg->sig;
        }
        ante->sig = nNodo;
        nNodo->ante = ante;
        nNodo->sig = seg;
        if(seg){
            seg->ante = nNodo;
        }
    }
    return lista;
}

Nodo *ultimoNodo(Nodo *lista){
    Nodo *ult = lista;
    while(ult->sig != NULL){
        ult = ult->sig;
    }
    return ult;
}

Nodo *borrarNodo(Nodo *lista, char ape[]){
    Nodo *aux = lista;
    if(lista){
        if(strcmp(lista->dato.apellido,ape)==0){
            lista = lista->sig;
            if(lista){
                lista->ante = NULL;
            }
            free(aux);
        }else{
            while(aux!=NULL && strcmp(aux->dato.apellido,ape)!=0){
                aux = aux->sig;
            }
            if(aux!=NULL && strcmp(aux->dato.apellido,ape)==0){
                Nodo *ant = aux->ante;
                Nodo *sigui = aux->sig;
                ant->sig = sigui;
                if(sigui){
                    sigui->ante = aux;
                }
                free(aux);
            }
        }
    }
    return lista;
}

Nodo *buscarNodo(Nodo *lista, char ape[]){
    Nodo *seg = lista;
    while(seg != NULL && strcmp(seg->dato.apellido,ape)!=0){
        seg = seg->sig;
    }
    return seg;
}


void mostrarLista(Nodo *lista, int x, int y){
    Nodo *seg;
    seg = lista;
    while(seg!=NULL){
        mostrarJugadorL(seg->dato,y);//vemos que incrementamos si 'y' o 'x'
        seg=seg->sig;
        y+=1;
    }
}

int contarNodos(Nodo *lista){
    int cN=0;
    Nodo *seg = lista;
    while(seg != NULL){
        cN++;
        seg = seg->sig;
    }
    return cN;
}

//recorre la lista y libera ese nodo siendo que al final retorna una lista vacia
Nodo *refreshlist(Nodo *lista){
    Nodo *aux;
    while(lista!=NULL){
        aux = lista;
        lista = lista->sig;
        free(aux);
    }
    return lista;
}

Nodo *sacarBolsoLista(Nodo *lista){
    Nodo *seg = lista;
    while(seg!=NULL){
        seg->dato.ropV.entregado = 0;
        seg->dato.ropV.bolso.ID_BOLSO = 0;
        seg = seg->sig;
    }
    return lista;
}
