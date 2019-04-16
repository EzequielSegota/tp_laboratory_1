#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarEstado(EPersona lista[], int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        lista[i].estado=0;
        strcpy(lista[i].nombre,"");
        lista[i].edad=0;
        lista[i].dni=0;
    }
}

int obtenerEspacioLibre(EPersona lista[], int largo)
{
    int i, posicionVacia=-1;

    for(i=0;i<largo;i++)
    {
        if(lista[i].estado==0)
        {
            posicionVacia=i;
            break;
        }
    }
    return posicionVacia;
}


void altaPersona(EPersona lista[],int largo)
{
    int vacio;

    vacio=obtenerEspacioLibre(lista, largo);

    if(vacio!=-1)
    {
        lista[vacio].estado=1;

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(lista[vacio].nombre);

        printf("\nIngrese edad: ");
        scanf("%d",&lista[vacio].edad);

        printf("\nIngrese DNI: ");
        scanf("%d",&lista[vacio].dni);
    }
    else
    {
	printf("\nError, no hay espacio disponible");
    }
}

void bajaPersona(EPersona lista[],int largo)
{
    int i;
    int indice;
    int dni;

    for(i=0;i<largo;i++)
    {
        printf("Nombre: %s -- Edad: %d -- DNI: %d\n",lista[i].nombre, lista[i].edad, lista[i].dni);
    }

    do{
        printf("Ingrese dni para eliminar: ");
        scanf("%d",&dni);
        indice=buscarPorDni(lista, largo,dni);
    }while(indice==-1);

    lista[indice].estado=0;
    strcpy(lista[indice].nombre,"");
    lista[indice].edad=0;
    lista[indice].dni=0;
}

int buscarPorDni(EPersona lista[], int largo, int dni)
{
    int i, indice=-1;

    for(i=0;i<largo;i++)
    {
        if(dni==lista[i].dni)
        {
            indice=i;
            break;
        }
        else if(i==largo-1)
            printf("Error DNI inexistente ");
    }

    return indice;
}

void imprimirNombre(EPersona lista[],int largo)
{
    int i,j,auxEstados=0,auxEnt,auxComp;
    char auxNombre[50];

    for(i=0;i<largo;i++)
    {
        if(lista[i].estado==1)
        {
            auxEstados++;
        }
    }
    for(i=0;i<auxEstados;i++)
    {
        for(j=i+1;j<auxEstados;j++)
        {
            auxComp=stricmp(lista[j].nombre,lista[i].nombre);
            if(auxComp==-1)
            {
                //Nombres
                strcpy(auxNombre,lista[j].nombre);
                strcpy(lista[j].nombre,lista[i].nombre);
                strcpy(lista[i].nombre,auxNombre);
                //Edad
                auxEnt=lista[j].edad;
                lista[j].edad=lista[i].edad;
                lista[i].edad=auxEnt;
                //DNI
                auxEnt=lista[j].dni;
                lista[j].dni=lista[i].dni;
                lista[i].dni=auxEnt;
            }
        }
    }


    for(i=0;i<auxEstados;i++)
    {
        printf("Nombre: %s Edad: %d DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
    }
}

void imprimirGrafica(EPersona lista[], int largo)
{
    int i, j, cantidad=0, cantidadDos=0, cantidadTres=0, masAlto=0, cantidades[21], filas;
    //Saco cantidades de usuarios con distintas edades
    for(i=0;i<largo;i++)
    {
        if(lista[i].edad<18 && lista[i].estado==1)
        {
            cantidad+=1;
        }

        if(lista[i].edad>=19 && lista[i].edad<=35 && lista[i].estado==1)
        {
            cantidadDos+=1;
        }

        if(lista[i].edad>35 && lista[i].estado==1)
        {
            cantidadTres+=1;
        }
    }
    //las posiciono dentro del Vector
	cantidades[1]=cantidad;
	cantidades[2]=cantidadDos;
	cantidades[3]=cantidadTres;
    //Encuentro el mayor
    for(i=1;i<=3;i++)
    {
        if (masAlto < cantidades[i])
        {
            masAlto = cantidades[i];
        }
    }
    //uso filas de aux
	filas = masAlto;
    //Imprimo
	for (i = 0; i < masAlto; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (cantidades[j] >= filas)
			{
				printf(" *        ");
			}
			else
			{
				printf("          ");
			}
		}
		//Uno menos que iterar
		filas = filas - 1;
		printf("\n");
	}

    printf("<18      ");
    printf("19-35      ");
    printf(">35\n");
}
