#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));
    if(this == NULL)
    {
        printf("No hay lugar para crear nuevo empleado.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int auxHorasTrabajadas;
    int auxId;
    float auxSueldo;
    int flag = 1;
    Employee* this = employee_new();

    this = employee_new();
    auxId = atoi(idStr);
    if(employee_setId(this,auxId)!= 1)
    {
        flag=0;
    }
    auxHorasTrabajadas = atoi(horasTrabajadasStr);
    if(employee_setHorasTrabajadas(this,auxHorasTrabajadas)!= 1)
    {
        flag=0;
    }
    if(employee_setNombre(this,nombreStr)!= 1)
    {
        flag=0;
    }
    auxSueldo = atof(sueldoStr);
    if(employee_setSueldo(this, auxSueldo)!=1)
    {
        this->sueldo = auxSueldo;
        flag=0;
    }

    return this;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id){
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
    int retorno = 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas != NULL){
        *horasTrabajadas=this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo != NULL){
        *sueldo=this->sueldo;
        retorno = 1;
    }
    return retorno;
}
