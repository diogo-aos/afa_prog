
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

### I/O `printf`

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

O nosso primeiro programa não tem algo importante:

### <span style="color:Chocolate">documentação</span>

--

Os programas devem ter várias informações sobre o programa em si, e.g. autor, propósito, etc.

```c
/* Nome: hello_world.c*/
/* Autor: Diogo Silva*/
/* Proposito: Mostrar "Hello world!" na consola.*/
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

No C, escrevemos comentários entre `/* */`.
Todo o texto entre estes símbolos é ignorado pelo comentário, i.e. não é interpretado como código.
<!-- .element: class="fragment"-->

--

```c
/*
Nome: hello_world.c
Autor: Diogo Silva
Proposito: Mostrar "Hello world!" na consola.
*/
#include <stdio.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

Um comentário pode compreender várias linhas.

--

Também podemos escrever comentários de apenas uma linha com o símbolo `//`.

Tudo o que vem depois deste símbolo é interpretado como um comentário.

```c
#include <stdio.h>

int main(){
    printf("Hello world!"); // escrever na consola
    return 0;
}
```

A legibilidade do programa aumenta bastante quando existem comentários que descrevem de forma sumária porções do código.
<!-- .element: class="fragment"-->


---

## Variáveis

A maior parte dos programas executa uma série de cálculos.
<!-- .element: class="fragment"-->

Para isso, precisam de um mecanismo para guardar dados de forma temporária.
<!-- .element: class="fragment"-->

É para isso que servem as **variáveis**.
<!-- .element: class="fragment"-->

--

As **variáveis** são locais na memória onde é possível gravar algum dado, temporáriamente, durante a execução do programa.

--

### Variáveis > Tipos

No C, todas as variáveis têm um **tipo** associado.

O C tem vários tipos de dados, mas para já usaremos apenas 2 tipos numéricos:
<!-- .element: class="fragment"-->

- int (inteiro)
- float (real, *floating point*)

<!-- .element: class="fragment"-->

--

Uma analogia aos tipos são os domínios na matemática, e.g. ``int`` pode ser comparado ao dominio dos números naturais.


Associado a um tipo, existe: <!-- .element: class="fragment"-->
- um conjunto de valores válidos (e.g. números inteiros positivos até 65.535) <!-- .element: class="fragment"-->
- operações válidas nos valores desse tipo (+ - * /) <!-- .element: class="fragment"-->


--

Diferentes tipos incluem diferentes conjuntos de valores válidos.

O C tem vários `int` que incluem diferentes intervalos de valores possíveis e.g. típicamente, `int` inclui valores inteiros no intervalo `[-65536, 65535]`.

--

O ``float`` inclui valores muito maiores que um ``int``, e contempla valores reais, e.g. 3.14.

Operações aritméticas em `float` podem ser mais lentas.

--

### Variáveis > declaração

Quando queremos usar uma variável, esta tem de ser declarada.

```c
int altura; // em cm
float massa; // em kg
```

``altura`` é uma variável do tipo ``int`` e ``massa`` é uma variável do tipo ``float``.

--

Também podemos declarar várias variáveis de um determinado tipo numa só linha.

```c
int altura, idade; // cm, meses
float massa, lucro; // kg, €
```

--

### Variáveis > atribuição

As variáveis recebem valores através da instrução de atribuição `=`.

```c
int altura; // em cm
float massa; // em kg

altura = 180;
massa = 75.2;
```

``altura`` tem agora o valor ``180`` e ``massa`` tem o valor ``75.2``
<!-- .element: class="fragment" -->

``180`` e ``75.2`` são constantes.
<!-- .element: class="fragment" -->

--

Depois das variáveis terem um valor atribuido, podem ser usadas no cálculo de outros valores.

```c
int altura; // em cm
float massa, imc; // em kg

altura = 180;
massa = 75.2;
imc = massa / (altura / 100.0); //indice massa corporal
```

--

As variáveis só podem ser usadas depois de declaradas.

```c [3]
int altura; // em cm

massa = 75.2;

float massa, imc; // em kg

altura = 180;

imc = massa / (altura / 100.0); //indice massa corporal
```

Este código é inválido porque estamos a atribuir um valor à variável ``massa``, que ainda não foi declarada.

--

### Variáveis > printf

Se quisermos mostrar o valor de uma determinada variável, podemos usar novamente a função ``printf``.

```c [6]
int altura; // em cm
float massa, imc; // em kg

altura = 180;
massa = 75.2;
printf("Altura: %d\n", altura);
```

O que significa o símbolo `%d`?
<!-- .element: class="fragment" -->

--

`%d` indica como é que o valor contido na variável ``altura`` deve ser interpretado.

Neste caso, `%d` indica que deve ser interpretado como um valor inteiro ``int``.
<!-- .element: class="fragment" -->

O descritor escolhido deve ser coerente com o tipo da variável que se vai mostrar.
<!-- .element: class="fragment" -->

`altura` é do tipo `int`, logo usamos o descritor `%d`.
<!-- .element: class="fragment" -->

--

Importante: o C não impede um "desalinhamento" entre tipo e descritor - é responsabildiade do programador garantir a coerência.

--

```c [6]
int altura; // em cm
float massa, imc; // em kg

altura = 180;
massa = 75.2;
imc = massa / (altura / 100.0); //indice massa corporal
printf("Indice massa corporal: %f\n", imc);
```

O descritor `%f` é usado para valores do tipo `float`.

--

### Variáveis > ``printf`` de expressões

O cálculo do IMC na variável intermédia `imc` é desnecessário, uma vez que podemos inserir a expressão completa do cálculo na função ``printf``.

```c [6]
int altura; // em cm
float massa, imc; // em kg

altura = 180;
massa = 75.2;
printf("Indice massa corporal: %f\n", massa / (altura / 100.0));
```

--

O que é uma expressão?

Uma expressão é algo que produz um valor concreto.
<!-- .element: class="fragment" -->

**Uma expressão produz sempre um valor com um valor concreto**, mesmo quando variáveis de tipos diferentes são misturadas (conversão automática de tipos será abordada posteriormente.)
<!-- .element: class="fragment" -->

--

Um valor de um determinado tipo pode sempre ser substituido por uma expressão do mesmo tipo.

--

### Variáveis > inicialização

Algumas variáveis são automaticamente inicializadas com o valor de 0 quando são declaradas, mas a maior parte não é.
<!-- .element: class="fragment" -->

Uma variável que não tenha um valor por defeito e que não tenha sofrido nenhuma atribuição está **não inicializada**.
<!-- .element: class="fragment" -->

--

É importante perceber que o C permite que uma variável seja usada em cálculos, mesmo não tenha sido inicializada.

```c
int altura; // em cm
float massa, imc; // em kg

massa = 75.2;
imc = massa / (altura / 100.0); //indice massa corporal
```

É **responsabilidade do programador saber que o programa pode ter um comportamento inválido**, porque a variável que não foi inicializada (que não teve nenhuma atribuição) pode conter qualquer valor.
<!-- .element: class="fragment" -->

--

As variáveis podem ser inicializadas no momento da sua declaração.

```c
int altura=180; // em cm
float massa=75.2, imc=0.0; // em kg
``

--

### Exercício

---


## I/O receber valores

Já sabemos mostrar valores ao utilizador do programa, mas como receber dados?

Usamos a função ``scanf``.
<!-- .element: class="fragment" -->

--

A função ``scanf`` funciona como o ``printf``, mas na direção oposta.

```c
scanf("%d", &a);  // receber altura do utilizador
scanf("%f", &b);  // receber altura do utilizador
```

Indicamos o formato dos dados que vamos receber e a variável onde os queremos guardar.
<!-- .element: class="fragment" -->


--

```c
scanf("%d", &a);  // receber altura do utilizador
scanf("%f", &b);  // receber altura do utilizador
```

Assumindo que já foram declaradas, qual será o tipo das variáveis ``a`` e ``b``?


Sabemos que `%d` funciona com valores `int`, logo `a` deverá ser do tipo `int`.
<!-- .element: class="fragment" -->

Na mesma linha, `b` deverá ser um `float`.
<!-- .element: class="fragment" -->

--

### Exercício

Alterar o exercício anterior para receber os valores do utilizador.

---

## Constantes

---

## Identificadores