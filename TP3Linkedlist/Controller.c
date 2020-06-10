#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    FILE* pFile = NULL;
    ll_clear(pArrayListEmployee);

    pFile = fopen(path, "r");
    retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{

return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len = ll_len(pArrayListEmployee);
    int i;
    int hsTrabjadas;
    int sueldo;
    char nombre[EMPLOYEENAME_SIZE];
    int id;
    Employee* aux;
    for(i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee, i);
        employee_getHorasTrabajadas(aux, &hsTrabjadas);
        employee_getSueldo(aux, &sueldo);
        employee_getNombre(aux, nombre);
        employee_getId(aux, &id);

        printf("%d--%s--%d--%d\n", id, nombre, hsTrabjadas, sueldo);
    }

    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}

