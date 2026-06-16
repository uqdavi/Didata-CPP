#include "Interpretador.h"

void executarLinha(vector<string> tokens, map<string, double>& variaveis) {

    if (tokens.size() == 3 && tokens[1] == "<-") {

        string nomeVariavel = tokens[0];
        double valor = stod(tokens[2]);

        variaveis[nomeVariavel] = valor;

        cout << "Variavel '" << nomeVariavel << "' recebeu o valor " << valor << endl;

    } else if (
        tokens.size() == 4 &&
        tokens[0] == "escreva" &&
        tokens[1] == "(" &&
        tokens[3] == ")"
    ) {

        string nomeVariavel = tokens[2];

        if (variaveis.count(nomeVariavel) == true) {
            cout << variaveis[nomeVariavel] << endl;
        } else {
            cout << "[ERROR] Variavel '" << nomeVariavel << "' nao encontrada!" << endl;
        }

    } else if (tokens.size() == 5 && tokens[1] == "<-") {

        string nomeVariavel = tokens[0];
        string operador = tokens[3];

        double value1 = resolverOperando(tokens[2], variaveis);
        double value2 = resolverOperando(tokens[4], variaveis);

        double result = aplicarOperador(value1, value2, operador);

        variaveis[nomeVariavel] = result;

        cout << "Variavel '" << nomeVariavel << "' recebeu o valor " << result << endl;

    } else if (
        tokens.size() == 6 &&
        tokens[0] == "escreva" &&
        tokens[1] == "(" &&
        tokens[5] == ")"
    ) {

        double value1 = resolverOperando(tokens[2], variaveis);
        double value2 = resolverOperando(tokens[4], variaveis);

        double result = aplicarOperador(value1, value2, tokens[3]);

        cout << result << endl;

    } else {
        cout << "[ERROR] Comando invalido!" << endl;
    }
}