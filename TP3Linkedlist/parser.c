#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        char idStr[500], nombreStr[500], horasTrabajadasStr[500], sueldoStr[500];
        Employee* auxEmployee;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            auxEmployee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            ll_add(pArrayListEmployee, auxEmployee);
        }

        retorno=1;
    }
    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
