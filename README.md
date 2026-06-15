# Didata CPP

> Projeto acadêmico desenvolvido para a disciplina de **Algoritmos e Programação**, sob orientação do professor **Josenalde Barbosa**.

## Sobre o projeto

O **Didata** (https://github.com/uqdavi/Didata) é um projeto pessoal que eu venho produzindo desde o início deste ano. Ele é basicamente uma nova linguagem de programação no formato de pseudocódigo, possuindo seu próprio instalador, compilador próprio, dentre outros recursos. Como ele é um projeto desenvolvido nativamente em Java, resolvi criar uma cópia simples dele **(Didata CPP)** usando recursos e bibliotecas em **C++** que eu aprendi nas aulas de algoritmos. A proposta é ler um arquivo de texto (`.txt`) contendo instruções escritas em pseudocódigo e executar essas instruções, produzindo a saída diretamente no terminal.

Exemplo de entrada (`arquivo.txt`):

```
a <- 10
b <- 20
escreva(a+b)
```

Saída:

```
30
```

O desenvolvimento é feito de forma incremental, com cada etapa documentando os conceitos da disciplina aplicados ao longo do projeto.

## Versão atual: v1.2.0

Atualmente, o Didata CPP já é capaz de interpretar:

- Atribuição de variáveis: `a <- 10`
- Atribuição com operações aritméticas (`+`, `-`, `*`, `/`): `c <- a + b`
- Comando `escreva(...)`, tanto para variáveis (`escreva(a)`) quanto para expressões (`escreva(a+b)`)

O histórico completo de versões — com o que foi adicionado e os conceitos aplicados em cada etapa — está disponível na aba [Releases](https://github.com/uqdavi/Didata-CPP/releases) do repositório.

## Tecnologias

- C++
- Bibliotecas da STL (Standard Template Library):
  - `<fstream>` — leitura de arquivos
  - `<sstream>` — tokenização de strings
  - `<vector>` — armazenamento dinâmico dos tokens
  - `<map>` — tabela de variáveis (nome → valor)

## Workflow de versionamento

O projeto segue o fluxo de branches `main` (versões oficiais) e `develop` (desenvolvimento), método ensinado pelo professor Marlon na disciplina de Fundamentos da Computação. Cada nova versão é marcada com uma tag (ex: `v1.2.0`) e documentada na seção de Releases.

## Status

Em desenvolvimento — novas funcionalidades serão adicionadas e documentadas a cada nova versão.