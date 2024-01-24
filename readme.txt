Grupo                        *
Amanda Almeida Cardoso       * 						         
Amanda dos Santos Almeida    *						        
Emily Gabriela Costa Ribeiro *	
******************************

 ____________________________________
|				                     |
|Trabalho Final da Disciplina de LP1.|
|____________________________________|

						

**********************************
* ENCONTRANDO A MAIOR COMUNIDADE *    
**********************************




Para executar no linux, abra o terminal na pasta Maior_Comunidade_LP1 e digite:


./Maior_Comunidade_LP1

ou 

make run





Para executar no windows, vá na pasta bin/Debug, abra o prompt de comandos e digite: 

Maior_Comunidade_LP1

Caso não funcione, tente abrir o makefile e altere a segunda linha CFLAGS para:

CFLAGS = -Wall -std=c99 -fstack-protector

Dê build no programa e tente novamente abrir o prompt de comandos no diretório Debug. Certifique-se de que no diretório Debug estejam presentes também os arquivos.txt




==================================================================================================================================================================================================

HEADER ("my_header.h"):

Contém as bibliotecas, uma diretiva, a struct, variáveis globais e os protótipos das funções.

==================================================================================================================================================================================================

1- main:

Chama as funções abaixo, imprime, libera os ponteiros.



===================================================================================================================================================================================================
 
 2- recebeArquivo:	

Recebe como parâmetro o nome do arquivo, os ponteiros para as variáveis globais que guardarão os valores da quantiadade total de pessoas e de amizades/conexões.
 Retorna void.
 
 void recebeArquivo(char nome[], int *pP, int *pA)
 
====================================================================================================================================================================================================			
 				
 3- retornaLista:  	
 
 Recebe como parâmetro o nome do arquivo, o total de amizades e a quantidade de colunas para formar uma matriz Nx2, a qual chamaremos de lista.
 N aqui refere-se a quantidade total de conexões que existem no arquivo.
 
 Essa função lê o arquivo.txt e popula a lista com o que está no arquivo, criando uma estrutura que usaremos como fonte de dados. 
 Retorna a lista para a main, que a recebe numa variável chamada lista_do_arquivo. 
 
 int **retornaLista(char nome[])
 
======================================================================================================================================================================================================
 				
 4 - imprimeLista: 	
 	
Função que imprime recursivamente uma lista no formato Nx2. 
Recebe como parâmetros um ponteiro de ponteiro que aponta para uma lista, o valor da linha e da coluna atual.
Retorna void.

void imprimeLista(int **lis, int linha_atual,int coluna_atual) 				
 				
 =====================================================================================================================================================================================================
 				
 5 - criaMatriz: 	
 
 Cria uma matriz alocada dinamicamente, não recebe nenhum parâmetro pois utiliza a variável glocal totalPessoas para criar uma matriz NxN, N sendo o total de pessoas. 
 Retorna a matriz.

int **criaMatriz()			 				
 ===================================================================================================================================================================================================== 				
 				
 6 - populaMatriz: 	
 
 Checa na lista as conexões que existem e popula a matriz de acordo com isso. Se há '1' quer dizer que existe conexão entre a  pessoa no índice [i][j]. 
 Se há 0, não há relação. A matriz acaba se tornando simétrica, pois se A tem relação com B, B tem relação com A, dessa forma:
  
  matriz[a][b] = 1 
  
  e 
  
  matriz[b][a] = 1		
 			
 Recebe como parâmetros a matriz e a lista criadas anteriormente. 
 Retorna void, pois apenas altera os valores da matriz já criada. 				

void populaMatrizDeAdjacencia(int **mat, int **lis)

=====================================================================================================================================================================================================
 
 7- imprimeMatriz: 	
 
 Função imprime a matriz no formado NxN, N sendo o número total de pessoas, que está guardado em variável global.
 Recebe como parâmetro a matriz.
 Retorna void.
 
void imprimeMatriz(int **mat)

 =====================================================================================================================================================================================================	
 
 8- criaListaDeConexão:  
 
 Cria uma lista Nx2, sendo N a quantidade de pessoas. Na primeira coluna da lista, temos o "número" da pessoa, e na segunda coluna a quantidade de conexões que essa pessoa tem. 
 
 linha 0: [0][0] = 1   ;  [0][1] = 4
 
 Representa que a pessoa tem 4 conexões. Note que a linha 0 está representando a pessoa 1, então por diversas vezes no programa, será necessário subtrair 1 do valor contido na 
 posição [][] da matriz para que possamos acessar de fato o índice que representa aquela pessoa.
 
 int** criaListaDeConexao(int **mat) 
 
 ======================================================================================================================================================================================================= 		
 
 9- ordenaLista: 
 
 Ordena a função usando um algoritmo de Selection Sort. O maior valor é passado para  a primeira posição, o segundo maior valor para a segunda posição e assim por diante. 
 Recebe como parâmetro a lista da função 8.
 Retorna void.
 
 void ordenaListaDeConexao(int **lis)
 
 ======================================================================================================================================================================================================= 	
 10- criaVetorPessoas:
 	
 Essa função recebe como parâmetros a lista ordenada da função anterior. 
 Irá criar um vetor de tamanho N, sendo N o total de pessoas. Esse vetor irá ser populado com as pessoas em ordem decrescente, da pessoa com mais conexões até a pessoa com menos conexões. 
 Retorna o vetor ordenado.
 
 int* criaVetorPessoas(int **lista);
 
 =======================================================================================================================================================================================================
 11 - criaVetorMaiorComunidade: 	
 
 
 Essa função cria o vetor com a maior comunidade encontrada. Para isso, assume que a primeira pessoa no vetor da função anterior, está presente na maior comunidade, já que é a pessoa com mais conexões. A lógica é ir adicionando na comunidade apenas quem tem conexão com a comunidade já formada até o momento, de forma que quando chega no final, todos presentes no vetor comunidade estão conectados entre si e essa forma a maior comunidade. O vetor comunidade é populado com 1 se a pessoa do indice i+1 está na comunidade, do contrário, popula-se com 0.
 
 Recebe como parâmetros a matriz de adjacencia e o vetor de pessoas ordenadas. 
 Retorna o vetor com a maior comunidade.

int *criaVetorMaiorComunidade(int **mat, int *pessoas_ordenadas_conexao) 
 =======================================================================================================================================================================================================

12- criaStructMaiorComunidade:

Cria um vetor de structs alocado dinamicamente. A struct se chama Maior Comunidade e tem como parâmetros int pessoa  e  int qtd_conexões. 
Para conseguir popular a struct de uma melhor forma, criamos um vetor chamado de pessoas, que possui tamanho relativo a quantidade de pessoas presentes na maior comunidade. 
Esse vetor será populado com o número do indivíduo que está na comunidade.  Exemplo: se a maior comunidade é (1,1,1,0,0), no vetor pessoas teremos (1,2,3). 
Em seguida populamos o campo .pessoa da struct com esses valores. 

Para popular o campo .qtd_conexões, temos duas opções. A primeira é acessar a quantidade de conexões que as pessoas 1,2 e 3 possuem numa lista de conexão não ordenada 
criada pela função 6.  Nessa lista, a pessoa 1 está em primeiro, a pessoa 2 em segundo, 3 em terceiro etc. Assim, é possível ir diretamente no índice da lista e ver quantas 
conexões ela possui. Um ponto a ser esclarescido é que essa lista não possui a quantidade total de conexões, apenas as conexões que estão na parte acima da diagonal 
principal da matriz.

Para contar a quantidade total de conexões de cada pessoa, temos a segunda opção: contar quantos 1's existem em cada linha da matriz, guardar o resultado numa variavel 
qtd_conexões_total e popular o campo da strcut com esses dados. Dessa forma, vemos absolutamente todas as conexões que uma pessoa tem. 

Ambas as formas estão presentes no código, basta comendar e descomentar a critério do leitor. Sugerimos a segunda forma.


Recebe como parâmetros a quantidade de pessoas na maior comunidade, o vetor maior comunidade, a lista de conexão não ordenada e  a matriz de adjacência
A função retorna o array_de_comunidade, que é um array de structs. 



MaiorComunidade *criaStructComunidade(int qtd_pessoas_na_maior_comunidade, int*maior_comunidade, int **lista_conexao_nao_ordenada, int **matriz_adj)


=======================================================================================================================================================================================================
 
13- criaArquivoSaida:

Recebe como parâmetros o array de structs criado na função anterior e a quantidade total de pessoas na maior comunidade. Essa função coloca num arquivo de saída as informações presentes nas structs.

Retorna void.

void criaArquivoSaida(MaiorComunidade *array,int qtd_pessoas)

========================================================================================================================================================================================================



Fim
(✿◠‿◠) 





 				
