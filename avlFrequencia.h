#ifndef AVL_FREQUENCIA_H
#define AVL_FREQUENCIA_H
#include "estrutura.h"
No* construirAvlFrequencia(Vetor* vetor);
void buscarPorFrequencia(No* raiz, int frequencia);
void liberarAvlFrequencia(No* raiz);
#endif
