#ifndef ARVORE_H
#define ARVORE_H

// Estrutura do nó da árvore binária
// Cada nó contém um valor inteiro e ponteiros para os filhos da esquerda e direita
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Funções básicas para manipulação da árvore binária
// Cria um novo nó com o valor especificado
No* criar_no(int valor);

// Libera toda a memória alocada para a árvore
void liberar_arvore(No* raiz);

// Calcula a altura da árvore (distância da raiz até a folha mais profunda)
int altura(No* raiz);

// Conta o número total de nós na árvore
int contar_nos(No* raiz);

// Conta o número de nós folha (nós sem filhos)
int contar_folhas(No* raiz);

// Imprime a árvore
void imprimir_arvore(No* raiz);

#endif