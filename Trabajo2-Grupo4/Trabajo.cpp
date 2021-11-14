#include<string>
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
	cout<<"****************************\nSOLO PERSONAL AUTORIZADO\nIngrese la cantidad de planes disponibles para vender:\n";
	cout<<"\n";
	cout<<"Listo para la venta por la web.\n";
	cout<<"****************************\n\n\n"; 
	cout<<"****************************\n";
	cout<<"Bienvenido!!!\nEsta web es para la contrataci�n de los planes telef�nicos de nuestra compa�ia.\n";
	cout<<"Para contratar uno de los planes disponibles se le pedir�n sus datos para seguir con el proceso.\n"; 
	cout<<"****************************\n\n";
	mayordeedad();
}


void mayordeedad(){
	int edadIngresada;
	jos:
  	cout<<"Ingrese su Edad (Debe ser mayor de edad para optar a la contrataci�n de un plan)\n"; 
  	cin>>edadIngresada; 
  	if (edadIngresada >= 18){ 
	    cout<<"Usted puede seguir adelante:\n\n"; 
	    menu();
    } else{
       cout<<"Usted no tiene la edad suficiente para poder contratar un plan tel�fonico.\n\n";
       goto jos;
    }
}

void tomaDeDatos(){

int r=0;

cout<<"A continuaci�n se van a tomar sus datos para la contrataci�n del plan:\n\n";
cout<<"Indique su nombre y apellido\n";
cin>>ND[count].nombre>>ND[count].apellido;
cout<<"Indique su RUT\n";
cin>>ND[count].rut;
cout<<"Indique el n�mero de celular al que se cargar� el plan\n";
cin>>ND[count].celular;
cout<<"Indique su email\n";
cin>>ND[count].email;
cout<<"Indique su direcci�n de domicilio\n";
cin>>ND[count].direccion;
cout<<"Desea ingresar otra persona? 1-si 2-no"<<endl;
cin>>r;
if(r==1){
	count=+1;
	menu();
}else{
	in:
	r=0;
	cout<<"1-estadistias\n2-mostra datos\n3.buscar persona"<<endl;
	cin>>r;
	switch(r){
		case 1:
			estadistica();
			break;
		case 2:
			for(int x=0;x<=count+1;x++){
				cout<<"Nombre: "<<ND[x].nombre<<" Apellido: "<<ND[x].apellido<<endl;
				cout<<"Direccion: "<<ND[x].direccion<<" Celular: "<<ND[x].celular<<endl;
			}
			goto in;
			break;
		case 3:
			string n,p;
			cout<<"nombre y apellido de la persona a buscar: ";
			cin>>n>>p;
			for(int x=0;x<=count+1;x++){
				if(n==ND[x].nombre && p==ND[x].apellido){
					cout<<"ID: "<<(x+1)<<" Nombre: "<<ND[x].nombre<<" Apellido: "<<ND[x].apellido<<endl;
				}
			}
			goto in;
			break;
	}
}

}


void descripcionPlanes(){
cout<<"\n";
cout<<"Los siguientes planes tenemos disponibles para usted:\n\n";
cout<<"Plan 1 - Este plan otorga 50 GB de internet para libre uso, 500 minutos en llamadas y tiene un valor de 10000$\n\n";
cout<<"Plan 2 - Este plan otorga 100 GB de internet para libre uso, 1000 minutos en llamadas y tiene un valor de 15000$\n\n";
cout<<"Plan 3 - Este plan otorga GB ilimitados de internet para libre uso, minutos ilimitados para llamadas y tiene un valor de 22500$\n\n";
cout<<"En el siguiente Men� estan las opciones ya descritas, elija el n�mero de su opci�n a contratar:\n\n";
}

void menu(){
	int opcionElegir;
    cout<<"******************************\n";
    cout<<"------- Elecci�n Plan --------\n";
    cout<<"******************************\n";
    cout<<"1.- Plan 1\n";
    cout<<"2.- Plan 2\n";
    cout<<"3.- Plan 3\n";
    cout<<"4.- Ning�n Plan\n";
    cout<<"Ingrese el plan que quiere contratar:\n";
    cin>>opcionElegir;
    eleccion(opcionElegir);

}
 
void eleccion(int gg){

    switch(gg){
        case 1: cout<<"Usted contrat� el plan 1.\n\n";
                Plan1= Plan1 + 1;
                tomaDeDatos();
                break;
        case 2: cout<<"Usted contrat� el plan 2.\n\n";
                Plan2= Plan2 + 1;
                tomaDeDatos();
                break;
        case 3: cout<<"Usted contratat� el plan 3.\n\n";
                Plan3= Plan3 + 1;
                tomaDeDatos();
                break;    
        case 4: cout<<"Usted no contrat� ning�n plan.\n\n";
                ningunPlan= ningunPlan + 1;
                break;           
        default: cout<<"El usuario ingres� una opci�n que no es v�lida.\n\n\n";
    }
  
}


void estadistica(){
  
  // Mostramos la estad�stica por pantalla...
  cout<<"******************************\n";
  cout<<"Estad�sticas:\n";
  cout<<"******************************\n";
  
  cout<<"******************************\n";
  cout<<"Estad�sticas:\n";
  cout<<"******************************\n";
  
  
  /*Calculo de porcentaje de cada plan contratado por el n�mero total de planes por 100*/
  Plan1 = (Plan1/planes)*100;  
  Plan2 = (Plan2/planes)*100;
  Plan3 = (Plan3/planes)*100;
  cout<<endl;
  cout<<"Plan 1     "<<Plan1;
  cout<<"Plan 2     \n"<<Plan2;
  cout<<"Plan 3       \n\n"<<Plan3;
  cout<<endl;
  cout<<"Plan 1     \n"<<Plan1;
  cout<<"Plan 2     \n"<<Plan2;
  cout<<"Plan 3      \n\n"<<Plan3;
  
}
