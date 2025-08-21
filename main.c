#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define tamanhoPalavra 21
#define listaDeMusicas "listaDeMusica"
#define tamanhoDaEstrofe 101

typedef struct {
    char nomeMusica[tamanhoPalavra];
    char nomeDoAutor[tamanhoPalavra];
    char estrofe[tamanhoDaEstrofe];
    char **palavras;
    int numPalavras;
} estruturaMusica;

void removerBarraN(char *valComBarraN){
    valComBarraN[strcspn(valComBarraN,"\n")] = 0;
}

void tratamentoMusica(estruturaMusica *infos){
    int tamanho = 2;
    for(int i = 0; i < infos->numPalavras; i++){
        int tamanhoAtual = strlen(infos->palavras[i]);
        if(tamanho >= tamanhoAtual){
            free(infos->palavras[i]);
            for(int aux = i; aux<infos->numPalavras - 1; aux++){
                infos->palavras[aux] = infos->palavras[aux + 1];
                infos->numPalavras--;
            }
        }
        for(int aux = 0; infos->palavras[i][aux]; aux++){
            infos->palavras[i][aux] = tolower(infos->palavras[i][aux]);
        }
    }
    char **aux = realloc(infos->palavras, infos->numPalavras * sizeof(char *));

 }

estruturaMusica carregarArquivo(const char* musicaArquivo) {
    estruturaMusica musica;
    musica.palavras = NULL;
    musica.numPalavras = 0;
    musica.estrofe[0] = '\0';
    musica.nomeMusica[0] = '\0';
    FILE *arquivo = fopen(musicaArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        strcpy(musica.nomeMusica, "ERRO");
        return musica;
    }
    if (fgets(musica.nomeMusica, sizeof(musica.nomeMusica), arquivo)) {
        removerBarraN(musica.nomeMusica);
    }
    if (fgets(musica.nomeDoAutor, sizeof(musica.nomeDoAutor), arquivo)) {
        removerBarraN(musica.nomeDoAutor);
    }
    size_t capacidadeLetra = 2048;
    char *letraCompleta = (char*) malloc(capacidadeLetra);
    letraCompleta[0] = '\0';
    char linhaBuffer[512];
    while (fgets(linhaBuffer, sizeof(linhaBuffer), arquivo) != NULL) {
        if (strlen(letraCompleta) + strlen(linhaBuffer) + 1 > capacidadeLetra) {
            capacidadeLetra *= 2;
            char *aux = (char*) realloc(letraCompleta, capacidadeLetra);
            if(aux == NULL) {
                    break;
            }
            letraCompleta = aux;
        }
        strcat(letraCompleta, linhaBuffer);
    }
    fclose(arquivo);
    char *fimEstrofe = strstr(letraCompleta, "\n\n");
    int tamanhoEstrofe = 0;
    if (fimEstrofe != NULL) {
        tamanhoEstrofe = fimEstrofe - letraCompleta;
    } else {
        tamanhoEstrofe = strlen(letraCompleta);
    }
    int tamanho_copia = tamanhoEstrofe < tamanhoDaEstrofe ? tamanhoEstrofe : tamanhoDaEstrofe;
    strncpy(musica.estrofe, letraCompleta, tamanho_copia);
    musica.estrofe[tamanho_copia] = '\0';
    char *letraVetor = strdup(letraCompleta);
    size_t capacidadePalavras = 50;
    musica.palavras = (char**) malloc(capacidadePalavras * sizeof(char*));
    char *palavra = strtok(letraVetor, "\n.,!?");
    while (palavra != NULL) {
        if (musica.numPalavras >= capacidadePalavras) {
            capacidadePalavras *= 2;
            musica.palavras = (char**) realloc(musica.palavras, capacidadePalavras * sizeof(char*));
        }
        char *novaPalavra = strdup(palavra);
        musica.palavras[musica.numPalavras] = novaPalavra;
        musica.numPalavras++;

        palavra = strtok(NULL, "\n.,!?");
    }
    return musica;
}


char* escolherPalavra(){
    char* palavra = (char*)malloc(tamanhoPalavra*sizeof(char));
    printf("escolha uma palavra: ");
    if(palavra == NULL){
        char* error = "error";
        printf("erro\n");
        return error;
    }else{
    scanf("%49s", palavra);
    return palavra;
}
}

void opcoes(void);

void menu(){
    printf("1 - vetor binario\n");
    printf("2 - arvore binario\n");
    printf("3 - arvore AVL\n");
    printf("4 - comparacao vetor e arvore binaria\n");
    printf("5 - comparacao vetor e arvore AVL\n");
    printf("6 - comparacao entre arvores");
    printf("7 - comparacao entre vetor, arvore binaria e arvore AVL\n");
    printf("8 - freqencia de uma palavra\n");
    opcoes();

}

void casos(int opcao);

void opcoes(){
    int escolha;
    menu();
    scanf("qual opcao ?", &escolha);
    casos(escolha);
}

void pesquisaBinario(){
}

void arvoreBinario(){
}

void arvoreAVL(){

}

void casos(int opcoes){
    clock_t inicioVetor, fimVetor,inicioArvoreB, fimArvoreB, inicioArvoreAVL, fimArvoreAVL;
    double tempoGastoVetor, tempoGastoArvoreB, tempoGastoArvoreAVL;
    switch(opcoes){
    case 1:
        inicioVetor = clock();
        pesquisaBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        printf("o tempo gasto por pesquisa binario foi%f\n", tempoGastoVetor);
        break;
    case 2:
        inicioVetor = clock();
        arvoreBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        printf("o tempo gasto por arvore binarioa foi%f\n", tempoGastoArvoreB);
        break;
    case 3:
        inicioArvoreAVL = clock();
        arvoreAVL();
        fimArvoreAVL = clock();
        tempoGastoArvoreAVL = fimArvoreAVL - inicioArvoreAVL;
        printf("o tempo gasto por arvore AVL foi%f\n", tempoGastoArvoreAVL);
        break;
    case 4:
        inicioVetor = clock();
        pesquisaBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioVetor = clock();
        arvoreBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        printf("o tempo gasto por pesquisa binario foi%f\n", tempoGastoVetor);
        printf("o tempo gasto por arvore binarioa foi%f\n", tempoGastoArvoreB);
        break;
    case 5:
        inicioVetor = clock();
        pesquisaBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioArvoreAVL = clock();
        arvoreAVL();
        fimArvoreAVL = clock();
        tempoGastoArvoreAVL = fimArvoreAVL - inicioArvoreAVL;
        printf("o tempo gasto por pesquisa binario foi%f\n", tempoGastoVetor);
        printf("o tempo gasto por arvore AVL foi%f\n", tempoGastoArvoreAVL);
        break;
    case 6:
        inicioVetor = clock();
        arvoreBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioArvoreAVL = clock();
        arvoreAVL();
        fimArvoreAVL = clock();
        tempoGastoArvoreAVL = fimArvoreAVL - inicioArvoreAVL;
        printf("o tempo gasto por arvore binarioa foi%f\n", tempoGastoArvoreB);
        printf("o tempo gasto por arvore AVL foi%f\n", tempoGastoArvoreAVL);
        break;
    case 7:
        inicioVetor = clock();
        pesquisaBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioVetor = clock();
        arvoreBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioArvoreAVL = clock();
        arvoreAVL();
        fimArvoreAVL = clock();
        tempoGastoArvoreAVL = fimArvoreAVL - inicioArvoreAVL;
        printf("o tempo gasto por pesquisa binario foi%f\n", tempoGastoVetor);
        printf("o tempo gasto por arvore binarioa foi%f\n", tempoGastoArvoreB);
        printf("o tempo gasto por arvore AVL foi%f\n", tempoGastoArvoreAVL);
        break;
    case 8:

    }
}

void primeiraEstrofe(FILE *arquivo){
    char linha[100];
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }
}

void nomeCompositor(FILE *arquivo){
    char linha[20];
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }
    primeiraEstrofe(arquivo);
}

void nomeDaMusica(FILE *arquivo){
    char linha[40];
    while(fgets(linha, sizeof(linha), arquivo)!= NULL){
        printf("%s", linha);
    }
    nomeCompositor(arquivo);
}

int main()
{
    char *palavraEscolhida = escolherPalavra();
    menu();
    return 0;
}
