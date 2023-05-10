#include <stdio.h>                                              //Importa las librerias necesarias.

int main(){                                                     //Funcion principal.

    int tam, contador, contador2, contador3;                    //Declaracion de variables.
    char a = 97;                                                //Declaracion de variable para imprimir el abecedario.

    printf("Dame el numero de nodos: \n");                      //Pide el numero de nodos.
    scanf("%d", &tam);                                          //Guarda el numero de nodos.
    int arreglo[tam][tam];                                      //Declaracion de arreglo bidimensional.
    printf(" ");                                                //Imprime un espacio en blanco.

    for (contador3 = 0; contador3 < tam; contador3++)           //Ciclo for para imprimir el abecedario.
    {
        printf("%c", a++);                                      //Imprime el abecedario.
    }

    printf("\n");                                               //Imprime un salto de linea.
    a = 97;                                                     //Reinicia la variable a = 97.

    for (contador2 = 0; contador2 < tam; contador2++)           //Ciclo for para imprimir el abecedario y el arreglo.
    {
        printf("%c", a++);                                      //Imprime el abecedario.
        for (contador = 0; contador < tam; contador++)          //Ciclo for para imprimir el arreglo.
        {
            arreglo[contador][contador2] = 0;                   //Inicializa el arreglo en 0.
            printf("%d", arreglo[contador][contador2]);         //Imprime el arreglo.
        }
        printf("\n");                                           //Imprime un salto de linea.
    }

    char x, y;                                                  //Declaracion de variables.
    int nx, ny;                                                 //Declaracion de variables.
    char resp = 's';                                            //Declaracion de variables.

    do                                                          //Ciclo do while para ingresar las intersecciones.
    {
        fflush(stdin);                                          //Limpia el buffer.
        printf("Ingresa la letra (x):\n");                      //Pide la letra x.
        scanf("%c", &x);                                        //Guarda la letra x.
        printf("Ingrese la (y):\n");                            //Pide la letra y.
        fflush(stdin);                                          //Limpia el buffer.       
        scanf("%c", &y);                                        //Guarda la letra y.

        nx = x -97;                                             //Convierte la letra x a numero.
        ny = y -97;                                             //Convierte la letra y a numero.
        arreglo[nx][ny] = 1;                                    //Guarda el 1 en la posicion nx, ny.

        a = 97;                                                 //Reinicia la variable a = 97.
        printf(" ");                                            //Imprime un espacio en blanco.

        for (contador3 = 0; contador3 < tam; contador3++)       //Ciclo for para imprimir el abecedario.
        {
            printf("%c", a++);                                  //Imprime el abecedario.
        }
        printf("\n");                                           //Imprime un salto de linea.
        a = 97;                                                 //Reinicia la variable a = 97.
        
        for (contador2 = 0; contador2 < tam; contador2++)       //Ciclo for para imprimir el abecedario y el arreglo.
        {
            printf("%c", a++);                                  //Imprime el abecedario.
            //a = 97;

            for (contador = 0; contador < tam; contador++)      //Ciclo for para imprimir el arreglo.
            {
                //arreglo[contador][contador2] = 0;
                printf("%d", arreglo[contador][contador2]);     //Imprime el arreglo.
            }
            printf("\n");                                       //Imprime un salto de linea.
        }

        printf("Deseas ingresar otra interseccion? s/n:\n");    //Pregunta si desea ingresar otra interseccion.
        fflush(stdin);                                          //Limpia el buffer.
        scanf("%c", &resp);                                     //Guarda la respuesta.
        

    } while (resp != 'n' && resp != 'N');                       //Condicion para que se repita el ciclo.
    return 0;                                                   //Retorna 0.
}