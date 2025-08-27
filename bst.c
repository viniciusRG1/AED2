#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

No* criarNo(InfoPalavra* dados) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dados = dados;
    novoNo->esquerda = novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

No* inserirEmBst(No* raiz, InfoPalavra* dados) {
    if (raiz == NULL) {
        return criarNo(dados);
    }
    int comparacao = strcmp(dados->palavra, raiz->dados->palavra);
    if (comparacao < 0) {
        raiz->esquerda = inserirEmBst(raiz->esquerda, dados);
    } else if (comparacao > 0) {
        raiz->direita = inserirEmBst(raiz->direita, dados);
    }
    return raiz;
}

No* buscarEmBst(No* raiz, const char* palavra) {
    if (raiz == NULL || strcmp(raiz->dados->palavra, palavra) == 0) {
        return raiz;
    }
    if (strcmp(palavra, raiz->dados->palavra) < 0) {
        return buscarEmBst(raiz->esquerda, palavra);
    }
    return buscarEmBst(raiz->direita, palavra);
}

void liberarBst(No* raiz) {
    if (raiz == NULL) return;
    liberarBst(raiz->esquerda);
    liberarBst(raiz->direita);
    free(raiz);
}
