#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisaBinaria.h"

int compararInfoPalavra(const void* a, const void* b) {
    InfoPalavra* infoA = *(InfoPalavra**)a;
    InfoPalavra* infoB = *(InfoPalavra**)b;
    return strcmp(infoA->palavra, infoB->palavra);
}

void ordenarVetor(Vetor* vetor) {
    qsort(vetor->itens, vetor->tamanho, sizeof(InfoPalavra*), compararInfoPalavra);
}

Vetor* criarVetor(int capacidade) {
    Vetor* vetor = (Vetor*)malloc(sizeof(Vetor));
    vetor->capacidade = capacidade;
    vetor->tamanho = 0;
    vetor->itens = (InfoPalavra**)malloc(sizeof(InfoPalavra*) * capacidade);
    return vetor;
}

void inserirNoVetor(Vetor* vetor, InfoPalavra* dados) {
    if (vetor->tamanho == vetor->capacidade) {
        vetor->capacidade *= 2;
        vetor->itens = (InfoPalavra**)realloc(vetor->itens, sizeof(InfoPalavra*) * vetor->capacidade);
    }
    vetor->itens[vetor->tamanho++] = dados;
}

InfoPalavra* buscaBinariaNoVetor(Vetor* vetor, const char* palavra) {
    int inicio = 0;
    int fim = vetor->tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int comparacao = strcmp(vetor->itens[meio]->palavra, palavra);
        if (comparacao == 0) {
            return vetor->itens[meio];
        }
        if (comparacao < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return NULL;
}

void liberarVetor(Vetor* vetor) {
    for (int i = 0; i < vetor->tamanho; i++) {
        free(vetor->itens[i]->palavra);
        free(vetor->itens[i]->musicaMaiorFrequencia.nomeMusica);
        free(vetor->itens[i]->musicaMaiorFrequencia.compositor);
        free(vetor->itens[i]->musicaMaiorFrequencia.trechoEstrofe);
        free(vetor->itens[i]);
    }
    free(vetor->itens);
    free(vetor);
}
