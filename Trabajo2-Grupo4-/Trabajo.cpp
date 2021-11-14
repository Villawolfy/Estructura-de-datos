#include<string.h>
#include <stdio.h>
#include<iostream>
using namespace std;


float Plan1=0,Plan2=0,Plan3=0,ningunPlan=0,planes=0,Planes=0;
int count=0;
void hola();
void mayordeedad();
void tomaDeDatos();
void descripcionPlanes();
void menu();
void estadistica();
void eleccion(int gg);

struct NODO{
string nombre,apellido,rut,celular,email,direccion;
};
NODO ND[50];
main(){ 
	hola();
}

void hola(){
	int planes;
	printf("****************************\nSOLO PERSONAL AUTORIZADO\nIngrese la cantidad de planes disponibles para vender:\n");
	printf("\n");
	printf("Listo para la venta por la web.\n");
	printf("****************************\n\n\n"); 
	printf("****************************\n");
	printf("Bienvenido!!!\nEsta web es para la contrataci�n de los planes telef�nicos de nuestra compa�ia.\n");
	printf("Para contratar uno de los planes disponibles se le pedir�n sus datos para seguir con el proceso.\n"); 
	printf("****************************\n\n");
	mayordeedad();
}


void mayordeedad(){
	int edadIngresada;
	jos:
  	printf("Ingrese su Edad (Debe ser mayor de edad para optar a la contrataci�n de un plan)\n"); 
  	scanf("%d", &edadIngresada); 
  	if (edadIngresada >= 18){ 
	    printf("Usted puede seguir adelante:\n\n"); 
	    menu();
    } else{
       printf("Usted no tiene la edad suficiente para poder contratar un plan tel�fonico.\n\n");
       goto jos;
    }
}

void tomaDeDatos(){

int r=0;

printf("A continuaci�n se van a tomar sus datos para la contrataci�n del plan:\n\n");
printf("Indique su nombre y apellido\n");
scanf("%s %s", ND[count].nombre, ND[count].apellido);
printf("Indique su RUT\n");
scanf("%d",ND[count].rut);
printf("Indique el n�mero de celular al que se cargar� el plan\n");
scanf("%d",ND[count].celular);
printf("Indique su email\n");
scanf("%s",ND[count].email);
printf("Indique su direcci�n de domicilio\n");
scanf("%s",ND[count].direccion);
printf("Desea ingresar otra persona? 1-si 2-no\n");
cin>>r;
if(r==1){
	count=+1;
	menu();
}else{
	in:
	r=0;
	printf("1-estadistias\n2-mostra datos\n3.buscar persona\n");
	cin>>r;
	switch(r){
		case 1:
			estadistica();
			break;
		case 2:
			for(int x=0;x<=count+1;x++){
				printf("Nombre: \n", &ND[x].nombre, " Apellido: \n", &ND[x].apellido);
				printf("Direccion: \n", &ND[x].direccion, " Celular: \n", &ND[x].celular);
			}
			goto in;
			break;
		case 3:
			string n,p;
			printf("nombre y apellido de la persona a buscar: ");
			cin>>n>>p;
			for(int x=0;x<=count+1;x++){
				if(n==ND[x].nombre && p==ND[x].apellido){
					printf("ID: \n", (x+1), " Nombre: \n", ND[x].nombre, " Apellido: \n",ND[x].apellido);
				}
			}
			goto in;
			break;
	}
}

}


void descripcionPlanes(){
printf("\n");
printf("Los siguientes planes tenemos disponibles para usted:\n\n");
printf("Plan 1 - Este plan otorga 50 GB de internet para libre uso, 500 minutos en llamadas y tiene un valor de 10000$\n\n");
printf("Plan 2 - Este plan otorga 100 GB de internet para libre uso, 1000 minutos en llamadas y tiene un valor de 15000$\n\n");
printf("Plan 3 - Este plan otorga GB ilimitados de internet para libre uso, minutos ilimitados para llamadas y tiene un valor de 22500$\n\n");
printf("En el siguiente Men� estan las opciones ya descritas, elija el n�mero de su opci�n a contratar:\n\n");
}

void menu(){
	int opcionElegir;
    printf("******************************\n");
    printf("------- Elecci�n Plan --------\n");
    printf("******************************\n");
    printf("1.- Plan 1\n");
    printf("2.- Plan 2\n");
    printf("3.- Plan 3\n");
    printf("4.- Ning�n Plan\n");
    printf("Ingrese el plan que quiere contratar:\n");
    scanf("%d", &opcionElegir);
    eleccion(opcionElegir);

}
 
void eleccion(int gg){

    switch(gg){
        case 1: printf("Usted contrat� el plan 1.\n\n");
                Plan1= Plan1 + 1;
                tomaDeDatos();
                break;
        case 2: printf("Usted contrat� el plan 2.\n\n");
                Plan2= Plan2 + 1;
                tomaDeDatos();
                break;
        case 3: printf("Usted contratat� el plan 3.\n\n");
                Plan3= Plan3 + 1;
                tomaDeDatos();
                break;    
        case 4: printf("Usted no contrat� ning�n plan.\n\n");
                ningunPlan= ningunPlan + 1;
                break;           
        default: printf("El usuario ingres� una opci�n que no es v�lida.\n\n\n");
    }
  
}


void estadistica(){
  
  // Mostramos la estad�stica por pantalla...
  printf("******************************\n");
  printf("Estad�sticas:\n");
  printf("******************************\n");
  
  printf("******************************\n");
  printf("Estad�sticas:\n");
  printf("******************************\n");
  
  
  /*Calculo de porcentaje de cada plan contratado por el n�mero total de planes por 100*/
  Plan1 = (Plan1/planes)*100;  
  Plan2 = (Plan2/planes)*100;
  Plan3 = (Plan3/planes)*100;
  printf("\n");
  cout<<"Plan 1     "<<Plan1;
  cout<<"Plan 2     \n"<<Plan2;
  cout<<"Plan 3       \n\n"<<Plan3;
  printf("\n");
  printf("Plan 1     \n", &Plan1);
  printf("Plan 2     \n", &Plan2);
  printf("Plan 3      \n\n", &Plan3);
  
}
