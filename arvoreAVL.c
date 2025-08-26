#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "avl_alpha.h"
#include "avl_freq.h"

// Protótipo da função que carrega os arquivos (deve estar em um .h)
void load_files_into_avl(const char* dir_path, Node** avl_root);

// Função para imprimir as informações da palavra
void print_word_info_avl(WordInfo* info) {
    if (info) {
        printf("Palavra: '%s'\n", info->word);
        printf("  Frequencia total: %d\n", info->total_repository_frequency);
        printf("  Exemplo de musica: '%s' por %s\n", info->max_freq_music.song_name, info->max_freq_music.composer);
    } else {
        printf("Palavra nao encontrada.\n");
    }
}

// ESTA É A FUNÇÃO QUE A MAIN CHAMA
void arvoreAVL() {
    Node* avl_root = NULL;
    int data_loaded = 0;

    // 1. Carregar os arquivos
    printf("Iniciando carga dos arquivos para a Arvore AVL...\n");
    load_files_into_avl("LetrasMusicas", &avl_root);
    data_loaded = (avl_root != NULL);
    if(data_loaded) {
        printf("Arquivos carregados com sucesso.\n");
    } else {
        printf("Nenhum dado foi carregado. Verifique a pasta 'LetrasMusicas'.\n");
        return;
    }

    // 2. Menu de busca interno
    int choice;
    printf("\n--- Opcoes de Busca na Arvore AVL ---\n");
    printf("1. Buscar por Palavra\n");
    printf("2. Buscar por Frequencia\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // 3. Buscar por Palavra
        char word[100];
        printf("Digite a palavra para buscar: ");
        scanf("%s", word);
        
        Node* result = search_alpha(avl_root, word);
        print_word_info_avl(result ? result->data : NULL);

    } else if (choice == 2) {
        // 4. Buscar por Frequência
        int freq;
        printf("Digite a frequencia para buscar: ");
        scanf("%d", &freq);

        printf("Construindo arvore de frequencia para a busca...\n");
        Node* freq_root = build_freq_avl(avl_root);
        
        printf("Palavras com frequencia %d:\n", freq);
        search_by_frequency(freq_root, freq);

        // Libera apenas os nós da árvore temporária
        free_avl_freq_nodes(freq_root);
    } else {
        printf("Opcao invalida.\n");
    }

    // 5. Liberar a memória
    free_avl_alpha_and_data(avl_root);
    printf("Memoria da arvore AVL liberada.\n");
}