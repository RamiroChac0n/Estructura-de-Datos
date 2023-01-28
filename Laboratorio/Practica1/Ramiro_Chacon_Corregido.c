#include <stdio.h>
#include <stdlib.h>

int comprobarPrimos(numInf, numSup){            //Agrega una funcion.
    int i;
    for ( i = numInf; i <= numSup; i++)
    {
        int j;
        int bandera = 0;
        for ( j = 1; j <= numSup; j++)
        {
            if (i % j == 0)
            {
                bandera++;
            }

            if (bandera > 2 || j >= i)          //Los numeros primos solo tienen 2 divisores (1 y ellos mismos), si tienen mas, no son primos.
            {
                break;
            }
        }
        if (bandera <= 2 && !(i < 2))           //El primo mas pequenio es 2
        {
            printf("%d \n",i);
        }
        
    }
    return 0;
}

int main(){
    int numeroInferior;
    int numeroSuperior;
    printf("Ingrese un numero: \n");
    scanf("%d", &numeroInferior);
    printf("Ingrese otro numero: \n");
    scanf("%d", &numeroSuperior);

    if (numeroInferior > numeroSuperior)
    {
        int aux = numeroInferior;
        numeroInferior = numeroSuperior;
        numeroSuperior = aux;
    }
    printf("El numero menor es: %d \n", numeroInferior);
    printf("El numero mayor es: %d \n", numeroSuperior);
    printf("Los numeros primos entre %d y %d son: \n", numeroInferior, numeroSuperior);

    comprobarPrimos(numeroInferior, numeroSuperior);
}