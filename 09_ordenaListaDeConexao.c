#include "my_header.h"

 void ordenaListaDeConexao(int **lis){
    // ordenando a lista
    int aux_1 = 0;
    int aux_2 = 0;
    int max = 0;

    for (int i = 0; i < totalPessoas-1; i ++){  //intera até o penultimo valor da matriz
        max = i;  //Tomamos a pessoa i como a que obtem maior qnt de amizades

        //Compara a pessoa i com o resto dos valores da coluna 0 ate o fim da matriz
        for (int k = i+1; k < totalPessoas; k++){
            //compara se a proxima pessoa(i+1) possui mais amizades que a variavel max(inicializada como igual a pessoa i)
            if (lis[k][1] > lis[max][1] ){  //compara a segunda coluna de duas linhas
                max = k;
            }
        }
        if (i != max){  //Checa se o valor de max foi atualizado, se foi atualizado eh pq existe um numero maior. Entao atualiza o valor de max
            //Temos que atualizar o valor na primeira e segunda coluna, para isso usamos duas variaveis auxiliares, já que nao temos um for para a coluna.
            aux_1 = lis[i][1];
            aux_2 = lis[i][0];

            lis[i][1] = lis[max][1];
            lis[i][0] = lis[max][0];

            lis[max][1] = aux_1;
            lis[max][0] = aux_2;
        }
    }
}
