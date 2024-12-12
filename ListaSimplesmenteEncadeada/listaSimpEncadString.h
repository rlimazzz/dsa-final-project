typedef struct {
    char name[100];
} Name;

typedef struct stringElement* ListString;
typedef struct numberElement* ListNumber;

//Strings
ListString* createListString();
void freeStr(ListString* list);
int insertInit(ListString* list, Name name);
int removeInit(ListString* list);
int sizeStr(ListString* list);
void writeFileStr(ListString* list, const char* name_file);

//Numeros
ListNumber* createListNumber();
void freeNumber(ListNumber* list);
int insertInitNumber(ListNumber* list, Name name);
int removeInitNumber(ListNumber* list);
int sizeNumber(ListNumber* list);
void writeFileNumber(ListNumber* list, const char* name_file);

// algoritmos de ordenação
void bubble_sort_nomes(ListString* list);
//void bubble_sort_number();

//void merge_sort_names();
//void merge_sort_number();
