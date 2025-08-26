// avl_freq.h
#ifndef AVL_FREQ_H
#define AVL_FREQ_H

#include "structures.h"

// Constrói a árvore de frequência a partir da árvore alfabética principal
Node* build_freq_avl(Node* alpha_root);

// Busca e imprime todas as palavras com uma dada frequência
void search_by_frequency(Node* freq_root, int freq);

// Libera APENAS os nós da árvore de frequência, não os dados
void free_avl_freq_nodes(Node* root);

#endif // AVL_FREQ_H