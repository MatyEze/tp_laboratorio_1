#include "funcionesgnr.h"

int getInt(char pedido[])
{
    int valor;
    printf(pedido);
    scanf("%d",&valor);
    return valor;
}

float getFloat(char pedido[])
{
    float valor;
    printf(pedido);
    scanf("%f",&valor);
    return valor;
}

int getIntMmR(int opcion, char pedido[], char error[], int maximo, int minimo)
{
    int valor;
    int reintentos=5;

    valor = getInt(pedido);
    switch(opcion)
    {
        case 1:
            while(valor>maximo && reintentos !=0)
            {
                valor=getInt(error);
                reintentos--;
            }
        break;
        case 2:
            while(valor<minimo && reintentos !=0)
            {
                valor=getInt(error);
                reintentos--;
            }
        break;
        case 3:
            while((valor < minimo || valor > maximo) && reintentos !=0)
            {
                valor=getInt(error);
                reintentos--;
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
    int reintentos=5;

    valor = getFloat(pedido);
    switch(opcion)
    {
        case 1:
            while(valor>maximo && reintentos !=0)
            {
                valor=getFloat(error);
                reintentos--;
            }
        break;
        case 2:
            while(valor<minimo && reintentos !=0)
            {
                valor=getFloat(error);
                reintentos--;
            }
        break;
        case 3:
            while((valor < minimo || valor > maximo) && reintentos !=0)
            {
                valor=getFloat(error);
                reintentos--;
            }
        break;
        default:
            printf("Error en funcion getFloatMmR: opcion erronea (1,2,3)");
        break;
    }

    return valor;
}


///////////////////////////////////////////////////////////A3.0 GET DATOS (char)////////////////////////////////////////////////////////////

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
    for(i=0; i<largo; i++)
    {
        letra=nombre[i];
        letra=tolower(letra);
        nombre[i]=letra;
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

void pausa(void)
{
    printf("\n\n\nPresiona CUALQUIER tecla para CONTINUAR...\n");
    //__fpurge(stdin);
    fflush(stdin);
    getchar();
}

int getSON(char pedido[], char error[])
{
    char resp;
    int valor=0;

    printf(pedido);
    //_fpurge(stdin);
    fflush(stdin);
    scanf("%c",&resp);
    resp = tolower(resp);
    while(resp != 's' && resp != 'n')
    {
        printf(error);
        //_fpurge(stdin);
        fflush(stdin);
        scanf("%c",&resp);
        resp = tolower(resp);
    }

    if(resp == 's')
    {
        valor=1;
    }
    return valor;
}
