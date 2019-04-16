#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define largo 20


int main()
{
    char seguir='s';
    int opcion=0;

    EPersona lista[largo];
    inicializarEstado(lista, largo);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                altaPersona(lista,largo);
                break;
            case 2:
                bajaPersona(lista,largo);
                break;
            case 3:
                imprimirNombre(lista,largo);
                break;
            case 4:
                imprimirGrafica(lista,largo);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
