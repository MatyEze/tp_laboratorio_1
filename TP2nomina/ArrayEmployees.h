#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesgnr.h"
#define SIZELIST 1000
#define SIZENAME 51


typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

void hardCode10Employees(Employee* list, int len);//hardcodeo 10 empleados.



/** \brief Para indicar que todas las posiciones del array están vacías,  esta función pone la bandera
 *              (isEmpty) en TRUE en todas las posiciones del array.
 *
 * \param list Employee*  Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
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


/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id y devuelve el indice
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
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

/** \brief ordena la lista de empleados de la A a la Z y por sector de menor a mayor
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int sortEmployeesUp(Employee* list, int len);

/** \brief ordena la lista de empleados de la Z a la A y por sector de mayor a menor
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int sortEmployeesDown(Employee* list, int len);


/** \brief cambia los datos de una estructura Employee (i) por otra (j) dentro de un array mediante sus indices
 *
 * \param i int indice
 * \param j int indice
 * \param list Employee*
 * \param len int
 * \return void
 *
 */
void swapEmployees(int i, int j, Employee* list, int len);

/** \brief Imprime el array de empleados de forma encolumnada.
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Mustra un emplado solo si isEmpty es 0
 *
 * \param employee Employee
 * \return void
 *
 */
void printOneEmployee(Employee employee);

/** \brief carga un empleado a un espacio vacio si no hay espacio lo notifica y cancela la opercion
 *         tambien genera una nueva ID tomando la ultima id usada y sumandole 1. la funcion retorna
 *         la ID generada en forma de int.
 *
 * \param list Employee*
 * \param sizeList int
 * \param lastID int ultima ID generada
 * \return int devuelve la nueva "ultima ID generada"
 *
 */
int cargarEmpleado(Employee* list,int sizeList, int lastID);

/** \brief encuentra por ID y abre un menu para modificar a un empleado
 *
 * \param list Employee*
 * \param sizeList int
 * \return void
 *
 */
void modificarEmpleado(Employee* list, int sizeList);

/** \brief muestra lista de empleados y pide una ID para empezar el proceso de baja del empleado
 *
 * \param list Employee*
 * \param sizeList int
 * \return void
 *
 */
void eliminarEmpleado(Employee* list, int sizeList);

/** \brief devuelve en forma de int la cantidad de emlpeados cargados.
 *
 * \param list Employee*
 * \param sizeList int
 * \return int
 *
 */
int cantidadDeEmpleados(Employee* list, int sizeList);

/** \brief Suma todo los salarios de los empleados cargados.
 *
 * \param list Employee*
 * \param size int
 * \return float
 *
 */
float totalSalario(Employee* list, int size);

/** \brief Devuelve en forma de int la cantidad de empleados que superan el salario promedio.
 *
 * \param list Employee*
 * \param size int
 * \return int
 *
 */
int cantidadDeEmpladosSobrePromedio(Employee* list, int size);

/** \brief verifica si hay empleados cargados.
 *
 * \param list Employee*
 * \param size int
 * \return int [0] no hay carga, [1] si hay carga.
 *
 */
int tieneCarga(Employee* list, int size);
