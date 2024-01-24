#include "my_header.h"

int *criaVetorPessoas(int **lista){
    int *vetor_ordenado;
    vetor_ordenado = malloc(sizeof(int*)*totalPessoas);

    //printf("vetor ordenado: \n");

    for (int i = 0; i < totalPessoas; i++){
            vetor_ordenado[i] = lista[i][0];
           // printf("%d ", vetor_ordenado[i]);
    }

    return vetor_ordenado;
}

//Cria uma lista de pessoas, indo da que possui maior qnt de amizades para a que possui a menor qnt
