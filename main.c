#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tamanhoPalavra 20
#define listaDeMusicas "listaDeMusica"

typedef struct {
    char nomeMusica[20];
    char nomeDoAutor[20];
    char *letra;
} estruturaMusica;

void removerBarraN(char *valComBarraN){
    valComBarraN[strcspn(valComBarraN,"\n")] = 0;
}

estruturaMusica carregarArquivo(const char* musicaArquivo){
    estruturaMusica musica;
    musica.letra = NULL;
    FILE *arquivo = fopen(musicaArquivo, "r");
    if(arquivo == NULL){
        perror("Erro ao abrir arquivo");
        strcpy(musica.nomeMusica, "ERRO");
        return musica;
    }
    if(fgets(musica.nomeMusica, sizeof(musica.nomeMusica), arquivo)){
        removerBarraN(musica.nomeMusica);
    }
    if(fgets(musica.nomeDoAutor, sizeof(musica.nomeDoAutor), arquivo)){
        removerBarraN(musica.nomeDoAutor);
    }
    size_t capacidade = 1024;
    musica.letra = (char*)malloc(capacidade);
    if(musica.letra == NULL){
        perror("falha em carregar a musica");
        fclose(arquivo);
        return musica;
    }
    musica.letra[0];
    char linhaBuffer[512];
    while (fgets(linhaBuffer, sizeof(linhaBuffer), arquivo) != NULL){
        if(strlen(musica.letra)+strlen(linhaBuffer)+ 1 > capacidade){
            capacidade *= 2;
            char *temp = (char*)realloc(musica.letra, capacidade);
            if(temp == NULL){
                perror("falha a realocao da letra");
                free(musica.letra);
                musica.letra = NULL;
                break;
            }
            musica.letra = temp;
        }
        strcat(musica.letra, linhaBuffer);
    }
    fclose(arquivo);
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
    opcoes();

}

void opcoes(){
    int escolha;
    menu();
    scanf("qual opcao ?", &escolha);
    menu();
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
