#include "ArrayEmployees.h"

void hardCode10Employees(Employee* list, int len)
{
    int i;
    Employee auxList[10]={{100, "Lucas", "Fernandez", 850, 2, 0},
                         {101, "Maria", "Sturger", 1200, 2, 0},
                         {102, "Nando", "Lourido", 3500, 3, 0},
                         {103, "Elmo", "Noloco", 500, 2, 0},
                         {104, "Luz", "Apagada", 550, 1, 0},
                         {105, "Juan", "Helsing", 500, 2, 0},
                         {106, "Lucas", "Fernandez", 550, 1, 0},
                         {107, "Mariano", "Camacho", 1390, 2, 0},
                         {108, "Aldo", "Defurze", 600, 1, 0},
                         {109, "Sol", "Ydrhefa", 580, 1, 0}};

    for(i=0; i<10; i++)
    {
        list[i]=auxList[i];
    }
}

int initEmployees(Employee* list, int len)
{
    int i;//employee
    int retorno=-1;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }

    retorno=0;
    return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int libre = findEmptyEmployee(list, len);
    int retorno=-1;

    if(libre!=-1)
    {
    list[libre].id = id;
    strcpy(list[libre].name, name);
    strcpy(list[libre].lastName, lastName);
    list[libre].salary = salary;
    list[libre].sector = sector;
    list[libre].isEmpty = 0;
    retorno = 0;
    }

    return retorno;
}

int findEmptyEmployee(Employee* list, int len)
{
    int i;//employee
    int libre=-1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty)
        {
            libre = i;
            break;
        }
    }
    return libre;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int i;//employee
    int index=-1;

    for(i=0; i<len; i++)
    {
        if(list[i].id == id)
        {
            index=i;
            break;
        }
    }
    return index;
}

int removeEmployee(Employee* list, int len, int id)
{
    int index = findEmployeeById(list, len, id);
    int retorno=-1;
    if(index != -1)
    {
        list[index].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int retorno;
    switch(order)
    {
        case 0:
            retorno=sortEmployeesDown(list, len);
        break;
        case 1:
            retorno=sortEmployeesUp(list, len);
        break;
    }
    return retorno;
}

/*void swapEmployees(int i, int j, Employee* list, int len)
{
    Employee auxEmployee;
    auxEmployee=list[i];
    list[i]=list[j];
    list[j]=auxEmployee;
}*/

int sortEmployeesUp(Employee* list, int len)
{
    int i;
    int j;
    int retorno=-1;
    Employee auxEmployee;

    for(i=0; i-1<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if((strcmp(list[i].lastName, list[j].lastName)) > 0)
            {
                auxEmployee=list[i];
                list[i]=list[j];
                list[j]=auxEmployee;
                retorno=0;
            }
            else if((strcmp(list[i].lastName, list[j].lastName)) == 0)
            {
                if(list[i].sector > list[j].sector)
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int sortEmployeesDown(Employee* list, int len)
{
    int i;
    int j;
    int retorno=-1;
    Employee auxEmployee;

    for(i=0; i-1<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if((strcmp(list[i].lastName, list[j].lastName)) < 0)
            {
                auxEmployee=list[i];
                list[i]=list[j];
                list[j]=auxEmployee;
                retorno=0;
            }
            else if((strcmp(list[i].lastName, list[j].lastName)) == 0)
            {
                if(list[i].sector < list[j].sector)
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int printEmployees(Employee* list, int length)
{
    int i;
    printf("ID                NOMBRE        SALARIO       SECTOR\n");
    for(i=0; i<length; i++)
    {
        printOneEmployee(list[i]);
    }
    return 0;
}

void printOneEmployee(Employee employee)
{
    if(!employee.isEmpty)
    {
        printf("%d %15s %8s %10.2f %10d\n", employee.id, employee.lastName, employee.name, employee.salary, employee.sector);
    }
}
