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

void troca(Aluno* a, Aluno* b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(ListaAlunos* lista) {
    int i, j;
    Aluno* atual;
    Aluno* proximo;

    for (i = 0; i < lista->tamanho - 1; i++) {
        atual = lista->inicio;
        proximo = atual->prox;
        for (j = 0; j < lista->tamanho - i - 1; j++) {
            if (atual->media > proximo->media) {
                troca(atual, proximo);
            }
            atual = atual->prox;
            proximo = proximo->prox;
        }
    }
}

int main() {
    ListaAlunos* lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista->inicio = NULL;
    lista->tamanho = 0;

    // Para adicionar algum aluno na lista, fazer:
    Aluno* a1 = (Aluno*) malloc(sizeof(Aluno));
    a1->matricula = 1;
    strcpy(a1->nome, "Aluno 1");
    a1->media = 8.5;
    a1->prox = NULL;
    a1->ant = NULL;
    lista->inicio = a1;
    lista->tamanho++;
    
    Aluno* a2 = (Aluno*) malloc(sizeof(Aluno));
    a2->matricula = 2;
    strcpy(a2->nome, "Aluno 2");
    a2->media = 9.0;
    a2->prox = NULL;
    a2->ant = a1;
    a1->prox = a2;
    lista->tamanho++;

    Aluno* a3 = (Aluno*) malloc(sizeof(Aluno));
    a3->matricula = 3;
    strcpy(a3->nome, "Aluno 3");
    a3->media = 7.0;
    a3->prox = NULL;
    a3->ant = a2;
    a2->prox = a3;
    lista->tamanho++;

    // Para ordena a lista usando o bubble sort:
    bubbleSort(lista);

    // Imprimir a lista ordenada:
    Aluno* atual = lista->inicio;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Media: %.1f\n", atual->matricula, atual->nome, atual->media);
        atual = atual->prox;
    }

    return 0;
}
