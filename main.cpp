#include <iostream>
#include <fstream> // Include para lermos o .txt
#include <string>
#include <map> // Famoso Include para tabelas, iremos usar para armazenar variaveis | [nome da variavel]: [valor da variavel]
#include <vector>

#include "Interpretador.h" 

using namespace std;

int main(int argc, char* argv[]) { // Como foi explicado em aula, é possível a função main receber argumentos. No nosso caso ira receber o arquivo.txt 

    // Fazendo uma simples verificação para identificar se o usuário digitou algum argumento
    if (argc < 2) { 
        cout << "[ALERT] Use: " << argv[0] << " nome_arquivo.txt" << endl;
        return 0;
    }

    fstream arquivo(argv[1]); //Aqui definimos o arquivo.txt que iremos trabalhar

    if (!arquivo.is_open()) { // Verificando se há algum erro ao abrir o arquivo.
        cout << "[ERROR] Erro ao abrir o arquivo " << argv[1] << endl;
        return 0;
    }

    map<string, double> variaveis; // Iremos armazenar as nossas variaveis nessa tabela, exemplo: [String nome da variavel]: [Double valor da variavel]
    string linha; // Iremos armazenar uma linha por vez nessa variavel

    // -- [ ATUALIZAÇÃO ] --
    // Em versões passadas, era executada uma linha por vez
    // Agora, precisamos carregar e guardar todas as linhas pois iremos trabalhar com blocos de códigos por causa do SE & SENAO
    vector<string> linhas; // Entao todas as linhas estarao armazenadas aqui nesse vector

    while ( getline(arquivo, linha) ) { 
        linhas.push_back(linha); //Lendo todas as linhas 1 por vez e dando um push_back para armazenalas no vector
    }

    // Com todas linhas ja armazenadas, vamos executar linha por linha com esse laço de repetição.
    for (size_t i = 0; i < linhas.size(); i++) {
        
        // Essa funcao ira retornar um vetor de tokens
        // Para mais informacoes, acesse o arquivo tokenizarLinha.cpp
        vector<string> tokens = tokenizarLinha(linhas[i]); 

        if (tokens.empty()) { // Caso retorne um vetor vaziu, significa que é uma linha em branco, entao usamos "continue" para pular a linha 
            continue;
        }


        // === [ ATUALIZAÇÃO ] ===
        // Adicionamos o comando de SE e SENAO
        // Antes, apenas usavamos o "executarLinha(tokens, variaveis, (int) i+1)" para executar uma linha por vez
        // Agora precisaremos trabalhar com blocos de codigos
        if( tokens[0] == "se" ) { // Caso a linha de codigo for uma condicional, iremos aplicar o algoritimo do SE e SENAO

            se(linhas, i, variaveis);

        } else { // Caso contrario, apenas executamos uma linha por vez normalmente
            executarLinha(tokens, variaveis, (int) i+1); 
            // imprimirTokens(tokens);
        }


    }

    arquivo.close(); // Ao finalizar a leitura de todas as linhas, fechamos o arquivo e damos um return 0 para encerrar o codigo.

    return 0;
}