#include <stdio.h>
#include <string.h>

struct Cliente
{
    char nombre [15];
    char apellido [15];
    char rut [13];
    int clave;
    char email[50];
    char direccion[50];
    long telefono;
};
void ingresarCliente(Cliente* c);
Cliente crearCliente(); 

int main(){
    Cliente ejemplo;
    ingresarCliente(&ejemplo);
    printf("Los datos del cliente son:\n");
    printf("%s\n", ejemplo.nombre);
    printf("%s\n", ejemplo.apellido);
    printf("%s\n", ejemplo.rut);
    printf("%d\n", ejemplo.clave);
    printf("%s\n", ejemplo.email);
    printf("%s\n", ejemplo.direccion);
    printf("%lu\n", ejemplo.telefono);
    
    return 0;
}

void ingresarCliente(Cliente* c){
    printf("Ingrese el nombre del cliente\n");
    scanf("%s", c->nombre);
    printf("Ingrese el apellido del cliente\n");
    scanf("%s", c->apellido);
    printf("Ingrese el rut del cliente\n");
    scanf("%s", c->rut);
    printf("Ingrese el clave del cliente\n");
    scanf("%d", c->clave);
    printf("Ingrese el e-mail del cliente\n");
    scanf("%s", c->email);
    printf("Ingrese la direccion del cliente\n");
    scanf("%s", c->direccion);
    printf("Ingrese el telefono del cliente\n");
    scanf("%lu", c->telefono);
}