#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
   * A1.0 GET DATOS (Int)
   * A2.0 GET DATOS (Float)
   * A3.0 GET DATOS (char)
   * -  A3.1 GET DATOS -nombre- (char)
   * B1.0 MENUS
   *
   *
*/




///////////////////////////////////////////////////////////A1.0 GET DATOS (Int) ////////////////////////////////////////////////////////////
int getInt(char pedido[]);
int getIntMmR(int opcion, char pedido[], char error[], int maximo, int minimo);

///////////////////////////////////////////////////////////A2.0 GET DATOS (Float)////////////////////////////////////////////////////////////
float getFloat(char pedido[]);
float getFloatMmR(int opcion, char pedido[], char error[], float maximo, float minimo);

///////////////////////////////////////////////////////////A3.0 GET DATOS (char)////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////A3.1 GET DATOS -nombre- (char)///////////////////////////////////////////////////
/** \brief pide un nombre y lo guarda en el array especificado en char nombre[] el nombre o apellido se modificar para que
 *         para que quede todo mayusculas(2) o solo la primera letra(1) esto se especifica en el int formato esta funcion
 *         esta funcion admite nombres largos ej: Matias Ezequiel. o nombres de una sola palabra.
 *
 * \param formato int  indica el formato (1)Formato (2)FORMATO
 * \param pedido[] char
 * \param nombre[] char se indica el array donde se guardara el nombre
 * \param sizeNombre int
 * \return void
 *
 */
void getNombre(int formato, char pedido[], char nombre[], int sizeNombre);
///////////////////////////////////////////////////////////B1.0 MENUS///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////Z1.0 OTRAS///////////////////////////////////////////////////////////////////////
char *strlwr(char *str); //para que funcione en GDB hay que implementarla manualmente

/** \brief realiza una pausa en el programa hasta que se presione una tecla
 *
 * \param void
 * \return void
 *
 */
void pausa(void);

/** \brief pide que se ingrese si o no y lo devulve en binario
 *
 * \param pedido[] char la pregunta
 * \param error[] char mensaje en caso de ingresar caracteres incorrectos
 * \return int 0 no, 1 si
 *
 */
int getSON(char pedido[], char error[]);
