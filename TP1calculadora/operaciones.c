
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

float sumar(float numA, float numB)
{
    float valor;

    valor = numA + numB;

    return valor;
}

float restar(float numA, float numB)
{
    float valor;

    valor = numA - numB;

    return valor;
}

float dividir(float numA, float numB)
{
    float valor;
    if(numB != 0)
    {
        valor = numA / numB;
    }
    else
    {
        valor = numA;
    }

    return valor;
}

float multiplicar(float numA, float numB)
{
    float valor;

    valor = numA * numB;

    return valor;
}

double factorial(float num)
{
    double valor = 1;
    int i;

    for (i = 1; i <= num; i++)
    {
        valor = valor * i;
    }

    return valor;
}

void resultadoDivicion (char mensaje[], float dividendo, float divisor, float resultado, char error[])
{

    if(divisor == 0)
    {
        printf(error);
    }
    else
    {
        printf(mensaje, dividendo, divisor, resultado);
    }
}

void mostrarFactorial (float num, double factorial)
{
    int numEnt=(int)num;

    if(numEnt < 0)
    {
        printf("El numero ingresado (%d) es menor a 0\n",numEnt);
        return;
    }



    if(factorial < 9999999)
    {
        printf("El factorial de %d es: %.0f\n", numEnt, factorial);
    }
    else
    {
        printf("El factorial de %d es: %E\n", numEnt, factorial);
    }
}
