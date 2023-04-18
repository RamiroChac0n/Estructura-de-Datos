#include <stdio.h>
#include <stdlib.h>

typedef struct Numero
{
    int numero;
}Numero;

typedef struct Nodo
{
    Numero numero;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista{
    Nodo *cabeza;
}Lista;

int main(){
    return 0;
}