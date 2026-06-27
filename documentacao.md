# 📖 Documentação — Linguagem Didata

Didata é uma linguagem de pseudocódigo interpretada, criada para fins didáticos.  
Os programas são escritos em arquivos `.txt` e executados pelo interpretador `main.exe`.

```bash
# Como executar
main.exe meu_programa.txt
```

---

## Índice

1. [Diretiva `#sem-logs`](#1-diretiva-sem-logs)
2. [Atribuição simples `<-`](#2-atribuição-simples--)
3. [Atribuição com operação `<-`](#3-atribuição-com-operação--)
4. [Escreva — valor simples](#4-escreva--valor-simples)
5. [Escreva — com operação](#5-escreva--com-operação)
6. [Condicional `se / senao se / senao / fimse`](#6-condicional-se--senao-se--senao--fimse)
7. [Laço `enquanto / fimenquanto`](#7-laço-enquanto--fimenquanto)
8. [Operadores aritméticos](#8-operadores-aritméticos)
9. [Operadores de comparação](#9-operadores-de-comparação)
10. [Mensagens do sistema](#10-mensagens-do-sistema)

---

## 1. Diretiva `#sem-logs`

Por padrão, o interpretador exibe mensagens de log `[LOGS]` a cada operação executada (atribuições, operações, etc.).  
Para **desativar** essas mensagens e exibir apenas a saída do programa, coloque `#sem-logs` na **primeira linha** do arquivo.

### Sintaxe

```
#sem-logs
```

### Exemplo — com logs (padrão)

**Arquivo:**
```
x <- 42
escreva(x)
```

**Saída:**
```
[LOGS] Variavel 'x' recebeu o valor 42
[LOGS] Escrevendo a variável [42]
42
```

### Exemplo — sem logs

**Arquivo:**
```
#sem-logs
x <- 42
escreva(x)
```

**Saída:**
```
42
```

> **Observação:** `#sem-logs` só é reconhecida e deve estar na primeira linha. Qualquer outra posição será ignorada.

---

## 2. Atribuição simples `<-`

Armazena um valor numérico literal em uma variável.  
Todas as variáveis são do tipo `double`.

### Sintaxe

```
<nome_variavel> <- <valor>
```

### Exemplos

```
x <- 10
nota <- 7.5
contador <- 0
resultado <- 3.14
```

**Saída (com logs):**
```
[LOGS] Variavel 'x' recebeu o valor 10
[LOGS] Variavel 'nota' recebeu o valor 7.5
[LOGS] Variavel 'contador' recebeu o valor 0
[LOGS] Variavel 'resultado' recebeu o valor 3.14
```

> **Regras:**
> - O operador de atribuição é `<-` (seta para a esquerda).
> - O nome da variável vem **antes** da seta e o valor vem **depois**.
> - Variáveis não precisam ser declaradas antes — são criadas automaticamente na primeira atribuição.

---

## 3. Atribuição com operação `<-`

Realiza uma operação aritmética entre dois operandos (variáveis ou literais) e armazena o resultado em uma variável.

### Sintaxe

```
<nome_variavel> <- <operando1> <operador> <operando2>
```

### Exemplos

```
a <- 10
b <- 3

soma    <- a + b
subtr   <- a - b
produto <- a * b
divisao <- a / b
```

**Saída (com logs):**
```
[LOGS] Variavel 'a' recebeu o valor 10
[LOGS] Variavel 'b' recebeu o valor 3
[LOGS] Variavel 'soma' recebeu o valor 13
[LOGS] Variavel 'subtr' recebeu o valor 7
[LOGS] Variavel 'produto' recebeu o valor 30
[LOGS] Variavel 'divisao' recebeu o valor 3.33333
```

**Misturando literais e variáveis:**
```
x <- 5
y <- x + 10
z <- 2 * x
```

> **Regras:**
> - Exatamente **um** operador por expressão (operações compostas não são suportadas).
> - Os operandos podem ser variáveis ou números literais.
> - Operadores suportados: `+`, `-`, `*`, `/`.

---

## 4. Escreva — valor simples

Exibe na tela o valor de uma variável ou um número literal.

### Sintaxe

```
escreva(<variavel_ou_valor>)
```

### Exemplos

**Exibindo uma variável:**
```
nome <- 99
escreva(nome)
```

**Saída:**
```
[LOGS] Variavel 'nome' recebeu o valor 99
[LOGS] Escrevendo a variável [99]
99
```

**Exibindo um literal numérico diretamente:**
```
escreva(42)
escreva(3.14)
```

**Saída:**
```
[LOGS] Escrevendo o valor na tela
42
[LOGS] Escrevendo o valor na tela
3.14
```

**Erro — variável não definida:**
```
escreva(fantasma)
```

**Saída:**
```
[ERROR] Variavel 'fantasma' nao encontrada!
```

> **Regras:**
> - Os parênteses são obrigatórios: `escreva(x)`.
> - Pode-se escrever com ou sem espaços entre o nome e o parêntese: `escreva(x)` ou `escreva( x )` (os espaços internos são ignorados pelo tokenizador).

---

## 5. Escreva — com operação

Calcula e exibe o resultado de uma operação aritmética diretamente, sem precisar criar uma variável intermediária.

### Sintaxe

```
escreva(<operando1> <operador> <operando2>)
```

### Exemplos

```
a <- 10
b <- 4

escreva(a + b)
escreva(a - b)
escreva(a * b)
escreva(a / b)
escreva(a + 100)
escreva(3 * b)
```

**Saída (sem logs):**
```
14
6
40
2.5
110
12
```

> **Regras:**
> - Exatamente **um** operador por expressão dentro do `escreva`.
> - Os operandos podem ser variáveis ou literais.

---

## 6. Condicional `se / senao se / senao / fimse`

Executa um bloco de código apenas se uma condição for verdadeira.  
Suporta até três ramificações: `se`, `senao se` e `senao`.

### Sintaxe completa

```
se (<condicao>) entao
    <bloco se>
senao se (<outra_condicao>)
    <bloco senao se>
senao
    <bloco senao>
fimse
```

### Sintaxe mínima (só o `se`)

```
se (<condicao>) entao
    <bloco se>
fimse
```

### Exemplos

**Exemplo 1 — apenas `se`:**
```
#sem-logs
nota <- 8

se (nota >= 7) entao
    escreva(1)
fimse
```

**Saída:**
```
1
```

---

**Exemplo 2 — `se` e `senao`:**
```
#sem-logs
x <- 3
y <- 10

se (x > y) entao
    escreva(x)
senao
    escreva(y)
fimse
```

**Saída:**
```
10
```

---

**Exemplo 3 — `se`, `senao se` e `senao`:**
```
#sem-logs
x <- 3
y <- 5
z <- 10

se (x > y) entao
    escreva(x)
senao se (z < y)
    escreva(z)
senao
    escreva(y)
fimse
```

**Saída:**
```
5
```
*(Nem `x > y` nem `z < y` são verdadeiros, então cai no `senao` e imprime `y = 5`)*

---

**Exemplo 4 — condições com `==` e `!=`:**
```
#sem-logs
a <- 7

se (a == 7) entao
    escreva(777)
fimse

se (a != 0) entao
    escreva(1)
fimse
```

**Saída:**
```
777
1
```

> **Regras:**
> - A palavra `entao` é **obrigatória** ao final da linha do `se`.
> - O bloco deve ser encerrado com `fimse`.
> - É possível ter apenas um `senao se` por bloco.
> - Recuo/indentação das linhas do bloco é opcional (apenas para legibilidade).
> - Os blocos `senao se` e `senao` são opcionais.

---

## 7. Laço `enquanto / fimenquanto`

Repete um bloco de código enquanto uma condição for verdadeira.  
Equivalente ao `while` de linguagens como C++ e Python.

### Sintaxe

```
enquanto (<condicao>) faca
    <bloco do loop>
fimenquanto
```

### Exemplos

**Exemplo 1 — contador simples:**
```
#sem-logs
a <- 1

enquanto (a <= 5) faca
    escreva(a)
    a <- a + 1
fimenquanto
```

**Saída:**
```
1
2
3
4
5
```

---

**Exemplo 2 — soma acumulada:**
```
#sem-logs
i <- 1
soma <- 0

enquanto (i <= 10) faca
    soma <- soma + i
    i <- i + 1
fimenquanto

escreva(soma)
```

**Saída:**
```
55
```

---

**Exemplo 3 — contagem regressiva:**
```
#sem-logs
n <- 5

enquanto (n > 0) faca
    escreva(n)
    n <- n - 1
fimenquanto
```

**Saída:**
```
5
4
3
2
1
```

---

**Exemplo 4 — `enquanto` com `se` interno:**
```
#sem-logs
i <- 1

enquanto (i <= 10) faca
    se (i == 5) entao
        escreva(i)
    fimse
    i <- i + 1
fimenquanto
```

**Saída:**
```
5
```

> **Regras:**
> - A palavra `faca` é **obrigatória** ao final da linha do `enquanto`.
> - O bloco deve ser encerrado com `fimenquanto`.
> - A condição é reavaliada a cada iteração.
> - O loop pode conter comandos `se` internos.
> - Cuidado com **loops infinitos**: garanta que a variável da condição seja modificada dentro do bloco.

---

## 8. Operadores Aritméticos

Utilizados em atribuições com operação e no `escreva` com operação.

| Operador | Operação | Exemplo | Resultado |
|:---:|---|---|---|
| `+` | Adição | `x <- 10 + 3` | `x = 13` |
| `-` | Subtração | `x <- 10 - 3` | `x = 7` |
| `*` | Multiplicação | `x <- 10 * 3` | `x = 30` |
| `/` | Divisão | `x <- 10 / 3` | `x ≈ 3.333` |

> **Atenção:** apenas **uma** operação por instrução. Expressões como `a + b + c` não são suportadas.

---

## 9. Operadores de Comparação

Utilizados nas condições do `se` e do `enquanto`.

| Operador | Significado | Exemplo |
|:---:|---|---|
| `>` | Maior que | `se (x > 10) entao` |
| `<` | Menor que | `enquanto (i < 5) faca` |
| `>=` | Maior ou igual | `se (nota >= 7) entao` |
| `<=` | Menor ou igual | `enquanto (n <= 100) faca` |
| `==` | Igual | `se (a == b) entao` |
| `!=` | Diferente | `se (x != 0) entao` |

---

## 10. Mensagens do Sistema

O interpretador pode emitir três tipos de mensagens:

| Prefixo | Tipo | Quando aparece |
|---|---|---|
| `[LOGS]` | Informação de depuração | A cada operação executada (desativável com `#sem-logs`) |
| `[ERROR]` | Erro de execução | Variável não encontrada, sintaxe inválida, comando desconhecido |
| `[ALERT]` | Alerta de uso | Quando o programa é executado sem informar o arquivo `.txt` |

### Erros comuns

| Mensagem | Causa |
|---|---|
| `[ERROR] Linha N: comando invalido!` | A linha não corresponde a nenhum comando reconhecido |
| `[ERROR] Variavel 'X' nao encontrada!` | Tentou usar `escreva(X)` antes de atribuir um valor a `X` |
| `[ERROR] Condicao invalida: ...` | A condição no `se` ou `enquanto` não contém um operador de comparação válido |
| `[ERROR] Linha N: sintaxe invalida no 'se'` | Faltou `(` ou `)` na condição do `se` |
| `[ERROR] Linha N: esperado 'entao' apos a condicao do 'se'` | A linha do `se` não termina com `entao` |
| `[ERROR] 'fimse' nao encontrado para o 'se' da linha N` | O bloco `se` não foi fechado com `fimse` |
| `[ERROR] Linha N: sintaxe invalida no 'enquanto'` | Faltou `(` ou `)` na condição do `enquanto` |
| `[ERROR] Linha N: esperado 'faca' apos a condicao do 'enquanto'` | A linha do `enquanto` não termina com `faca` |
| `[ERROR] 'fimenquanto' nao encontrado para o 'enquanto' da linha N` | O bloco `enquanto` não foi fechado com `fimenquanto` |

---

## Programa Completo de Exemplo

```
#sem-logs

a <- 1
soma <- 0

enquanto (a <= 5) faca
    soma <- soma + a
    a <- a + 1
fimenquanto

escreva(soma)

se (soma > 10) entao
    escreva(1)
senao
    escreva(0)
fimse
```

**Saída:**
```
15
1
```
