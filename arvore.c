#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

// Cria um novo nó para a árvore
// Aloca memória dinamicamente e inicializa com o valor fornecido
// Retorna NULL se a alocação falhar
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

// Libera recursivamente toda a memória alocada para a árvore
// Usa percurso pós-ordem para garantir que os filhos sejam liberados antes do pai
void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);  // Libera subárvore esquerda
        liberar_arvore(raiz->direita);   // Libera subárvore direita
        free(raiz);                      // Libera o nó atual
    }
}

// Calcula a altura da árvore recursivamente
// Retorna -1 para árvore vazia
// A altura é a maior distância entre a raiz e uma folha
int altura(No* raiz) {
    if (raiz == NULL) {
        return -1;
    }
    
    int altura_esquerda = altura(raiz->esquerda);
    int altura_direita = altura(raiz->direita);
    
    // Retorna a maior altura entre as subárvores + 1 (nível atual)
    return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
}

// Conta o número total de nós na árvore recursivamente
// Usa a fórmula: total = 1 + nós_esquerda + nós_direita
int contar_nos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

// Conta o número de nós folha (nós sem filhos) recursivamente
// Um nó é folha se não tem filho esquerdo nem direito
int contar_folhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;  // Encontrou uma folha
    }
    return contar_folhas(raiz->esquerda) + contar_folhas(raiz->direita);
}

// Imprime a árvore em pré-ordem (raiz, esquerda, direita)
void imprimir_arvore(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);           // Visita a raiz
        imprimir_arvore(raiz->esquerda);     // Visita subárvore esquerda
        imprimir_arvore(raiz->direita);      // Visita subárvore direita
    }
}