#include "my_header.h"

void imprimeLista(int **lista, int linha_atual,int coluna_atual){ //linha_atual e coluna_atual = 0

    //Condição de parada
    if (linha_atual == totalPessoas - 1 && coluna_atual == 1){
        printf("%d\n", lista[linha_atual][coluna_atual]);
        return;
    }

    printf("%d ", lista[linha_atual][coluna_atual]); // imprimindo o elemento atual lista

    // Atingindo a coluna (2-1) = 1, ou seja, a segunda e ultima coluna, vai para a próxima linha
    if (coluna_atual == COLUNAS - 1){
        printf("\n");
        imprimeLista(lista, linha_atual + 1, 0);
    } else{
        imprimeLista(lista, linha_atual, coluna_atual + 1);
    }
}

//A função imprimeLista é uma função recursiva que imprime os elementos de uma lista nx2 de inteiros, imprimindo
//primeiro a posição [0][0], depois [0][1], depois [1][0], e assim sucessivamente, de forma recursiva, ou seja, a função chama ela
//mesma até atingir a condinção de parada, que é [n][1], sendo 'n' o número total de pessoas
