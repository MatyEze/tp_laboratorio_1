
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
