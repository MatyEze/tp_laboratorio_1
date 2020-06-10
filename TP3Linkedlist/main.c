#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funcionesgnr.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
        opcion = getIntMmR(3, "1-CARGAR DATOS DESDE EL CSV (TEXTO)\n2-CARGAR DATOS DESDE EL CSV (BINARIO)\n3-ALTA EMPLEADO\n4-MODIFICAR EMPLEADO\n5-BAJA EMPLEADO\n6-LISTAR EMPLEADOS\n7-ORDENAR EMPLEADOS\n8-GUARDAR EN CSV (TEXTO)\n9-GUARDAR EN CSV (BINARIO)\n10-SALIR\nINGRESE OPCION:",
                  "OPCION INVALIDA REINGRESE: ", 10, 1);


        switch(opcion)
        {
            case 1:
                controller_loadFromBinary("data.csv", listaEmpleados);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:

            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
        }
    }while(opcion!=10);

    return 0;
}
