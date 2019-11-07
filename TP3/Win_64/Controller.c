#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


int menu()
{
    system("cls");
    int opcion;
    printf("   Opciones:\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
    opcion = getValidInt("Ingrese opcion: ", "Error de ingreso, reintente.\n");
    return opcion;
}


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "r")) == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        retorno = 1;
    }
    parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf("  ALTA DE EMPLEADO \n\n");
    char auxId[128], auxNombre[128], auxHorasTrabajadas[128], auxSueldo[128];
    Employee* this = employee_new();
    getStringNumeros("Ingrese ID: ", auxId);
    getValidStringRango("Ingrese nombre: ", "Error de ingreso, reintente.", auxNombre, 128);
    getStringNumeros("Ingrese horas trabajadas: ", auxHorasTrabajadas);
    getStringNumerosFlotantes("Ingrese sueldo: ", auxSueldo);
    this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    ll_add(pArrayListEmployee, this);
    printf("\n");
    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char confirmacion;
    int idEmpleado;
    int opcion;

    char auxNombre[51];
    int auxHorasT;
    int* auxHorasActuales;
    auxHorasActuales=malloc(sizeof(int*));
    float auxSueldo;
    float* sueldoActual;
    sueldoActual=malloc(sizeof(float*));
    char name[51];
    Employee* this;
    system("cls");
    printf(" MODIFICAR EMPLEADO \n\n");
    idEmpleado = getValidInt("Ingrese ID: ", "Error de ingreso. Reintente.");
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
        {
            retorno = 1;
            break;
        }
    }
    if(retorno == 1){
        printf("\n     ID |      Nombre  | H. Trabajadas |     Sueldo\n\n");
        printf("\n   %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        printf("\n Menu de opciones\n\n1- Modificar nombre\n2- Modificar horas trabajadas\n3- Modificar sueldo\n4- Salir\n\n");
        opcion = getValidIntRango("Ingrese opcion: ", "Error de ingreso. Reintente.", 1, 4);
    }
    do
    {
        switch(opcion)
        {
        case 1:
            printf("\nModificar nombre\n\n");
            getValidStringRango("Ingrese nuevo nombre: ", "Error, solo se admiten letras.\n", auxNombre, 51);
            employee_getNombre(this, name);
            printf("\nSe modificara \"%s\" por \"%s\"\n\n", auxNombre, name);
            fflush(stdin);
            confirmacion = getValidChar("Confirma la modificacion (s/n)?: ", "\nError de ingreso. Reintente.\n", 's', 'n');
            if(confirmacion == 's'){
                employee_setNombre(this, auxNombre);
                printf("Se modifico el nombre con exito.\n\n");
            }
            else{
                printf("Se cancelo la modificacion del nombre.\n\n");
            }
            break;
        case 2:
            printf("\nModificar Horas trabajadas\n\n");
            auxHorasT=getValidInt("Ingrese cantidad de horas:","Error de ingreso, reintente.\n");
            employee_getHorasTrabajadas(this,auxHorasActuales);
            printf("\nSe modificara \"%d\" por \"%d\"\n\n",*auxHorasActuales, auxHorasT);
            fflush(stdin);
            confirmacion = getValidChar("Confirma la modificacion (s/n)?: ", "\nError de ingreso. Reintente.\n", 's', 'n');
            if(confirmacion == 's'){
                employee_setHorasTrabajadas(this, auxHorasT);
                printf("Se modifico las horas con exito.\n\n");
            }
            else{
                printf("Se cancelo la modificacion de las horas trabajadas.\n\n");
            }
            break;
        case 3:
            printf("\nModificar Sueldo\n\n");
            auxSueldo=getValidFloat("Ingrese nuevo sueldo:","Error de ingreso, reintente.\n");
            employee_getSueldo(this,sueldoActual);
            printf("\nSe modificara \"%f\" por \"%f\"\n\n",*sueldoActual, auxSueldo);
            fflush(stdin);
            confirmacion = getValidChar("Confirma la modificacion (s/n)?: ", "\nError de ingreso. Reintente.\n", 's', 'n');
            if(confirmacion == 's'){
                employee_setSueldo(this, auxSueldo);
                printf("Se modifico el sueldo con exito.\n\n");
            }
            else{
                printf("Se cancelo la modificacion del sueldo.\n\n");
            }
            break;
        case 4:
            system("cls");
            printf("\nAdios!");
            break;
        default:
            printf("\nError de ingreso.\n\n");
        }
    }while(opcion!=4);

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char confirmacion;
    Employee* this;
    int idEmpleado;
    system("cls");
    printf(" BAJA DE EMPLEADO\n\n");
    idEmpleado = getValidInt("Ingrese ID: ", "Error de ingreso. Reintente.");
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
            {
            printf("\n   ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
            printf("\n %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
            confirmacion = getValidChar("\nDesea eliminar al empleado (s/n)?: ", "\nError, ingreso un caracter no valido, reintente.", 's', 'n'); //Pido y valido confirmacion de baja
            if(confirmacion == 's')
            {
                ll_remove(pArrayListEmployee, i);
                printf("\nEmpleado dado de baja con exito.\n\n");
            }
            else
            {
                printf("\nSe cancelo la baja del empleado\n\n");
            }
            retorno = 1;
            break;
        }
    }
    if(retorno == 0)
    {
        printf("\nNo hay empleados con el ID ingresado.\n");
    }
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* this;
    system("cls");
    printf(" LISTA DE EMPLEADOS \n\n");
    printf("   ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = ll_get(pArrayListEmployee,i);
        printf(" %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo); //Imprimo this
        retorno = 1;
        if(i%100==0 && i!=0)
        {
            system("pause");
        }
    }
    printf("\n");
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* this;
    this=malloc(sizeof(Employee*));

    Employee* thisAux;
    thisAux=malloc(sizeof(Employee*));

    Employee* thisAuxAux;
    thisAuxAux=malloc(sizeof(Employee*));

    float* sueldo;
    sueldo=malloc(sizeof(float*));

    float* sueldoAux;
    sueldoAux=malloc(sizeof(float*));

    system("cls");
    printf(" ORDENAR EMPLEADOS \n\n");
    for(int i=0; i<ll_len(pArrayListEmployee)-1; i++)
    {
        this = ll_get(pArrayListEmployee,i);
        employee_getSueldo(this,sueldo);
        for(int j=i+1; j<ll_len(pArrayListEmployee); j++)
        {
            thisAux = ll_get(pArrayListEmployee,j);
            employee_getSueldo(thisAux,sueldoAux);
            if(*sueldoAux>*sueldo)
            {
                thisAuxAux=this;
                this=thisAux;
                thisAux=thisAuxAux;
            }
        }
    }
    controller_ListEmployee(pArrayListEmployee);
    retorno = 1;
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleado;
    int retorno = 0;
    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fprintf(pArchivo, "%d,%s,%d,%f\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        }
        printf("\nDatos guardados con exito.\n");
        retorno = 1;
    }
    fclose(pArchivo);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


