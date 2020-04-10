
#include <stdio.h>
#include <stdlib.h>
#include "getdatos.h"

float getFloat(char pedido[])
{
    float valor;

    printf("%s", pedido);
    scanf("%f",&valor);

    return valor;
}

float getFloatMin(char pedido[], float min, char error[])
{
    float valor;

    printf("%s", pedido);
    scanf("%f",&valor);

    while(valor<min)
    {
        printf("%s", error);
        scanf("%f",&valor);
    }

    return valor;
}

float getFloatMax(char pedido[], float max, char error[])
{
    float valor;

    printf("%s", pedido);
    scanf("%f",&valor);

    while(valor>max)
    {
        printf("%s", error);
        scanf("%f",&valor);
    }

    return valor;
}
