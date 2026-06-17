#include "Interpretador.h"

vector<string> tokenizarLinha(string linha) {

    stringstream ss(linha);

    string token;
    vector<string> tokens;

    while (ss >> token) {
        vector<string> subTokens = separarToken(token);

        for (string t : subTokens) {
            tokens.push_back(t);
        }
    }

    return tokens;
}