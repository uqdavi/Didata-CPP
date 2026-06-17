#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

// Ja colocamos todos os includes aqui para nao precisar chamar em cada arquivo
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

void executarLinha(vector<string> tokens, map<string, double>& variaveis);

void imprimirTokens(vector<string> tokens);

#endif