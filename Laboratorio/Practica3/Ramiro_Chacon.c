#include <stdio.h>
#include <stdlib.h>
#include <time.h>
   
struct fecha                                                            //Creando nuestro tipo de dato (Date) desde cero usando struct.
{
        int day;
        int month;
        int year;

        int hour;
        int minute;
        int seconds;
};                                 
struct fecha* creando_Fecha();                                          //Inicializando nuestra función.

int main() {                                               
        struct fecha* puntero_Fecha = creando_Fecha();                  //Llamando a la función.
        printf("Hoy es: %d/%d/%d %d:%d:%d\n", puntero_Fecha->day, puntero_Fecha->month, puntero_Fecha->year, puntero_Fecha->hour, puntero_Fecha->minute, puntero_Fecha->seconds); 
        return 0;
}

struct fecha* creando_Fecha(){
        time_t tiempo = time(0);                                        //Código sugerido para obtener los segundos desde
        struct tm *tlocal = localtime(&tiempo);                         //el 1 de enero de 1970.  

        struct fecha fecha_Actual;
        struct fecha *puntero_Fecha = malloc(sizeof(fecha_Actual));     //Uso de memoria dinámica.

        puntero_Fecha->month = tlocal->tm_mon +1;                       //Obtiene el mes, siendo enero el mes 0 y diciembre el mes 11.
        puntero_Fecha->year = tlocal->tm_year + 1900;                   //Obtiene el año -1900.

        if ((tlocal->tm_hour) < 6)                                      //Algoritmo que corrige las 6 horas adelantas.
        {       
                puntero_Fecha->day = tlocal->tm_mday - 1;               //Como la hora que da está adelantada, puede que el día se adelante.
                puntero_Fecha->hour = tlocal->tm_hour +18;              //Corrigiendo la hora adelantada si es menor a las 6:00 am.
        }else
        {
                puntero_Fecha->hour = tlocal->tm_hour - 6;              //Corrigiendo la hora adelanta si es mayor o igual a las 6:00 am.
        }   
        puntero_Fecha->minute = tlocal->tm_min;
        puntero_Fecha->seconds = tlocal->tm_sec;

        return puntero_Fecha;                                           //Retornando el struct.
}