#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[50];
    float media;
    struct aluno* prox;
    struct aluno* ant;
} Aluno;

typedef struct lista {
    Aluno* inicio;
    int tamanho;
} ListaAlunos;

void insertionSort(ListaAlunos* lista) {
    int i, j;
    Aluno* chave;
    Aluno* atual;

    for (i = 1; i < lista->tamanho; i++) {
        chave = lista->inicio->prox;
        atual = chave->ant;
        for (j = i - 1; j >= 0 && atual->matricula > chave->matricula; j--) {
            atual->prox = chave->prox;
            chave->prox->ant = atual;
            atual->ant->prox = chave;
            chave->ant = atual->ant;
            atual->ant = chave;
            chave->prox = atual;
            if (atual == lista->inicio) {
                lista->inicio = chave;
            }
            chave = atual;
            atual = chave->ant;
        }
    }
}

int main() {
    ListaAlunos* lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista->inicio = NULL;
    lista->tamanho = 0;

    // Para adicionar algum aluno na lista, seguir o modelo:
    Aluno* a1 = (Aluno*) malloc(sizeof(Aluno));
    a1->matricula = 2;
    strcpy(a1->nome, "Aluno 1");
    a1->media = 8.5;
    a1->prox = NULL;
    a1->ant = NULL;
    lista->inicio = a1;
    lista->tamanho++;

    // Para ordenar a lista usando o insertion sort:
    insertionSort(lista);

    // Imprimir a lista ordenada:
    Aluno* atual = lista->inicio;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Media: %.1f\n", atual->matricula, atual->nome, atual->media);
        atual = atual->prox;
    }

    return 0;
}
