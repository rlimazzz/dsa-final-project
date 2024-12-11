typedef struct element* List;
typedef struct element Element;

List* createList();
int appendInit(List *list, int element);
int deleteInit(List *list);
int removeFirst(List *list, int number);
int removeLast(List *list, int number);
void freeList(List *list);
void print(List *list);