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
    int i;
    while (i < 100)
    {
        tabla[i] = mallock(sizeof(nodo));
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

registro *CrearNodo(char nombre[100], char contrasena[100], char Info[100]){
    registro *aux = mallock(sizeof(registro));
    strcpy(aux->nombre, nombre);
    strcpy(aux->contrasena, contrasena);
    strcpy(aux->Info, Info);
    aux->sig = NULL;
    return aux;
}

void AgregarDato(){
    char nombre[100];
    char contrasena[100];
    char info[100];
    printf("Escribar el nombre de la cuenta: ");
    fflush(stdin);
    gets(nombre);

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
    gets(contrasena);
    printf("Escriba la informacion de la cuenta:\n");
    fflush(stdin);
    gets(info);

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
        tabla[hash]->tamanioLista++;
    }
}

//Nos quedamos por acá
int BuscarDato(){
    char nombre[100];
    printf("Escriba el nombre de la cuenta que desea buscar:\n");
    fflush(stdin);
    gets(nombre);
    int hash = funcionHash(nombre);
    registro *aux = tabla[hash]->reg;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, nombre) == 0)
        {
            printf("Nombre: %s\n", aux->nombre);
            printf("Contrasena: %s\n", aux->contrasena);
            printf("Informacion: %s\n", aux->Info);
            return 1;
        }
        aux = aux->sig;
    }
    printf("No se encontro la cuenta\n");
    return 0;
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
            break;
        }
    }
    return 0;
}