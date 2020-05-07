#include "funcionesgnr.h"

int getInt(char pedido[])
{
    int valor;
    printf(pedido);
    scanf("%d",&valor);
    return valor;
}

int getIntMmR(int opcion, char pedido[], char error[], int maximo, int minimo)
{
    int valor;

    valor = getInt(pedido);
    switch(opcion)
    {
        case 1:
            while(valor>maximo)
            {
                valor=getInt(error);
            }
        break;
        case 2:
            while(valor<minimo)
            {
                valor=getInt(error);
            }
        break;
        case 3:
            while(valor < minimo || valor > maximo)
            {
                valor=getInt(error);
            }
        break;
        default:
            printf("Error en funcion getIntMmR: opcion erronea (1,2,3)");
        break;
    }

    return valor;
}

float getFloatMmR(int opcion, char pedido[], char error[], float maximo, float minimo)
{
    float valor;

    valor = getInt(pedido);
    switch(opcion)
    {
        case 1:
            while(valor>maximo)
            {
                valor=getInt(error);
            }
        break;
        case 2:
            while(valor<minimo)
            {
                valor=getInt(error);
            }
        break;
        case 3:
            while(valor < minimo || valor > maximo)
            {
                valor=getInt(error);
            }
        break;
        default:
            printf("Error en funcion getFloatMmR: opcion erronea (1,2,3)");
        break;
    }

    return valor;
}
