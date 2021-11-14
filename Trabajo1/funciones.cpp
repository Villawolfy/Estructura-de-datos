#include <stdio.h>
#include <time.h>
#include <string.h>
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
char celular[14];
char email[50];
char direccion[50];

// Variables auxiliares
float planes=0; //Cantidad de planes disponibles
char DatosContratoPlan[30]; //  Nombre para el archivo de registro (con la respectiva ubicación)

// Variables para almacenar respuestas
FILE* registrar;


float inicio(){
printf("****************************\nSOLO PERSONAL AUTORIZADO\nIngrese la cantidad de planes disponibles para vender:\n");
scanf("%f", &planes);
printf("\n");
printf("Listo para la venta por la web.\n");
printf("****************************\n\n\n"); 
return planes;
}

void bienvenida(){
printf("****************************\n");
printf("Bienvenido!!!\nEsta web es para la contratación de los planes telefónicos de nuestra compañia.\n");
printf("Para contratar uno de los planes disponibles se le pedirán sus datos para seguir con el proceso.\n"); 
printf("****************************\n\n");
}

void mayordeedad(int* edadIngresada){ 
  printf("Ingrese su Edad (Debe ser mayor de edad para optar a la contratación de un plan)\n"); 
  scanf("%d", &edadIngresada); 
  if ((*edadIngresada >= 18)){ 
    printf("Usted puede seguir adelante:\n\n"); 
    menu();
    } else{
       printf("Usted no tiene la edad suficiente para poder contratar un plan teléfonico.\n\n");
       
    }
}

void tomaDeDatos(int i, int edadingresada){
printf("A continuación se van a tomar sus datos para la contratación del plan:\n\n");
printf("Indique su nombre y apellido\n");
scanf("%s %s", &nombre, &apellido);
printf("Indique su RUT\n");
scanf("%s", &rut);
printf("Indique el número de celular al que se cargará el plan\n");
scanf("%s", &celular);
printf("Indique su email\n");
scanf("%s", &email);
printf("Indique su dirección de domicilio\n");
scanf("%s", &direccion);

registrar = fopen(DatosContratoPlan, "a+");
  fprintf(registrar, "%s", apellido);
  fprintf(registrar, "|");
  fprintf(registrar, "%s",  nombre);
  fprintf(registrar, "|");
  fprintf(registrar, "%s", rut);
  fprintf(registrar, "|");
  fprintf(registrar, "%s", celular);
  fprintf(registrar, "|");
  fprintf(registrar, "%s", email);
  fprintf(registrar, "|");
  fprintf(registrar, "%s", direccion);
  fprintf(registrar, "|");
  
  printf("Su número de atención es el %d\n\n\n", i + 1);
  fprintf(registrar, "\n\n");
  fclose(registrar);
}


void descripcionPlanes(){
printf("\n");
printf("Los siguientes planes tenemos disponibles para usted:\n\n");
printf("Plan 1 - Este plan otorga 50 GB de internet para libre uso, 500 minutos en llamadas y tiene un valor de 10000$\n\n");
printf("Plan 2 - Este plan otorga 100 GB de internet para libre uso, 1000 minutos en llamadas y tiene un valor de 15000$\n\n");
printf("Plan 3 - Este plan otorga GB ilimitados de internet para libre uso, minutos ilimitados para llamadas y tiene un valor de 22500$\n\n");
printf("En el siguiente Menú estan las opciones ya descritas, elija el número de su opción a contratar:\n\n");
}

void menu(){
  int opcionElegir;
    printf("******************************\n");
    printf("------- Elección Plan --------\n");
    printf("******************************\n");
    printf("1.- Plan 1\n");
    printf("2.- Plan 2\n");
    printf("3.- Plan 3\n");
    printf("4.- Ningún Plan\n");
    printf("Ingrese el plan que quiere contratar:\n");
    scanf("%d", &opcionElegir);
    eleccion(opcionElegir);

}
 
void eleccion(int opcionElegir){

    switch(opcionElegir){
        case 1: printf("Usted contrató el plan 1.\n\n");
                Plan1= Plan1 + 1;
                break;
        case 2: printf("Usted contrató el plan 2.\n\n");
                Plan2= Plan2 + 1;
                break;
        case 3: printf("Usted contratató el plan 3.\n\n");
                Plan3= Plan3 + 1;
                break;    
        case 4: printf("Usted no contrató ningún plan.\n\n");
                ningunPlan= ningunPlan + 1;
                break;           
        default: printf("El usuario ingresó una opción que no es válida.\n\n\n");
    }
  
}


void estadistica(){
  
  // Mostramos la estadística por pantalla...
  printf("******************************\n");
  printf("Estadísticas:\n");
  printf("******************************\n");
  registrar = fopen(DatosContratoPlan, "a+");
  fprintf(registrar, "******************************\n");
  fprintf(registrar, "Estadísticas:\n");
  fprintf(registrar, "******************************\n");
  
  
  /*Calculo de porcentaje de cada plan contratado por el número total de planes por 100*/
  Plan1 = (Plan1/planes)*100;  
  Plan2 = (Plan2/planes)*100;
  Plan3 = (Plan3/planes)*100;
  printf("            %c\n", 37);
  printf("Plan 1     %.2f\n", Plan1);
  printf("Plan 2     %.2f\n", Plan2);
  printf("Plan 3       %.2f\n\n", Plan3);
  fprintf(registrar, "            %c\n", 37);
  fprintf(registrar, "Plan 1     %.2f\n", Plan1);
  fprintf(registrar, "Plan 2     %.2f\n", Plan2);
  fprintf(registrar, "Plan 3      %.2f\n\n", Plan3);
  


  fclose(registrar);
}


void crearArchivo(int datos){

  time_t rawtime;
  struct tm * timeinfo;
    
  char strMonth[5], strDay[5], strYear[5];

  time( &rawtime );
  timeinfo = localtime(&rawtime);
    
  sprintf(strYear, "%d", (timeinfo->tm_year+1900));
  sprintf(strMonth, "%02d", timeinfo->tm_mon+1);
  sprintf(strDay, "%02d", timeinfo->tm_mday);

  if (datos==0){
    strcpy(DatosContratoPlan, "./datos/");
  } else {
    strcpy(DatosContratoPlan, "./estadisticas/");
  }
  strcat(DatosContratoPlan, strYear);
  strcat(DatosContratoPlan, strMonth);
  strcat(DatosContratoPlan, strDay);
  strcat(DatosContratoPlan, ".txt");
    
  registrar = fopen(DatosContratoPlan, "a+");
  fclose(registrar);
}

