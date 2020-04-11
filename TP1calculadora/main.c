#include <stdio.h>
#include <stdlib.h>
#include "getdatos.h"
#include "operaciones.h"

int main()
{
 int opcion;
 float numeroA;
 float numeroB;
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
            break;
            case 4:
                resultadoDivicion("El resultado de %f / %f es = %f\n", numeroA, numeroB, resDiv, "No se puede dividir por 0.\n");
                system("pause");
            break;
        }
     //system("pause");
     system("cls");

    }while(opcion!=5);



    return 0;
}
