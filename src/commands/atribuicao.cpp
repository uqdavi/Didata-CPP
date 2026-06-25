#include "Interpretador.h"

bool atribuicao(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs) {

    // verifica se combina com o padrão "a <- 10"
    if ( tokens.size() == 3 && tokens[1] == "<-" ) {
        string nomeVariavel = tokens[0]; // Nome no inicio [0]
        double valor = stod(tokens[2]); // Valor no final [2]

        // Aplica o valor na tabela
        variaveis[nomeVariavel] = valor;

        if (mostrarLogs == true) cout << "[LOGS] Variavel '" << nomeVariavel << "' recebeu o valor " << valor << endl;
        
        return true;
    }

    return false;
}