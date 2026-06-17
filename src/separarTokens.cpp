#include "Interpretador.h"

vector<string> separarToken(string token) {

    vector<string> result;
    string armazem = "";

    for (size_t i = 0; i < token.size(); i++) {
        char c = token[i];

        if (c == '<' && i + 1 < token.size() && token[i + 1] == '-') {
            if (!armazem.empty()) {
                result.push_back(armazem);
                armazem = "";
            }

            result.push_back("<-");
            i++;
            continue;
        }

        if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/') {
            if (!armazem.empty()) {
                result.push_back(armazem);
                armazem = "";
;
            }

            result.push_back(string(1, c));
        } else {
            armazem += c;
        }
    }

    if (!armazem.empty()) {
        result.push_back(armazem);
    }

    return result;
}