#include "Interpretador.h"

bool atribuicaoOperacao(vector<string> tokens, map<string, double>& variaveis) {

    if ( tokens.size() == 5 && tokens[1] == "<-" ) {
        string nomeVariavel = tokens[0];

        double value1 = resolverOperando(tokens[2], variaveis);
        double value2 = resolverOperando(tokens[4], variaveis);
        double result = aplicarOperador(value1, value2, tokens[3]);

        variaveis[nomeVariavel] = result;

        cout << "Variavel '" << nomeVariavel << "' recebeu o valor " << result << endl;

        return true;
    }

    return false;
}