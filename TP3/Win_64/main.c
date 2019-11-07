#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int seguir = 's';
    int controllerFromText = 0;
    int controllerFromBinary = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            if(controllerFromText == 0 && controllerFromBinary == 0){
                controller_loadFromText("data.csv",listaEmpleados);
                controllerFromText = 1;
            }
            else{
                if(controllerFromText == 1){
                    printf("\nLa lista ya fue cargada en modo texto, de cargarla nuevamente y de haber lugar en memoria se duplicaran los datos en sistema.\n\n");
                }
                if(controllerFromBinary == 1){
                    printf("\nLa lista ya fue cargada en modo binario, de cargarla nuevamente y de no haber guardado los datos se perderan.\n\n");
                }
            }
            system("pause");
            break;
        case 2:
            if(controllerFromText == 0 && controllerFromBinary == 0){

                controllerFromBinary = 1;
            }
            else{
                if(controllerFromBinary == 1){
                    printf("\nLa lista ya fue cargada en modo binario, de cargarla nuevamente y de haber lugar en memoria se duplicaran los datos en sistema.\n\n");
                }
                if(controllerFromText == 1){
                    printf("\nLa lista ya fue cargada en modo texto, de cargarla nuevamente y de no haber guardado los datos se perderan.\n\n");
                }
            }
            system("pause");
            break;
        case 3:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_addEmployee(listaEmpleados);
            }
            else{
                printf("\n No se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_editEmployee(listaEmpleados);
            }
            else{
                printf("\n No se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_removeEmployee(listaEmpleados);
            }
            else{
                printf("\n No se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 6:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_ListEmployee(listaEmpleados);
            }
            else{
                printf("\n No se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            system("pause");
            break;
        case 8:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else{
                printf("\n No se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 9:
            break;
        case 10:
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta, reintente.\n\n");
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');
    return 0;
}
