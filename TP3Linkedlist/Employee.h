#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define EMPLOYEENAME_SIZE 128
typedef struct
{
    int id;
    char nombre[EMPLOYEENAME_SIZE];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea un dato Employee en memoria y devuelve su puntero
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief crea un dato Employee en memoria con parapetros en forma de string y devuelve su puntero
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief muestra con printf el empleado selecionado
 *
 * \param this Employee*
 * \return int -1 si this es NULL, 1 todo OK
 *
 */
int printEmployee(Employee* this);

void employee_delete();
int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);
////////////////seters y geters///////////////////////////////////////////
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
//////////////////////////////////////////////////////////////////////////



#endif // employee_H_INCLUDED
