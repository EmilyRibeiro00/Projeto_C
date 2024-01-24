#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<unistd.h>
#define COLUNAS 2

/**Struct**/

typedef struct {
    int pessoa;
    int qtd_conexoes;
}MaiorComunidade;

/**Variaveis Globais**/

extern int totalPessoas;
extern int totalAmizades;

/** Prototipo de Funçoes**/

void recebeArquivo(char nomeDoArquivo[], int *pPessoas, int *pAmizades);

int **retornaLista(char nomeDoArquivo[]);

void imprimeLista(int **lis, int linha_atual, int coluna_atual);

int **criaMatriz();

void imprimeMatriz(int **mat);

void populaMatrizDeAdjacencia(int **mat, int **lis);

int **encontraComunidade(int **mat);

void ordenaListaDeConexao(int **lis);

int *criaVetorMaiorComunidade(int **mat, int *lis);

int * criaVetorPessoas(int **lista);

MaiorComunidade * criaStructComunidade(int qtd_pessoas_na_maior_comunidade, int* maior_comunidade, int** lista_qtd_conexao_nao_ordenada, int**matriz_adj);

void criaArquivoSaida(MaiorComunidade * array_de_comunidades, int qtd_pessoas);
