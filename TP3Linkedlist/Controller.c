#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "funcionesgnr.h"



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
    int retorno=0;
    Employee* newEmployee = employee_new();
    if(pArrayListEmployee != NULL && newEmployee != NULL)
    {
        retorno=1;
        int id, sueldo, hstrabajadas;
        char nombre[EMPLOYEENAME_SIZE];

        get_ultimaId("ultimaID.csv", &id);
        //printf("ultima id %d\n", id); //control
        id++;
        set_ultimaIdTo("ultimaID.csv", id);
        //printf("ultima id %d\n", id); //control
        getNombre(1, "Ingrese nombre: ", nombre, EMPLOYEENAME_SIZE);
        sueldo=getIntMmR(2, "Ingrese el sueldo: ", "ERROR valor no valido reingrese: ", 0, 1);
        hstrabajadas=getIntMmR(2, "Ingrese las horas trabajadas: ", "ERROR valor no valido reingrese", 0, 1);


        employee_setId(newEmployee, id);
        employee_setSueldo(newEmployee, sueldo);
        employee_setHorasTrabajadas(newEmployee, hstrabajadas);
        employee_setNombre(newEmployee, nombre);

        ll_add(pArrayListEmployee, newEmployee);
        free(newEmployee);

    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    if(pArrayListEmployee != NULL)
    {
        retorno=1;
        int idToIndex = getInt("Ingrese id del empleado que desea modificar: ");
        int opcion;
        if(getEmployeeById(pArrayListEmployee, idToIndex, &idToIndex) == 2)
        {
            do{
                printf("Modificando a:\n");
            }while(opcion != 6);
        }
        else
        {
            printf("ID NO ENCONTRADA...\n");
        }
    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 1;
        int len = ll_len(pArrayListEmployee);
        int i;
        Employee* aux;
        printf("%6s %20s %15s %10s\n", "ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");
        for(i=0; i<len; i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee, i);
            printEmployee(aux);
        }
    }


    return retorno;
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
            //printf("se guardo %d,%s,%d,%d\n", id, nombre, hstrabajadas, sueldo); //control
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
    //printf("ultima id %d\n", ultimaId); //control
    for(i=0; i<len; i++)
    {
        employeeRead = (Employee*) ll_get(pArrayListEmployee, i);
        employee_getId(employeeRead, &idRead);
        if(idRead>ultimaId)
        {
                ultimaId=idRead;
        }
    }

    //printf("ultima id %d\n", ultimaId); //control
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

int getEmployeeById(LinkedList* pArrayListEmployee, int id, int* index)
{
    int retorno=-1;
    if(pArrayListEmployee != NULL && index != NULL && id > 0)
    {
        int i;
        int len = ll_len(pArrayListEmployee);
        int idRead;
        Employee* auxEmpl;
        retorno=1;

        for(i=0; i<len; i++)
        {
            auxEmpl = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmpl, &idRead);
            if(idRead == id)
            {   retorno=2;
                *index=i;
                break;
            }
        }

    }
    return retorno;
}
