#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración de la Lista simple enlazada
typedef struct Nodo{
    int elem;
    struct Nodo *sig;
    struct Nodo *ant;
}ListaCircularDE;

//Crear Vacía
ListaCircularDE *listaCab = NULL;
ListaCircularDE *listaFin = NULL;

//Insertar Final
void insertarFinal (int e) {
    ListaCircularDE *nuevoNodo; //Variable local para el nuevo nodo a insertar

    //Se asigna espacio en memoria dinámica para el nuevo nodo y se le inserta el elemento
    nuevoNodo = malloc(sizeof(ListaCircularDE));
    nuevoNodo->elem = e;

    if (listaCab == NULL) {
        listaCab = nuevoNodo;
        listaFin = nuevoNodo;
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;
    }
    else {
        listaFin->sig = nuevoNodo;
        nuevoNodo->ant = listaFin;
        nuevoNodo->sig = listaCab;
        listaCab->ant = nuevoNodo;
        listaFin = nuevoNodo;
    }
}

//Mostrar lista hacia delante infinitamente
void mostrarLista () {
    ListaCircularDE *pAux = listaCab;

    while (pAux->sig != NULL) {
        printf("\n%i\n", pAux->elem);
        pAux = pAux->sig;
    }
}

//Mostrar lista Inversamente infinitamente
void mostrarListaInversa () {
    ListaCircularDE *pAux = listaFin;

    while (pAux->ant != NULL) {
        printf("\n%i\n", pAux->elem);
        pAux = pAux->ant;
    }
}

void mostrarInversaSinInfinito () {
    ListaCircularDE *pAux = listaFin;

    while (pAux->ant != listaFin) {
        printf("\n%i\n", pAux->elem);
        pAux = pAux->ant;
    }

    printf("\n%i\n", pAux->elem);
}


int main() {

    int valor = 0;
    int sn = 1;

    while (sn == 1) {
        printf("\nSi desea introducir un elemento en la lista pulse 1, si no pulse 0: ");
        scanf("%i",&sn);

        while (sn != 1 && sn != 0) {
            printf("\nSi desea introducir un elemento en la lista pulse 1, si no pulse 0: ");
            scanf("%i",&sn);
        }

        if (sn == 1) {
            printf("Introduzca el elemento que desea insertar en la lista: ");
            scanf("%i", &valor);
            insertarFinal(valor);
        }
    }

    //mostrarLista();
    //mostrarListaInversa();
    mostrarInversaSinInfinito();

    printf("\n\n");
    system("pause");
    return 0;
}