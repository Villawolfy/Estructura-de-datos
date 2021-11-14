#include <stdio.h>

int main(){
    int* numero1 = new int; //crea el puntero n1 y le asigna direccion de memoria
    int* numero2 = new int; //crea el puntero n2 y le asigna direccion de memoria
    int* suma = new int; // crea el puntero suma y le asigna direccion de memoria

    printf("Ingrese el primer número:\n"); // pido el primer numero
    scanf("%d", numero1); // Leo el primer numero(no se utiliza & porque numero1 ya esla dir. de memoria)
    printf("Ingrese el segundo número:\n");
    scanf("%d", numero2);

    *suma = *numero1 + *numero2;
    /* al contenido de la dir de memoria */
    printf("El resultado de la suma entre %d y %d es: %d\n", *numero1, *numero2, *suma);
    delete numero1;
    delete numero2;
    delete suma;

    return 0;
}