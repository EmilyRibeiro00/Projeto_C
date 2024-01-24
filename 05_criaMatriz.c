#include "my_header.h"

int **criaMatriz(){
    int **matriz = calloc(totalPessoas,sizeof(int*)); //????

    if(matriz==NULL){
        printf("Erro ao criar matriz");
    }
    for (int linha = 0; linha < totalPessoas; linha++) {
        matriz[linha] = calloc(totalPessoas,sizeof(int));
    }
    return matriz;
}

//alocando dinamicamente espaço para a matriz totalPessoasXtotalPessoas, inicializando as linhas e colunas com zero
/* Exemplo
    00000
    00000
    00000
    00000
    00000
*/
