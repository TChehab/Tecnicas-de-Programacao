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
        for (j = i - 1; j >= 0 && atual->media > chave->media; j--) {
            atual->prox = chave->prox;
            if (chave->prox != NULL) {
                chave->prox->ant = atual;
            }
            atual->ant->prox = chave;
            chave->ant = atual->ant;
            atual->ant = chave;
            chave->prox = atual;
            if (atual == lista->inicio) {
                lista->inicio = chave;
            }
            atual = chave;
            chave = atual->prox; 
        }
    }
}


int main() {
    ListaAlunos* lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista->inicio = NULL;
    lista->tamanho = 0;

    // Para adicionar algum aluno na lista, seguir o modelo:
    Aluno* a1 = (Aluno*) malloc(sizeof(Aluno));
    a1->matricula = 2211194;
    strcpy(a1->nome, "Tiago Chehab");
    a1->media = 7;
    a1->prox = NULL;
    a1->ant = NULL;
    lista->inicio = a1;
    lista->tamanho++;
    
    Aluno* a2 = (Aluno*) malloc(sizeof(Aluno));
    a2->matricula = 2298474;
    strcpy(a2->nome, "Gabriel Brandao");
    a2->media = 9;
    a2->prox = NULL;
    a2->ant = a1;
    a1->prox = a2;
    lista->tamanho++;

    Aluno* a3 = (Aluno*) malloc(sizeof(Aluno));
    a3->matricula = 2236187;
    strcpy(a3->nome, "Enzo Filippelli");
    a3->media = 4.5;
    a3->prox = NULL;
    a3->ant = a2;
    a2->prox = a3;
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
