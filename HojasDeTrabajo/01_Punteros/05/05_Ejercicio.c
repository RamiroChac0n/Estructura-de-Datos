#include <stdio.h>
#include <stdlib.h>

int main(){
    int a=50,b=75,*ptra=&a,*ptrb=&b,aux=0;  // Inicializa 2 variables tipo entero con valores de 50 y 75, respectivamente. Inicializa 2 punteros con las direcciones de las variables anteriores. Inicializa una variable auxiliar.
    aux=*ptra;                              // Le asigna a aux el valor de ptra; es decir: 50
    ptra=ptrb;                              // Le asigna a ptra el valor de ptrb; es decir: la dirección de b
    ptrb=&aux;                              // Le asigna a ptrb la dirección de aux
    a=*ptra;                                // Le asigna a a el valor de ptra; es decir: 75
    b=*ptrb;                                // Le asigna a b el valor de ptrb; es decir: 50
    printf("a:%d\nb:%d",a,b);               // Imprime los valores de a y b
    return 0;                               // Retorna 0
}