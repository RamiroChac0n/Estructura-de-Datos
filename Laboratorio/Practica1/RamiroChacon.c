#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeroInferior = 100;
    int numeroSuperior = 5;

    if (numeroInferior > numeroSuperior)
    {
        int aux = numeroInferior;
        numeroInferior = numeroSuperior;
        numeroSuperior = aux;
    }
}