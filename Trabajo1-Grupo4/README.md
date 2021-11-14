# WEB PARA VENTA DE PLANES
El siguiente programa se utiliza para la venta de planes teléfonicos de una compañía, considerando que sea fácil de usar para el usuario y no tenga complicaciones al contratar su plan, también este programa debe guardar las estadísticas de los planes contratados en porcentajes, para tener una idea de cuál plan es el más vendido y para futuras nuevas opciones, y también los datos de cada persona que contrata un plan.


## Compilador
Para compilar, se recomienda ejecutar los comandos de GitBash en el siguiente orden:
```bash
g++ -c implementaciones.cpp
g++ -c main.cpp
g++ -o ejecutable implementaciones.o main.o
./ejecutable  //Para ejecutar el programa
```

## Créditos
Este programa fue desarrollado por:
* José Díaz. (j.diaz26@ufromail.cl)
* Fernando Villalobos. (f.villalobos03@ufromail.cl)

Desarrollado en el departamento de Ingerniería Eléctrica de la Universidad de la Frontera, para el  ramo de estructura de datos y algoritmos, con el apoyo del profesor Matthias Clein.

## Listado de cambios
### [23/09/2021] 
#### v1.0b:
   * Versión inestable, que necesita modificaciones para funcionar bien
   * Archivo README básico sin formato
   * Separación del programa en main.cpp , implementaciones.cpp y funciones.h
### [25/09/2021] 
#### v1.1b:
   * Corregido un error en la funcion de la edad ingresada
   * README mejorado
   * Se agregó el listado de cambios por versión al README
   * Versión estable
   
### [26/09/2021] 
#### v1.2b:
   * Manejo de archivos para datos personales
   * Los datos se guardan en un archivo "datos.txt"
   * Manejo de archivos para estadisticas de los planes contratados
   * Las estadisticas se guardan en un archivo "estadisticas.txt"
   * Version terminada y declarada como estable
