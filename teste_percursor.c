#include "arvore.h"
#include "percursos.h"
#include <stdio.h>

int main() {
    // Criando uma árvore de exemplo
    No* raiz = criar_no(1);
    raiz->esquerda = criar_no(2);
    raiz->direita = criar_no(3);
    raiz->esquerda->esquerda = criar_no(4);
    raiz->esquerda->direita = criar_no(5);
    raiz->direita->esquerda = criar_no(6);
    raiz->direita->direita = criar_no(7);

    /*
    A árvore criada tem esta estrutura:
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */

    printf("Percurso em Pre-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf("Percurso Em-ordem: ");
    em_ordem(raiz);
    printf("\n");

    printf("Percurso em Pos-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    printf("Percurso por Niveis: ");
    percurso_por_niveis(raiz);
    printf("\n");

    // Liberando a memória
    liberar_arvore(raiz);
    printf("Arvore liberada com sucesso!\n");

    return 0;
}