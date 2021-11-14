#ifndef LISTA_STRUCT_H
#define LISTA_STRUCT_H

#define tipoDato int

struct cliente{
    char nombre[30];
    char apellido[30];
    char rut[15];
    char celular[15];
    char email[60];
    char direccion[60];
};

#define tipoDato cliente

struct nodo{
	tipoDato dato;
	struct nodo* next;
	nodo(){
		next=NULL;
	}
	nodo(tipoDato x){
		nodo();
		dato=x;
	}
};

struct Lista{
	struct nodo* primero;
	Lista(){
		primero=NULL;
	}
};


#endif