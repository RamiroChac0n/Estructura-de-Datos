#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct Empleado
    {
        int id;
        int nit;
        char firstName[15];
        char lastName[15];
        int phone;
        char departamento[30];
        int salario;
    };

    struct Empleado empresa[10];

    struct Empleado emp0;
    emp0.id = 0;
    emp0.nit = 11;
    strncpy(emp0.firstName, "Kenneth", 14);
    strncpy(emp0.lastName, "Urrutia", 14);
    emp0.phone = 45869523;
    strncpy(emp0.departamento, "Ingenieria", 29);
    emp0.salario = 1200;
    empresa[0] = emp0;

    struct Empleado emp1;
    emp1.id = 1;
    emp1.nit = 12;
    strncpy(emp1.firstName, "Raul", 14);
    strncpy(emp1.lastName, "Gonzales", 14);
    emp1.phone = 78964523;
    strncpy(emp1.departamento, "Zootecnia", 29);
    emp1.salario = 800;
    empresa[1] = emp1;

    struct Empleado emp2;
    emp2.id = 2;
    emp2.nit = 13;
    strncpy(emp2.firstName, "Ramiro", 14);
    strncpy(emp2.lastName, "Chacon", 14);
    emp2.phone = 45869512;
    strncpy(emp2.departamento, "Ingenieria", 29);
    emp2.salario = 2500;
    empresa[2] = emp2;

    struct Empleado emp3;
    emp3.id = 3;
    emp3.nit = 14;
    strncpy(emp3.firstName, "Roberto", 14);
    strncpy(emp3.lastName, "Cuyol", 14);
    emp3.phone = 56482351;
    strncpy(emp3.departamento, "Admon", 29);
    emp3.salario = 300;
    empresa[3] = emp3;

    struct Empleado emp4;
    emp4.id = 4;
    emp4.nit = 15;
    strncpy(emp4.firstName, "Marilu", 14);
    strncpy(emp4.lastName, "Garcia", 14);
    emp4.phone = 58462014;
    strncpy(emp4.departamento, "Estetica", 29);
    emp4.salario = 800;
    empresa[4] = emp4;

    struct Empleado emp5;
    emp5.id = 5;
    emp5.nit = 16;
    strncpy(emp5.firstName, "Daniel", 14);
    strncpy(emp5.lastName, "Juarez", 14);
    emp5.phone = 45869720;
    strncpy(emp5.departamento, "Filosofia", 29);
    emp5.salario = 3000;
    empresa[5] = emp5;

    struct Empleado emp6;
    emp6.id = 6;
    emp6.nit = 17;
    strncpy(emp6.firstName, "Filiponcio", 14);
    strncpy(emp6.lastName, "Arduaro", 14);
    emp6.phone = 45368921;
    strncpy(emp6.departamento, "Electronica", 29);
    emp6.salario = 1300;
    empresa[6] = emp6;

    struct Empleado emp7;
    emp7.id = 7;
    emp7.nit = 18;
    strncpy(emp7.firstName, "Cristobal", 14);
    strncpy(emp7.lastName, "Sance", 14);
    emp7.phone = 45968952;
    strncpy(emp7.departamento, "Arquitectura", 29);
    emp7.salario = 950;
    empresa[7] = emp7;

    struct Empleado emp8;
    emp8.id = 8;
    emp8.nit = 19;
    strncpy(emp8.firstName, "Jonathan", 14);
    strncpy(emp8.lastName, "Jostar", 14);
    emp8.phone = 48965237;
    strncpy(emp8.departamento, "Zootecnia", 29);
    emp8.salario = 1500;
    empresa[8] = emp8;

    struct Empleado emp9;
    emp9.id = 9;
    emp9.nit = 20;
    strncpy(emp9.firstName, "Joel", 14);
    strncpy(emp9.lastName, "Delapkovotz", 14);
    emp9.phone = 14857920;
    strncpy(emp9.departamento, "Derecho", 29);
    emp9.salario = 1700;
    empresa[9] = emp9;

    int opcion = 3;
    do{      
        switch (opcion)
        {
        case 1:
            int nit;
            printf("Ingrese el NIT del empleado: \n");
            scanf("%d", &nit);
            int i;
            for (i = 0; i < 10; i++)
            {
                if(empresa[i].nit == nit){
                    printf("---- Empleado ----\n");
                    printf("Codigo de identificacion:   %d\n", empresa[i].id);
                    printf("NIT:                        %d\n", empresa[i].nit);
                    printf("Nombre:                     %s\n", empresa[i].firstName);
                    printf("Apellido:                   %s\n", empresa[i].lastName);
                    printf("Numero telefonico:          %d\n", empresa[i].phone);
                    printf("Departamento:               %s\n", empresa[i].departamento);
                    printf("Salario:                    $ %d.00\n", empresa[i].salario);
                    printf("\n");
                }
            }        
            break;
        case 2:
            printf("---- Lista de Empleados ----\n");
            int j;
            for ( j = 0; j < 10; j++)
            {
                printf("%d. %s %s\n", j +1, empresa[j].firstName, empresa[j].lastName);
            }
            printf("\n");
            break; 
        case 3:
            break;                      
        default:
            printf("%d no es una opcion valida\n\n", opcion);
            break;
        }
        printf("--- M E N U ---\n\n");
        printf("1.  Buscar por NIT\n");
        printf("2.  Listar todos los empleados\n");
        printf("3.  SALIR\n");
        scanf("%d", &opcion); 
        printf("\n\n\n\n\n");         
    }while(!(opcion == 3));
    return 0;
}