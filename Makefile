CC = gcc
CFLAGS = -Wall -std=c99
TARGET = Maior_Comunidade_LP1

# Lista de arquivos-fonte
SOURCES = 01_main.c 02_recebeArquivo.c 03_retornaLista.c 04_imprimeLista.c 05_criaMatriz.c \
          06_populaMatriz.c 07_imprimeMatriz.c 08_criaListaDeConexao.c 09_ordenaListaDeConexao.c \
          10_criaVetorPessoas.c 11_criaVetorMaiorComunidade.c 12_criaStructComunidade.c \
          13_criaArquivoSaida.c

# Gera os nomes dos arquivos-objeto a partir dos arquivos-fonte
OBJECTS = $(SOURCES:.c=.o)

# Nome do projeto do Code::Blocks
CBP_FILE = Maior_Comunidade_LP1.cbp

# Variável de ambiente OS para determinar o sistema operacional
ifeq ($(OS),Windows_NT)
	EXECUTABLE = $(TARGET).exe
	RM = del
else
	EXECUTABLE = $(TARGET)
	RM = rm -f
endif

# Regra padrão para compilar o programa
all: $(EXECUTABLE)

# Regra para compilar o programa
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $^

# Regras para gerar arquivos-objeto a partir dos arquivos-fonte
%.o: %.c my_header.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para executar o programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Regra para abrir o programa com o gedit (ou outro editor de texto)
open:
	gedit $(TARGET).c &

# Regra para limpar arquivos intermediários e o executável
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

