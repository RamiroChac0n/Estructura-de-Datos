#include <stdio.h>
#include <stdlib.h>

int comprobarPrimos(numeroInferior, numeroSuperior){            //Agrega una funcion.
    int posiblePrimo;
    for ( posiblePrimo = numeroInferior; posiblePrimo <= numeroSuperior; posiblePrimo++)
    {
        int divisor;
        int numeroDePrimos = 0;
        for ( divisor = 1; divisor <= numeroSuperior; divisor++)
        {
            if (posiblePrimo % divisor == 0)
            {
                numeroDePrimos++;
            }

            if (numeroDePrimos > 2 || divisor >= posiblePrimo)          //Los numeros primos solo tienen 2 divisores (1 y ellos mismos), si tienen mas, no son primos.
            {
                break;
            }
        }
        if (numeroDePrimos <= 2 && !(posiblePrimo < 2))           //El primo mas pequenio es 2
        {
            printf("%d \n",posiblePrimo);
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