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
    Node *newNode = malloc(sizeof(Node));
    newNode->estudante = estudante;
    newNode->next = *head;
    *head = newNode;
}

// function to print a Estudante pointer
void printEstudante(Estudante *estudante) {
    printf("ID: %d\n", estudante->id);
    printf("Nome: %s\n", estudante->nome);
    printf("Media Final: %.2f\n", estudante->media_final);
}

// function to print a linked list of Estudante
void printEstudantes(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printEstudante(&current->estudante);
        current = current->next;
    }
}


int main(){
    int n_estudantes = 5;
    
    // load mock data
    Estudante *estudantes = createEstudantes(n_estudantes);

    // create linked list
    Node *head = NULL;

    // add all estudantes to linked list
    for (int i = 0; i < n_estudantes; i++) {
        addEstudante(&head, estudantes[i]);
    }

    free(estudantes);

    // print linked list
    printEstudantes(head);

    // iterate over the list and remove Estudante with media_final < 17
    Node *curr = head;
    Node *prev = NULL;
    while(curr != NULL){
        if(curr->estudante.media_final < 17){
            // remove node
            // check if node is head
            if(prev == NULL){
                head = curr->next;
            }else{
                prev->next = curr->next;
            }
            printf("removing estudante %s com média %.2f\n", curr->estudante.nome, curr->estudante.media_final);
            free(curr);
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }

    // imprimir quadro de honra
    printf("\nQuadro de Honra:\n");
    printEstudantes(head);
}
