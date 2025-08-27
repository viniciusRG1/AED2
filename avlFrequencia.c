#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlFrequencia.h"

int obterAlturaFrequencia(No* no) { if (no == NULL) return 0; return no->altura; }
int maximoFrequencia(int a, int b) { return (a > b) ? a : b; }

No* rotacaoDireitaFrequencia(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    y->altura = maximoFrequencia(obterAlturaFrequencia(y->esquerda), obterAlturaFrequencia(y->direita)) + 1;
    x->altura = maximoFrequencia(obterAlturaFrequencia(x->esquerda), obterAlturaFrequencia(x->direita)) + 1;
    return x;
}

No* rotacaoEsquerdaFrequencia(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    x->altura = maximoFrequencia(obterAlturaFrequencia(x->esquerda), obterAlturaFrequencia(x->direita)) + 1;
    y->altura = maximoFrequencia(obterAlturaFrequencia(y->esquerda), obterAlturaFrequencia(y->direita)) + 1;
    return y;
}

int obterFatorBalanceamentoFrequencia(No* no) {
    if (no == NULL) return 0;
    return obterAlturaFrequencia(no->esquerda) - obterAlturaFrequencia(no->direita);
}

No* inserirEmAvlFrequencia(No* no, InfoPalavra* dados) {
    if (no == NULL) {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->dados = dados;
        novoNo->esquerda = novoNo->direita = NULL;
        novoNo->altura = 1;
        return novoNo;
    }
    if (dados->frequenciaTotalRepositorio < no->dados->frequenciaTotalRepositorio)
        no->esquerda = inserirEmAvlFrequencia(no->esquerda, dados);
    else if (dados->frequenciaTotalRepositorio > no->dados->frequenciaTotalRepositorio)
        no->direita = inserirEmAvlFrequencia(no->direita, dados);
    else {
        if (strcmp(dados->palavra, no->dados->palavra) < 0)
             no->esquerda = inserirEmAvlFrequencia(no->esquerda, dados);
        else
             no->direita = inserirEmAvlFrequencia(no->direita, dados);
    }
    no->altura = 1 + maximoFrequencia(obterAlturaFrequencia(no->esquerda), obterAlturaFrequencia(no->direita));
    int fatorBalanceamento = obterFatorBalanceamentoFrequencia(no);
    if (fatorBalanceamento > 1 && dados->frequenciaTotalRepositorio < no->esquerda->dados->frequenciaTotalRepositorio)
        return rotacaoDireitaFrequencia(no);
    if (fatorBalanceamento < -1 && dados->frequenciaTotalRepositorio > no->direita->dados->frequenciaTotalRepositorio)
        return rotacaoEsquerdaFrequencia(no);
    if (fatorBalanceamento > 1 && dados->frequenciaTotalRepositorio > no->esquerda->dados->frequenciaTotalRepositorio) {
        no->esquerda = rotacaoEsquerdaFrequencia(no->esquerda);
        return rotacaoDireitaFrequencia(no);
    }
    if (fatorBalanceamento < -1 && dados->frequenciaTotalRepositorio < no->direita->dados->frequenciaTotalRepositorio) {
        no->direita = rotacaoDireitaFrequencia(no->direita);
        return rotacaoEsquerdaFrequencia(no);
    }
    return no;
}

No* construirAvlFrequencia(Vetor* vetor) {
    No* raiz = NULL;
    for (int i = 0; i < vetor->tamanho; i++) {
        raiz = inserirEmAvlFrequencia(raiz, vetor->itens[i]);
    }
    return raiz;
}

void buscarPorFrequencia(No* raiz, int frequencia) {
    if (raiz == NULL) {
        return;
    }
    if (frequencia < raiz->dados->frequenciaTotalRepositorio) {
        buscarPorFrequencia(raiz->esquerda, frequencia);
    } else if (frequencia > raiz->dados->frequenciaTotalRepositorio) {
        buscarPorFrequencia(raiz->direita, frequencia);
    } else {
        printf("  - Palavra: '%s' (Frequência: %d)\n", raiz->dados->palavra, raiz->dados->frequenciaTotalRepositorio);
        buscarPorFrequencia(raiz->esquerda, frequencia);
        buscarPorFrequencia(raiz->direita, frequencia);
    }
}

void liberarAvlFrequencia(No* raiz) {
    if (raiz == NULL) return;
    liberarAvlFrequencia(raiz->esquerda);
    liberarAvlFrequencia(raiz->direita);
    free(raiz);
}
