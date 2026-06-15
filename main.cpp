#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


vector<string> separarToken(string token) {

    vector<string> result;
    string armazem = "";
    
    for(char c: token) {
        if( c == '(' || c == ')' ) { // Aqui verificamos se encontramos os parentes para casos como "escreva(x)"
            if( !armazem.empty() == true ) { // Verificamos se tem alguma coisa ja armazenada, para ai resetar "" o armazem
                result.push_back(armazem);
                armazem = "";
            }
            result.push_back(string(1, c)); // Como é um Vector de string, ele nao aceita char, entao convertemos o char para string
        } else {
            armazem += c;
        }
    }

    if( !armazem.empty() == true ) result.push_back(armazem); // Se tiver algo sobrando no armazem, colocamos no vetor!

    return result;

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

        cout << "Tokens: ";
        for( string t: tokens ) // famoso for-each ensinado pelo professor em aula
            cout << "[" << t << "] ";
        cout << endl;
        

    }

    arquivo.close();
    return 0;
    

}