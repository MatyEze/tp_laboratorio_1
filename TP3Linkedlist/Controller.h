


/** \brief se encarga de llamar a las funciones para hacer la carga desde un archivo csv a la linkedlist selecionada
 *
 * \param path char* ubicacion del archivo csv
 * \param pArrayListEmployee LinkedList* puntero de la linkedlist selecionada
 * \return int -1 si no se realiza el parseo, 1 todo OK
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee); //listo

/** \brief lista todo los empleados cargados en la linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int -1 si pArrayListEmployee es NULL, 1 si todo OK
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee); //listo

/** \brief guarda los datos de la linkedlist selecionada en un archivo csv selecionado
 *
 * \param path char* ubicacion del archivo csv
 * \param pArrayListEmployee LinkedList* puntero de linkedlist selecionada
 * \return int -1 si hay problemas con el archivo csv, 1 todo OK
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);//listo

/** \brief compara todas las id de la linkedlist con la del archivo csv selecionado si hay alguna id mayor a la del archivo esta seria la nueva ultima id
 *
 * \param path char* ubicacion del archivo csv donde se guarda la ultima id
 * \param pArrayListEmployee LinkedList* puntero de la linkedlist
 * \return int -1 si hay problemas con el archivo csv, 1 todo  OK
 *
 */
int set_ultimaId(char* path, LinkedList* pArrayListEmployee); //listo

/** \brief lee la ultima id desde el archivo csv y lo guarda como entero en la variable selecionada
 *
 * \param path char* ubicacion del archivo csv donde se guarda la ultima id
 * \param ultimaId int*
 * \return int -1 si hay problemas con el archivo csv, 1 todo  OK
 *
 */
int get_ultimaId(char* path, int* ultimaId); //listo

/** \brief seta la ultima id al valor pasado por parametros
 *
 * \param path char* ubicacion del archivo csv donde se guarda la ultima id
 * \param id int valor al que se quiere setear la ultima id
 * \return int -1 si hay problemas con el archivo csv, 1 todo  OK
 *
 */
int set_ultimaIdTo(char* path, int id); //listo

int controller_addEmployee(LinkedList* pArrayListEmployee); //listo

int getEmployeeById(LinkedList* pArrayListEmployee, int id, int* index); //listo

int controller_editEmployee(LinkedList* pArrayListEmployee); //listo

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


int controller_removeEmployee(LinkedList* pArrayListEmployee);
