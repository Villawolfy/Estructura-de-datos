#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int opcion;
    FILE* registro;
    char lista[20];
    char nombre[15];
    char apellido[20];
    char rut[15];
    char mail[50];
    char direccion[70];
    char telefono[20];

    printf("--- Agendar clientes---\n");
    printf("1.- Listar txt\n");
    printf("2.- Crear txt\n");
    printf("3.- Mostrar registros del txt\n");
    printf("4.- Añadir registro en txt\n");
    printf("5.- Salir\n");
    printf("Ingrese su opción:\n");
    scanf("%d", &opcion);

    switch(opcion){
        case 1: printf("Los contratos que tenemos actualmente son:\n");
                system("ls *.txt");
                break;
        case 2: printf("Ingrese el nombre de la lista que quiere crear:\n");
                scanf("%s", lista);
                strcat(lista, ".txt");          
                registro = fopen(lista, "w");
                fclose(registro); 
                break;
        case 3: printf("Las listas de usuarios disponibles son:\n");
                system("ls *.txt");
                printf("Ingrese el nombre del txt que quiere revisar:\n");
                scanf("%s", lista);
                strcat(lista, ".txt");
                registro  = fopen(lista, "r");
                // Imprimir
                while(!feof(registro)){
                    fscanf(registro, "%s %s %s %s %s %s\n", nombre, apellido, rut, mail, direccion, telefono);
                    printf("%s %s %s %s %s %s\n", nombre, apellido, rut, mail, direccion, telefono);
                }
                fclose(registro);
                break;
        case 4: printf("Las listas con contactos disponibles son:\n");
                system("ls *.txt");
                printf("Ingrese el nombre del txt que quiere editar:\n");
                scanf("%s", lista);
                strcat(lista, ".txt");
                printf("Ingrese el nombre del usuario:\n");
                scanf("%s", nombre);
                printf("Ingrese el apellido del usuario:\n");
                scanf("%s", apellido);
                printf("Ingrese el rut del usuario:\n");
                scanf("%s", rut);
                printf("Ingrese el e-mail del usuario:\n");
                scanf("%s", mail);
                printf("Ingrese la direccion del usuario:\n");
                scanf("%s", direccion);
                printf("Ingrese el telefono del usuario:\n");
                scanf("%s", telefono);
                registro = fopen(lista, "a");
                fprintf(registro, "%s %s %s\n", nombre, apellido, telefono);
                fclose(registro);  
                break;
        case 5: break;
        default: printf("La opcion elegida no existe.\n");
    }

    return 0;
}