#include "percursos.h"
#include <stdio.h>
#include <stdlib.h>

// Estrutura da fila para percurso por níveis
typedef struct FilaNo {
    No* no;
    struct FilaNo* prox;
} FilaNo;

typedef struct {
    FilaNo* frente;
    FilaNo* tras;
} Fila;

// Funções auxiliares para a fila
Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->frente = NULL;
        f->tras = NULL;
    }
    return f;
}

void enfileirar(Fila* f, No* no) {
    FilaNo* novo = (FilaNo*)malloc(sizeof(FilaNo));
    if (novo != NULL) {
        novo->no = no;
        novo->prox = NULL;
        if (f->tras != NULL) {
            f->tras->prox = novo;
        } else {
            f->frente = novo;
        }
        f->tras = novo;
    }
}

No* desenfileirar(Fila* f) {
    if (f->frente == NULL) return NULL;
    
    FilaNo* temp = f->frente;
    No* no = temp->no;
    f->frente = f->frente->prox;
    if (f->frente == NULL) {
        f->tras = NULL;
    }
    free(temp);
    return no;
}

void liberar_fila(Fila* f) {
    while (f->frente != NULL) {
        FilaNo* temp = f->frente;
        f->frente = f->frente->prox;
        free(temp);
    }
    free(f);
}

// Implementação dos percursos
void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);  // Visita a raiz
        pre_ordem(raiz->esquerda);   // Percorre subárvore esquerda
        pre_ordem(raiz->direita);    // Percorre subárvore direita
    }
}

void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);    // Percorre subárvore esquerda
        printf("%d ", raiz->valor);   // Visita a raiz
        em_ordem(raiz->direita);     // Percorre subárvore direita
    }
}

void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);   // Percorre subárvore esquerda
        pos_ordem(raiz->direita);    // Percorre subárvore direita
        printf("%d ", raiz->valor);   // Visita a raiz
    }
}

void percurso_por_niveis(No* raiz) {
    if (raiz == NULL) return;

    Fila* f = criar_fila();
    enfileirar(f, raiz);

    while (f->frente != NULL) {
        No* no_atual = desenfileirar(f);
        printf("%d ", no_atual->valor);

        if (no_atual->esquerda != NULL) {
            enfileirar(f, no_atual->esquerda);
        }
        if (no_atual->direita != NULL) {
            enfileirar(f, no_atual->direita);
        }
    }

    liberar_fila(f);
}