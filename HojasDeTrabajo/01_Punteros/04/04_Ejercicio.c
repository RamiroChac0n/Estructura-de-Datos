#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool primo(int *num){
    int n = *num;
    int factor = 2;
    while (factor < n){
        if (n % factor == 0){
            return false;
        }
        factor++;
    }
    return true;
}

int main(){
    int n = 0;
    printf("Ingrese un valor: ");
    scanf("%d", &n);
    int *num = &n;
    if (primo(num)){
        printf("El numero %d es primo", n);
    } else {
        printf("El numero %d no es primo", n);
    }
    return 0;
}