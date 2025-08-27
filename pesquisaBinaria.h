#ifndef PESQUISA_BINARIA_H
#define PESQUISA_BINARIA_H
#include "estrutura.h"
Vetor* criarVetor(int capacidade);
void inserirNoVetor(Vetor* vetor, InfoPalavra* dados);
InfoPalavra* buscaBinariaNoVetor(Vetor* vetor, const char* palavra);
void liberarVetor(Vetor* vetor);
void ordenarVetor(Vetor* vetor);
#endif
