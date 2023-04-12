#include <stdio.h>
#include <stdlib.h>

int main(){
    int lado = 4;
    int *a, **b;
    a = &lado;
    b = &a;
    int volumen = 0;
    volumen = **b * **b * **b;
    printf("El volume es: %d", volumen);
}