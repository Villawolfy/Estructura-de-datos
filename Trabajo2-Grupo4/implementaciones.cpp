#include <stdio.h>
#include "funciones.h"

// Variables para estadisticas 
float Plan1=0;
float Plan2=0;
float Plan3=0;
float ningunPlan=0;


// Variables de almacenamiento
char nombre[30];
char apellido[30];
char rut[15];
char celular[15];
char email[60];
char direccion[60];

// Variables auxiliares
int planes=0; //Cantidad de planes disponibles.

//Variables para modificacion de archivos.
FILE * registrar;


int inicio(){
/*
  * Nombre de la función: inicio.
  * Tipo de función: int.
  * Parámetros: No requiere parámetros.
  * Dato de retorno: “planes” de tipo int;
  * Descripción de la función: La función inicio() imprime la pantalla de inicio
  * del programa, donde se pregunta la cantidad de planes disponibles para la venta, y devuelve
  * la cantidad de planes que ingresó el usuario.
  */
printf("****************************\n");
printf("SOLO PERSONAL AUTORIZADO\n\n");
printf("Ingrese la cantidad de planes disponibles para vender:\n"); //Cantidad total de planes a la venta.
scanf("%d", &planes);
printf("\n");
printf("Listo para la venta por la web.\n");
printf("****************************\n\n\n"); 
return planes;
}

void bienvenida(){
 /*
  * Nombre de la función: bienvenida.
  * Tipo de función: void.
  * Parámetros: No requiere parámetros
  * Dato de retorno: no retorna datos
  * Descripción de la función: La función bienvenida() imprime por pantalla una bienvenida para el cliente.
  */
printf("****************************\n");
printf("Bienvenido!!!\nEsta web es para la contratacion de los planes telefonicos de nuestra compañia.\n");
printf("Para la contratacion de algun plan debe ser mayor de edad e ingresar algunos datos personales\n"); 
printf("****************************\n\n");
}

void mayordeedad(int* edadIngresada){ 
  /*
  * Nombre de la función: mayordeedad.
  * Tipo de función: void.
  * Parámetros: "edadIngresada" de tipo int.
  * Dato de retorno: No retorna datos.
  * Descripción de la función: La función mayordeedad() sirve para ver si el cliente es mayor de edad
  * o no, en el caso de que si lo es puede seguir con la contratacion del plan, en caso contrario
  * no puede seguir con la contracion y se vuelve a la bienvenida del programa.
  */
  printf("Ingrese su Edad\n"); 
  scanf("%d", edadIngresada); 
  if ((*edadIngresada >= 18)){ 
    printf("Usted puede seguir adelante con la contratacion:\n\n"); 
  
    } else{
       printf("Usted no tiene la edad suficiente para poder contratar un plan telefonico.\n\n");
      
    }
}


void tomaDeDatos(int i, int edadIngresada){
 /*
  * Nombre de la función: tomaDeDatos.
  * Tipo de función: void.
  * Parámetros: "i" de tipo int
  * Dato de retorno: No retorna datos
  * Descripción de la función: La función tomaDeDatos() pregunta al usuario sus datos personales, para la contratación de planes, y los almacena en el documento de texto.
  */
registrar = fopen("datos.txt", "a+"); // Creación de archivo para el guardado de datos del cliente.

printf("A continuacion se van a tomar sus datos para la contratacion del plan:\n\n"); //Pedido de datos del cliente.
printf("Indique su nombre y apellido (Con un espacio entre el nombre y el apellido)\n");
scanf("%s %s", &nombre, &apellido);
fprintf(registrar, nombre);
fprintf(registrar, " ");
fprintf(registrar, apellido);
fprintf(registrar, "|");

printf("Indique su RUT (Sin puntos ni guion\n");
scanf("%s", &rut);
fprintf(registrar, rut);
fprintf(registrar, "|");
printf("Indique el numero de celular al que se cargara el plan\n");
scanf("%s", &celular);
fprintf(registrar, celular);
fprintf(registrar, "|");
printf("Indique su email\n");
scanf("%s", &email);
fprintf(registrar, email);
fprintf(registrar, "|");
printf("Indique su direccion de domicilio (sin espacios al escribir la direccion)\n");
scanf("%s", &direccion);
fprintf(registrar, direccion);
fprintf(registrar, "|");
  
  
  printf("Ahora con la completacion de sus datos ya puede seguir con el proceso\n\n");
  fprintf(registrar, "\n\n");
  fclose(registrar);
}

void descripcionPlanes(){ 
  /*
  * Nombre de la función: descripcionPlanes.
  * Tipo de función: void.
  * Parámetros: No requiere parámetros
  * Dato de retorno: No retorna datos
  * Descripción de la función: La función descripcionPlanes() como dice su nombre describe los planes
  * disponibles para contratar.
  */
printf("\n");
printf("Los siguientes planes tenemos disponibles para usted:\n\n");
printf("Plan 1 - Este plan otorga 50 GB de internet para libre uso, 500 minutos en llamadas y tiene un valor de 10000$\n\n");
printf("Plan 2 - Este plan otorga 100 GB de internet para libre uso, 1000 minutos en llamadas y tiene un valor de 15000$\n\n");
printf("Plan 3 - Este plan otorga GB ilimitados de internet para libre uso, minutos ilimitados para llamadas y tiene un valor de 22500$\n\n");
printf("En el siguiente Menu estan las opciones ya descritas, elija el numero de su opcion a contratar:\n\n");
}

void menu(int* opcionElegir){
  /*
  * Nombre de la función: menu.
  * Tipo de función: void.
  * Parámetros: "opcionElegir" de tipo int
  * Dato de retorno: No retorna datos
  * Descripción de la función: La función menu() muestra los planes con su numero para que haga
  * la eleccion el cliente.
  */
    printf("******************************\n");
    printf("------- Eleccion Plan --------\n");
    printf("******************************\n");
    printf("1.- Plan 1\n");
    printf("2.- Plan 2\n");
    printf("3.- Plan 3\n");
    printf("4.- Ningun Plan\n");
    printf("Ingrese el plan que quiere contratar:\n");
    scanf("%d", opcionElegir);
    printf("\n");

}
 
void eleccion(int* opcionElegir){
/*
  * Nombre de la función: eleccion.
  * Tipo de función: void.
  * Parámetros: "opcionElegir" de tipo int
  * Dato de retorno: No retorna datos
  * Descripción de la función: La función eleccion() sirve para que el cliente elija el plan por
  * el que se decidio, se muestra por pantalla agradecimientos por la compañia y por último
  * al elegir un plan este suma una contratación que servira para las estadisticas finales.
  */
    switch(*opcionElegir){
        case 1: printf("Usted contrato el plan 1.\nEn menos de 24 horas su plan ya estara cargado al numero telefonico que ingreso en sus datos.\n");
                printf("Muchas gracias por la contratacion de nuestros servicios, que tenga una excelente semana y disfrute nuestro plan.\n\n");
                Plan1= Plan1 + 1;
                break;
        case 2: printf("Usted contrato el plan 2.\nEn menos de 24 horas su plan ya estara cargado al numero telefonico que ingreso en sus datos.\n");
                printf("Muchas gracias por la contratacion de nuestros servicios, que tenga una excelente semana y disfrute nuestro plan.\n\n");
                Plan2= Plan2 + 1;
                break;
        case 3: printf("Usted contrato el plan 3.\nEn menos de 24 horas su plan ya estara cargado al numero telefonico que ingreso en sus datos.\n");
                printf("Muchas gracias por la contratacion de nuestros servicios, que tenga una excelente semana y disfrute nuestro plan.\n\n");
                Plan3= Plan3 + 1;
                break;    
        case 4: printf("Usted no contrato ningun plan.\n");
                printf("Esperamos que proximamente decida contratar algun plan, que tenga una excelenta semana.\n\n");
                ningunPlan= ningunPlan + 1;
                break;           
        default: printf("El usuario ingreso una opcion que no es valida.\n\n\n");
              
    }
  
}

void estadistica(){
 /*
  * Nombre de la función: estadistica.
  * Tipo de función: void.
  * Parámetros: No requiere parámetros
  * Dato de retorno: No retorna datos
  * Descripción de la función: La función estadistica() calcula las estadísticas de los datos
  * y la muestra por pantalla
  */
  
  registrar = fopen("estadisticas.txt", "a+"); //Creación de archivo para el guardado de estadísticas

  // Mostramos la estadística por pantalla
  printf("******************************\n");
  printf("Estadisticas:\n");
  printf("******************************\n");
  fprintf(registrar, "******************************\n");
  fprintf(registrar, "Estadísticas:\n");
  fprintf(registrar, "******************************\n");
  
  /*Cantidad de clientes en contratar un plan o no:*/
  printf("La cantidad de clientes en contratar algun plan o no es de: %d clientes.\n\n", planes);
  fprintf(registrar, "La cantidad de clientes en contratar algun plan o no es de: %d clientes.\n\n", planes);

  /*Calculo de porcentaje de cada plan contratado por el número total de planes por 100*/
  printf("Porcentajes de contratacion de cada plan por el numero total de clientes:\n\n");
  fprintf(registrar, "porcentajes de contratacion de cada opcion:\n");
  Plan1 = (Plan1/planes)*100;  
  Plan2 = (Plan2/planes)*100;
  Plan3 = (Plan3/planes)*100;
  ningunPlan = (ningunPlan/planes)*100;
  printf("               %c\n", 37);
  printf("Plan 1         %.2f\n", Plan1);
  printf("Plan 2         %.2f\n", Plan2);
  printf("Plan 3         %.2f\n", Plan3);
  printf("Ningun plan    %.2f\n\n\n", ningunPlan);

  //Guardado de los porcentajes en el archivo
  fprintf(registrar, "             %c\n", 37);
  fprintf(registrar, "Plan 1       %.2f\n", Plan1);
  fprintf(registrar, "Plan 2       %.2f\n", Plan2);
  fprintf(registrar, "Plan 3       %.2f\n", Plan3);
  fprintf(registrar, "Ningun plan  %.2f\n\n", ningunPlan);

  if ((Plan1 > Plan2) && (Plan1 > Plan3)){
        printf("El Plan 1 es el plan mas vendido.\n");
        fprintf(registrar, "El Plan 1 es el plan mas vendido.\n");
  } else if((Plan2 > Plan1) && (Plan2 > Plan3)){
        printf("El Plan 2 es el plan mas vendido.\n");
        fprintf(registrar, "El Plan 2 es el plan mas vendido.\n");
  } else{  
        printf("El Plan 3 es el plan mas vendido.\n");
        fprintf(registrar, "El Plan 3 es el plan mas vendido.\n");
  }
  


  fclose(registrar); //Cerrar archivo

}









