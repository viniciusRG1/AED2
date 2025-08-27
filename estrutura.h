#ifndef ESTRUTURA_H
#define ESTRUTURA_H
typedef struct InfoMusica {
    char* nomeMusica;
    char* compositor;
    char* trechoEstrofe;
    int frequenciaNaMusica;
} InfoMusica;

typedef struct InfoPalavra {
    char* palavra;
    int frequenciaTotalRepositorio;
    InfoMusica musicaMaiorFrequencia;
} InfoPalavra;

typedef struct No {
    InfoPalavra* dados;
    struct No* esquerda;
    struct No* direita;
    int altura;
} No;

typedef struct Vetor {
    InfoPalavra** itens;
    int capacidade;
    int tamanho;
} Vetor;
#endif
