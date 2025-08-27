#ifndef BST_H
#define BST_H
#include "estrutura.h"
No* inserirEmBst(No* raiz, InfoPalavra* dados);
No* buscarEmBst(No* raiz, const char* palavra);
void liberarBst(No* raiz);
#endif
