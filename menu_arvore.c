#include "arvore.h"
#include "abb.h"
#include "percursos.h"
#include <stdio.h>
#include <stdlib.h>

// Variáveis globais para o programa
// tipo_arvore: controla qual tipo de árvore está sendo usado
//   0: nenhuma árvore selecionada
//   1: árvore binária simples
//   2: árvore binária de busca (ABB)
int tipo_arvore = 0;

// Ponteiro para a raiz da árvore atual
No* raiz = NULL;

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar(); // Captura o Enter
}

void imprimir_menu() {
    limpar_tela();
    printf("=== MENU DE ARVORES ===\n");
    printf("1. Usar Arvore Binaria Simples\n");
    printf("2. Usar Arvore Binaria de Busca (ABB)\n");
    printf("3. Inserir elemento\n");
    printf("4. Buscar elemento\n");
    printf("5. Remover elemento\n");
    printf("6. Imprimir arvore\n");
    printf("7. Analise da arvore\n");
    printf("8. Percursos\n");
    printf("0. Sair\n\n");
    printf("Tipo atual: %s\n", 
           tipo_arvore == 0 ? "Nenhum" : 
           tipo_arvore == 1 ? "Arvore Binaria Simples" : "ABB");
    printf("\nEscolha uma opcao: ");
}

void menu_percursos() {
    limpar_tela();
    printf("=== MENU DE PERCURSOS ===\n");
    printf("1. Pre-ordem\n");
    printf("2. Em-ordem\n");
    printf("3. Pos-ordem\n");
    printf("4. Por niveis\n");
    printf("5. Mostrar todos os percursos\n");
    printf("0. Voltar\n\n");
    printf("Escolha uma opcao: ");

    int opcao;
    scanf("%d", &opcao);

    printf("\nResultado do percurso: ");
    switch(opcao) {
        case 1:
            printf("Pre-ordem: ");
            pre_ordem(raiz);
            break;
        case 2:
            printf("Em-ordem: ");
            em_ordem(raiz);
            break;
        case 3:
            printf("Pos-ordem: ");
            pos_ordem(raiz);
            break;
        case 4:
            printf("Por niveis: ");
            percurso_por_niveis(raiz);
            break;
        case 5:
            printf("Pre-ordem:   ");
            pre_ordem(raiz);
            printf("\nEm-ordem:    ");
            em_ordem(raiz);
            printf("\nPos-ordem:   ");
            pos_ordem(raiz);
            printf("\nPor niveis:  ");
            percurso_por_niveis(raiz);
            break;
    }
    printf("\n");
    pausar();
}

void menu_analise() {
    limpar_tela();
    printf("=== ANALISE DA ARVORE ===\n");
    printf("Altura: %d\n", altura(raiz));
    printf("Numero total de nos: %d\n", contar_nos(raiz));
    printf("Numero de folhas: %d\n", contar_folhas(raiz));
    
    if (tipo_arvore == 2) {
        printf("E uma ABB valida? %s\n", verificar_abb(raiz) ? "Sim" : "Nao");
        No* min = encontrar_minimo(raiz);
        No* max = encontrar_maximo(raiz);
        if (min) printf("Valor minimo: %d\n", min->valor);
        if (max) printf("Valor maximo: %d\n", max->valor);
    }
    
    pausar();
}

void inserir_elemento() {
    if (tipo_arvore == 0) {
        printf("Por favor, selecione primeiro o tipo de arvore (opcao 1 ou 2).\n");
        pausar();
        return;
    }

    int valor;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &valor);

    if (tipo_arvore == 2) { // ABB
        raiz = inserir_abb(raiz, valor);
        printf("Valor %d inserido na ABB.\n", valor);
    } else { // Árvore simples
        No* novo = criar_no(valor);
        if (raiz == NULL) {
            raiz = novo;
        } else {
            // Para árvore simples, vamos inserir como primeiro espaço disponível
            No* fila[1000];
            int frente = 0, tras = 0;
            fila[tras++] = raiz;

            while (frente < tras) {
                No* atual = fila[frente++];
                if (atual->esquerda == NULL) {
                    atual->esquerda = novo;
                    break;
                }
                if (atual->direita == NULL) {
                    atual->direita = novo;
                    break;
                }
                if (atual->esquerda) fila[tras++] = atual->esquerda;
                if (atual->direita) fila[tras++] = atual->direita;
            }
        }
        printf("Valor %d inserido na arvore simples.\n", valor);
    }
    pausar();
}

void buscar_elemento() {
    if (tipo_arvore == 0) {
        printf("Por favor, selecione primeiro o tipo de arvore (opcao 1 ou 2).\n");
        pausar();
        return;
    }

    int valor;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    No* resultado = NULL;
    if (tipo_arvore == 2) {
        resultado = buscar_abb(raiz, valor);
    } else {
        // Implementação de busca para árvore simples usando percurso em largura
        if (raiz) {
            No* fila[1000];
            int frente = 0, tras = 0;
            fila[tras++] = raiz;

            while (frente < tras) {
                No* atual = fila[frente++];
                if (atual->valor == valor) {
                    resultado = atual;
                    break;
                }
                if (atual->esquerda) fila[tras++] = atual->esquerda;
                if (atual->direita) fila[tras++] = atual->direita;
            }
        }
    }

    if (resultado) {
        printf("Valor %d encontrado na arvore!\n", valor);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valor);
    }
    pausar();
}

void remover_elemento() {
    if (tipo_arvore == 0) {
        printf("Por favor, selecione primeiro o tipo de arvore (opcao 1 ou 2).\n");
        pausar();
        return;
    }

    int valor;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &valor);

    if (tipo_arvore == 2) {
        raiz = remover_abb(raiz, valor);
        printf("Valor %d removido da ABB (se existia).\n", valor);
    } else {
        printf("Desculpe, a remocao nao esta implementada para arvore binaria simples.\n");
    }
    pausar();
}

int main() {
    int opcao;
    do {
        imprimir_menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Seleciona Árvore Binária Simples
                // Libera a árvore anterior se existir
                if (raiz != NULL) {
                    printf("Aviso: A arvore atual sera liberada.\n");
                    liberar_arvore(raiz);
                    raiz = NULL;
                }
                tipo_arvore = 1;
                printf("Modo Arvore Binaria Simples ativado.\n");
                pausar();
                break;

            case 2: // Seleciona Árvore Binária de Busca (ABB)
                // Libera a árvore anterior se existir
                if (raiz != NULL) {
                    printf("Aviso: A arvore atual sera liberada.\n");
                    liberar_arvore(raiz);
                    raiz = NULL;
                }
                tipo_arvore = 2;
                printf("Modo Arvore Binaria de Busca ativado.\n");
                pausar();
                break;

            case 3: // Inserir novo elemento na árvore
                // A função inserir_elemento() verifica o tipo de árvore
                // e faz a inserção apropriada
                inserir_elemento();
                break;

            case 4: // Buscar elemento na árvore
                // A função buscar_elemento() usa o algoritmo apropriado
                // dependendo do tipo de árvore
                buscar_elemento();
                break;

            case 5: // Remover elemento da árvore
                // A remoção só está implementada para ABB
                remover_elemento();
                break;

            case 6: // Imprimir árvore usando percurso em-ordem
                if (raiz == NULL) {
                    printf("Arvore vazia!\n");
                } else {
                    printf("Arvore em ordem: ");
                    em_ordem(raiz);
                    printf("\n");
                }
                pausar();
                break;

            case 7: // Análise completa da árvore
                // Mostra altura, número de nós, folhas e outras informações
                menu_analise();
                break;

            case 8: // Menu de diferentes tipos de percurso
                // Permite visualizar a árvore de diferentes formas
                menu_percursos();
                break;

            case 0: // Sair
                if (raiz != NULL) {
                    liberar_arvore(raiz);
                }
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);

    return 0;
}