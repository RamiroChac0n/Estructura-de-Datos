#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char *a[8] = {"mercurio", "venus", "tierra", "marte", "jupiter", "saturno", "urano", "neptuno"};
    for ( i = 0; i < 8; i++)
    {
        //printf("Planeta: %s\n", a[i]);
        //printf("Planeta: %c\n", *(a+3));                // Solo imprime el planeta que está en la posición 3, recordando que se empieza desde 0
        printf("Planeta: %c\n", **(a));
        printf("Planeta: %c\n", **(a+2));
        printf("Planeta: %c\n", **(a+3));
    }
    return 0;
}