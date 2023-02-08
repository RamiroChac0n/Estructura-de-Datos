#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int opcion = 3;
    do{      
        switch (opcion)
        {
        case 1:
            printf("Caso 1\n\n");
            break;
        case 2:
            printf("Caso 2\n\n");
            break; 
        case 3:
            break;                      
        default:
            printf("%d no es una opcion valida\n\n", opcion);
            break;
        }
        printf("--- M E N U ---\n\n");
        printf("1.  Caso 1 \n");
        printf("2.  Caso 2 \n");
        scanf("%d", &opcion);          
    }while(!(opcion == 3));
    return 0;
}