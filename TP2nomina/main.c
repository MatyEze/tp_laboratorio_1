#include "ArrayEmployees.h"

int main()
{
    int tieneCarga=0;
    int ultimaid;
    Employee employeeList[SIZELIST];
    initEmployees(employeeList, SIZELIST);
    ///////////////HARDCODE////////////////////
    hardCode10Employees(employeeList, SIZELIST);
    tieneCarga=1;
    ultimaid=109;
    ///////////////////////////////////////////
    sortEmployees(employeeList, SIZELIST, 0);
    printEmployees(employeeList, SIZELIST);
    return 0;
}
