


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee); //listo

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployee(LinkedList* pArrayListEmployee); //listo

int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);//listo

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int set_ultimaId(char* path, LinkedList* pArrayListEmployee); //listo
int get_ultimaId(char* path, int* ultimaId); //listo
int set_ultimaIdTo(char* path, int id); //listo
