#include <stdio.h>
#include <stdlib.h>
#include "getdatos.h"

int main()
{
 int opcion;
 float numeroA;
 float numeroB;

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

            break;
            case 4:

            break;
        }
     //system("pause");
     system("cls");

    }while(opcion!=5);



    return 0;
}
