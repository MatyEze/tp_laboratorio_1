#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"
#include <string.h>


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pNewEmployee = NULL;
    pNewEmployee = employee_new();
    if(pNewEmployee != NULL)
    {
        employee_setId(pNewEmployee, atoi(idStr));
        employee_setNombre(pNewEmployee, nombreStr);
        employee_setHorasTrabajadas(pNewEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(pNewEmployee, atoi(sueldoStr));
    }
    return pNewEmployee;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno =-1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno =-1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno =-1;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno =-1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno =-1;
    if(this != NULL)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno =-1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno =-1;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int retorno =-1;
    if(this != NULL && horasTrabajdas != NULL)
    {
        *horasTrabajdas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}


int employee_CompareByName(void* e1, void* e2)
{
    int retorno=0;
    if(e1 != NULL && e2 != NULL)
    {
        Employee* employee1 = (Employee*) e1;
        Employee* employee2 = (Employee*) e2;
        retorno = strcmp(employee1->nombre, employee2->nombre);
    }
    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    int retorno=0;
    if(e1 != NULL && e2 != NULL)
    {
        Employee* employee1 = (Employee*) e1;
        Employee* employee2 = (Employee*) e2;
        if(employee1->id > employee2->id)
        {
            retorno=1;
        }
        else
        {
            if(employee1->id < employee2->id)
            {
                retorno=-1;
            }
            else
            {
                retorno=0;
            }
        }
    }
    return retorno;
}

int printEmployee(Employee* this)
{
    int retorno=-1;
    if(this != NULL)
    {
        int id, sueldo, hsTrabjadas;
        char nombre[EMPLOYEENAME_SIZE];
        retorno=1;
        employee_getHorasTrabajadas(this, &hsTrabjadas);
        employee_getSueldo(this, &sueldo);
        employee_getNombre(this, nombre);
        employee_getId(this, &id);

        printf("%6d %20s %15d %10d\n", id, nombre, hsTrabjadas, sueldo);
    }
    return retorno;
}
