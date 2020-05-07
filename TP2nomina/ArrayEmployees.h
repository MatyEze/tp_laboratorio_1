#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZELIST 30
typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

void hardCode10Employees(Employee* list, int len);//hardcodeo 10 empleados.



/** \brief Para indicar que todas las posiciones del array est�n vac�as,  esta funci�n pone la bandera
 *              (isEmpty) en TRUE en todas las posiciones del array.
 *
 * \param list Employee*  Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief Agrega en un array de empleados existente los valores recibidos como par�metro en la primer posici�n libre.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief busca un espacio libre y devuelve el indice del primero que encuentre.
 *
 * \param list Employee*
 * \param len int
 * \return int -1 si no encuentra espacio si encuentra devuelve indice.
 *
 */
int findEmptyEmployee(Employee* list, int len);


/** \brief Busca un empleado recibiendo como par�metro de b�squeda su Id y devuelve el indice
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Elimina de manera l�gica (isEmpty Flag en 1) un empleado recibiendo como par�metro su Id.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param list Employee*
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

int sortEmployeesUp(Employee* list, int len);
int sortEmployeesDown(Employee* list, int len);
void swapEmployees(int i, int j, Employee* list, int len);

/** \brief Imprime el array de empleados de forma encolumnada.
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

void printOneEmployee(Employee employee);
