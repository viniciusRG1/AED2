// avl_alpha.h
#ifndef AVL_ALPHA_H
#define AVL_ALPHA_H

#include "structures.h"

// Insere ou atualiza uma palavra na árvore. A função agora gerencia a criação do WordInfo.
Node* insert_or_update_alpha(Node* node, const char* word, const char* song_name, const char* composer);

// Busca um nó na árvore pela palavra
Node* search_alpha(Node* root, const char* word);

// Libera a memória da árvore e de todos os dados (WordInfo) contidos nela
void free_avl_alpha_and_data(Node* root);

#endif // AVL_ALPHA_H