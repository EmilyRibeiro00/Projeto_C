#include "my_header.h"

MaiorComunidade *criaStructComunidade(int qtd_pessoas_na_maior_comunidade, int*maior_comunidade, int**lista_qtd_conexao_nao_ordenada, int** matriz_adj){

    int pessoas[qtd_pessoas_na_maior_comunidade];
    int indice = 0;
    int individuo = 0;
    int j = 0;

    // Alocando array de struct
    MaiorComunidade * array_de_comunidade;
    array_de_comunidade = malloc(sizeof(MaiorComunidade)*qtd_pessoas_na_maior_comunidade);


    // Guardando as pessoas que fazem parte de uma comunidade no vetor pessoas
    while (indice < qtd_pessoas_na_maior_comunidade){
        if(maior_comunidade[j] != 0){
            pessoas[indice] = j+1;
            indice++;
        }
        j++;

    }

    // Populando struct

    for(int i = 0; i < qtd_pessoas_na_maior_comunidade; i++){

        array_de_comunidade[i].pessoa = pessoas[i];

        // Subtrai 1 para poder acessar o valor correto da pessoa na lista nao ordenada, pois a pessoa 1 ocupa o indice 0.
        individuo = pessoas[i] - 1;

        // Populando o campo qtd_conexoes da struct com os valores presentes na lista nao ordenada
        //array_de_comunidade[i].qtd_conexoes = lista_qtd_conexao_nao_ordenada[individuo][1];
    }

   /**

    O código abaixo serve para se quisermos alterar a quantidade de conexões que vamos colocar na struct. Da forma que está configurada acima,
    apenas vai para a struct os valores das conexões explícitas que estavam originalmente no arquivo.txt. Se quisermos alterar isso para a quantidade
    total de conexões que uma pessoa tem, usaremos o código abaixo. **/


    indice = 0;
    int qtd_conexoes_total = 0;

    while (indice<qtd_pessoas_na_maior_comunidade){

        // individuo guarda numero da pessoa que está na maior comunidade, subtrai 1 pois pessoa 1 refere-se ao indice 0, por exemplo.
        individuo = pessoas[indice]-1;

        for(int i =0; i < totalPessoas; i++){
            // guarda quantas conexões tem a pessoa contando quantos 1's possui na sua linha
            if (matriz_adj[individuo][i] == 1){
                qtd_conexoes_total+=matriz_adj[individuo][i];
            }
        }
        array_de_comunidade[indice].qtd_conexoes = qtd_conexoes_total;
        indice++;
        qtd_conexoes_total = 0;
    }

    return array_de_comunidade;
}
