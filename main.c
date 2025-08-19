#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanhoPalavra 20


char* escolherPalavra(){
    char* palavra = (char*)malloc(tamanhoPalavra*sizeof(char));
    printf("escolha uma palavra: ");
    if(palavra == NULL){
        printf("erro\n");
        return -1;
    }else{
    scanf("%49s", palavra);
    return palavra;
}
}

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
    switch(opcoes){
    case 1:
        vetorBinario();
        break;
    case 2:
        arvoreBinario();
        break;
    case 3:
        arvoreAVL();
        break;
    case 4:
        vetorBinario();
        arvoreBinario();
        break;
    case 5:
        vetorBinario();
        arvoreAVL();
        break;
    case 6:
        arvoreBinario();
        arvoreAVL();
        break;
    case 7:
        vetorBinario();
        arvoreBinario();
        arvoreAVL();
        break;
    }
}



int main()
{
    char* escolherPalavra = escolherPalavra();
    menu();
    return 0;
}
