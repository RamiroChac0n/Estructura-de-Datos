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

agregarActualizacion(){
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

    if(pila.cantidadDatosActuales < pila.tamanioPila){
        strcpy(pila.p[pila.cantidadDatosActuales].empleado.nombre, nombre);
        pila.p[pila.cantidadDatosActuales].empleado.edad = 25;
        pila.p[pila.cantidadDatosActuales].f.dia = 27;
        pila.p[pila.cantidadDatosActuales].f.mes = 3;
        pila.p[pila.cantidadDatosActuales].f.anio = 2023;     
    
        int datosActuales = pila.cantidadDatosActuales;
        pila.cantidadDatosActuales = datosActuales +1; 
    }else
    {
        printf("Pila esta llena\n");
    }
     
}

MostrarUltimaActualizacion(){
    printf("nombre: %s\nedad: %d\ndia: %d\nmes: %d\nanio: %d\n", pila.p[(pila.cantidadDatosActuales) -1].empleado.nombre,
                                                                pila.p[(pila.cantidadDatosActuales) -1].empleado.edad,
                                                                pila.p[(pila.cantidadDatosActuales) -1].f.dia,
                                                                pila.p[(pila.cantidadDatosActuales) -1].f.mes,
                                                                pila.p[(pila.cantidadDatosActuales) -1].f.anio);
}

EliminarActualizacion(){
    strcpy(pila.p[(pila.cantidadDatosActuales) -1].empleado.nombre, " ");
            pila.p[(pila.cantidadDatosActuales) -1].f.dia = 0;
            pila.p[(pila.cantidadDatosActuales) -1].empleado.edad = 0;
            pila.p[(pila.cantidadDatosActuales) -1].f.mes = 0;
            pila.p[(pila.cantidadDatosActuales) -1].f.anio = 0;
            int cantDatos = pila.cantidadDatosActuales;

            if (pila.cantidadDatosActuales > 0)
            {
                pila.cantidadDatosActuales = cantDatos -1; 
            }
            
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

    strcpy(pila.p[2].empleado.nombre, "Ricardo");
    pila.p[2].empleado.edad = 25;
    pila.p[2].f.dia = 29;
    pila.p[2].f.mes = 3;
    pila.p[2].f.anio = 2023;

    pila.tamanioPila = 10;
    pila.cantidadDatosActuales = 3;

    int opc;
    char continuar;
    do{
        //system("cls");
        printf("Ingrese la operación que desea realizar\n");
        printf("(1) Agregar nueva actualización\n");
        printf("(2) Eliminar actualización\n");
        printf("(3) Mostrar ultima actualización\n");
        scanf("%i", &opc);

        if(opc == 1){
            agregarActualizacion();
        }else if(opc == 2){
            EliminarActualizacion();
        }else if(opc == 3){
            MostrarUltimaActualizacion();
        }

        printf("Desea continuar Si (s) No (n)\n");
        scanf(" %c", &continuar);
    }while(continuar == 's' || continuar == 'S');
    //system("pause");
}