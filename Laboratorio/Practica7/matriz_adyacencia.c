#include <stdio.h>

int main(){

    int tam, contador, contador2, contador3;
    char a = 97;

    printf("Dame el numero de nodos: \n");
    scanf("%d", &tam);
    int arreglo[tam][tam];
    printf(" ");

    for (contador3 = 0; contador3 < tam; contador3++)
    {
        printf("%c", a++);
    }

    printf("\n");
    a = 97;

    for (contador2 = 0; contador2 < tam; contador2++)
    {
        printf("%c", a++);
        for (contador = 0; contador < tam; contador++)
        {
            arreglo[contador][contador2] = 0;
            printf("%d", arreglo[contador][contador2]);
        }
        printf("\n");
    }

    char x, y;
    int nx, ny;
    char resp = 's';

    do
    {
        fflush(stdin);
        printf("Ingresa la letra (x):\n");
        scanf("%c", &x);
        printf("Ingrese la (y):\n");
        fflush(stdin);
        scanf("%c", &y);

        nx = x -97;
        ny = y -97;
        arreglo[nx][ny] = 1;

        a = 97;
        printf(" ");

        for (contador3 = 0; contador3 < tam; contador3++)
        {
            printf("%c", a++);
        }
        printf("\n");
        a = 97;
        
        for (contador2 = 0; contador2 < tam; contador2++)
        {
            printf("%c", a++);
            //a = 97;

            for (contador = 0; contador < tam; contador++)
            {
                //arreglo[contador][contador2] = 0;
                printf("%d", arreglo[contador][contador2]);
            }
            printf("\n");
        }

        printf("Deseas ingresar otra interseccion? s/n:\n");
        fflush(stdin);
        scanf("%c", &resp);
        

    } while (resp != 'n' && resp != 'N');
    return 0;
}