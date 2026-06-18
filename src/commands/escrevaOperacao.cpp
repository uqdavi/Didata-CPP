#include "Interpretador.h"

bool escrevaOperacao(vector<string> tokens, map<string, double>& variaveis) {

    if ( tokens.size() == 6 && tokens[0] == "escreva" && tokens[1] == "(" && tokens[5] == ")" ) {
        double value1 = resolverOperando(tokens[2], variaveis);
        double value2 = resolverOperando(tokens[4], variaveis);
        double result = aplicarOperador(value1, value2, tokens[3]);

        cout << result << endl;

        return true;
    }

    return false;
}