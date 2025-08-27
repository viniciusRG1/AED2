#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "bst.h"

int obterAltura(No* no);
int maximo(int a, int b);
No* rotacaoDireita(No* noY);
No* rotacaoEsquerda(No* noX);
int obterFatorBalanceamento(No* no);
No* criarNoAvl(InfoPalavra* dados);

int obterAltura(No* no) {
    if (no == NULL) return 0;
    return no->altura;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

No* criarNoAvl(InfoPalavra* dados) {
    No* no = (No*)malloc(sizeof(No));
    no->dados = dados;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;
    return no;
}

No* rotacaoDireita(No* noY) {
    No* noX = noY->esquerda;
    No* subArvoreT2 = noX->direita;
    noX->direita = noY;
    noY->esquerda = subArvoreT2;
    noY->altura = maximo(obterAltura(noY->esquerda), obterAltura(noY->direita)) + 1;
    noX->altura = maximo(obterAltura(noX->esquerda), obterAltura(noX->direita)) + 1;
    return noX;
}

No* rotacaoEsquerda(No* noX) {
    No* noY = noX->direita;
    No* subArvoreT2 = noY->esquerda;
    noY->esquerda = noX;
    noX->direita = subArvoreT2;
    noX->altura = maximo(obterAltura(noX->esquerda), obterAltura(noX->direita)) + 1;
    noY->altura = maximo(obterAltura(noY->esquerda), obterAltura(noY->direita)) + 1;
    return noY;
}

int obterFatorBalanceamento(No* no) {
    if (no == NULL) return 0;
    return obterAltura(no->esquerda) - obterAltura(no->direita);
}

No* inserirEmAvl(No* no, InfoPalavra* dados) {
    if (no == NULL) return criarNoAvl(dados);
    int comparacao = strcmp(dados->palavra, no->dados->palavra);
    if (comparacao < 0)
        no->esquerda = inserirEmAvl(no->esquerda, dados);
    else if (comparacao > 0)
        no->direita = inserirEmAvl(no->direita, dados);
    else
        return no;
    no->altura = 1 + maximo(obterAltura(no->esquerda), obterAltura(no->direita));
    int fatorBalanceamento = obterFatorBalanceamento(no);
    if (fatorBalanceamento > 1 && strcmp(dados->palavra, no->esquerda->dados->palavra) < 0)
        return rotacaoDireita(no);
    if (fatorBalanceamento < -1 && strcmp(dados->palavra, no->direita->dados->palavra) > 0)
        return rotacaoEsquerda(no);
    if (fatorBalanceamento > 1 && strcmp(dados->palavra, no->esquerda->dados->palavra) > 0) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }
    if (fatorBalanceamento < -1 && strcmp(dados->palavra, no->direita->dados->palavra) < 0) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }
    return no;
}

No* buscarEmAvl(No* raiz, const char* palavra) {
    return buscarEmBst(raiz, palavra);
}

void liberarAvl(No* raiz) {
    liberarBst(raiz);
}
