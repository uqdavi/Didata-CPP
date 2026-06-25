#include "Interpretador.h"

bool atribuicaoOperacao(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs) {

    if ( tokens.size() == 5 && tokens[1] == "<-" ) { // x <- 10 + 20
        string nomeVariavel = tokens[0]; // Nome no inicio [0]

        double value1 = resolverOperando(tokens[2], variaveis); // Primeiro valor em terceiro [2]
        double value2 = resolverOperando(tokens[4], variaveis);  // Segundo valor em quinto [5]
        double result = aplicarOperador(value1, value2, tokens[3]); // Aplicar a matematica com o aplicarOperando.cpp

        // Armazena a variavel na tabela de variaveis
        variaveis[nomeVariavel] = result;

        if (mostrarLogs == true) {
    cout << "Variavel '" << nomeVariavel << "' recebeu o valor " << result << endl;
}

        return true;
    }

    return false;
}