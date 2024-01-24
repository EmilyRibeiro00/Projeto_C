#include "my_header.h"

void populaMatrizDeAdjacencia(int **mat, int **lis){
    for(int i = 0; i < totalAmizades; i++){
        int a = lis[i][0];
        int b = lis[i][1];
        --a;    //Subtrai 1 pois na lista os valores começam pela "pessoa 1", mas na matriz essa pessoa está no indice 0, e não
        --b;    //no indice 1.
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
}

//popula a matriz TPxTP com 1 caso haja amizade entre duas pessoas
