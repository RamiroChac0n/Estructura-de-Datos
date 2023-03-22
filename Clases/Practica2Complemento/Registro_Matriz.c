#include <stdio.h>
#include <stdlib.h>

struct cliente{
    int edad;
    char nombre[10];
    float sueldo;
}clientes[2][2];

void ingreso_cliente(){

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Ingrese los datos para el nuevo registro: \n");
            printf("Ingrese su edad: \n");
            scanf("%i", &clientes[i][j].edad);
            fflush(stdin);
            printf("Ingrese su nombre: \n");
            gets(clientes[i][j].nombre);
            printf("Ingrese su sueldo: \n");
            scanf("%f", &clientes[i][j].sueldo);
            fflush(stdin);
            printf("\n\n");
        }
    }
}

void mostrar_cliente(){
    printf("Los datos almacenados son:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Edad: %i \n", clientes[i][j].edad);
            printf("Nombre: %s \n", clientes[i][j].nombre);
            printf("Sueldo: %f \n", clientes[i][j].sueldo);
            printf("\n\n");
        }
    }
    system("pause");
}

main(){
    char resp;
    int opc;
    do{
        system("cls");
        printf("Menu de opciones: \n");
        printf("1. Ingresar datos del cliente. \n");
        printf("2. Mostrar datos del cliente. \n");
        printf("3. Salir. \n");
        printf("Ingrese la opcion deseada: \n");
        scanf("%i", &opc);
        fflush(stdin);
        switch(opc){
            case 1:
                ingreso_cliente();
                break;
            case 2:
                mostrar_cliente();
                break;
            case 3:
                //exit(0);
                break;
            default:
                printf("Opcion no valida. \n");
                break;
        }
        printf("Desea continuar? (s/n): \n");
        scanf("%c", &resp);
        fflush(stdin);
    }while(resp=='s' || resp=='S');
    return 0;
}