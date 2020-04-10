

/** \brief = getFloat(char[]); toma un flotante
 *
 * \param char[] = mensaje de pedido
 * \return float
 *
 */
float getFloat(char[]);

/** \brief getFloatMin(char[], float, char[]); toma un flotante y lo valida con un minimo
 *
 * \param char[] = mensaje de pedido
 * \param float = el minimo para validar
 * \param char[] = mensaje de error
 * \return float
 *
 */
float getFloatMin(char[], float, char[]);

/** \brief getFloatMax(char[], float, char[]); toma un flotante y lo valida con un maximo
 *
 * \param char[] = mensaje de pedido
 * \param float = el maximo para validar
 * \param char[] = mensaje de error
 * \return float
 *
 */
float getFloatMax(char[], float, char[]);

/** \brief getFloatMinMax(char[], float, float, char[]); toma un flotante y lo valida dentro del rango ingresado
 *
 * \param char[] = mensaje de pedido
 * \param float = el minimo para validar
 * \param float = el maximo para validar
 * \param char[] = mensaje de error
 * \return float
 *
 */
float getFloatMinMax(char[], float, float, char[]);
