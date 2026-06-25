#include "Interpretador.h"

// Nosso primeiro comando, o "escreva"
// Ou para os mais chegados, o famoso "cout"

bool escreva(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs) {

    if (
        tokens.size() == 4 &&
        tokens[0] == "escreva" &&
        tokens[1] == "(" &&
        tokens[3] == ")"
    ) {

        string nomeVariavel = tokens[2];

        if (variaveis.count(nomeVariavel) == true) { // Se o valor entre os parenteses for uma variavel, ele mostra o valor dela
            
            if (mostrarLogs) cout << "[LOGS] Escrevendo a variável [" << variaveis[nomeVariavel] << "]" << endl;
            
            // Ex: escreva(x)
            // Ai busca na tabela de variaveis, e mostra
            cout << variaveis[nomeVariavel] << endl;
            
        } else { // Caso nao for uma variavel, so mostra o valor
            
            try { // O professor pediu para tentarmos usar o try catch, entao aqui esta!
                if (mostrarLogs) cout << "[LOGS] Escrevendo o valor na tela" << endl;
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