#include "Interpretador.h"

void se(const vector<string>& linhas, size_t& i, map<string, double>& variaveis) {
    // Aqui a gente usa um conceito interessante chamado "passagem por referencia"
    // Ao inves de criarmos copias das variaveis que sao passadas como argumentos na funcao
    // Usamos os valores reais delas usando o "&"
    // Entao se modificarmos, por exemplo, o size_t i, la na main tambem sera modificado

    string linhaSe = linhas[i]; // Aqui guardamos a linha de codigo do SE ... "se (x > y) entao"
    
    // Iremos guardar o inicio e o fim dos ( ) por dentro deles esta a condicao do SE ... "( x > y )"
    size_t inicio = linhaSe.find('(');
    size_t fim = linhaSe.find(')');

    if (inicio == string::npos || fim == string::npos) { // Se o find retornar lixo, significa que o usuario digitou errado
        cout << "[ERROR] Linha " << i + 1 << ": sintaxe invalida no 'se'" << endl;
        return;
    }

    // E aqui pegamos a condição do SE, que esta entre o inicio e o fim dos ( )
    string condicao = linhaSe.substr(inicio + 1, fim - inicio - 1);

    // POR ENQUANTO< VAMOS TRABALHAR APENAS COM 3 BLOCOS
    // O bloco do SE ENTAO
    // O bloco do SENAO SE
    // E o bloco do SENAO
    // Nao iremos adicionar varios SENAO SE por que vai ser chato demais de fazer, talvez nao de tempo ate a data da apresentacao
    vector<string> blocoEntao;
    vector<string> blocoSenaoSe;
    vector<string> blocoSenao;

    // CASO tenha o Senao SE, vamos armazenar aqui a condição dele
    string condicaoSenaoSe = "";

    bool noSenaoSe = false;
    bool noSenao = false;

    vector<string> tokensSe = tokenizarLinha(linhaSe);

    // É importante o usuario digitar o entao ao finalizar a condicao, para seguir um padrao sintatico de pseudocodigo
    // Exemplo: se (x > y) *ENTAO* ...
    if (tokensSe.empty() || tokensSe.back() != "entao") {
        cout << "[ERROR] Linha " << i + 1 << ": esperado 'entao' apos a condicao do 'se'" << endl;
        return;
    }

    i++; // avança para a linha depois do "se (...) entao"

    while (i < linhas.size()) {

        string l = linhas[i];
        vector<string> tokens = tokenizarLinha(l);

        if (!tokens.empty() && tokens[0] == "fimse") { // Se for o fimse, apenas paramos o loop
            break;
        } else if (!tokens.empty() && tokens[0] == "senao" && tokens.size() > 1 && tokens[1] == "se") {
            // AQUI ENTRA A QUESTAO DO SENAO SE, QUE JA FOI DIFICIL
            // Mais que isso é loucura
            size_t ini = l.find('(');
            size_t fim2 = l.find(')');
            if (ini == string::npos || fim2 == string::npos) { // Mesma coisa la de cima
                cout << "[ERROR] Linha " << i + 1 << ": sintaxe invalida no 'senao se'" << endl;
                return;
            }
            condicaoSenaoSe = l.substr(ini + 1, fim2 - ini - 1); // Salvamos a condicao na variavel
            noSenaoSe = true; // Aqui avisamos que encontramos um Senao Se
        } else if (!tokens.empty() && tokens[0] == "senao") {
            noSenao = true; // Aqui avisamos que encontramos um Senao
        } else if (noSenao) {
            blocoSenao.push_back(l); // Executar o bloco do Senao, caso tenha
        } else if (noSenaoSe) {
            blocoSenaoSe.push_back(l); // Executar o bloco do Senao se, caso tenha
        } else {
            blocoEntao.push_back(l); // Executar a linha abaixo do Se entao
        }

        i++;
    }

    if (i >= linhas.size()) { // Se ultrapassar esse limite, significa que o fimse nao foi encontrado, ai paramos a funcao por erro de sintaxe
        cout << "[ERROR] 'fimse' nao encontrado para o 'se' da linha " << i + 1 << endl;
        return;
    }

    // Pegamos a condicao da SE, e verificamos se alguma condicao bate com o avaliarCondicao.cpp
    bool resultado = avaliarCondicao(condicao, variaveis);
    vector<string> blocoEscolhido; // E aqui ira ficar o bloco de codigo escolhido para ser executado

    // Vemos qual bloco satisfaz a condicao
    if (resultado) {
        blocoEscolhido = blocoEntao;
    } else if (!condicaoSenaoSe.empty() && avaliarCondicao(condicaoSenaoSe, variaveis)) {
        blocoEscolhido = blocoSenaoSe;
    } else {
        blocoEscolhido = blocoSenao;
    }

    for (size_t j = 0; j < blocoEscolhido.size(); j++) { // Aqui executamos todas as linhas do vector blocoEscolhido
        // E aqui é basicamente a mesma coisa do main, copiei e colei
        vector<string> tokens = tokenizarLinha(blocoEscolhido[j]); // 
        if (tokens.empty()) {
            continue;
        }
        executarLinha(tokens, variaveis, j + 1);
    }

}