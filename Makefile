# Arquivo Makefile criado por uma IA para auxiliar na compilação dos diversos arquivos do projeto

# Nome do executável gerado
TARGET = main

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I include

# Lista de arquivos fonte
SRCS = main.cpp \
       src/tokenizarLinha.cpp \
       src/separarTokens.cpp \
       src/resolverOperando.cpp \
       src/aplicarOperador.cpp \
       src/avaliarCondicao.cpp \
       src/executarLinha.cpp \
       src/imprimirTokens.cpp \
       src/commands/atribuicao.cpp \
       src/commands/atribuicaoOperacao.cpp \
       src/commands/escreva.cpp \
       src/commands/escrevaOperacao.cpp \
       src/commands/se.cpp \
       src/commands/enquanto.cpp 

# Regra principal: compila tudo e gera o executável
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regra de limpeza: remove o executável gerado
clean:
	rm -f $(TARGET)