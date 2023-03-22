#include <stdio.h>                                                      // Libreria estandar de C
#include <stdlib.h>                                                     // Libreria estandar de C

struct cliente{                                                         // Estructura de datos
    int edad;                                                           // Variable de tipo entero
    char nombre[10];                                                    // Variable de tipo cadena
    float sueldo;                                                       // Variable de tipo flotante
}clientes[2][2];                                                        // Matriz de estructuras

void ingreso_cliente(){                                                 // Funcion para ingresar datos

    for(int i=0; i<2; i++){                                             // Ciclo for para ingresar datos
        for(int j=0; j<2; j++){                                         // Ciclo for para ingresar datos
            printf("Ingrese los datos para el nuevo registro: \n");     // Imprime en pantalla
            printf("Ingrese su edad: \n");                              // Imprime en pantalla
            scanf("%i", &clientes[i][j].edad);                          // Almacena el dato en la variable
            fflush(stdin);                                              // Limpia el buffer
            printf("Ingrese su nombre: \n");                            // Imprime en pantalla
            fgets(clientes[i][j].nombre, 10, stdin);                    // Almacena el dato en la variable
            printf("Ingrese su sueldo: \n");                            // Imprime en pantalla
            scanf("%f", &clientes[i][j].sueldo);                        // Almacena el dato en la variable
            fflush(stdin);                                              // Limpia el buffer
            printf("\n\n");                                             // Imprime en pantalla
        }
    }
}

void mostrar_cliente(){                                                 // Funcion para mostrar datos
    printf("Los datos almacenados son:\n");                             // Imprime en pantalla
    for(int i=0; i<2; i++){                                             // Ciclo for para mostrar datos
        for(int j=0; j<2; j++){                                         // Ciclo for para mostrar datos
            printf("Edad: %i \n", clientes[i][j].edad);                 // Imprime en pantalla
            printf("Nombre: %s \n", clientes[i][j].nombre);             // Imprime en pantalla  
            printf("Sueldo: %f \n", clientes[i][j].sueldo);             // Imprime en pantalla
            printf("\n\n");                                             // Imprime en pantalla
        }
    }
}

int main(){                                                             // Funcion principal
    char resp;                                                          // Variable de tipo caracter
    int opc;                                                            // Variable de tipo entero
    do{                                                                 // Ciclo do while
        printf("Menu de opciones: \n");                                 // Imprime en pantalla
        printf("1. Ingresar datos del cliente. \n");                    // Imprime en pantalla
        printf("2. Mostrar datos del cliente. \n");                     // Imprime en pantalla
        printf("3. Salir. \n");                                         // Imprime en pantalla
        printf("Ingrese la opcion deseada: \n");                        // Imprime en pantalla
        scanf("%i", &opc);                                              // Almacena el dato en la variable
        fflush(stdin);                                                  // Limpia el buffer
        switch(opc){                                                    // Switch para seleccionar la opcion
            case 1:                                                     // Opcion 1
                ingreso_cliente();                                      // Llama a la funcion
                break;                                                  // Termina el switch
            case 2:                                                     // Opcion 2
                mostrar_cliente();                                      // Llama a la funcion
                break;                                                  // Termina el switch
            case 3:                                                     // Opcion 3
                exit(0);                                                // Termina el programa
                break;                                                  // Termina el switch
            default:                                                    // Opcion por defecto
                printf("Opcion no valida. \n");                         // Imprime en pantalla
                break;                                                  // Termina el switch
        }
        printf("Desea continuar? (s/n): \n");                           // Imprime en pantalla
        scanf("%c", &resp);                                             // Almacena el dato en la variable
        fflush(stdin);                                                  // Limpia el buffer
    }while(resp=='s' || resp=='S');                                     // Condicion del ciclo
    return 0;                                                           // Retorna 0
}