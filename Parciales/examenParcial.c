#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mes
{
    char nombre[20];
    struct dia dia[31];
};

struct dia
{
    struct PROGRAMACION* next;
};

struct PROGRAMACION
{
    char tarea[50];
    struct PROGRAMACION* next;
};


int main(){
    struct mes anio[12];

    struct mes enero;
    strncpy(enero.nombre, "Enero", 19);

    struct mes febrero;
    strncpy(febrero.nombre, "Febrero",19);

    struct mes marzo;
    strncpy(marzo.nombre, "Marzo",19);

    struct mes abril;
    strncpy(abril.nombre, "Abril",19);

    struct mes mayo;
    strncpy(mayo.nombre, "Mayo",19);

    struct mes junio;
    strncpy(junio.nombre, "Junio",19);

    struct mes julio;
    strncpy(julio.nombre, "Julio",19);

    struct mes agosto;
    strncpy(agosto.nombre, "Agosto",19);

    struct mes septiembre;
    strncpy(septiembre.nombre, "Septiembre",19);

    struct mes octubre;
    strncpy(octubre.nombre, "Octubre",19);

    struct mes noviembre;
    strncpy(noviembre.nombre, "Noviembre",19);

    struct mes diciembre;
    strncpy(diciembre.nombre, "Diciembre", 19);

    anio[0] = enero;
    anio[1] = febrero;
    anio[2] = marzo;
    anio[3] = abril;
    anio[4] = mayo;
    anio[5] = junio;
    anio[6] = julio;
    anio[7] = agosto;
    anio[8] = septiembre;
    anio[9] = octubre;
    anio[10] = noviembre;
    anio[11] = diciembre;

    return 0;
}