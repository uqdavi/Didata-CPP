#include "Interpretador.h"

// Comando a nivel de debug

void imprimirTokens(vector<string> tokens) {

    cout << "Tokens: ";

    for (string t : tokens) {
        cout << "[" << t << "] ";
    }

    cout << endl;
}