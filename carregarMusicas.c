#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include "carregarMusicas.h"

typedef struct PalavraNaMusica {
    char* palavra;
    int frequenciaNaMusica;
    char* primeiraLinhaOcorrencia;
    struct PalavraNaMusica* proximo;
} PalavraNaMusica;

void limparPalavra(char* palavra) {
    int i = 0, j = 0;
    while (palavra[i]) {
        if (isalpha(palavra[i])) {
            palavra[j++] = tolower(palavra[i]);
        }
        i++;
    }
    palavra[j] = '\0';
}

void processarArquivo(const char* nomeArquivo, Vetor* vetor) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        fprintf(stderr, "Aviso: Não foi possível abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }
    char linha[1024];
    char nomeMusica[256], compositor[256];
    if(fgets(nomeMusica, sizeof(nomeMusica), arquivo) == NULL) { fclose(arquivo); return; }
    nomeMusica[strcspn(nomeMusica, "\r\n")] = 0;
    if(fgets(compositor, sizeof(compositor), arquivo) == NULL) { fclose(arquivo); return; }
    compositor[strcspn(compositor, "\r\n")] = 0;
    PalavraNaMusica* listaPalavrasMusica = NULL;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char linhaOriginal[1024];
        strcpy(linhaOriginal, linha);
        char* contexto = NULL;
        char* palavraToken = strtok_r(linha, " \t\n\r", &contexto);
        while (palavraToken != NULL) {
            limparPalavra(palavraToken);
            if (strlen(palavraToken) > 3) {
                PalavraNaMusica* atual = listaPalavrasMusica;
                while(atual != NULL && strcmp(atual->palavra, palavraToken) != 0) {
                    atual = atual->proximo;
                }
                if (atual) {
                    atual->frequenciaNaMusica++;
                } else {
                    PalavraNaMusica* novaPalavra = (PalavraNaMusica*)malloc(sizeof(PalavraNaMusica));
                    novaPalavra->palavra = strdup(palavraToken);
                    novaPalavra->frequenciaNaMusica = 1;
                    novaPalavra->primeiraLinhaOcorrencia = strdup(linhaOriginal);
                    novaPalavra->proximo = listaPalavrasMusica;
                    listaPalavrasMusica = novaPalavra;
                }
            }
            palavraToken = strtok_r(NULL, " \t\n\r", &contexto);
        }
    }
    fclose(arquivo);
    PalavraNaMusica* atual = listaPalavrasMusica;
    while(atual != NULL) {
        InfoPalavra* palavraExistente = NULL;
        for(int i = 0; i < vetor->tamanho; ++i){
            if(strcmp(vetor->itens[i]->palavra, atual->palavra) == 0){
                palavraExistente = vetor->itens[i];
                break;
            }
        }
        if (palavraExistente) {
            palavraExistente->frequenciaTotalRepositorio += atual->frequenciaNaMusica;
            if (atual->frequenciaNaMusica > palavraExistente->musicaMaiorFrequencia.frequenciaNaMusica) {
                free(palavraExistente->musicaMaiorFrequencia.nomeMusica);
                free(palavraExistente->musicaMaiorFrequencia.compositor);
                free(palavraExistente->musicaMaiorFrequencia.trechoEstrofe);
                palavraExistente->musicaMaiorFrequencia.nomeMusica = strdup(nomeMusica);
                palavraExistente->musicaMaiorFrequencia.compositor = strdup(compositor);
                palavraExistente->musicaMaiorFrequencia.frequenciaNaMusica = atual->frequenciaNaMusica;
                char trechoFinal[101];
                strncpy(trechoFinal, atual->primeiraLinhaOcorrencia, 100);
                trechoFinal[100] = '\0';
                palavraExistente->musicaMaiorFrequencia.trechoEstrofe = strdup(trechoFinal);
            }
        } else {
            InfoPalavra* novaInfoPalavra = (InfoPalavra*)malloc(sizeof(InfoPalavra));
            novaInfoPalavra->palavra = strdup(atual->palavra);
            novaInfoPalavra->frequenciaTotalRepositorio = atual->frequenciaNaMusica;
            novaInfoPalavra->musicaMaiorFrequencia.nomeMusica = strdup(nomeMusica);
            novaInfoPalavra->musicaMaiorFrequencia.compositor = strdup(compositor);
            novaInfoPalavra->musicaMaiorFrequencia.frequenciaNaMusica = atual->frequenciaNaMusica;
            char trechoFinal[101];
            strncpy(trechoFinal, atual->primeiraLinhaOcorrencia, 100);
            trechoFinal[100] = '\0';
            novaInfoPalavra->musicaMaiorFrequencia.trechoEstrofe = strdup(trechoFinal);
            inserirNoVetor(vetor, novaInfoPalavra);
        }
        atual = atual->proximo;
    }
    atual = listaPalavrasMusica;
    while(atual != NULL) {
        PalavraNaMusica* proximo = atual->proximo;
        free(atual->palavra);
        free(atual->primeiraLinhaOcorrencia);
        free(atual);
        atual = proximo;
    }
}

void carregarMusica(const char* caminhoDiretorio, Vetor* vetor) {
    DIR* diretorio = opendir(caminhoDiretorio);
    if (diretorio == NULL) {
        perror("Erro ao abrir o diretório");
        return;
    }
    struct dirent* entradaDiretorio;
    printf("Lendo arquivos da pasta '%s'...\n", caminhoDiretorio);
    while ((entradaDiretorio = readdir(diretorio)) != NULL) {
        if (strstr(entradaDiretorio->d_name, ".txt")) {
            char caminhoCompleto[1024];
            snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminhoDiretorio, entradaDiretorio->d_name);
            printf("Processando: %s\n", caminhoCompleto);
            processarArquivo(caminhoCompleto, vetor);
        }
    }
    closedir(diretorio);
    printf("Leitura de arquivos concluída.\n");
}
