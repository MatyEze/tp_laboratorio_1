
/** \brief toma los datos del archivo csv selecionado, los tranforma en datos employee y luego los carga en una linkedlist selecionada
 *
 * \param pFile FILE* puntero del archivo csv
 * \param pArrayListEmployee LinkedList* puntero de la linkedlist destino
 * \return int -1 si los parametros pasados son NULL, 1 todo ok
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
