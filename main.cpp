#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "Interpretador.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "[ALERT] Use: " << argv[0] << " nome_arquivo.txt" << endl;
        return 0;
    }

    fstream arquivo(argv[1]);

    if (!arquivo.is_open()) {
        cout << "[ERROR] Erro ao abrir o arquivo " << argv[1] << endl;
        return 0;
    }

    map<string, double> variaveis;
    string linha;

    while (getline(arquivo, linha)) {

        vector<string> tokens = tokenizarLinha(linha);

        if (tokens.empty()) {
            continue;
        }

        executarLinha(tokens, variaveis);

        imprimirTokens(tokens);
    }

    arquivo.close();

    return 0;
}