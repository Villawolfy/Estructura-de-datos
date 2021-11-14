#include <stdio.h>
#include "usuarioStruct.h"
int main(){
    saludo();
    despedida();
    User a;
    a.edad = 20;
    printf("la edad del usuario es %d\n", a.edad);
    return 0;
}