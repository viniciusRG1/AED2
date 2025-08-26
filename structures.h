// structures.h
#ifndef STRUCTURES_H
#define STRUCTURES_H

// Estrutura para armazenar as informações da música
typedef struct MusicInfo {
    char* song_name;
    char* composer;
    char* stanza_snippet;
    int in_song_frequency;
} MusicInfo;

// Estrutura principal para cada palavra
typedef struct WordInfo {
    char* word;
    int total_repository_frequency;
    MusicInfo max_freq_music;
} WordInfo;

// Nó unificado para ambas as Árvores AVL
typedef struct Node {
    WordInfo* data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

#endif // STRUCTURES_H