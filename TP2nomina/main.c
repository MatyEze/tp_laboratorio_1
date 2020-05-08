#include "ArrayEmployees.h"

int main()
{
    int tieneCarga=0;
    int ultimaId;
    int menuOpcion;
    int opcionInforme;
    Employee employeeList[SIZELIST];
    initEmployees(employeeList, SIZELIST);
    ///////////////HARDCODE////////////////////
    hardCode10Employees(employeeList, SIZELIST);
    tieneCarga=1;
    ultimaId=109;
    ///////////////////////////////////////////
    do{
        menuOpcion = getIntMmR(3,"1-CARGAR empleado\n2-MODIFICAR empleado\n3-ELIMINAR empleado\n4-INFORMES\n5-SALIR\n\nIngrese una opcion: ", "ERROR opcion invalida REINGRESE: ", 5, 1);
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
                    eliminarEmpleado(employeeList, SIZELIST);
                }
                else
                {
                    printf("No se han cargado empleados.\n");
                }
            break;
            case 4:
                do{
                    system("cls");
                    opcionInforme = getIntMmR(3, "1-MOSTRAR listado de empleados ordenado ALFABETICAMENTE Y por SECTOR\n2-INFORMAR total y promedio de los salarios y cuantos empleados superan el salario promedio\n3-ATRAS\nIngrese opcion: ",
                                              "ERROR opcion invalida REINGRESE: ", 3, 1);
                    system("cls");
                    switch(opcionInforme)
                    {
                        case 1:
                            sortEmployees(employeeList, SIZELIST, 1);
                            printEmployees(employeeList, SIZELIST);
                            pausa();
                        break;
                        case 2:

                        break;
                    }
                }while(opcionInforme!=3);
            break;
        }

        system("cls");
    }while(menuOpcion != 5);

    return 0;
}
