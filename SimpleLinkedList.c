#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración de la Lista simple enlazada
typedef struct Nodo{
    int elem;
    struct Nodo *sig;
}Lista;

//Crear Vacía
Lista* lista = NULL;

//Insertar Final
void insertarFinal (int e) {
    Lista *nuevoNodo; //Variable local para el nuevo nodo a insertar

    //Se asigna espacio en memoria dinámica para el nuevo nodo y se le inserta el elemento
    nuevoNodo = malloc(sizeof(Lista));
    nuevoNodo->elem = e;
    nuevoNodo->sig = NULL;

    if (lista == NULL) {
        lista = nuevoNodo;
    }
    else {
        Lista *pAux = lista;

        while (pAux->sig != NULL) {
            pAux = pAux->sig;
        }

        pAux->sig = nuevoNodo;
    }
}

//Mostrar lista
void mostrarLista () {
    Lista *pAux = lista;

    while (pAux != NULL) {
        printf("\n%i\n", pAux->elem);
        pAux = pAux->sig;
    }
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