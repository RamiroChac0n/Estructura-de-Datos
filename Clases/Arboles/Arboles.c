#include <stdio.h>                                      //Importa las librerias necesarias.
#include <stdlib.h>                                     //Importa las librerias necesarias.
#include <string.h>                                     //Importa las librerias necesarias.

typedef struct Nodo                                     //Crea una estructura llamada "nodo" que almacena un entero y otra estructura Nodo.
{
    int dato;                                           //Guarda un el valor del nodo
    struct Nodo *hizquierdo, *hderecho;                 //Crear otra estructura Nodo
}nodo;

typedef struct arbol{                                   //Crea una función arbol.

    int cantidadNodos;                                  //Almacena la cantidad de nodos del árbol.
    struct nodo *raiz;                                  //Crea una estructura nodo el cual apunta hacía la raíz.
} arbolito;

arbolito *arbol = NULL;                                 //Crea un puntero de tipo arbol apuntando a NULL.

nodo *CrearNodo(int dato){                              //Crea un función para añadir nodos.
    nodo *auxNodo = malloc(sizeof(nodo));               //Inicializa un puntero auxiliar con la función mallock tomando el tamaño del tipo "nodo".
    auxNodo->dato = dato;                               //A auxNodo se le apunta a dato.
    auxNodo->hderecho = auxNodo->hizquierdo = NULL;     //Se inicializan los hijos derechos e izquierdos a NULL.
    return auxNodo;                                     //Retornar el puntero del nodo.
}

int agregarDatoArbol(int dato){                         //Crea una función para guardar datos en el árbol.
    if(arbol == NULL){                                  //Comprueba si el arbol está vació.
        arbol = malloc(sizeof(arbolito));               //Inicializa con la función malloc un arbol.
        arbol->raiz = CrearNodo(dato);                  //Hace que la raiz del árbol se cree si el árbol está vació.
        arbol->cantidadNodos = 1;                       //Aumenta la cantidad de nodos en el árbol.
    }else{                                              //Si el árbol no está vació, esta parte se ejecuta.
        nodo *aux = arbol->raiz;                        //Crea un puntero de tipo nodo que se iguala a la raiz del arbol.
        while (aux != NULL)                             //Mientras el puntero aux no sea NULL, nos seguimos moviendo.
        {
            if (dato > aux->dato)                       //Si el dato es mayor que el valor del nodo, entonces se mueve a la derecha.
            {
                if (aux->hderecho == NULL)              //Comprobamos que el hijo derecho esté vació.
                {
                    aux->hderecho = CrearNodo(dato);    //Si el hijo derecho está vació se agrega el nuevo nodo con su valor.
                    return 0;                           //Retorna 0 si todo funcionó.
                }
                aux = aux->hderecho;                    //Si no está vació, entonces nos movemos al hijo derecho.
            }else{
                if(aux->hizquierdo == NULL){            //Si el dato no es mayor al hijo derecho, entonces lo comparamos con el izquierdo.
                    aux->hizquierdo = CrearNodo(dato);  //Si está vació el hijo izquierdo, creamos el nodo con el valor dato.
                    return 0;                           //Retorna 0 si todo funciona.
                }
                aux = aux->hizquierdo;                  //Si no está vació, nos movemos al izquierdo y seguimos comparando.
            }
            
        }
        
    }
}

int mostrarArbol(nodo *raiz, int contador){             //Crea la función para mostrar el árbol en pantalla.
    if (raiz == NULL)                                   //Si el árbol está vació, no muestra nada.
    {
        return 0;                                       //Retorna 0 si está vació.
    }else{
        mostrarArbol(raiz->hderecho, contador +1);      //Si no está vació, procedemos a recorrer el árbol y a mostrarlo en pantalla.
        int i;                                          //Inicializamos nuestro iterador en 0.
        for (i = 0; i < contador; i++)                  //Usamos un bucle for para recorre el árbol.
        {
            printf("  ");                               //Agregamos unos cuantos espacios para que se vea mejor.
        }
        printf("%d", raiz->dato);                       //Imprime en pantalla en valor del nodo actual.
        printf("\n");                                   //Salto de línea.
        mostrarArbol(raiz->hizquierdo, contador +1);    //Usamos recursividad para imprimir el árbol y nos movemos de nodo, diciendole a la raíz que apunte al hijo izquierdo.
    }
    
}

int main(){                                             //Función main.

    agregarDatoArbol(40);                               //Agrega un dato y crea un nuevo nodo.
    agregarDatoArbol(50);                               //Agrega un dato y crea un nuevo nodo.
    agregarDatoArbol(25);                               //Agrega un dato y crea un nuevo nodo.
    agregarDatoArbol(70);                               //Agrega un dato y crea un nuevo nodo.
    agregarDatoArbol(60);                               //Agrega un dato y crea un nuevo nodo.
    agregarDatoArbol(45);                               //Agrega un dato y crea un nuevo nodo.
    mostrarArbol(arbol->raiz, 0);                       //lLama a la función mostrarArbol para imprimirlo en pantalla, le mandamos un puntero indicandole la raiz y en que posición empezamos.
    return 0;                                           //Retorna 0 si todo está bien.
}