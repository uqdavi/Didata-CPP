#include "Interpretador.h"

// Esse aqruivo é como o "coração do algoritimo"
// Sera executada cada linha aqui

void executarLinha(vector<string> tokens, map<string, double>& variaveis, int numeroLinha) {

    // Aqui temos todos os comandos, caso ele encontre algum, ele executa

    if ( atribuicao(tokens, variaveis) ) return; // Variavel, ex: X <- 10

    if ( atribuicaoOperacao(tokens, variaveis) ) return; // Variavel com operacao, ex: X <- 10 + 20

    if ( escreva(tokens, variaveis) ) return; // Escreva, ex: escreva(X)

    if ( escrevaOperacao(tokens, variaveis) ) return; // Escreva com Operacao, ex: escreva(X+10)

    // Caso nao encontre, significa que a linha é invalida
    cout << "[ERROR] Linha " << numeroLinha << ": comando invalido!" << endl;
}