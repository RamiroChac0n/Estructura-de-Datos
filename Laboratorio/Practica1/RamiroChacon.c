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

    int i;
    for ( i = numeroInferior; i <= numeroSuperior; i++)
    {
        int j;
        int bandera = 0;
        for ( j = 1; j < numeroSuperior; j++)
        {
            if (i % j == 0)
            {
                bandera++;
            }

            if (bandera > 2)        //Los numeros primos solo tienen 2 divisores (1 y ellos mismos), si tienen mas, no son primos.
            {
                return 2;
            }
        }
        if (bandera <= 2)
        {
            printf("%d",j);
        }
        
    }
    
}