
## Estruturas de Dados Dinâmicas

### Diogo Silva
####  CAP / ENGEL
dasilva@academiafa.edu.pt

<!-- .slide: data-background="white" -->
---

## O primeiro programa

```c
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

O que está a acontecer?
<!-- .element: class="fragment fade-out" data-fragment-index="0"-->

Este programa simples escreve no terminal a frase "Hello world!", sem as ".
<!-- .element: class="fragment fade-in-then-out" data-fragment-index="0"-->

--


```c [1]
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

"Importa" código externo ao nosso programa, permitindo chamar a
função printf, que não está aqui definida.



--


```c [3,6]
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

É a função principal do programa.
Os programas em C começam sempre nesta função.
Todos os programas têm uma função `main`.

--

```c [4]
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

É uma instrução que chama a função
`printf` da biblioteca `stdio.h` (que faz parte do próprio C),
dando-lhe como input o literal de _string_ `"Hello world!"`.

A função "imprime" no terminal o input recebido.

Todas as instruções no C acabam com `;`.
<!-- .element: class="fragment" -->

--

```c [5]
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

Especifica o valor de retorno do nosso programa,
neste caso 0.

--

## Escrevi o código, e agora?


--

- preprocessamento
  - obedece a comandos que começam com # (diretivas) 
  <!-- .element: class="fragment" -->
  - funciona um pouco como um editor de texto, onde se adicionam ou modificam partes do código <!-- .element: class="fragment" -->
- compilação
  - transformar o código C numa linguagem que o computador perceba = linguagem máquina
  <!-- .element: class="fragment" -->
- _linking_
  - combina o output gerado pela compilação com outro código necessário à execução do programa (e.g. stdio.h para usar o printf)
  <!-- .element: class="fragment" -->

--

Quando damos indicação ao nosso IDE para compilar e correr o código,
estes 3 passos tipicamente acontecem de forma automática.

---

## Componentes de um programa

```c
#diretivas

int main(){
    instruções;
}
```

--

### A diretiva _include_

```c
#include <stdio.h>
```

Esta diretiva indica que o conteúdo da biblioteca `stdio.h ` deve ser incluida no programa atual.

--

### Funções

Funções são procedimentos ou subrotinas que executam uma determinado conjunto de instruções.

Cada função é uma determinada receita para um determinado comportamento ou funcionalidade.
<!-- .element: class="fragment" -->

Isto permite que o mesmo comportamento seja executado diversas vezes num programa sem o ter que implementar múltiplas vezes.
<!-- .element: class="fragment" -->

--

### Instruções

Uma instrução é um comando que é executado quando o programa corre, e.g.

```c
printf("Hello world!");
```

--

### I/O

A capacidade de um programa comunicar com o mundo exterior é fundamental para que seja útil.

No nosso primeiro programa, essa comunicação foi feita com a função `printf` e o output foi apresentado num terminal.

--

Anteriormente foi referido que a função recebeu um _literal de string_, uma série sequencial de caracteres entre "".

As "" não são incluidas no que aparece no terminal. Se quisermos incluir " no nosso output, é necessário escrever \".


--

O `printf` não inclui automaticamente o fim de linha.

Para garantir que o `printf` seguinte não apresenta o seu conteúdo na mesma linha do anterior, é necessário adicionar `\n`.

```c
printf("Hello world!\n");
printf("Good morning, Vietnam!");
```

---


## Comentários

