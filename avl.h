#ifndef AVL_H
#define AVL_H
#include "estrutura.h"
No* inserirEmAvl(No* raiz, InfoPalavra* dados);
No* buscarEmAvl(No* raiz, const char* palavra);
void liberarAvl(No* raiz);
#endif
