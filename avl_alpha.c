#include <string.h> // Necessário para a função strcmp
#include "structures.h" // Necessário para a definição do Nó (Node)

/**
 * @brief Procura por um nó na árvore AVL com base em uma palavra-chave.
 * * @param root A raiz da árvore onde a busca será realizada.
 * @param word A palavra a ser procurada.
 * @return Node* Retorna o ponteiro para o nó encontrado ou NULL se a palavra não existir na árvore.
 */
Node* search_alpha(Node* root, const char* word) {
    // Caso base 1: a árvore está vazia (a palavra não existe).
    // Caso base 2: a palavra no nó atual é a que procuramos.
    if (root == NULL || strcmp(root->data->word, word) == 0) {
        return root;
    }

    // Se a palavra a ser procurada for alfabeticamente menor que a palavra do nó atual,
    // continue a busca na subárvore esquerda.
    if (strcmp(word, root->data->word) < 0) {
        return search_alpha(root->left, word);
    }

    // Se a palavra a ser procurada for maior, continue a busca na subárvore direita.
    return search_alpha(root->right, word);
}