#ifndef ABB_H
#define ABB_H

#include "arvore.h"

// Funções específicas para Árvore Binária de Busca (ABB)

// Insere um novo valor mantendo a propriedade de ABB:
// - valores menores à esquerda
// - valores maiores à direita
No* inserir_abb(No* raiz, int valor);

// Busca um valor na ABB usando a propriedade de ordenação
// Retorna o nó se encontrar, NULL caso contrário
No* buscar_abb(No* raiz, int valor);

// Remove um valor da ABB mantendo sua propriedade de ordenação
No* remover_abb(No* raiz, int valor);

// Encontra o valor mínimo na ABB (nó mais à esquerda)
No* encontrar_minimo(No* raiz);

// Encontra o valor máximo na ABB (nó mais à direita)
No* encontrar_maximo(No* raiz);

// Verifica se a árvore é uma ABB válida
// Retorna 1 se for válida, 0 caso contrário
int verificar_abb(No* raiz);

#endif