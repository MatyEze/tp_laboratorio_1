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
    int retorno=-1;
    if(pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        FILE* pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            retorno=1;
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        fclose(pFile);
        set_ultimaId("ultimaID.csv", pArrayListEmployee);
    }
    return retorno;
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
        int guardado=1;
        char auxNombre[EMPLOYEENAME_SIZE];
        Employee* auxEmployee;
        if(getEmployeeById(pArrayListEmployee, idToIndex, &idToIndex) == 2)
        {
            auxEmployee = employee_new();
            *auxEmployee = *((Employee*) ll_get(pArrayListEmployee, idToIndex));
            do{
                system("cls");
                printf("Modificando a:\n");
                printf("%6s %20s %15s %10s\n", "ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");
                printEmployee(auxEmployee);
                opcion=getIntMmR(3, "1-modificar NOMBRE\n2-modificar HS TRABAJADAS\n3-modificar SUELDO\n4-GUARDAR\n5-SALIR\nINGRESE OPCION: ",
                                 "ERROR opcion invalida REINGRESE: ", 5, 1);
                switch(opcion)
                {
                    case 1:
                        getNombre(1, "Ingrese nuevo nombre: ", auxNombre, EMPLOYEENAME_SIZE);
                        employee_setNombre(auxEmployee, auxNombre);
                        guardado=0;
                    break;
                    case 2:
                        employee_setHorasTrabajadas(auxEmployee, getIntMmR(2, "Ingrese las horas trabajadas: ", "ERROR valor no valido reingrese", 0, 1));
                        guardado=0;
                    break;
                    case 3:
                        employee_setSueldo(auxEmployee, getIntMmR(2, "Ingrese nuevo sueldo: ", "ERROR valor no valido reingrese: ", 0, 1));
                        guardado=0;
                    break;
                    case 4:
                        system("cls");
                        printf("ORIGINAL\n");
                        printEmployee((Employee*) ll_get(pArrayListEmployee, idToIndex));
                        printf("NUEVO\n");
                        printEmployee(auxEmployee);
                        if(getSON("Esta SEGURO que quiere GUARDAR los cambios ingrese s/n: ", "ERROR valor no valido reingrese: "))
                        {
                            *((Employee*) ll_get(pArrayListEmployee, idToIndex)) = *auxEmployee;
                            guardado=1;
                            printf("Se a GUARDADO los cambios con EXITO.\n");
                            pausa();
                        }
                        else
                        {
                            printf("Cambios CANCELADOS.\n");
                            pausa();
                        }
                    break;
                    case 5:
                        if(!guardado)
                        {
                            if(getSON("Esta seguro que quiere salir sin guardar (s/n): ", "ERROR valor invalido REINGRESE: "))
                            {
                                free(auxEmployee);
                                opcion = 5;
                            }
                            else
                            {
                                opcion =-1;
                            }
                        }
                    break;
                }

            }while(opcion != 5);
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
    int retorno=-1;
    if(pArrayListEmployee != NULL)
    {
        int idToIndex=getInt("Ingres id del empleado a eliminar: ");
        if(getEmployeeById(pArrayListEmployee, idToIndex, &idToIndex) == 2)
        {
            printf("Esta seguro que quiere eliminar a:\n");
            printEmployee((Employee*) ll_get(pArrayListEmployee, idToIndex));
            if(getSON("Ingrese (s/n)", "VALOR no valido REINGRESE (s/n): "))
            {
                ll_remove(pArrayListEmployee, idToIndex);
                printf("EL EMPLEADO SE A ELIMINADO EXITOSAMENTE...\n");
            }
            else
            {
                printf("LA OPERACION CANCELADA...\n");
            }
        }
        else
        {
            printf("ID NO ENCONTRADA...\n");
        }
        retorno=1;
    }
    return retorno;
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
    int retorno=-1;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        int opcion=getIntMmR(3, "ORDENAR LISTA\n1-Por id\n2-Por nombre\n3-CANCELAR\nINGRESE OPCION: ",
                             "ERROR opcion no valida REINGRESE: ", 3, 1);
        switch(opcion)
        {
            case 1:
                printf("ORDENANDO puede tardar unos segundos...\n");
                ll_sort(pArrayListEmployee, employee_CompareById, 1);
                printf("SE A ORDENADO LA LISTA\n");
            break;
            case 2:
                printf("ORDENANDO puede tardar unos segundos...\n");
                ll_sort(pArrayListEmployee, employee_CompareByName, 1);
                printf("SE A ORDENADO LA LISTA\n");
            break;
        }
        retorno=1;
    }
    return retorno;
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
    int retorno=-1;
    if(pArrayListEmployee != NULL)
    {
        FILE* pFile=NULL;
        int i;
        int len = ll_len(pArrayListEmployee);
        //printf("tama�o lista a guardar: %d\n", len); //control
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            retorno=1;
            for(i=0; i<len; i++)
            {
                fwrite((Employee*) ll_get(pArrayListEmployee, i), sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
    }

    return retorno;
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
