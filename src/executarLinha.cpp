#include "Interpretador.h"

void executarLinha(vector<string> tokens, map<string, double>& variaveis, int numeroLinha) {

    if ( atribuicao(tokens, variaveis) ) return;

    if ( atribuicaoOperacao(tokens, variaveis) ) return;

    if ( escreva(tokens, variaveis) ) return;

    if ( escrevaOperacao(tokens, variaveis) ) return;

    cout << "[ERROR] Linha " << numeroLinha << ": comando invalido!" << endl;
}