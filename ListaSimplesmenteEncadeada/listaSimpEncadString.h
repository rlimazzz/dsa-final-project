typedef struct {
    char name[100];
} Name;

typedef struct {
    int number;
} Number;

typedef struct stringElement* ListString;
typedef struct numberElement* ListNumber;

//Strings
ListString* createListString();
void freeStr(ListString* list);
int insertInit(ListString* list, Name name);
void insert_txt(const char *name_file, ListString* list);
int removeInit(ListString* list);
int sizeStr(ListString* list);
void writeFileStr(ListString* list, const char* name_file);

//Numeros
ListNumber* createListNumber();
void freeNumber(ListNumber* list);
int insertInitNumber(ListNumber* list, Number number);
void insert_bin(const char *name_file, ListNumber* list);
int removeInitNumber(ListNumber* list);
int sizeNumber(ListNumber* list);
void writeFileNumber(ListNumber* list, const char* name_file);

// algoritmos de ordenação
void bubble_sort_nomes(ListString* list);
void bubble_sort_numeros(ListNumber* list);

//void merge_sort_names();
//void merge_sort_number();
