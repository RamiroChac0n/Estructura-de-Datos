#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TAM 100

void AgregarDato();
int BuscarDato();
int EliminarDato();

typedef struct Registro
{
    char nombre[100];
    char contrasena[100];
    char Info[100];
    struct Registro *sig;
    
} registro;

typedef struct Nodo
{
    int tamanioLista;
    registro *reg;
} nodo;

nodo *tabla[100];

IniciarTabla(){
    int i = 0;
    while (i < 100)
    {
        tabla[i] = malloc(sizeof(nodo));
        tabla[i]->reg = NULL;
        tabla[i]->tamanioLista = 0;
        i++;
    }
}

int funcionHash(char nombre[100]){
    int i = 0, suma = 0;
    while (i < strlen(nombre))
    {
        suma += nombre[i];
        i++;
    }
    return suma % 100;
}

registro *CrearNodo(char nombre[100], char contrasena[100], char info[1000]){
    registro *aux = malloc(sizeof(registro));
    strcpy(aux->nombre, nombre);
    strcpy(aux->contrasena, contrasena);
    strcpy(aux->Info, info);
    aux->sig = NULL;
    return aux;
}

void AgregarDato(){
    char nombre[100];
    char contrasena[100];
    char info[100];
    printf("Escribar el nombre de la cuenta:\n");
    fflush(stdin);
    fgets(nombre, 100, stdin);

    int hash = funcionHash(nombre);
    registro *comprobarCuenta = tabla[hash]->reg;
    while (comprobarCuenta != NULL)
    {
        if (strcmp(comprobarCuenta->nombre, nombre) == 0)
        {
            printf("El nombre de la cuenta ya esta en uso\n");
            return;
        }
        comprobarCuenta = comprobarCuenta->sig;
    }
    printf("Escriba la contrasena de la cuenta:\n");
    fflush(stdin);
    fgets(contrasena, 100, stdin);
    printf("Escriba la informacion de la cuenta:\n");
    fflush(stdin);
    fgets(info, 100, stdin);

    registro *nodo = CrearNodo(nombre, contrasena, info);
    if (tabla[hash]->reg == NULL)
    {
        tabla[hash]->reg = nodo;
        tabla[hash]->tamanioLista = 1;
    }
    else
    {
        registro *aux = tabla[hash]->reg;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nodo;
        int tamanoLista = tabla[hash]->tamanioLista;
        tabla[hash]->tamanioLista = tamanoLista +1; 
    }
}

int BuscarDato(){
    char nombre[100], contrasena[100];
    printf("Ingrese su nombre de cuenta\n");
    fflush(stdin);
    fgets(nombre, 100, stdin);
    int hash = funcionHash(nombre);
    if(tabla[hash]->reg != NULL){
        registro *aux = tabla[hash]->reg;
        while (aux != NULL)
        {
            if (strcmp(nombre, aux->nombre) == 0)
            {
                printf("Ingrese la contrasena para confirmar el acceso\n");
                fflush(stdin);
                fgets(contrasena, 100, stdin);

                if(strcmp(contrasena, aux->contrasena) == 0){
                    printf("Se ha logueado con exito\n");
                    printf("Informacion\n -------------- \n");
                    printf("%s", aux->Info);
                    printf("\n ------- \n");
                }else{
                    printf("Login fallido\n");
                    return 0;
                }
                aux = aux->sig;
            }else{
                printf("Este usuario no existe\n");
                return 0;
            }
        }       
    }
}

// Nos quedamos por acá
EliminarDato(){
    char nombreCuenta[100], contrasena[100];
    printf("Ingrese el nombre de la cuenta a eliminar\n");
    fflush(stdin);
    fgets(nombreCuenta, 100, stdin);
    int hash = funcionHash(nombreCuenta);
    if(tabla[hash]->reg != NULL){
        registro *aux = tabla[hash]->reg;
        registro *auxAnt = NULL;

        while (aux != NULL)
        {
            if (strcmp(nombreCuenta, aux->nombre) == 0)
            {
                printf("Ingrese la ocntrasena para confirmar la accion \n");
                fflush(stdin);
                fgets(contrasena, 100, stdin);
                
                if (strcmp(contrasena, aux->contrasena) == 0)
                {
                    if (auxAnt == NULL)
                    {
                        tabla[hash]->reg = aux->sig;
                        free(aux);
                    }else
                    {
                        if (aux->sig == NULL)
                        {
                            auxAnt->sig = aux->sig;
                            free(aux);
                        }
                    }
                    printf("La cuenta fue eliminada con éxito\n");
                    return 0;
                }else
                {
                    printf("Acción denegada\n");
                }
            } 
            auxAnt = aux;
            aux = aux->sig;
        } 
    }
    printf("Cuenta inexistente\n");
}

int main(){
    IniciarTabla();
    int resp, cont = 1;
    while (cont == 1)
    {
        printf("Ingrese la opcion que desea realizar:\n");
        printf("(1) Agregar dato\n");
        printf("(2) Buscar dato\n");
        printf("(3) Eliminar dato\n");
        printf("(4) SALIR\n");
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            AgregarDato();
            break;
        case 2:
            BuscarDato();
            break;
        case 3:
            EliminarDato();
            break;
        case 4:
            cont = 0;
            break;
        default:
            printf("Opcion no valida\n");
        }
    }
    return 0;
}