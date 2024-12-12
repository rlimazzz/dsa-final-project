#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimpEncadString.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    Nome dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_inicio(Lista* li, Nome nome){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = nome;
    no->prox = (*li);
    *li = no;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

void escreve_lista_em_arquivo(Lista* li, const char* nome_arquivo) {
    if (li == NULL || *li == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Abre o arquivo em modo de escrita
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
        return;
    }

    // Percorre a lista e escreve cada elemento em uma nova linha
    Elem* no = *li;
    while (no != NULL) {
        fprintf(arquivo, "%s\n", no->dados.nome);
        no = no->prox;
    }
    fclose(arquivo);

    printf("Lista escrita com sucesso no arquivo '%s'.\n", nome_arquivo);
}

//Algoritmos de ordenação

void bubble_sort_nomes(Lista* li) {
    if (li == NULL || *li == NULL)
        return;

    int trocou;
    Elem* no;
    int limite = tamanho_lista(li);
    printf("%d\n", limite);
    do {
        trocou = 0;
        no = *li;

        for (int i = 0; i < limite - 1; i++) {
            if (strcmp(no->dados.nome, no->prox->dados.nome) > 0) {
                Nome temp = no->dados;
                no->dados = no->prox->dados;
                no->prox->dados = temp;
                trocou = 1;
            }
            no = no->prox;
        }
        printf("\r%d", limite);
        limite--; 
    } while (trocou);
}
