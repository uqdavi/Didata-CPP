#include "Interpretador.h"

void imprimirTokens(vector<string> tokens) {

    cout << "Tokens: ";

    for (string t : tokens) {
        cout << "[" << t << "] ";
    }

    cout << endl;
}