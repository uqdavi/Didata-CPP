#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> separarToken(string token);

double resolverOperando(string token, map<string, double>& variaveis);

double aplicarOperador(double value1, double value2, string operador);

vector<string> tokenizarLinha(string linha);

void executarLinha(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs);

void imprimirTokens(vector<string> tokens);

bool atribuicao(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs);
bool atribuicaoOperacao(vector<string> tokens, map<string, double>& variaveis, bool mostrarLogs);
bool escreva(vector<string> tokens, map<string, double>& variaveis);
bool escrevaOperacao(vector<string> tokens, map<string, double>& variaveis);

// Se Senao
bool avaliarCondicao(const string& condicao, map<string, double>& variaveis);
void se(const vector<string>& linhas, size_t& i, map<string, double>& variaveis);

#endif