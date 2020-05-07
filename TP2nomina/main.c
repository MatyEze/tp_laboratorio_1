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
        menuOpcion = menu5opciones("1-OPCION", "2-OPCION", "3-OPCION", "4-OPCION", "5-SALIR");
        switch(menuOpcion)
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
        }
    }while(menuOpcion != 5);

    return 0;
}
