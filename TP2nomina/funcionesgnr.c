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
///////////////////////////////////////////////////////////A3.1 GET DATOS -nombre- (char)///////////////////////////////////////////////////

void getNombre(int formato, char pedido[], char nombre[], int sizeNombre)
{
    int largo;
    int i;
    char letra;
    printf(pedido);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(nombre, sizeNombre, stdin);
    largo=strlen(nombre);
    nombre[largo-1]='\0';
    while(nombre[largo-2] == ' ' || nombre[0] == ' ')
    {
        printf("ERROR formato invalido REINGRESE: ");
        //__fpurge(stdin);
        fflush(stdin);
        fgets(nombre, sizeNombre, stdin);
        largo=strlen(nombre);
        nombre[largo-1]='\0';
    }

    switch(formato)
    {
        case 1: //PRIMER LETRA MAYUSCULA LAS DEMAS MINUSCULA.
            for(i=0; i<largo; i++)
            {
                if(i==0)
                {
                    letra=nombre[i];
                    letra=toupper(letra);
                    nombre[i]=letra;
                }
                else if(nombre[i] == ' ')
                {
                    letra=nombre[i+1];
                    letra=toupper(letra);
                    nombre[i+1]=letra;
                }
            }
        break;
        case 2: //TODO MAYUSCULA.
            for(i=0; i<largo; i++)
            {
                    letra=nombre[i];
                    letra=toupper(letra);
                    nombre[i]=letra;
            }
        break;
    }

}

///////////////////////////////////////////////////////////B1.0 MENUS///////////////////////////////////////////////////////////////////////

int menu3opciones(char opcion1[], char opcion2[], char opcion3[])
{
    int opcionRetorno;

    printf(opcion1);
    printf("\n");
    printf(opcion2);
    printf("\n");
    printf(opcion3);
    printf("\n");
    opcionRetorno = getIntMmR(3, "Ingrese opcion: ", "ERROR opcion no valida REINGRESE: ", 3, 1);

    return opcionRetorno;
}

int menu5opciones(char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[])
{
    int opcionRetorno;

    printf(opcion1);
    printf("\n");
    printf(opcion2);
    printf("\n");
    printf(opcion3);
    printf("\n");
    printf(opcion4);
    printf("\n");
    printf(opcion5);
    printf("\n");
    opcionRetorno = getIntMmR(3, "Ingrese opcion: ", "ERROR opcion no valida REINGRESE: ", 5, 1);

    return opcionRetorno;
}







///////////////////////////////////////////////////////////Z1.0 OTRAS///////////////////////////////////////////////////////////////////////

char *strlwr(char *str) //para que funcione en GDB hay que implementarla manualmente
{
  unsigned char *p = (unsigned char *)str;
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }
  return str;
}
