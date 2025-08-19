#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanhoPalavra 20


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

void vetorBinario(){
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
        vetorBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        printf("o tempo gasto por vetor binario foi%f\n", tempoGastoVetor);
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
        vetorBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioVetor = clock();
        arvoreBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        printf("o tempo gasto por vetor binario foi%f\n", tempoGastoVetor);
        printf("o tempo gasto por arvore binarioa foi%f\n", tempoGastoArvoreB);
        break;
    case 5:
        inicioVetor = clock();
        vetorBinario();
        fimVetor = clock();
        tempoGastoVetor = fimVetor - inicioVetor;
        inicioArvoreAVL = clock();
        arvoreAVL();
        fimArvoreAVL = clock();
        tempoGastoArvoreAVL = fimArvoreAVL - inicioArvoreAVL;
        printf("o tempo gasto por vetor binario foi%f\n", tempoGastoVetor);
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
        vetorBinario();
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
        printf("o tempo gasto por vetor binario foi%f\n", tempoGastoVetor);
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


int main()
{
    char *palavraEscolhida = escolherPalavra();
    menu();
    return 0;
}
