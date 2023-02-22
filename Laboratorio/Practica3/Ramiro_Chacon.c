#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creando_Fecha();

int main() {
        creando_Fecha();
        return 0;
}

void creando_Fecha(){
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);

        struct fecha
        {
                int day;
                int month;
                int year;

                int hour;
                int minute;
                int seconds;
        };   

        struct fecha fecha_Actual;
        struct fecha *puntero_Fecha = malloc(sizeof(fecha_Actual));

        puntero_Fecha->day = tlocal->tm_mday;
        puntero_Fecha->month = tlocal->tm_mon +1;
        puntero_Fecha->year = tlocal->tm_year + 1900;

        if ((tlocal->tm_hour) < 6)
        {
                puntero_Fecha->hour = tlocal->tm_hour +18;
        }else
        {
                puntero_Fecha->hour = tlocal->tm_hour - 6;
        }   
        puntero_Fecha->minute = tlocal->tm_min;
        puntero_Fecha->seconds = tlocal->tm_sec;
        printf("Hoy es: %d/%d/%d %d:%d:%d\n", puntero_Fecha->day, puntero_Fecha->month, puntero_Fecha->year, puntero_Fecha->hour, puntero_Fecha->minute, puntero_Fecha->seconds); 
}