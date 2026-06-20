#include "Interpretador.h"

// Codigo que encontrei na internet para remover espacos de uma string
// Exemplo: " abcd " -> "abcd"
// So para previnir caso o usuario digite com espacos
string trim(const string& s) {
    size_t inicio = s.find_first_not_of(" \t");
    size_t fim    = s.find_last_not_of(" \t");
    if (inicio == string::npos) return "";
    return s.substr(inicio, fim - inicio + 1);
}

bool avaliarCondicao( const string& condicao, map<string, double>& variaveis ) { // Expliquei a questao desses argumentos la no se.cpp
    
    vector<string> operadores = {">=", "<=", "==", "!=", ">", "<"}; // Operadores possiveis

    for (const string& op : operadores) { // Famoso for-each ensinado pelo professor

        size_t pos = condicao.find(op); // Tentando identificar a condicação

        if (pos != string::npos) { // Aqui caso conseguimos achar a condicação, ou seja, for diferente ! de lixo ::npso

            string esquerda = trim(condicao.substr(0, pos));
            string direita  = trim(condicao.substr(pos + op.size()));

            double valEsq = resolverOperando(esquerda, variaveis);
            double valDir = resolverOperando(direita, variaveis);

            if (op == ">")  return valEsq >  valDir;
            if (op == "<")  return valEsq <  valDir;
            if (op == ">=") return valEsq >= valDir;
            if (op == "<=") return valEsq <= valDir;
            if (op == "==") return valEsq == valDir;
            if (op == "!=") return valEsq != valDir;
        }
    }

    cout << "[ERROR] Condicao invalida: " << condicao << endl;
    return false;
}