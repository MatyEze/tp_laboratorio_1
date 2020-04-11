#include <stdio.h>
#include <stdlib.h>
#include "getdatos.h"
#include "operaciones.h"

int main()
{
 int opcion;
 float numeroA = 0;
 float numeroB = 0;
 float resSum;
 float resRst;
 float resDiv;
 float resMult;
 float resFA;
 float resFB;


    do
    {
        printf("\n1. Cambiar numero A (%f)", numeroA);
        printf("\n2. Cambiar numero B (%f)", numeroB);
        printf("\n3. Calcular operaciones.");
        printf("\n4. Mostrar resultados.");
        printf("\n5. Salir.\n");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                numeroA=getFloat("\nIngrese el numero A: ");
            break;
            case 2:
                numeroB=getFloat("\nIngrese el numero B: ");
            break;
            case 3:
                resSum = sumar(numeroA, numeroB);
                resRst = restar(numeroA, numeroB);
                resDiv = dividir(numeroA, numeroB);
                resMult = multiplicar(numeroA, numeroB);
                resFA = factorial(numeroA);
                resFB = factorial(numeroB);
            break;
            case 4:
                printf("\n");
                printf("---------RESULTADOS-------------------------------------------------\n");
                printf("El resultado de %f + %f es: %f\n", numeroA, numeroB, resSum);
                printf("El resultado de %f - %f es: %f\n", numeroA, numeroB, resRst);
                resultadoDivicion("El resultado de %f / %f es: %f\n", numeroA, numeroB, resDiv, "No se puede dividir por 0.\n");
                printf("El resultado de %f * %f es: %f\n", numeroA, numeroB, resMult);
                printf("El factorial de %f es: %E\n", numeroA, resFA);
                printf("El factorial de %f es: %E\n", numeroB, resFB);
                printf("--------------------------------------------------------------------\n");
                system("pause");
            break;
        }
     //system("pause");
     system("cls");

    }while(opcion!=5);



    return 0;
}
