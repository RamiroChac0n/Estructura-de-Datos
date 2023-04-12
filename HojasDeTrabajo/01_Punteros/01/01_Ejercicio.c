#include <stdio.h>
#include <stdlib.h>

int main(){
    int numA = 21;              // Inicializa una variable tipo entero con un valor de "21"
    int numB = 22;              // Inicializa una variable tipo entero con un valor de 
    int *num_ptr1, *num_ptr2;   // Inicializa 2 punteros
    num_ptr1 = &numA;           // Le asigna a num_ptr1 la dirección numA
    num_ptr2 = num_ptr1;        // Le asigna a num_ptr2 el valor de num_ptr1; es decir: la dirección de numA
    *num_ptr2 = 33;             // El puntero num_ptr2 tendrá 33 como valor
    numB = *num_ptr2;           // numB será igual al valor del puntero num_ptr2; es decir: 33
}