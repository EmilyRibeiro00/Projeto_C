#include "my_header.h"

int  *criaVetorMaiorComunidade(int **mat, int *pessoas_ordenadas_conexao){
    int *comunidade = calloc(totalPessoas,sizeof(int*)); //aloca uma quantidade especificada de blocos de memória, inicializa todos os bits de cada bloco
                                                         //para zero e retorna um ponteiro para a primeira posição do bloco de memória alocado.
    bool pode_adicionar = true;

    if(comunidade==NULL){
        printf("erro ao criar comunidade");
    }

    int k = pessoas_ordenadas_conexao[0]-1; //inicializaçao de k
    comunidade[k] = 1; //inicializamos a comunidade com o indice da pessoa com maior conexao

    while (k < totalPessoas){ //primeira pessoa da lista é a primeira candidata
        pode_adicionar = true; //Antes de verificar a conexão de k com a comunidade existente, definimos, inicialmente, que k pode ser add à comunidade.
        for (int i = 0; i < totalPessoas; i ++){ //Um loop for interno é utilizado para percorrer todas as pessoas na comunidade existente e
                                                 //verificar a conexão com a pessoa representada por k.
            if (k == i) continue;  //Se k for igual a i (ou seja, a mesma pessoa), o loop continua para a próxima iteração sem fazer mais verificações.
            if (comunidade[i] == 0) continue; //Se a pessoa i não estiver na comunidade (representado por comunidade[i] == 0), o loop continua para a
                                              //próxima iteração sem fazer mais verificações.
            if (mat[i][k] == 0){ //Se a pessoa k não estiver conectada à pessoa i na matriz populada
                pode_adicionar = false;
                break;
            }
        }
        if (pode_adicionar == true){ // altera o vetor comunidade apenas se houver conexao
            comunidade[k] = 1;
        }
        k++; //O índice k é incrementado para verificar a próxima pessoa na lista.
    }
    printf("\n");
    return comunidade;
}

//funçao que cria uma lista de pessoas presentes na maior comunidade, alocando 1 para as pessoas que possuem relaçoes mutuas entre si. É criado um vetor
//de tamanho n(TotalPessoas),inicializando todos os bits da memória alocada para zero. Em seguida, atribuimos o n°-1 da pessoas com maior número de
//amizades a variável k, já pressumindo que está pessoa está na maior comunidade. Inicalizamos o vetor no indice k com 1, mantendo os demais indices iguais
//a zero. Depois, entramos em um loop externo e outro externo, o loop interno verifica as condiçoes de adição da pessoa de indice i, comparando

