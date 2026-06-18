#include "Interpretador.h"

bool tentarExecutarEscreva(vector<string> tokens, map<string, double>& variaveis) {

    if (
        tokens.size() == 4 &&
        tokens[0] == "escreva" &&
        tokens[1] == "(" &&
        tokens[3] == ")"
    ) {

        string nomeVariavel = tokens[2];

        if (variaveis.count(nomeVariavel) == true) {
            cout << variaveis[nomeVariavel] << endl;
        } else {
            try {
                double valor = stod(nomeVariavel);
                cout << valor << endl;
            } catch (...) {
                cout << "[ERROR] Variavel '" << nomeVariavel << "' nao encontrada!" << endl;
            }
        }

        return true;
    }

    return false;
}