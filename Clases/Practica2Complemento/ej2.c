#include <stdio.h>
#include <conio.h>

void mult9(int arreglo[9][12]){
    int fila, columna, contador;
    contador = 1;
    for (fila = 0; fila < 9; fila++)
    {
        for (columna = 0; columna < 12; columna++)
        {
            arreglo[fila][columna] = contador * 9;
            contador++;
        }
    }
}

void mostrar(int arreglo[9][12]){
    int fila, columna;
    for (fila = 0; fila < 9; fila++)
    {
        for (columna = 0; columna < 12; columna++)
        {
            if(arreglo[fila][columna] < 100){
                printf("%d   ", arreglo[fila][columna]);
            }
            if(arreglo[fila][columna] < 100 && arreglo[fila][columna] >= 10){
                printf("%d  ", arreglo[fila][columna]);
            }
            if(arreglo[fila][columna] < 1000 && arreglo[fila][columna] >= 100){
                printf("%d ", arreglo[fila][columna]);
            }
        }
        printf("\n");
    }
}

int main(){
    int arreglo[9][12];
    mult9(arreglo);
    print("Los elementos de la matriz principal son: \n");
    mostrar(arreglo);
    getch();
    return 0;
}