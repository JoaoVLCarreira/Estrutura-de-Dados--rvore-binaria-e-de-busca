#include "abb.h"
#include "percursos.h"
#include <stdio.h>

void imprimir_resultado_busca(No* resultado, int valor) {
    if (resultado != NULL) {
        printf("Valor %d encontrado na arvore!\n", valor);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valor);
    }
}

int main() {
    No* raiz = NULL;
    
    // Testando inserção
    printf("Inserindo valores na arvore...\n");
    raiz = inserir_abb(raiz, 50);
    raiz = inserir_abb(raiz, 30);
    raiz = inserir_abb(raiz, 70);
    raiz = inserir_abb(raiz, 20);
    raiz = inserir_abb(raiz, 40);
    raiz = inserir_abb(raiz, 60);
    raiz = inserir_abb(raiz, 80);

    /*
    A árvore criada tem esta estrutura:
           50
         /    \
        30     70
       /  \   /  \
      20  40 60   80
    */

    printf("\narvore em ordem: ");
    em_ordem(raiz);  // Utilizando a função do arquivo arvore.h
    printf("\n");

    // Testando busca
    printf("\nTestando busca:\n");
    imprimir_resultado_busca(buscar_abb(raiz, 40), 40);
    imprimir_resultado_busca(buscar_abb(raiz, 90), 90);

    // Testando mínimo e máximo
    No* min = encontrar_minimo(raiz);
    No* max = encontrar_maximo(raiz);
    printf("\nValor minimo na arvore: %d\n", min->valor);
    printf("Valor maximo na arvore: %d\n", max->valor);

    // Testando verificação de ABB
    printf("\nE uma arvore binaria de busca valida? %s\n", 
           verificar_abb(raiz) ? "Sim" : "Nao");

    // Testando remoção
    printf("\nRemovendo o valor 30...\n");
    raiz = remover_abb(raiz, 30);
    printf("Arvore em ordem apos remocao: ");
    em_ordem(raiz);
    printf("\n");

    // Verificando se ainda é uma ABB válida após a remoção
    printf("E uma arvore binaria de busca valida apos remocao? %s\n", 
           verificar_abb(raiz) ? "Sim" : "Nao");

    // Liberando a memória
    liberar_arvore(raiz);
    printf("\nArvore liberada com sucesso!\n");

    return 0;
}