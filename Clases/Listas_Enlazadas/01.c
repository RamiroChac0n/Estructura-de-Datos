#include <stdio.h>
#include <string.h>

typedef struct Fecha{
    int dia;
    int mes;
    int anio;
}fecha;

struct  Persona
{
    char nombre[60];
    int edad;
};

typedef struct  Nodo
{
    struct Persona empleado;
    struct Fecha f;
}nodo[10];

struct Pila
{
    int cantidadDatosActuales;
    int tamanioPila;
    nodo p;
}pila;

void agregarActualizacion(){
    int edad, dia, mes, anio;
    char nombre[60];
    printf("Ingrese su nombre: \n");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese edad: \n");
    scanf("%d", &edad);

    printf("Ingrese dia de actualizacion: \n");
    scanf("%d", &dia);

    printf("Ingrese mes de actualizacion: \n");
    scanf("%d", &mes);

    printf("Ingrese anio de actualizacion: \n");
    scanf("%d", &anio);     

    strcpy(pila.p[pila.cantidadDatosActuales].empleado.nombre, nombre);
    pila.p[pila.cantidadDatosActuales].empleado.edad = 25;
    pila.p[pila.cantidadDatosActuales].f.dia = 27;
    pila.p[pila.cantidadDatosActuales].f.mes = 3;
    pila.p[pila.cantidadDatosActuales].f.anio = 2023;     

    int datosActuales = pila.cantidadDatosActuales;
    pila.cantidadDatosActuales = datosActuales +1;  
}

int main(){
    strcpy(pila.p[0].empleado.nombre, "Pedro");
    pila.p[0].empleado.edad = 25;
    pila.p[0].f.dia = 27;
    pila.p[0].f.mes = 3;
    pila.p[0].f.anio = 2023;

    strcpy(pila.p[1].empleado.nombre, "Pedro");
    pila.p[1].empleado.edad = 25;
    pila.p[1].f.dia = 27;
    pila.p[1].f.mes = 3;
    pila.p[1].f.anio = 2023;

    strcpy(pila.p[2].empleado.nombre, "Pedro");
    pila.p[2].empleado.edad = 25;
    pila.p[2].f.dia = 27;
    pila.p[2].f.mes = 3;
    pila.p[2].f.anio = 2023;

    pila.tamanioPila = 10;
    pila.cantidadDatosActuales = 3;
    return 0;
}