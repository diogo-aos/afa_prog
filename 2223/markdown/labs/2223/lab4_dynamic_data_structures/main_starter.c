#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* * * * * * * * * * * * * * * * * * * * * * * *
    * ESTRUTURAS *
* * * * * * * * * * * * * * * * * * * * * * * */

typedef struct {
    int id;
    char nome[50];
    float media_final;
} Estudante;

// linked list node of type Estudante
typedef struct node {
    Estudante estudante;
    struct node *next;
} Node;

// function to print a Estudante pointer
void printEstudante(Estudante *estudante) {
    printf("ID: %d\n", estudante->id);
    printf("Nome: %s\n", estudante->nome);
    printf("Media Final: %.2f\n", estudante->media_final);
}


/* * * * * * * * * * * * * * * * * * * * * * * *
    * MOCK DATA *
* * * * * * * * * * * * * * * * * * * * * * * */


// array of 20 porguese first names
char *nomes_proprios[] = {
    "Maria",
    "Joao",
    "Ana",
    "Pedro",
    "Carla",
    "Jose",
    "Margarida",
    "Miguel",
    "Sofia",
    "Ricardo",
    "Ines",
    "Paulo",
    "Beatriz",
    "Tiago",
    "Catarina",
    "Andre",
    "Filipa",
    "Bruno",
    "Diana",
    "Rui"
};

// array of 20 portuguese last names
char *apelidos[] = {
    "Silva",
    "Santos",
    "Rodrigues",
    "Costa",
    "Oliveira",
    "Martins",
    "Ferreira",
    "Pereira",
    "Carvalho",
    "Marques",
    "Gomes",
    "Sousa",
    "Fernandes",
    "Goncalves",
    "Ribeiro",
    "Leal",
    "Faria",
    "Henriques",
    "Neves",
    "Oliveira"
};



Estudante *createEstudantes(unsigned int n) {
    Estudante *estudantes = malloc(n * sizeof(Estudante));
    for (int i = 0; i < n; i++) {
        estudantes[i].id = 1400 + i;
        int rand_nome = rand() % 20;
        int rand_apelido = rand() % 20;
        sprintf(estudantes[i].nome, "%s %s", nomes_proprios[rand_nome], apelidos[rand_apelido]);
        estudantes[i].media_final = 5 + rand() % 16;
    }
    return estudantes;
}


/* * * * * * * * * * * * * * * * * * * * * * * *
    * LISTA LIGADA *
* * * * * * * * * * * * * * * * * * * * * * * */

// function to add estudante to list
void addEstudante(Node **head, Estudante estudante) {

}


// function to print a linked list of Estudante
void printEstudantes(Node *head) {
}


int main(){
    // podes alterar este valor para testar com arrays de tamanhos diferentes
    int n_estudantes = 10;

    // receber array de Estudantes aleatórios
    

    // criar lista ligada
    

    // adicionar todos os Estudante do array à lista ligada
    

    // libertar array de Estudante da memória

    // escrever na consola todos os Estudante da lista ligada

    // eliminar da lista ligada todos os Estudante com media_final < 17
    //     para cada estudante removido, escrever na consola "removido estudante <nome> com media <media_final>"


    // imprimir quadro de honra (todos os alunos com média final >= 17)
    printf("\nQuadro de Honra:\n");
    // ...


}
