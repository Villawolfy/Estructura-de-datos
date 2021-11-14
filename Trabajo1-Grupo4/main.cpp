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
*Descripción general del programa: Este programa tiene el próposito de manejar
*un sistema de venta de planes telefónicos de una compañía,
*considerando que sea fácil de usar y amigable para el usuario y no tenga complicaciones
*al contratar su plan, también el programa guardará los datos de la persona que
*contratará el plan en un archivo para poder realizar bien el proceso 
*y las estadísticas en porcentajes de los planes vendidos en otro archivo, que permitira
*saber cuantas personas han contratado planes y cual es el plan más vendido por la compañía.
*/

#include <stdio.h>
#include "funciones.h" 

// Variables auxiliares
int Planes=0; //Cantidad de planes disponibles
int opcionElegir; //opción elegida por el usuario
int edadIngresada; //edad ingresada por el usuario


// Programa
int main(){
  

// Pantalla de inicio
Planes = inicio();

// Inicio de ventas 
  for(int i = 0; i < Planes ; i++){    // Contador desde 0 hasta agotarse los planes disponibles

  // Pantalla de bienvenida
  bienvenida();

  // Pregunta de edad, en la cual se necesita ser mayor de edad para poder contratar un plan.
  mayordeedad(&edadIngresada);
  if(edadIngresada < 18){  //Si es menor de edad el contador sigue intacto
  i --; 
  continue;
  }

  // Toma de datos del cliente para seguir con la contratación del plan
  if (edadIngresada >= 18){
      tomaDeDatos(i, edadIngresada);
  } else {
      i = i - 1;
  }

  // Descripción de los planes
 descripcionPlanes();
   
  // Menu planes disponibles
  menu(&opcionElegir);

  // Elección plan
  eleccion(&opcionElegir);
  
  }

// Acabandose los planes:
printf("No quedan mas planes telefonicos disponibles para la venta.\n\n");
printf("Proximamente tendremos mas planes disponibles y variedad.\n\n");
estadistica(); //Muestra las estadisticas de los planes contratados.

return 0;
}