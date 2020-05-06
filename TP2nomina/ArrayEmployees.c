#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{
    int i;//employee

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }
}
