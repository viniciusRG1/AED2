#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estrutura.h"
#include "pesquisaBinaria.h"
#include "bst.h"
#include "avl.h"
#include "avlFrequencia.h"
#include "carregarMusicas.h"

void imprimirMenu() {
    printf("\n--- Repositório de Músicas ---\n");
    printf("1. Carregar todas as músicas da pasta 'LetrasMusicas'\n");
    printf("2. Buscar por palavra\n");
    printf("3. Buscar por frequência\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

void imprimirInfoPalavra(InfoPalavra* info) {
    if (info) {
        printf("Palavra: '%s'\n", info->palavra);
        printf("  Frequência total: %d\n", info->frequenciaTotalRepositorio);
        printf("  Encontrada na música (exemplo):\n");
        printf("    - Título: %s\n", info->musicaMaiorFrequencia.nomeMusica);
        printf("    - Compositor: %s\n", info->musicaMaiorFrequencia.compositor);
    } else {
        printf("Palavra não encontrada.\n");
    }
}

int main() {
    Vetor* vetor = criarVetor(1000);
    No* raizBst = NULL;
    No* raizAvl = NULL;
    int dadosCarregados = 0;
    int opcao;
    do {
        imprimirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                if (dadosCarregados) {
                    printf("Os dados já foram carregados.\n");
                    break;
                }
                clock_t inicio, fim;
                double tempoCpuUsado;
                const char* nomeDiretorio = "LetrasMusicas";
                inicio = clock();
                carregarMusica(nomeDiretorio, vetor);
                fim = clock();
                tempoCpuUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\n--- Tempos de Carga e Construção ---\n");
                printf("1. Tempo para processar arquivos e popular o vetor: %f segundos\n", tempoCpuUsado);
                inicio = clock();
                ordenarVetor(vetor);
                fim = clock();
                tempoCpuUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("2. Tempo para ordenar o vetor: %f segundos\n", tempoCpuUsado);
                inicio = clock();
                for (int i = 0; i < vetor->tamanho; i++) {
                    raizBst = inserirEmBst(raizBst, vetor->itens[i]);
                }
                fim = clock();
                tempoCpuUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("3. Tempo para construir a Árvore de Busca Binária (BST): %f segundos\n", tempoCpuUsado);
                inicio = clock();
                for (int i = 0; i < vetor->tamanho; i++) {
                    raizAvl = inserirEmAvl(raizAvl, vetor->itens[i]);
                }
                fim = clock();
                tempoCpuUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("4. Tempo para construir a Árvore AVL: %f segundos\n", tempoCpuUsado);
                if (vetor->tamanho > 0) {
                    dadosCarregados = 1;
                    printf("\nCarga finalizada. Total de %d palavras únicas no repositório.\n", vetor->tamanho);
                } else {
                     printf("\nNenhuma palavra foi carregada. Verifique o caminho da pasta e o conteúdo dos arquivos.\n");
                }
                break;
            }
            case 2: {
                 if (!dadosCarregados) {
                    printf("Por favor, carregue os dados primeiro (opção 1).\n");
                    break;
                }
                char palavraParaBuscar[100];
                printf("Digite a palavra para buscar: ");
                scanf("%s", palavraParaBuscar);
                limparPalavra(palavraParaBuscar);
                clock_t inicio, fim;
                double tempoUsado;
                inicio = clock();
                InfoPalavra* resultadoVetor = buscaBinariaNoVetor(vetor, palavraParaBuscar);
                fim = clock();
                tempoUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\n--- Vetor (Busca Binária) ---\n");
                imprimirInfoPalavra(resultadoVetor);
                printf("Tempo de busca: %f segundos\n", tempoUsado);
                inicio = clock();
                No* resultadoBst = buscarEmBst(raizBst, palavraParaBuscar);
                fim = clock();
                tempoUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\n--- Árvore Binária de Busca ---\n");
                imprimirInfoPalavra(resultadoBst ? resultadoBst->dados : NULL);
                printf("Tempo de busca: %f segundos\n", tempoUsado);
                inicio = clock();
                No* resultadoAvl = buscarEmAvl(raizAvl, palavraParaBuscar);
                fim = clock();
                tempoUsado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\n--- Árvore AVL ---\n");
                imprimirInfoPalavra(resultadoAvl ? resultadoAvl->dados : NULL);
                printf("Tempo de busca: %f segundos\n", tempoUsado);
                break;
            }
            case 3: {
                if (!dadosCarregados) {
                    printf("Por favor, carregue os dados primeiro (opção 1).\n");
                    break;
                }
                int frequenciaParaBuscar;
                printf("Digite a frequência para buscar: ");
                scanf("%d", &frequenciaParaBuscar);
                printf("Construindo árvore AVL por frequência...\n");
                No* raizAvlFrequencia = construirAvlFrequencia(vetor);
                printf("Palavras encontradas com frequência %d:\n", frequenciaParaBuscar);
                buscarPorFrequencia(raizAvlFrequencia, frequenciaParaBuscar);
                liberarAvlFrequencia(raizAvlFrequencia);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    liberarVetor(vetor);
    liberarBst(raizBst);
    liberarAvl(raizAvl);
    return 0;
}
