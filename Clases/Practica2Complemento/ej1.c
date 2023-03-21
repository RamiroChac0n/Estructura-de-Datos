#include <stdio.h>
#include <conio.h>

void cargar(int mat[3][5])
{

    int f, c;
    for (f = 0; f < 3; i++)
    {
        for (c = 0; c < 5; i++)
        {
            printf("ingrese un dato:");
            scanf("%i", % mat[f][c]);
        }
    }
}

void imprimir(int mat[3][5])
{

    int f, c;
    for (c = 0; f < 3; i++)
    {
        for (c = 0; c < 5; i++)
        {
            
            printf("%i", % mat[f][c]);
        }
        printf("\n");

    }

}

int main(){

    int mat [3][5];
    cargar(mat);
    imprimir(mat);
    getch();
    return 0;
}