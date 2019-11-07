#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* this = employee_new();
    int cantidad;
    char auxId[50], auxNombre[50], auxHorasTrabajadas[50], auxSueldo[50];
    cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    while(!feof(pFile))
    {
        cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        if(cantidad == 4)
        {
            this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, this);
        }
        else if(cantidad != 4)
        {
            if(!feof(pFile))
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else
            {
                printf("\nSe leyo todo el archivo.");
            }
        }
    }
    printf("\n --> Empleados cargados correctamente.\n\n");
    fclose(pFile);
    return 1;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
