#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funcionesgnr.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). //LISTO
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado //LISTO
     4. Modificar datos de empleado //  LISTO
     5. Baja de empleado //LISTO
     6. Listar empleados //LISTO
     7. Ordenar empleados //LISTO
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). //LISTO
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    int readUId;
    LinkedList* listaEmpleados = ll_newLinkedList();
    //set_ultimaIdTo("ultimaID.csv", 0); //ejecutar el programa 1 vez con esta linea sin comentar si se quiere resetear la ultima id a 0.

    do{
        //printf("tamanio de lista : %d\n", ll_len(listaEmpleados)); //control
        //get_ultimaId("ultimaID.csv", &readUId); //control
        //printf("Ultima ID: %d\n", readUId); // control
        opcion = getIntMmR(3, "1-CARGAR DATOS DESDE EL CSV (TEXTO)\n2-CARGAR DATOS DESDE EL BIN (BINARIO)\n3-ALTA EMPLEADO\n4-MODIFICAR EMPLEADO\n5-BAJA EMPLEADO\n6-LISTAR EMPLEADOS\n7-ORDENAR EMPLEADOS\n8-GUARDAR EN CSV (TEXTO)\n9-GUARDAR EN BIN (BINARIO)\n10-SALIR\nINGRESE OPCION:",
                  "OPCION INVALIDA REINGRESE: ", 10, 1);

        switch(opcion)
        {
            case 1:
                if(ll_isEmpty(listaEmpleados))
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    printf("CARGADO CON EXITO...\n");
                }
                else if(getSON("Se perderan los datos no guardados esta seguro que quiere cargar (s/n): ", "ERROR dato no valido reingrese (s/n): "))
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    printf("CARGADO CON EXITO...\n");
                }
                else
                {
                    printf("CARGADO CANCELADO...\n");
                }
                pausa();
            break;
            case 2:
                if(ll_isEmpty(listaEmpleados))
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    printf("CARGADO CON EXITO...\n");
                }
                else if(getSON("Se perderan los datos no guardados esta seguro que quiere cargar (s/n): ", "ERROR dato no valido reingrese (s/n): "))
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    printf("CARGADO CON EXITO...\n");
                }
                else
                {
                    printf("CARGADO CANCELADO...\n");
                }
                pausa();
            break;
            case 3:
                get_ultimaId("ultimaID.csv", &readUId);
                if(ll_isEmpty(listaEmpleados) && readUId != 0)
                {
                    printf("NO SE A CARGADO NINGUNA LISTA, INGRESE A LAS OPCIONES 1 O 2 PARA CARGAR UNA...\n");
                }
                else
                {
                    controller_addEmployee(listaEmpleados);
                }
                pausa();
            break;
            case 4:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LAS OPCIONES 1 O 2 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 5:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LAS OPCIONES 1 O 2 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 6:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LAS OPCIONES 1 O 2 PARA CARGAR...\n");
                }

                pausa();
            break;
            case 7:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS ELIJA LAS OPCIONES 1 O 2 PARA CARGAR...\n");
                }
                pausa();
            break;
            case 8:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_saveAsText("data.csv", listaEmpleados);
                    printf("SE A GUARDADO CON EXITO...\n");
                }
                else
                {
                    printf("NO HAY DATOS QUE GUARDAR...\n");
                }
                pausa();
            break;
            case 9:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_saveAsBinary("data.bin", listaEmpleados);
                    printf("SE A GUARDADO CON EXITO...\n");
                }
                else
                {
                    printf("NO HAY DATOS QUE GUARDAR...\n");
                }
                pausa();
            break;
        }
        system("cls");
    }while(opcion!=10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
