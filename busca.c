#include<stdio.h>

typedef struct registro {
    int id;
    char nome[50];
    char nome_carro[50];
    char cor_carro[50];
    struct registro* prox;
}   Registro;

Registro* buscalinear(Registro* lista, int id) {
    Registro* atual = lista;
    while (atual!= NULL && atual -> id != id){
        atual = atual -> prox;
    }
    return atual;
}

int main() {
    Registro a, b, c, *resultado;
    
    // Define valores para os registros "a", "b" e "c"
    a.id = 1;
    strcpy(a.nome, "João");
    strcpy(a.nome_carro, "Fusca");
    strcpy(a.cor_carro, "Azul");
    a.prox = &b;

    b.id = 2;
    strcpy(b.nome, "Maria");
    strcpy(b.nome_carro, "Gol");
    strcpy(b.cor_carro, "Vermelho");
    b.prox = &c;

    c.id = 3;
    strcpy(c.nome, "Pedro");
    strcpy(c.nome_carro, "Uno");
    strcpy(c.cor_carro, "Branco");
    c.prox = NULL;

    // Busca um registro com ID igual a 2 na lista encadeada
    resultado = buscalinear(&a, 2);

    // Verifica se o registro foi encontrado
    if (resultado == NULL) {
        printf("Registro nao encontrado.\n");
    } else {
        printf("Registro encontrado: %d, %s, %s, %s\n", resultado->id, resultado->nome, resultado->nome_carro, resultado->cor_carro);
    }

    return 0;
}
