#include "my_header.h"

void recebeArquivo(char nomeDoArquivo[], int *pPessoas, int *pAmizades){
    FILE *arquivo = fopen(nomeDoArquivo, "r");

    if (arquivo == NULL){
                printf("Nao foi possivel abrir o arquivo\n");
                getchar();
                return;
    }

    fscanf(arquivo,"%*s %*s %d %d", &*pPessoas,&*pAmizades);

    fclose(arquivo);
}

//Recebendo o nome do arquivo, lendo o arquivo e guardando os dois ultimos valores da primeira linha nas variaveis
//globais de TotalPessoas e TotalAmizades
