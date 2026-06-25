#include "Interpretador.h"

bool escrevaOperacao(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs) {

    if ( tokens.size() == 6 && tokens[0] == "escreva" && tokens[1] == "(" && tokens[5] == ")" ) {
        double value1 = resolverOperando(tokens[2], variaveis);
        double value2 = resolverOperando(tokens[4], variaveis);
        double result = aplicarOperador(value1, value2, tokens[3]);

        if (mostrarLogs) cout << "[LOGS] Realizando Operação no Escreva" << endl;

        cout << result << endl;

        return true;
    }

    return false;
}