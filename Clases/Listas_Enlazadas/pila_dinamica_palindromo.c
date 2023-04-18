#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Letra
{
    char letra;
    struct Letra *sig;
}letra;

typedef struct Pila
{
    struct Letra *tope;
}pila;

pila *p = NULL;
pila *p2 = NULL;

letra *CrearNodo(char caracter){
    letra *aux;
    aux = malloc(sizeof(letra));
    aux->letra = caracter;
    aux->sig = NULL;
    return aux;
}

void InvertirPalabra(){
    char caracter;
    letra *aux2 = p->tope;
    if (p2 == NULL)
    {
        caracter = aux2->letra;
        p2 = malloc(sizeof(pila));
        p2->tope = CrearNodo(caracter);
        while (aux2 !=  NULL)
        {
            caracter = aux2->letra;
            letra *aux = CrearNodo(caracter);
            aux->sig = p2->tope;
            p2->tope = aux;
            aux2 = aux2->sig;
        }
        
    }
    
}

void CompararPalabra(){
    letra *aux1 = p->tope;
    letra *aux2 = p2->tope;

    while (aux1 != NULL)
    {
        if(aux1->letra != aux2->letra){
            printf("No son palíndromos\n");
            return;
        }
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    } 
    printf("Es un palíndromo\n");
}

void MostrarTope(){
    if(p == NULL){
        printf("Pila esta vacia\n");
    }else
    {
        letra *aux = p->tope;
        while (aux != NULL)
        {
            printf("%c\n", aux->letra);
            aux = aux->sig;
        }
        
    }
    
}

void AnalizarPalabra(){
    char palabra[60], caracter;
    printf("Ingrese palabra que desea analizar\n");
    fflush(stdin);
    gets(palabra);

    int i = 0;
    while (i < strlen(palabra))
    {
        caracter = palabra[i];
        if(p == NULL){
            p = malloc(sizeof(pila));
            p->tope = CrearNodo(caracter);
        }else
        {
            letra *aux = CrearNodo(caracter);
            aux->sig = p->tope;
            p->tope = aux;
        }
        i++;
    }
    InvertirPalabra();
    CompararPalabra();
}

int main(){
    int opc;
    char continuar;
    do{
        printf("Ingrese la operación que desea realizar\n");
        printf("(1) Analizar palabra\n");
        printf("(2) Mostrar tope de la pila\n");
        scanf("%i", &opc);
        if(opc == 1){
            AnalizarPalabra();
        }else if(opc == 2){
            MostrarTope();
        }
        printf("Desea continuar si (S) No (N)\n");
        scanf(" %c", &continuar);
    }while(continuar == 's' || continuar == 'S');
}