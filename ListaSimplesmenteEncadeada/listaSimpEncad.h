typedef struct {
    char name[1000];
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
void bubble_sort_numeros_crescente(ListNumber* list);
void bubble_sort_numeros_decrescente(ListNumber* list);

void split_list(ListString source, ListString* frontRef, ListString* backRef);
ListString merge_sorted_lists(ListString a, ListString b, double* troca_count);
void merge_sort_names(ListString* list, double* troca_count);

void split_list_number(ListNumber source, ListNumber* frontRef, ListNumber* backRef);
ListNumber merge_sorted_lists_number_crescente(ListNumber a, ListNumber b, double* troca_count);
ListNumber merge_sorted_lists_number_decrescente(ListNumber a, ListNumber b, double* troca_count);
void merge_sort_number_crescente(ListNumber* list, double* troca_count);
void merge_sort_number_decrescente(ListNumber* list, double* troca_count);
