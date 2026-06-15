# Didata CPP

> Projeto acadêmico desenvolvido para a disciplina de **Algoritmos e Programação**, sob orientação do professor **Josenalde Barbosa**.

## Sobre o projeto

O **Didata** (https://github.com/uqdavi/Didata) é um projeto pessoal que eu venho produzindo desde o início deste ano. Ele é basicamente uma nova linguagem de programação no formato de "Pseudocódigo", possuindo seu próprio instalável, compilador próprio, dentre outros recursos. Como ele é um projeto desenvolvido nativamente em Java, resolvi criar uma cópia simples dele **(Didata CPP)** usando recursos e bibliotecas em **C++** que eu aprendi nas aulas de algoritmos. A proposta é ler um arquivo de texto (`.txt`) contendo instruções escritas em pseudocódigo e executar essas instruções, produzindo a saída diretamente no terminal.

Exemplo de entrada (`arquivo.txt`):

```
a <- 10
escreva(a)
```

Saída esperada:

```
10
```

O desenvolvimento será feito de forma incremental, com cada etapa documentando os conceitos da disciplina aplicados ao longo do projeto.

## Versões

### v1.1.0 (atual)

Nesta versão, o projeto passou a:

- Ler o arquivo `.txt` linha por linha, usando `getline`.
- Separar cada linha em **tokens** (pedaços), usando `stringstream` e o operador `>>`.
- Tratar tokens que contêm parênteses, por exemplo: `escreva(a)` é separado em `escreva`, `(`, `a` e `)` — através da função `separarToken`.
- Iniciar a modularização do código, com a criação da primeira função fora do `main`.

Novas bibliotecas utilizadas:

- `<sstream>` — permite tratar uma `string` como um stream, possibilitando ler "palavra por palavra" com `>>`. Documentação: https://en.cppreference.com/w/cpp/header/sstream
- `<vector>` — usado para armazenar os tokens de forma dinâmica. Documentação: https://www-w3schools-com.translate.goog/cpp/cpp_vectors.asp?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc

### v1.0.0

- Criação do arquivo principal `main.cpp`.
- Inclusão da biblioteca `<fstream>`, utilizada para leitura de arquivos de texto.

Documentação oficial: https://www.w3schools.com/cpp/ref_fstream_fstream.asp

## Tecnologias

- C++
- Bibliotecas da STL (Standard Template Library):
  - `<fstream>` — leitura de arquivos
  - `<sstream>` — tokenização de strings
  - `<vector>` — armazenamento dinâmico dos tokens

## Status

Em desenvolvimento — novas funcionalidades serão adicionadas e documentadas a cada nova versão.