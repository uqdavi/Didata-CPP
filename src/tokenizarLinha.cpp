#include "Interpretador.h"

// Nessa funcao iremos fazer toda a magica por tras da interpretação do pseudocodigo
// Essa funcao basicamente recebe uma linha de codigo como parametro, e "tokeniza" ela, ou seja: separa em partes
// Exemplo, se a linha de codigo for "X <- 50", ela ira retornar um vetor com cada parte dessa linha separada, ex:
// [X] [<-] [50]
// E assim, conseguiremos aplicar TODA a logica e algoritimo para interpretar o pseudocodigo

vector<string> tokenizarLinha(string linha) { 

    // Iremos utilizar o include sstring
    // Ele funciona basicamente com um cin
    // Se a linha de codigo for "X <- 50", ele separa como se fosse asssim:
    // cin >> "x" >> "<-" >> "50"
    stringstream ss(linha);

    string token;
    vector<string> tokens; // Vamos guardar os tokens aqui, e depois da um return nele

    while (ss >> token) { // Lendo a string espaço por espaco;

        // -- [ ATUALIZAÇÃO ] --
        // Identificamos um pequeno probleminha, entao criamos o arquivo separarTokens.cpp para resolver
        // Para mais informações da resolução do problema, acesse o separarTokens.cpp
        vector<string> subTokens = separarToken(token); 

        for (string t : subTokens) {
            tokens.push_back(t);
        }
    }

    // Retornamos os tokens separadinhos e pronto para aplicar todos algoritimos
    return tokens;
}