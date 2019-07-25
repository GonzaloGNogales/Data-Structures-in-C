#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración del Árbol Binario
typedef struct Nodo{
    int raiz;
    struct Nodo *izq, *der;
}ArbolBinario;

//Crear Arbol Bin Vacío
ArbolBinario *arbol = NULL;


//Construir arbol
void construirArbol (int e, struct Nodo **a) {
    ArbolBinario *nuevoNodo; //Variable local para el nuevo nodo a insertar

    //Se asigna espacio en memoria dinámica para el nuevo nodo y se le inserta el elemento
    nuevoNodo = malloc(sizeof(ArbolBinario));
    nuevoNodo->raiz = e;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    if ((*a) == NULL) {
        (*a) = nuevoNodo;
    }
    else if (e < (*a)->raiz) {
            construirArbol(e, &(*a)->izq);
    }
    else if (e > (*a)->raiz) {
            construirArbol(e, &(*a)->der);
    }
}

//Búsqueda en el árbol
int buscar (int e, struct Nodo *a) {
    if(a != NULL) {
        if(e == a->raiz) {
            return a->raiz;
        }
        else if(e < a->raiz) {
            return buscar(e, a->izq);
        }
        else {
            return buscar(e, a->der);
        }
    }
    else return 0;
}

//Imprimir raiz de un árbol
void imprimirRaiz (struct Nodo *a) {
    printf("%i", a->raiz);
}

//Recorrido en PostOrden del árbol
void postOrden (struct Nodo *a) {
    if (a == NULL) {
        return;
    }

    postOrden(a->izq);
    postOrden(a->der);
    printf("%i ",a->raiz);
}

//Recorrido en InOrden del árbol
void inOrden (struct Nodo *a) {
    if (a == NULL) {
        return;
    }

    inOrden(a->izq);
    printf("%i ",a->raiz);
    inOrden(a->der);
}

//Recorrido en PreOrden del árbol
void preOrden (struct Nodo *a) {
    if (a == NULL) {
        return;
    }

    printf("%i ",a->raiz);
    preOrden(a->izq);
    preOrden(a->der);
}

int main() {

    int valor = 0;
    int eBus = 0;
    int sn = 1;

    while (sn == 1) {
        printf("\nSi desea introducir un elemento en el arbol binario pulse 1, si no pulse 0: ");
        scanf("%i",&sn);

        while (sn != 1 && sn != 0) {
            printf("\nSi desea introducir un elemento en el arbol binario pulse 1, si no pulse 0: ");
            scanf("%i",&sn);
        }

        if (sn == 1) {
            printf("Introduzca el elemento que desea insertar en el arbol binario: ");
            scanf("%i", &valor);
            construirArbol(valor,&arbol);
        }
    }

    //PostOrden
    printf("\n\nEl Post-Orden del arbol es: ");
    postOrden(arbol);

    //InOrden
    printf("\nEl In-Orden del arbol es: ");
    inOrden(arbol);

    //PreOrden
    printf("\nEl Pre-Orden del arbol es: ");
    preOrden(arbol);

    //Buscar un elemento en el arbol y mostrarlo
    printf("\n\nEscriba el elemento que desea encontrar en el arbol: ");
    scanf("%i", &eBus);

    if (buscar(eBus, arbol) != 0) {
        printf("\nEl elemento %i SI se encuentra en el arbol.", eBus);
    }
    else {
        printf("\nEl elemento %i NO se encuentra en el arbol.", eBus);
    }


    printf("\n\n");
    system("pause");
    return 0;
}