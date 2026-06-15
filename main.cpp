#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


vector<string> separarToken(string token) {

    vector<string> result;
    string armazem = "";
    
    // for(char c: token) {
    //     if( c == '(' || c == ')' ) { // Aqui verificamos se encontramos os parentes para casos como "escreva(x)"
    //         if( !armazem.empty() == true ) { // Verificamos se tem alguma coisa ja armazenada, para ai resetar "" o armazem
    //             result.push_back(armazem);
    //             armazem = "";
    //         }
    //         result.push_back(string(1, c)); // Como é um Vector de string, ele nao aceita char, entao convertemos o char para string
    //     } else {
    //         armazem += c;
    //     }
    // }

    for( size_t i = 0; i < token.size(); i++ ) {
        char c = token[i];

        if( c == '<' && token[i+1] == '-' ) { // Aqui esta sendo verificado se o token é um '<-'
            if(!armazem.empty()) {
                result.push_back(armazem);
                armazem = "";
            }
            result.push_back("<-");
            i++; // para pular o '-'
            continue;
        }

        if( c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/'  ) {
            if(!armazem.empty()) {
                result.push_back(armazem);
                armazem = "";
            }
            result.push_back(string(1, c));
        } else {
            armazem += c;
        }
    }

    if( !armazem.empty() == true ) result.push_back(armazem); // Se tiver algo sobrando no armazem, colocamos no vetor!

    return result;

}

double resolverOperando( string token, map<string, double>& variaveis ) {

    if( variaveis.count(token) == true ) return variaveis[token];

    return stod(token);

}

double aplicarOperador( double value1, double value2, string operador ) {
    if (operador == "+") return value1 + value2;
    else if (operador == "-") return value1 - value2;
    else if (operador == "*") return value1 * value2;
    else if (operador == "/") return value1 / value2;

    return 0; // Aqui caso nao tenha nenhum desses operadores, ele ira retornar 0, para o codigo nao quebrar!
}



int main(int argc, char* argv[]) {
    // Vimos na ultima aula (11/06) sobre essa questao de passar argumentos no main
    // argc = quantidade de argumentos
    // argv[0] = devemos ignorar
    // argv[1] = aqui seria o primeiro argumento, no qual seria o nome do arquivo.txt

    if( argc < 2 ) {
        cout << "[ALERT] Use: " << argv[0] << " nome_arquivo.txt" << endl;
        return 0;
    }

    // aqui criamos a "variável" do arquivo. Com ela, conseguirimos ler o conteúdo dela.
    fstream arquivo(argv[1]);

    if( !arquivo.is_open() ) {
        cout << "[ERROR] Erro ao abrir o arquivo " << argv[1] << endl;
        return 0;
    }

    map<string, double> variaveis; // Isso aqui será uma "Tabela de Variáves": nome <- valor
    string linha; // Nessa variável iremos guardar o conteúdo de uma linha inteira usando a função "getline(arquivo, linha)"

    // Este laço de repetição irá funcionar da seguinte forma:
    // Equanto tiver linhas para se ler no arquivo, ele irá ler e salvar a linha inteira na nossa "string linha"
    // Enquanto tiver linha para ler, a função getline() irá retornar "true", continuara lendo as linhas 1 por vez e salvando na variável
    // Caso acabe e não tenha mais linhas para ler, a função irá retorna "false", fazendo assim o laço de repetição acabar.
    while ( getline(arquivo, linha) ) {
        // cout << "Linha lida: " << linha << endl;

        // Essa variável irá separar a linha em pedaços
        // Esses pedaços a gente chama de "TOKENS"
        stringstream ss(linha);
        
        string token;
        vector<string> tokens;
        
        // O operador ">>" Ignora qualquer espaço/tab no início 
        while ( ss >> token ) { // retorna false quando chegar ao final da linha, encerrando o loop
            vector<string> subTokens = separarToken(token);
            for(string t: subTokens) {
                tokens.push_back(t);
            }
        }

        if( tokens.size() == 3 && tokens[1] == "<-" ) {
            string nomeVariavel = tokens[0];
            double valor = stod(tokens[2]); // Transformando String em Double

            variaveis[nomeVariavel] = valor;
            cout << "Variavel '" << nomeVariavel << "' recebeu o valor " << valor << endl;

        } else if( tokens.size() == 4 && tokens[0] == "escreva" && tokens[1] == "(" && tokens[3] == ")" ) {

            string nomeVariavel = tokens[2];

            if( variaveis.count(nomeVariavel) == true ) { // o count é nada mais que verificar na tabela se a variavel existe!
                cout << variaveis[nomeVariavel] << endl;                
            } else cout << "[ERROR] Variável '" << nomeVariavel << "' nao encontrada!" << endl;

        } else if( tokens.size() == 5 && tokens[1] == "<-" ) {

            string nomeVariavel = tokens[0];
            string operador = tokens[3];

            double value1 = resolverOperando(tokens[2], variaveis);
            double value2 = resolverOperando(tokens[4], variaveis);
            double result = aplicarOperador(value1, value2, operador);

            // if(operador == "+") result = value1 + value2;
            // else if(operador == "-") result = value1 - value2;
            // else if(operador == "*") result = value1 * value2;
            // else if(operador == "/") result = value1 / value2;

            variaveis[nomeVariavel] = result;
            cout << "Variavel '" << nomeVariavel << "' recebeu o valor " << result << endl;


        } else if( tokens.size() == 6 && tokens[0] == "escreva" && tokens[1] == "(" && tokens[5] == ")"  ) {
            double value1 = resolverOperando(tokens[2], variaveis);
            double value2 = resolverOperando(tokens[4], variaveis);
            double result = aplicarOperador(value1, value2, tokens[3]);

            cout << result << endl;
        }

        cout << "Tokens: ";
        for( string t: tokens ) // famoso for-each ensinado pelo professor em aula
            cout << "[" << t << "] ";
        cout << endl;
        

    }

    arquivo.close();
    return 0;
    

}