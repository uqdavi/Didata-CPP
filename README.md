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

## Versão atual: 1.0.0

Nesta primeira versão, o projeto conta apenas com:

- Criação do arquivo principal `main.cpp`.
- Inclusão da biblioteca `<fstream>`, que será utilizada para leitura de arquivos de texto.

A `<fstream>` faz parte da biblioteca padrão do C++ e fornece as classes responsáveis pela manipulação de arquivos, como `ifstream` (entrada/leitura) e `ofstream` (saída/escrita).

Documentação oficial: https://en.cppreference.com/w/cpp/header/fstream

## Tecnologias

- C++
- Bibliotecas da STL (Standard Template Library)

## Status

Em desenvolvimento — novas funcionalidades serão adicionadas e documentadas a cada nova versão.