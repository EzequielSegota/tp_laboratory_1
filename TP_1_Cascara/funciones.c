#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float A, float B)
{
    float s;

    s = A + B;

    return (s);
}

float resta(float A, float B)
{
    float r;

    r = A - B;

    return (r);
}


float division(float A, float B)
{
    float d;

    while(B==0)
    {
        printf("\n\nIngrese un valor distinto de 0 para el divisor:\n\n");
        scanf("%f",&B);
    }
    d = A / B;


    return d;
}


float multiplicacion(float A, float B)
{
    float m;

    m= A*B;

    return m;
}


float factorial(float A)
{
    int X;
    float Y;
    int f;

    X=A;
    Y=A;

    Y=Y-X;

    while(Y>0 && Y<1 || A<0)
    {
        printf("\n\nError, no se puede factorear un numero decimal o negativo, ingrese nuevo numero:");
        scanf("%f",&A);

        X=A;
        Y=A;

        Y=Y-X;
    }
    if(A==0)
    {
        f=1;
    }
    else
    {
        f=A*factorial(A-1);
    }

    return f;
}

void todasLasOperaciones(float A,float B)
{
                int X;
                float Y;
                int f;
                X=A;
                Y=A;

                Y=Y-X;

                printf("A=%.2f\nB=%.2f\n",A,B);
                printf("Resultado de la SUMA es: %.2f\n",suma(A,B));
                printf("Resultado de la RESTA es: %.2f\n",resta(A,B));
                printf("Resultado de la MULTIPLICACION es: %.2f\n",multiplicacion(A,B));
                if(B!=0)
                {
                    printf("Resultado de la DIVISION es: %.2f\n",division(A,B));
                }
                else
                {
                    printf("No se puedo resolver la DIVISION, por favor eliga un valor distinto de 0 para B y intente nuevamente\n");
                }
                if(Y>0 || A<0)
                {
                    printf("Error, no se puede factorear un numero decimal o negativo\n");
                }
                else
                {
                   printf("El FACTORIAL de A es %2.f\n",factorial(A));
                   printf("El FACTORIAL de B es %2.f\n",factorial(B));
                }


}

