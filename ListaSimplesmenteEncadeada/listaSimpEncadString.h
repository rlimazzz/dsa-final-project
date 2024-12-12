typedef struct {
    char nome[100];
} Nome;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_inicio(Lista* li, Nome nome);
int remove_lista_inicio(Lista* li);
int tamanho_lista(Lista* li);
void escreve_lista_em_arquivo(Lista* li, const char* nome_arquivo);

// algoritmos de ordenação
void bubble_sort_nomes(Lista* li);
