#include <stdio.h>
#include <time.h>

void creando_Fecha();

int main() {

        return 0;
}

void creando_Fecha(){
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        printf("%s\n",output);
        
        struct fecha
        {
                int dd;
                int mm;
                int yy;

                int HH;
                int MM;
                int SS;
        };   
}