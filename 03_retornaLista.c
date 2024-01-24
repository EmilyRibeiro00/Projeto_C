#include "my_header.h"

int **retornaLista(char nomeDoArquivo[]){
    char linhaIgnorada[20];
    int linha = 0;
    char linhaTexto[20];
    int **lista; //Matriz nx2
    lista = malloc(sizeof(int*)*totalAmizades); //Alocando espaço para os ponteiros para as linhas

    for (int i = 0; i < totalAmizades; i++){ //Alocando espaço para cada linha (array de inteiros)
        lista[i] = malloc(sizeof(int)*COLUNAS);
    }

    FILE *arquivo = fopen(nomeDoArquivo, "r"); // Abrindo arquivo

    if (arquivo == NULL){
        printf("Não foi possível abrir o arquivo.\n");
    }

    fgets(linhaIgnorada, sizeof(linhaIgnorada), arquivo); ///Lendo e ignorando a 1° linha do arquivo

    //Percorre o arquivo, partindo da 2° linha, até a ultima linha, populando a lista com os dados do arquivo
    for (linha = 0; linha < totalAmizades && fgets(linhaTexto, sizeof(linhaTexto), arquivo) != NULL; linha++) {
        sscanf(linhaTexto, "%*c %d %d", &lista[linha][0], &lista[linha][1]);
    }
    fclose(arquivo);
    return lista;
}

// Função para ler um arquivo contendo informações sobre amizades e retornar uma matriz nX2
// onde n é a quantidade de pessoas e cada linha representa uma pessoa com suas amizades.
