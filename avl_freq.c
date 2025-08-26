#include <stdio.h> // Necessário para a função printf
#include "structures.h" // Necessário para a definição do Nó (Node)

/**
 * @brief Busca e imprime todas as palavras que correspondem a uma frequência específica.
 * * @param freq_root A raiz da árvore organizada por frequência.
 * @param freq A frequência a ser procurada.
 */
void search_by_frequency(Node* freq_root, int freq) {
    // Caso base: se o nó é nulo, não há nada a fazer.
    if (freq_root == NULL) {
        return;
    }
    
    // Verifica se o nó atual tem a frequência desejada.
    if (freq_root->data->total_repository_frequency == freq) {
        printf("  - Palavra: '%s' (Música: %s)\n", freq_root->data->word, freq_root->data->max_freq_music.song_name);
    }

    // Continua a busca em ambas as subárvores, pois pode haver outras
    // palavras com a mesma frequência em diferentes partes da árvore.
    search_by_frequency(freq_root->left, freq);
    search_by_frequency(freq_root->right, freq);
}