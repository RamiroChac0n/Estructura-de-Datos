#include <stdio.h>
#define TAM 10
#define OK 0
#define ERROR 1

struct matriz{
    unsigned filas, columnas;
    float matriz[TAM][TAM];
};

char Menu(void){
    char d;
    printf("\n Elige la opcion deseada: \n");
    printf("\t0 -- Salir del programa.\n");
    printf("\t1 -- Cambiar la matriz A.\n");
    printf("\t2 -- Cambiar la matriz B.\n");
    printf("\t3 -- Calcular A*B.\n");
    printf("\t4 -- Calcular B*A.\n");
    while((d = getchar()) < '0' || d > '4')
    return d;
}

unsigned PedirTamano(const char *cadena){
    unsigned valor = 0;
    do
    {
        printf("%s", cadena);
        scanf("%u", &valor);
        fflush(stdin);
        printf("\n");
    } while (valor < 1 || valor > TAM);
    return valor;
}

void PedirMatriz(struct matriz *a){
    register unsigned i, j;
    float valor;
    a->filas = PedirTamano("\nIntroduce el numero de filas: ");
    a->columnas = PedirTamano("\nIntroduce el numero de columnas: \n");
    for(i = 0; i < a->filas; i++)
        for(j = 0; j < a->columnas; j++)
        {
            printf("M[%u][%u] = ", i, j);
            scanf("%f", &valor);
            fflush(stdin);
            printf("\n");
            a->matriz[i][j] = valor;
        }
}

int Multiplicar(const struct matriz *a, const struct matriz *b, struct matriz *res){
    register unsigned i, j, k;
    if(a->columnas != b->filas)
        return ERROR;
    res->filas = a->filas;
    res->columnas = b->columnas;
    for(i = 0; i < a->filas; i++)
        for(j = 0; j < b->columnas; j++)
        {
            res->matriz[i][j] = 0;
            for(k = 0; k < a->filas; k++)
                res->matriz[i][j] += a->matriz[i][k] * b->matriz[k][j];
        }
    return OK;
}

void Mostrar(const struct matriz *res){
    register unsigned i, j;
    for(i = 0; i < res->filas; i++)
    {
        for(j = 0; j < res->columnas; j++)
            printf("Res[%u][%u] = %f\n", i, j, res->matriz[i][j]);
        printf("\nPulsa Enter para continuar...\n");
        getchar();
    }
}

int main(void){
    struct matriz a, b, res;
    char d;
    a.filas = a.columnas = b.filas = b.columnas = 1;
    a.matriz[0][0] = b.matriz[0][0] = 1.0;
    do
    {
        switch (d = Menu())
        {
        case '1':
            PedirMatriz(&a);
            break;
        case '2':
            PedirMatriz(&b);
            break;
        case '3':
            if(Multiplicar(&a, &b, &res) == OK)
                Mostrar(&res);
            else
                printf("No se puede multiplicar.\n");
            break;
        case '4':
            if(Multiplicar(&b, &a, &res) == OK)
                Mostrar(&res);
            else
                printf("No se puede multiplicar.\n");
            break;
        default:
            break;
        }
    } while (d != '0');
    
    return 0;
}