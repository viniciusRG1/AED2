#ifndef CARREGAR_MUSICAS_H
#define CARREGAR_MUSICAS_H
#include "estrutura.h"
#include "pesquisaBinaria.h"
#include "bst.h"
#include "avl.h"
void processarArquivo(const char* nomeArquivo, Vetor* vetor);
void carregarMusica(const char* caminhoDiretorio, Vetor* vetor);
void limparPalavra(char* palavra);
#endif
