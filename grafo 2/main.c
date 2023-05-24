#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void mostra_vetor(int *vet, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

void mostra_vetor2(float *vet, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%.2f ", vet[i]);
    printf("\n");
}

int main() {
    Grafo *gr = cria_grafo(5, 5, 1);
    int eh_digrafo = 1;
    insere_aresta(gr, 0, 1, eh_digrafo, 1);
    insere_aresta(gr, 1, 3, eh_digrafo, 2);
    insere_aresta(gr, 1, 2, eh_digrafo, 3);
    insere_aresta(gr, 2, 4, eh_digrafo, 4);
    insere_aresta(gr, 3, 0, eh_digrafo, 5);
    insere_aresta(gr, 3, 4, eh_digrafo, 6);
    insere_aresta(gr, 4, 1, eh_digrafo, 7);
    imprime_grafo(gr);
    
    int num_adjacentes;
    int *adjacentes;
    for (int i = 0; i < 5; i++) {
        adjacentes = obter_adjacentes(gr, i, &num_adjacentes);

        if (adjacentes != NULL) {
            printf("Adjacentes do nó %d: ", i);
            for (int i = 0; i < num_adjacentes; i++) {
                printf("%d ", adjacentes[i]);
            }
            printf("\n");

            free(adjacentes);
        }
    }

    libera_grafo(gr);
    return 0;
}