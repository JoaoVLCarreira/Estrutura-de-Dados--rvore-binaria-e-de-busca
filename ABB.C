
#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

No* inserir_abb(No* raiz, int valor) {
    // Se a árvore está vazia, cria um novo nó
    if (raiz == NULL) {
        return criar_no(valor);
    }

    // Insere recursivamente na subárvore apropriada
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_abb(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_abb(raiz->direita, valor);
    }
    // Se o valor já existe, não faz nada

    return raiz;
}

No* buscar_abb(No* raiz, int valor) {
    // Se a árvore está vazia ou encontrou o valor
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Busca recursivamente na subárvore apropriada
    if (valor < raiz->valor) {
        return buscar_abb(raiz->esquerda, valor);
    }
    return buscar_abb(raiz->direita, valor);
}

No* encontrar_minimo(No* raiz) {
    No* atual = raiz;
    // O menor valor sempre está na extremidade esquerda
    while (atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* encontrar_maximo(No* raiz) {
    No* atual = raiz;
    // O maior valor sempre está na extremidade direita
    while (atual != NULL && atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual;
}

No* remover_abb(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    // Busca o nó a ser removido
    if (valor < raiz->valor) {
        raiz->esquerda = remover_abb(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = remover_abb(raiz->direita, valor);
    }
    else {
        // Nó com um ou nenhum filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos
        No* temp = encontrar_minimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover_abb(raiz->direita, temp->valor);
    }
    return raiz;
}

// Função auxiliar para verificação da ABB
int verificar_abb_aux(No* raiz, int min, int max) {
    if (raiz == NULL) {
        return 1;
    }

    // Verifica se o valor atual está dentro dos limites
    if (raiz->valor <= min || raiz->valor >= max) {
        return 0;
    }

    // Verifica recursivamente as subárvores
    return verificar_abb_aux(raiz->esquerda, min, raiz->valor) &&
           verificar_abb_aux(raiz->direita, raiz->valor, max);
}

int verificar_abb(No* raiz) {
    return verificar_abb_aux(raiz, INT_MIN, INT_MAX);
}
