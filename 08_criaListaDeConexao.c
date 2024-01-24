#include "my_header.h"

int** encontraComunidade(int **mat){
    int **qtd_conex;
    qtd_conex = malloc(sizeof(int*)*totalPessoas); //alocando espaço para as linhas

    for (int i = 0; i < totalPessoas; i++) {
        qtd_conex[i] = malloc(sizeof(int)*COLUNAS); // alocando espaço para as colunas
    }

    int conexao = 0;
    for (int i = 0; i < totalPessoas ; i ++){
        for (int j = 0; j < totalPessoas; j ++){
            if (j > i) {  //para acessar apenas a matriz superior
                if (mat[i][j] == 1 ){
                    conexao++;}
            }
        }
        qtd_conex[i][0] = i+1; //atualiza o número da pessoa, pois o i=0 corresponde a pessoa 1
        qtd_conex[i][1] = conexao; //atribui o numero de conexoes a segunda coluna na matriz TPxN
        conexao = 0; //reinicia a variavel conexao para a proxima pessoa
    }
    return qtd_conex;
}

//funçao que pecorre a matriz TPxTP e cria uma matriz TPxN, utilizando-se de dois loops,um para pecorrer as linhas e outro as colunas,
//para encontrar a quantidade de conexoes que cada pessoa tem, caso a mat[i][j] seja igual a 1 é adicionado +1 no número de conexões da
//pessoa i

