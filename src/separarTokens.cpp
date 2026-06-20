#include "Interpretador.h"

// Criamos esse algoritimo para resolver uma pequena problematica
// Apos a adição do comando "escreva(10)", percebe-se que o usuario digita tudo junto, sem espaço algum
// Entao precisamos de um script que leia a linha de codigo, e caso identifique parenteses "(" ou ")", ele separe como tokens tambem
// Exemplo, se a linha de codigo for "escreva(10)", ira ficar separado da seguinte forma:
// tokens: [escreva] [(] [10] [)]
// Assim, conseguimos aplicar a logica no comando "escreva"

vector<string> separarToken(string token) {

    vector<string> result;
    string armazem = "";

    for (size_t i = 0; i < token.size(); i++) {
        char c = token[i]; // Nesse laço, iremos ler letra por letra, ou melhor, char por char. Caso identifique um parenteses, ele separa como token

        if (c == '<' && i + 1 < token.size() && token[i + 1] == '-') {
            if (!armazem.empty()) {
                result.push_back(armazem);
                armazem = "";
            }

            result.push_back("<-");
            i++;
            continue;
        }


        // === [ ATUALIZAÇÃO ] ===
        // Aplicaremos operações matematicas em nosso interpretador de pseudocodigo
        // Entao iremos separar os operadores (+, -, /, *) como tokens tambem
        // Assim, podemos identificar as operações matematica que o usuario quer realizar
        if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/') {
            if (!armazem.empty()) {
                result.push_back(armazem);
                armazem = "";
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