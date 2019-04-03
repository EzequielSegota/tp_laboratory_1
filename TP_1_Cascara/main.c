#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float A=0;
    float B=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    float resultadoA;
    float resultadoB;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",A);
        printf("2- Ingresar 2do operando (B=%.2f)\n",B);
        printf("3- Realizar todas las operaciones\n");
        printf("4- Resultado de todas las operaciones\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\n\nIngrese numero:");
                scanf("%f",&A);
                break;
            case 2:
                system("cls");
                printf("\n\nIngrese numero:");
                scanf("%f",&B);
                break;
            case 3:
                system("cls");
                resultadoSuma=suma(A,B);
                resultadoResta=resta(A,B);
                resultadoDivision=division(A,B);
                resultadoMultiplicacion=multiplicacion(A,B);
                resultadoA=factorial(A);
                resultadoB=factorial(B);
                break;
            case 4:
                system("cls");
                printf("\n\nEl resultado de A+B es: %.2f \n\n",resultadoSuma);
                printf("\n\nEl resultado de A-B es: %.2f \n\n",resultadoResta);
                printf("\n\nEl resultado de A/B es: %.2f \n\n",resultadoDivision);
                printf("\n\nEl resultado de A*B es: %.2f \n\n",resultadoMultiplicacion);
                printf("\n\nEl resultado de !A es: %.2f \n\n",resultadoA);
                printf("\n\nEl resultado de !B es: %.2f \n\n",resultadoB);
                break;
            case 5:
                system("cls");
                seguir = 'n';
                break;
            default:
                printf("\n\nNumero erroneo.\n\n");
                system("pause");
                system("cls");
                break;
        }

    }


        return 0;
}


