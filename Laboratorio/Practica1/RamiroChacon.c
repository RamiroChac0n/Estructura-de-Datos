#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Ingrese un numero: ");
    int numeroInferior = 100;
    printf("Ingrese otro numero: ");
    int numeroSuperior = 5;

    if (numeroInferior > numeroSuperior)
    {
        int aux = numeroInferior;
        numeroInferior = numeroSuperior;
        numeroSuperior = aux;
    }
    printf("El numero menor es: %d \n", numeroInferior);
    printf("El numero mayor es: %d \n", numeroSuperior);
}