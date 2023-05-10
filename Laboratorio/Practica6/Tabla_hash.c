#include <stdio.h>                                                              //Importa las librerias necesarias.
#include <stdlib.h>                                                             //Importa las librerias necesarias.
#include <string.h>                                                             //Importa las librerias necesarias.
#include <stdbool.h>                                                            //Importa las librerias necesarias.
#define TAM 100                                                                 //Define el tamaño de la tabla hash.

void AgregarDato();                                                             //Crea la función para agregar datos.
int BuscarDato();                                                               //Crea la función para buscar datos.
int EliminarDato();                                                             //Crea la función para eliminar datos.

typedef struct Registro                                                         //Crea la estructura para los registros.
{
    char nombre[100];                                                           //Crea un arreglo de caracteres para guardar el nombre.
    char contrasena[100];                                                       //Crea un arreglo de caracteres para guardar la contraseña.
    char Info[100];                                                             //Crea un arreglo de caracteres para guardar la información.
    struct Registro *sig;                                                       //Crea un puntero para el siguiente registro.                                      
    
} registro;                                                                     //Crea un alias para la estructura.

typedef struct Nodo                                                             //Crea la estructura para los nodos.
{
    int tamanioLista;                                                           //Crea una variable para guardar el tamaño de la lista.
    registro *reg;                                                              //Crea un puntero para los registros.
} nodo;                                                                         //Crea un alias para la estructura.

nodo *tabla[100];                                                               //Crea un arreglo de nodos para la tabla hash.

IniciarTabla(){                                                                 //Crea la función para iniciar la tabla hash.
    int i = 0;                                                                  //Crea una variable para el ciclo.
    while (i < 100)                                                             //Ciclo para recorrer la tabla hash.
    {
        tabla[i] = malloc(sizeof(nodo));                                        //Reserva memoria para el nodo.
        tabla[i]->reg = NULL;                                                   //Inicializa el puntero de los registros en NULL.
        tabla[i]->tamanioLista = 0;                                             //Inicializa el tamaño de la lista en 0.
        i++;                                                                    //Incrementa la variable del ciclo.     
    }
}

int funcionHash(char nombre[100]){                                              //Crea la función para la función hash.
    int i = 0, suma = 0;                                                        //Crea las variables para el ciclo y la suma.
    while (i < strlen(nombre))                                                  //Ciclo para recorrer el nombre.
    {
        suma += nombre[i];                                                      //Suma el valor del caracter a la suma.
        i++;                                                                    //Incrementa la variable del ciclo.
    }
    return suma % 100;                                                          //Retorna el valor de la suma.
}

registro *CrearNodo(char nombre[100], char contrasena[100], char info[1000]){   //Crea la función para crear un nodo.
    registro *aux = malloc(sizeof(registro));                                   //Reserva memoria para el registro.
    strcpy(aux->nombre, nombre);                                                //Copia el nombre al registro.
    strcpy(aux->contrasena, contrasena);                                        //Copia la contraseña al registro.
    strcpy(aux->Info, info);                                                    //Copia la información al registro.
    aux->sig = NULL;                                                            //Inicializa el puntero del siguiente registro en NULL.
    return aux;                                                                 //Retorna el registro.
}

void AgregarDato(){                                                             //Crea la función para agregar datos.
    char nombre[100];                                                           //Crea un arreglo de caracteres para guardar el nombre.
    char contrasena[100];                                                       //Crea un arreglo de caracteres para guardar la contraseña.
    char info[100];                                                             //Crea un arreglo de caracteres para guardar la información.
    printf("Escribar el nombre de la cuenta:\n");                               //Imprime en pantalla.
    fflush(stdin);                                                              //Limpia el buffer.
    fgets(nombre, 100, stdin);                                                  //Lee el nombre.

    int hash = funcionHash(nombre);                                             //Crea una variable para guardar el valor de la función hash.
    registro *comprobarCuenta = tabla[hash]->reg;                               //Crea un puntero para comprobar la cuenta.
    while (comprobarCuenta != NULL)                                             //Ciclo para recorrer la lista.
    {
        if (strcmp(comprobarCuenta->nombre, nombre) == 0)                       //Compara el nombre de la cuenta.
        {
            printf("El nombre de la cuenta ya esta en uso\n");                  //Imprime en pantalla.
            return;                                                             //Retorna la función.
        }
        comprobarCuenta = comprobarCuenta->sig;                                 //Avanza al siguiente registro.
    }
    printf("Escriba la contrasena de la cuenta:\n");                            //Imprime en pantalla.
    fflush(stdin);                                                              //Limpia el buffer.
    fgets(contrasena, 100, stdin);                                              //Lee la contraseña.
    printf("Escriba la informacion de la cuenta:\n");                           //Imprime en pantalla.
    fflush(stdin);                                                              //Limpia el buffer.
    fgets(info, 100, stdin);                                                    //Lee la información.

    registro *nodo = CrearNodo(nombre, contrasena, info);                       //Crea un nodo.
    if (tabla[hash]->reg == NULL)                                               //Comprueba si el registro es el primero.
    {
        tabla[hash]->reg = nodo;                                                //Guarda el nodo en el registro.
        tabla[hash]->tamanioLista = 1;                                          //Guarda el tamaño de la lista.
    }
    else                                                                        //Si no es el primero.
    {
        registro *aux = tabla[hash]->reg;                                       //Crea un puntero para recorrer la lista.
        while (aux->sig != NULL)                                                //Ciclo para recorrer la lista.
        {
            aux = aux->sig;                                                     //Avanza al siguiente registro.
        }
        aux->sig = nodo;                                                        //Guarda el nodo en el registro.
        int tamanoLista = tabla[hash]->tamanioLista;                            //Crea una variable para guardar el tamaño de la lista.
        tabla[hash]->tamanioLista = tamanoLista +1;                             //Guarda el tamaño de la lista.
    }
}

int BuscarDato(){                                                               //Crea la función para buscar datos.
    char nombre[100], contrasena[100];                                          //Crea un arreglo de caracteres para guardar el nombre y la contraseña.
    printf("Ingrese su nombre de cuenta\n");                                    //Imprime en pantalla.
    fflush(stdin);                                                              //Limpia el buffer.
    fgets(nombre, 100, stdin);                                                  //Lee el nombre.
    int hash = funcionHash(nombre);                                             //Crea una variable para guardar el valor de la función hash.
    if(tabla[hash]->reg != NULL){                                               //Comprueba si el registro no es nulo.
        registro *aux = tabla[hash]->reg;                                       //Crea un puntero para recorrer la lista.
        while (aux != NULL)                                                     //Ciclo para recorrer la lista.
        {
            if (strcmp(nombre, aux->nombre) == 0)                               //Compara el nombre de la cuenta.
            {
                printf("Ingrese la contrasena para confirmar el acceso\n");     //Imprime en pantalla.
                fflush(stdin);                                                  //Limpia el buffer.
                fgets(contrasena, 100, stdin);                                  //Lee la contraseña.

                if(strcmp(contrasena, aux->contrasena) == 0){                   //Compara la contraseña.
                    printf("Se ha logueado con exito\n");                       //Imprime en pantalla.
                    printf("Informacion\n -------------- \n");                  //Imprime en pantalla.
                    printf("%s", aux->Info);                                    //Imprime en pantalla.
                    printf("\n ------- \n");                                    //Imprime en pantalla.
                }else{                                                          //Si la contraseña es incorrecta.
                    printf("Login fallido\n");                                  //Imprime en pantalla.
                    return 0;                                                   //Retorna la función.
                }
                aux = aux->sig;                                                 //Avanza al siguiente registro.
            }else{                                                              //Si el nombre de la cuenta es incorrecto.
                printf("Este usuario no existe\n");                             //Imprime en pantalla.       
                return 0;                                                       //Retorna la función.
            }
        }       
    }
}

// Nos quedamos por acá
EliminarDato(){                                                                 //Crea la función para eliminar datos.
    char nombreCuenta[100], contrasena[100];                                    //Crea un arreglo de caracteres para guardar el nombre y la contraseña.
    printf("Ingrese el nombre de la cuenta a eliminar\n");                      //Imprime en pantalla.
    fflush(stdin);                                                              //Limpia el buffer.   
    fgets(nombreCuenta, 100, stdin);                                            //Lee el nombre de la cuenta.
    int hash = funcionHash(nombreCuenta);                                       //Crea una variable para guardar el valor de la función hash.
    if(tabla[hash]->reg != NULL){                                               //Comprueba si el registro no es nulo.
        registro *aux = tabla[hash]->reg;                                       //Crea un puntero para recorrer la lista.
        registro *auxAnt = NULL;                                                //Crea un puntero para guardar el registro anterior.

        while (aux != NULL)                                                     //Ciclo para recorrer la lista.
        {
            if (strcmp(nombreCuenta, aux->nombre) == 0)                         //Compara el nombre de la cuenta.
            {
                printf("Ingrese la ocntrasena para confirmar la accion \n");    //Imprime en pantalla.
                fflush(stdin);                                                  //Limpia el buffer.
                fgets(contrasena, 100, stdin);                                  //Lee la contraseña.
                
                if (strcmp(contrasena, aux->contrasena) == 0)                   //Compara la contraseña.
                {
                    if (auxAnt == NULL)                                         //Comprueba si el registro anterior es nulo.
                    {
                        tabla[hash]->reg = aux->sig;                            //Guarda el registro siguiente en el registro.
                        free(aux);                                              //Libera el espacio de memoria.
                    }else                                                       //Si no es nulo.
                    {
                        if (aux->sig == NULL)
                        {
                            auxAnt->sig = aux->sig;                             //Guarda el registro siguiente en el registro anterior.
                            free(aux);                                          //Libera el espacio de memoria.
                        }
                    }
                    printf("La cuenta fue eliminada con éxito\n");              //Imprime en pantalla.
                    return 0;                                                   //Retorna la función.
                }else                                                           //Si la contraseña es incorrecta.
                {
                    printf("Acción denegada\n");                                //Imprime en pantalla.
                }
            } 
            auxAnt = aux;                                                       //Guarda el registro actual en el registro anterior.
            aux = aux->sig;                                                     //Avanza al siguiente registro.
        } 
    }
    printf("Cuenta inexistente\n");                                             //Imprime en pantalla.
}

int main(){                                                                     //Crea la función principal.
    IniciarTabla();                                                             //Llama a la función para iniciar la tabla.
    int resp, cont = 1;                                                         //Crea variables para guardar la respuesta y para el ciclo.
    while (cont == 1)                                                           //Ciclo para el menú.
    {
        printf("Ingrese la opcion que desea realizar:\n");                      //Imprime en pantalla.
        printf("(1) Agregar dato\n");                                           //Imprime en pantalla.
        printf("(2) Buscar dato\n");                                            //Imprime en pantalla.
        printf("(3) Eliminar dato\n");                                          //Imprime en pantalla.
        printf("(4) SALIR\n");                                                  //Imprime en pantalla.
        scanf("%d", &resp);                                                     //Lee la respuesta.
        switch (resp)                                                           //Ciclo para la respuesta.
        {
        case 1:AgregarDato();break;                                             //Llama a la función para agregar datos.
        case 2:BuscarDato();break;                                              //Llama a la función para buscar datos.
        case 3:EliminarDato();break;                                            //Llama a la función para eliminar datos.
        case 4:cont = 0;break;                                                  //Cambia el valor de la variable para salir del ciclo.
        default:printf("Opcion no valida\n");break;                             //Imprime en pantalla.
        }
    }
    return 0;                                                                   //Retorna 0 si todo está bien.
}