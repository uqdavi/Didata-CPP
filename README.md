# Didata CPP

> Projeto acadêmico desenvolvido para a disciplina de **Algoritmos e Programação**, sob orientação do professor **Josenalde Barbosa**.

## Sobre o projeto

O **Didata** (https://github.com/uqdavi/Didata) é um projeto pessoal que eu venho produzindo desde o início deste ano. Ele é basicamente uma nova linguagem de programação no formato de pseudocódigo, possuindo seu próprio instalador, compilador próprio, dentre outros recursos. Como ele é um projeto desenvolvido nativamente em Java, resolvi criar uma cópia simples dele **(Didata CPP)** usando recursos e bibliotecas em **C++** que eu aprendi nas aulas de algoritmos. A proposta é ler um arquivo de texto (`.txt`) contendo instruções escritas em pseudocódigo e executar essas instruções, produzindo a saída diretamente no terminal.

Exemplo de entrada (`arquivo.txt`):

```
x <- 10
y <- 20

se (x < y) entao
    escreva(x)
senao
    escreva(y)
fimse
```

Saída:

```
10
```

O desenvolvimento é feito de forma incremental, com cada etapa documentando os conceitos da disciplina aplicados ao longo do projeto.

## Versão atual: v1.4.0

Atualmente, o Didata CPP já é capaz de interpretar:

- Atribuição de variáveis: `a <- 10`
- Atribuição com operações aritméticas (`+`, `-`, `*`, `/`): `c <- a + b`
- Comando `escreva(...)`, tanto para variáveis (`escreva(a)`) quanto para expressões (`escreva(a+b)`) e valores literais (`escreva(100)`)
- Condicional `se/senao se/senao/fimse` com suporte a operadores de comparação (`>`, `<`, `>=`, `<=`, `==`, `!=`)
- Laço de repetição `enquanto/fimenquanto` com suporte às mesmas comparações do `se`
- Flag `#sem-logs` no topo do arquivo para suprimir mensagens de log sem afetar a saída principal

## Sintaxe suportada

### Atribuição

```
x <- 10
y <- x + 5
```

### Impressão

```
escreva(x)
escreva(x + y)
escreva(100)
```

### Condicional

```
se (x > y) entao
    escreva(x)
senao se (x == y) entao
    escreva(0)
senao
    escreva(y)
fimse
```

### Laço de repetição

```
enquanto (x < 10) faca
    escreva(x)
    x <- x + 1
fimenquanto
```

### Flag de logs

Coloque `#sem-logs` na primeira linha do arquivo para desativar as mensagens de log:

```
#sem-logs
x <- 1
enquanto (x < 5) faca
    escreva(x)
    x <- x + 1
fimenquanto
```

## Estrutura do projeto

```
Didata-CPP/
├── include/
│   └── Interpretador.h              # Cabeçalho central — declara todas as funções
├── src/
│   ├── commands/                    # Implementações de cada comando da linguagem
│   │   ├── atribuicao.cpp           # Comando: atribuição simples          (x <- 10)
│   │   ├── atribuicaoOperacao.cpp   # Comando: atribuição com operação     (x <- a + b)
│   │   ├── enquanto.cpp             # Comando: loop de repetição     enquanto (x <= 10) faca ...
│   │   ├── escreva.cpp              # Comando: impressão de valor           escreva(x)
│   │   ├── escrevaOperacao.cpp      # Comando: impressão de expressão       escreva(a + b)
│   │   └── se.cpp                   # Comando: condicional se/senao se/senao/fimse
│   ├── aplicarOperador.cpp          # Aplica um operador aritmético (+, -, *, /)
│   ├── avaliarCondicao.cpp          # Avalia uma condição booleana (>, <, >=, <=, ==, !=)
│   ├── executarLinha.cpp            # Despacha tokens para o comando correto
│   ├── imprimirTokens.cpp           # Utilitário de depuração — exibe tokens
│   ├── resolverOperando.cpp         # Resolve operando (variável ou literal numérico)
│   ├── separarTokens.cpp            # Subdivide tokens que contêm operadores colados
│   └── tokenizarLinha.cpp           # Divide uma linha em tokens brutos
├── main.cpp                         # Ponto de entrada — carrega e executa o arquivo
├── main.exe                         # Executável compilado (Windows)
├── test.txt                         # Arquivo de teste para o interpretador
├── Makefile                         # Script de compilação automática
├── README.md                        # Documentação geral do projeto
└── .gitignore                       # Arquivos ignorados pelo Git
```

## Tecnologias

- C++
- Bibliotecas da STL (Standard Template Library):
  - `<fstream>` — leitura de arquivos
  - `<sstream>` — tokenização de strings
  - `<vector>` — armazenamento dinâmico dos tokens
  - `<map>` — tabela de variáveis (nome → valor)

## Executar online

Você pode rodar o projeto diretamente no navegador, sem precisar instalar nada, pelo Google Colab:

🔗 [Abrir no Google Colab](https://colab.research.google.com/drive/1RDipd6OCLXt0Xl3iU7b1cDH5mm3IP_c6?usp=sharing)

## Como compilar e executar

```bash
# Compilar com Make
make

# Compilar manualmente com g++
g++ main.cpp src/*.cpp src/commands/*.cpp -I include -o main.exe

# Executar
main programa.txt        # Windows
./main programa.txt      # Linux/Mac

# Limpar o executável
make clean
```

## Workflow de versionamento

O projeto segue o fluxo de branches `main` (versões oficiais) e `develop` (desenvolvimento), método ensinado pelo professor Marlon na disciplina de Fundamentos da Computação. Cada nova versão é marcada com uma tag (ex: `v1.3.0`) e documentada na seção de Releases.

## Status

Em desenvolvimento — novas funcionalidades serão adicionadas e documentadas a cada nova versão.