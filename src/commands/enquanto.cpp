#include "Interpretador.h"

void enquanto(const vector<string>& linhas, size_t& i, map<string, double>& variaveis, bool mostrarLogs) {

    string linhaEnquanto = linhas[i]; // Guardamos a linha do "enquanto (x < 10) faca"

    // Extraindo a condição entre ( ), é nela que vamos trabalhar 
    size_t inicio = linhaEnquanto.find('(');
    size_t fim    = linhaEnquanto.find(')');

    if (inicio == string::npos || fim == string::npos) {
        cout << "[ERROR] Linha " << i + 1 << ": sintaxe invalida no 'enquanto'" << endl;
        return;
    }

    string condicao = linhaEnquanto.substr(inicio + 1, fim - inicio - 1); // Aqui a gente pegou o que estava entre parenteses, que a principio é para ser a condição do loop

    // Validando o "faca" no final, seguindo o mesmo padrao do "entao" no se
    vector<string> tokensEnquanto = tokenizarLinha(linhaEnquanto);
    if (tokensEnquanto.empty() || tokensEnquanto.back() != "faca") {
        cout << "[ERROR] Linha " << i + 1 << ": esperado 'faca' apos a condicao do 'enquanto'" << endl;
        return;
    }

    i++; // Avança para a primeira linha do bloco

    // Coletamos todas as linhas do corpo do loop, igual ao se
    vector<string> blocoCorpo;

    while (i < linhas.size()) {
        vector<string> tokens = tokenizarLinha(linhas[i]);

        if (!tokens.empty() && tokens[0] == "fimenquanto") {
            break; // Encontrou o fim do bloco
        }

        blocoCorpo.push_back(linhas[i]);
        i++;
    }

    if (i >= linhas.size()) {
        cout << "[ERROR] 'fimenquanto' nao encontrado para o 'enquanto' da linha " << i + 1 << endl;
        return;
    }

    // Aqui está a diferença principal em relação ao SE:
    // Avaliamos a condição repetidamente e executamos o blocoCorpo a cada iteração
    while (avaliarCondicao(condicao, variaveis)) {

        if (mostrarLogs) cout << "[LOGS] Enquanto: condicao '" << condicao << "' verdadeira, executando bloco" << endl;

        for (size_t j = 0; j < blocoCorpo.size(); j++) {
            vector<string> tokens = tokenizarLinha(blocoCorpo[j]);
            if (tokens.empty()) continue;

            if (tokens[0] == "se") {
                se(blocoCorpo, j, variaveis, mostrarLogs);
            } else {
                executarLinha(tokens, variaveis, j + 1, mostrarLogs);
            }
        }
    }

    if (mostrarLogs) cout << "[LOGS] Enquanto: condicao '" << condicao << "' falsa, encerrando loop" << endl;
}