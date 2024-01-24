#include "my_header.h"

void imprimeMatriz(int **mat){
    for (int linha = 0; linha < totalPessoas; linha++){
       for (int coluna = 0; coluna < totalPessoas; coluna++){
            printf("%d ", mat[linha][coluna]);
        }
       printf("\n");
    }
}


