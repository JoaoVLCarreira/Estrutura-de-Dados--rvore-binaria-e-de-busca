#ifndef PERCURSOS_H
#define PERCURSOS_H

#include "arvore.h"

// Funções de percurso em árvore binária

// Percurso em pré-ordem: visita raiz, subárvore esquerda, subárvore direita
// Útil para copiar ou serializar a árvore
void pre_ordem(No* raiz);

// Percurso em-ordem: visita subárvore esquerda, raiz, subárvore direita
// Em uma ABB, visita os nós em ordem crescente
void em_ordem(No* raiz);

// Percurso em pós-ordem: visita subárvore esquerda, subárvore direita, raiz
// Útil para deletar a árvore (visita filhos antes do pai)
void pos_ordem(No* raiz);

// Percurso por níveis: visita nós nível por nível, da esquerda para direita
// Usa uma estrutura de fila para controlar a ordem de visita
void percurso_por_niveis(No* raiz);

#endif