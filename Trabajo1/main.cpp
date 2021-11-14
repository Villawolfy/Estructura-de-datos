/* Universidad de La Frontera
* Departamento de Ingeniería Eléctrica 
* IIE344-1: ESTRUCTURA DE DATOS Y ALGORITMOS
*
* Tarea 1
*
* Autores: José Díaz. (j.diaz26@ufromail.cl)
* Fernando Villalobos. (f.villalobos03@ufromail.cl)
* 
*
* Fecha: 26/09/2021
*
* Descripción general del programa: Este programa tiene el próposito de manejar un sistema de venta de planes telefónicos de una compañía, considerando que sea fácil de usar para el usuario y no tenga complicaciones al contratar su plan, también el programa guardará los datos de la persona que contratará el plan en un archivo y las estadísticas en porcentajes de los planes vendidos en otro archivo.
*/

#include <stdio.h>
#include <time.h>   
#include <string.h>
#include "funciones.h" 

// Variables auxiliares
float Planes=0; //Cantidad de planes disponibles
int opcionElegir; //opción elegida por el usuario
int edadIngresada; //edad ingresada por el usuario


// Programa
int main(){
  
// Creación del archivo de registro
crearArchivo(0);
// Pantalla de inicio
Planes = inicio();

// Inicio de ventas 
  for(int i = 0; i < Planes ; i++){    // Contador desde 0 hasta agotarse los planes disponibles

  // Pantalla de bienvenida
  bienvenida();

  // Pregunta de edad, en la cual se necesita ser mayor de edad para poder contratar un plan.
  mayordeedad(&edadIngresada);
  if(edadIngresada > 17){
  continue;
  }
  // Toma de datos del cliente para seguir con la contratación del plan
  if (edadIngresada > 17){
      tomaDeDatos(i, edadIngresada);
    } else {
      i = i - 1;
    }

  // Descripción de los planes
 descripcionPlanes();
   
  // Menu planes
  // Elección plan
  
}
// Acabandose los planes:
printf("No quedan planes teléfonicos disponibles para contratar\n");
crearArchivo(1);
estadistica();

return 0;
}