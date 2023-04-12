#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 12;
    int b = 20;
    int *ptra, *ptrb;
    ptra = &a;
    ptrb = &b;
    a = *ptra + *ptrb;
    printf("La suma es: %d", a);
}