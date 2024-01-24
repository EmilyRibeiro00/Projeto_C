#include "my_header.h"

void criaArquivoSaida(MaiorComunidade *array, int qtd_pessoas){
    FILE* parq;
    parq = fopen("arquivo_de_saida.txt", "w+");

    if(parq == NULL){
        getchar();
        printf("erro ao criar arquivo de saida");
    }

    for (int i = 0; i < qtd_pessoas; i++) {
        fprintf(parq,"Pessoa %d com %d amizades \n", array[i].pessoa,array[i].qtd_conexoes);
    }

    fclose(parq);
}
