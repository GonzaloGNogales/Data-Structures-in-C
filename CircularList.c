#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración de la Lista simple enlazada
typedef struct Nodo{
    int elem;
    struct Nodo *sig;
}ListaCircular;

//Crear Vacía
ListaCircular *lista = NULL;

//Insertar Final
void insertarFinal (int e) {
    ListaCircular *nuevoNodo; //Variable local para el nuevo nodo a insertar

    //Se asigna espacio en memoria dinámica para el nuevo nodo y se le inserta el elemento
    nuevoNodo = malloc(sizeof(ListaCircular));
    nuevoNodo->elem = e;

    if (lista == NULL) {
        lista = nuevoNodo;
        nuevoNodo->sig = nuevoNodo;
    }
    else {
        ListaCircular *pAux = lista;

        while (pAux->sig != lista) {
            pAux = pAux->sig;
        }

        pAux->sig = nuevoNodo;
        nuevoNodo->sig = lista;
    }
}

//Mostrar lista
void mostrarLista () {
    ListaCircular *pAux = lista;

    while (pAux->sig != lista) {
        printf("\n%i\n", pAux->elem);
        pAux = pAux->sig;
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

    mostrarLista();

    printf("\n\n");
    system("pause");
    return 0;
}