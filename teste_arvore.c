#include "arvore.h"
#include <stdio.h>

int main() {
    // Criando uma árvore de exemplo
    No* raiz = criar_no(10);
    raiz->esquerda = criar_no(5);
    raiz->direita = criar_no(15);
    raiz->esquerda->esquerda = criar_no(3);
    raiz->esquerda->direita = criar_no(7);
    raiz->direita->direita = criar_no(20);

    // Testando todas as funções
    printf("Imprimindo a arvore em pre-ordem: ");
    imprimir_arvore(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", altura(raiz));
    printf("Numero total de nos: %d\n", contar_nos(raiz));
    printf("Numero de folhas: %d\n", contar_folhas(raiz));

    // Liberando a memória
    liberar_arvore(raiz);
    printf("Arvore liberada com sucesso!\n");

    return 0;
}