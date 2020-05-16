#include "ArrayEmployees.h"

void hardCode10Employees(Employee* list, int len)
{
    int i;
    Employee auxList[10]={{100, "Norberto", "FERNANDEZ", 850, 2, 0},
                         {101, "Maria", "STURGER", 1200, 2, 0},
                         {102, "Nando", "LOURIDO", 3500, 3, 0},
                         {103, "Elmo", "NOLOCO", 500, 2, 0},
                         {104, "Luz", "APAGADA", 550, 1, 0},
                         {105, "Juan", "HELSING", 500, 2, 0},
                         {106, "Lucas", "FERNANDEZ", 550, 1, 0},
                         {107, "Mariano", "CAMACHO", 1390, 2, 0},
                         {108, "Aldo", "DEFURZE", 600, 1, 0},
                         {109, "Sol", "YDRHEFA", 580.50, 1, 0}};

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

int cargarEmpleado(Employee* list,int sizeList, int lastID)
{
    int nuevaID;
    char name[SIZELIST];
    char lastName[SIZENAME];
    if (findEmptyEmployee(list, sizeList) != -1)
    {
        getNombre(1, "Ingrese Nombre: ", name, SIZENAME);
        getNombre(2, "Ingrese Apellido: ", lastName, SIZENAME);
        nuevaID=lastID+1;
        addEmployee(list, sizeList, nuevaID, name, lastName,
                    getFloatMmR(2, "Ingrese Salario: ", "ERROR salario invalido REINGRESE: ", 0, 1),
                    getIntMmR(2, "Ingrese numero de sector: ", "ERROR sector invalido REINGRESE: ", 0, 1));

        printf("Se a cargado CORRECTAMENTE.\n\n");
    }
    else
    {
        printf("No hay espacio disponible.\n\n");
        nuevaID=lastID;
    }


    return nuevaID;
}

void modificarEmpleado(Employee* list, int sizeList)
{
    Employee auxEmployee;
    int idToIndex;
    int opcion;
    char resp;
    int guardado=1;

    printEmployees(list, sizeList);
    idToIndex = findEmployeeById(list, sizeList, getInt("Ingrese la ID del empleado que desea MODIFICAR: "));
    while(idToIndex == -1)
    {
        idToIndex = findEmployeeById(list, sizeList, getInt("ERROR ID no encontrada REINGRESE: "));
    }

    auxEmployee=list[idToIndex];

    do{
        system("cls");
        printf("MODIFICANDO al empleado.\n");
        printOneEmployee(auxEmployee);
        opcion=getIntMmR(3, "1-modificar NOMBRE\n2-modificar APELLIDO\n3-modificar SALARIO\n4-modificar SECTOR\n5-GUARDAR.\n6-ATRAS\n\nIngrese una opcion: ", "ERROR opcion no valida REINGRESE: ", 6, 1);
        switch(opcion)
        {
        case 1:
            getNombre(1, "Ingrese NUEVO nombre: ", auxEmployee.name, SIZENAME);
            guardado=0;
        break;
        case 2:
            getNombre(2, "Ingrese NUEVO apellido: ", auxEmployee.lastName, SIZENAME);
            guardado=0;
        break;
        case 3:
            auxEmployee.salary = getFloatMmR(2, "Ingrese NUEVO Salario: ", "ERROR salario invalido REINGRESE: ", 0, 1);
            guardado=0;
        break;
        case 4:
            auxEmployee.sector = getIntMmR(2, "Ingrese NUEVO numero de sector: ", "ERROR sector invalido REINGRESE: ", 0, 1);
            guardado=0;
        break;
        case 5:
            printf("ORIGINAL\n");
            printOneEmployee(list[idToIndex]);
            printf("NUEVO\n");
            printOneEmployee(auxEmployee);
            printf("Esta SEGURO que quiere GUARDAR los cambios ingrese s/n: ");
            fflush(stdin);
            scanf("%c",&resp);
            if(resp == 's')
            {
                list[idToIndex] = auxEmployee;
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
        case 6:
            if(!guardado)
            {
                printf("Esta SEGURO que quiere SALIR sin GUARDAR los CAMBIOS ingrese s/n: ");
                fflush(stdin);
                scanf("%c",&resp);
                if(resp == 's')
                {
                    opcion = 6;
                }
                else
                {
                    opcion =-1;
                }
            }
        break;
        }
    }while(opcion!=6);

}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
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
            if((strcmp(list[i].lastName, list[j].lastName)) > 0 || ( (strcmp(list[i].lastName, list[j].lastName)) == 0 && list[i].sector > list[j].sector ))
            {
                auxEmployee=list[i];
                list[i]=list[j];
                list[j]=auxEmployee;
                retorno=0;
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
            if((strcmp(list[i].lastName, list[j].lastName)) < 0 || ( (strcmp(list[i].lastName, list[j].lastName)) == 0 && list[i].sector < list[j].sector ) )
            {
                auxEmployee=list[i];
                list[i]=list[j];
                list[j]=auxEmployee;
                retorno=0;
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

void eliminarEmpleado(Employee* list, int sizeList)
{
    int idToIndex;
    char resp;
    printEmployees(list, sizeList);
    idToIndex = findEmployeeById(list, sizeList, getInt("Ingrese la ID del empleado que desea ELIMINAR: "));
    while(idToIndex == -1)
    {
        idToIndex = findEmployeeById(list, sizeList, getInt("ERROR ID no encontrada REINGRESE: "));
    }
    printf("Esta SEGURO que quiere ELIMINAR al EMPLEADO:\n");
    printOneEmployee(list[idToIndex]);
    printf("Ingrese s/n: ");
    fflush(stdin);
    scanf("%c",&resp);
    if(resp=='s')
    {
        list[idToIndex].isEmpty = 1;
        printf("Se a ELIMINADO al EMPLEADO exitosamente.\n");
        pausa();
    }
    else
    {
        printf("Se a CANCELADO la ELIMINACION.\n");
        pausa();
    }
}

int cantidadDeEmpleados(Employee* list, int sizeList)
{
    int i;
    int cant=0;
    for(i=0; i<sizeList; i++)
    {
        if(!list[i].isEmpty)
        {
            cant++;
        }
    }
    return cant;
}

float totalSalario(Employee* list, int size)
{
    int i;
    float total=0;

    for(i=0; i<size; i++)
    {
        if(!list[i].isEmpty)
        {
            total += list[i].salary;
        }
    }
    return total;
}

int cantidadDeEmpladosSobrePromedio(Employee* list, int size)
{
    int i;
    float salarioTotal = totalSalario(list, size);
    int cantEpleados = cantidadDeEmpleados(list, size);
    float promedio = salarioTotal/cantEpleados;
    int cantSobrePromedio=0;

    for(i=0; i<size; i++)
    {
        if(list[i].salary > promedio && !list[i].isEmpty)
        {
            cantSobrePromedio++;
        }
    }

    return cantSobrePromedio;
}

int tieneCarga(Employee* list, int size)
{
    int valor=0;

    if(cantidadDeEmpleados(list, size) > 0)
    {
        valor=1;
    }
    return valor;
}
