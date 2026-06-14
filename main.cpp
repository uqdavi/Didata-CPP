#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

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
    ifstream arquivo(argv[1]);

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
        cout << "Linha lida: " << linha << endl;
    }

    arquivo.close();
    return 0;
    

}