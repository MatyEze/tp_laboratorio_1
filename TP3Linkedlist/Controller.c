#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
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

    set_ultimaId("ultimaID.csv", pArrayListEmployee);
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
    int retorno =-1;
    Employee* auxEmployee;
    int id, hstrabajadas, sueldo;
    char nombre[EMPLOYEENAME_SIZE];
    int len = ll_len(pArrayListEmployee);
    int i;
    FILE* pFile=NULL;
    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        retorno=1;
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &id);
            employee_getHorasTrabajadas(auxEmployee, &hstrabajadas);
            employee_getSueldo(auxEmployee, &sueldo);
            employee_getNombre(auxEmployee, nombre);

            fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, hstrabajadas, sueldo);
            //printf("se guardo %d,%s,%d,%d\n", id, nombre, hstrabajadas, sueldo);
        }

    }
    fclose(pFile);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}


int set_ultimaId(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile = NULL;
    int ultimaId=-1;
    int len=ll_len(pArrayListEmployee);
    int idRead;
    int i;
    Employee* employeeRead;

    get_ultimaId(path, &ultimaId);
    printf("ultima id %d\n", ultimaId);
    for(i=0; i<len; i++)
    {
        employeeRead = (Employee*) ll_get(pArrayListEmployee, i);
        employee_getId(employeeRead, &idRead);
        if(idRead>ultimaId)
        {
                ultimaId=idRead;
        }
    }

    printf("ultima id %d\n", ultimaId);
    pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        fprintf(pFile, "%d\n", ultimaId);
        retorno=1;
    }
    fclose(pFile);
    return retorno;
}

int get_ultimaId(char* path, int* ultimaId)
{
    FILE* pFile=NULL;
    int retorno=-1;
    char ultimaIdStr[500];

    pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        retorno=1;
        fscanf(pFile, "%[^\n]\n", ultimaIdStr);
    }
    fclose(pFile);

    *ultimaId = atoi(ultimaIdStr);

    return retorno;
}

int set_ultimaIdTo(char* path, int id)
{
    int retorno=-1;
    FILE* pFile = NULL;
    pFile=fopen(path, "w");
    if(pFile != NULL)
    {
        retorno=1;
        fprintf(pFile, "%d", id);
    }
    fclose(pFile);
    return retorno;
}
