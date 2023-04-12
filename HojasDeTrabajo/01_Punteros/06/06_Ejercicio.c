#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char *a[8] = {"mercurio", "venus", "tierra", "marte", "jupiter", "saturno", "urano", "neptuno"};
    for ( i = 0; i < 8; i++)
    {
        printf("Planeta: %s\n", a[i]);                          // Imprime todos los planetas
        //printf("Planeta: %s\n", *(a+3));                      // Imprime el cuarto planeta    
        //printf("Planeta: %c\n", **(a));                       // Imprime la primera del primer planeta            
        //printf("Planeta: %c\n", **(a+2));                     // Imprime la primera del tercer planeta
        //printf("Planeta: %c\n", **(a+3));                     // Imprime la primera del cuarto planeta
    }
    return 0;
}