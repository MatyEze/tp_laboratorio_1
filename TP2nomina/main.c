#include "ArrayEmployees.h"

int main()
{
    int tieneCarga=0;
    int ultimaId;
    int menuOpcion;
    Employee employeeList[SIZELIST];
    initEmployees(employeeList, SIZELIST);
    ///////////////HARDCODE////////////////////
    hardCode10Employees(employeeList, SIZELIST);
    tieneCarga=1;
    ultimaId=109;
    ///////////////////////////////////////////
    do{
        menuOpcion = getIntMmR(3,"1-CARGAR empleado\n2-MODIFICAR empleado\n3-OPCION\n4-MOSTRAR\n5-SALIR\n\nIngrese una opcion: ", "ERROR opcion invalida REINGRESE: ", 5, 1);
        switch(menuOpcion)
        {
            case 1:
                ultimaId=cargarEmpleado(employeeList, SIZELIST, ultimaId);
                tieneCarga=1;
                pausa();
            break;
            case 2:
                if(tieneCarga)
                {
                    modificarEmpleado(employeeList, SIZELIST);
                }
                else
                {
                    printf("No se han cargado empleados.\n");
                }
            break;
            case 3:
                if(tieneCarga)
                {

                }
                else
                {
                    printf("No se han cargado empleados.\n");
                }
            break;
            case 4:
                printEmployees(employeeList, SIZELIST);
                pausa();

            break;
        }

        system("cls");
    }while(menuOpcion != 5);

    return 0;
}
