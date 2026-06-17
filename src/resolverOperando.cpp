#include "Interpretador.h"

double resolverOperando(string token, map<string, double>& variaveis) {

    if (variaveis.count(token) == true) {
        return variaveis[token];
    }

    return stod(token);
}